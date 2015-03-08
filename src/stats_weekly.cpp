#include "../inc/stats_weekly.h"

Stats_Weekly::Stats_Weekly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Weekly)
{
    setWindowTitle("Weekly Statistics");

    ui->setupUi(this);

    graph = ui->widget;
    stats_weekly_week = ui->stats_weekly_week;
    stats_weekly_label = ui->stats_weekly_label;

    connect(stats_weekly_week, SIGNAL(valueChanged(int)), this, SLOT(week_changed_callback(int)));

    init_graph();

}

Stats_Weekly::~Stats_Weekly()
{
    delete ui;
}

void Stats_Weekly::init_graph()
{
    QVector<double> x(7), y(7), y_av(7);

    QDate *date = new QDate();
    *date = date->currentDate();
    sel_week = date->weekNumber();
    stats_weekly_week->setValue(sel_week);

    int d_o_w = date->dayOfWeek() - 1;
    pos[d_o_w].day = date->day();
    pos[d_o_w].month = date->month();
    pos[d_o_w].year = date->year();

    /* finds position 0, according to selected date */
    pos[0].day = pos[d_o_w].day - d_o_w;
    if (pos[0].day < 1) {
        if (pos[d_o_w].month != 1) {
            pos[0].day = days_in_month(pos[d_o_w].month - 1) + (pos[0].day);
            pos[0].month = pos[d_o_w].month - 1;
            pos[0].year = pos[d_o_w].year;
        } else {
            pos[0].day = days_in_month(12) + (pos[0].day);
            pos[0].month = 12;
            pos[0].year = pos[d_o_w].year - 1;
        }
    } else {
        pos[0].month = pos[d_o_w].month;
        pos[0].year = pos[d_o_w].year;
    }

    // calculates the days for the selected week */
    for (int i = 0; i < 7; i++)
        pos[i+1] = fill_next_pos(pos[i]);

    /* x is 0 - 7 (monday to sunday 0 is discarded) */
    for (int i = 0; i < 7; i++)
        x[i] = i+1;

    QString label = "From: " +
            QString::number( pos[0].day )     + " - "   +
            QString::number( pos[0].month )   + " - "  +
            QString::number( pos[0].year )    + " \nTo: " +
            QString::number( pos[6].day )     + " - "   +
            QString::number( pos[6].month )   + " - "  +
            QString::number( pos[6].year );

    stats_weekly_label->setText(label);
    stats_weekly_label->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    /* returns the y axis, based on the week days */
    y = get_hours(pos);

    // create graph and assign data to it:
    graph->addGraph();
    graph->legend->setVisible(true);
    graph->graph(0)->setData(x, y);

    QPen pen;
    pen.setColor(QColor(30, 40, 255, 150));
    graph->graph(0)->setLineStyle(QCPGraph::lsLine);
    graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    pen.setWidthF(2);
    graph->graph(0)->setPen(pen);
    graph->graph(0)->setName("Working Hours");

    for (int i = 0; i < 7; i++)
        y_av[i] = 8;

    /* average hours graph */
    graph->addGraph();
    graph->graph(1)->setData(x, y_av);
    pen.setColor(QColor(255, 40, 0, 150));
    pen.setStyle(Qt::DotLine);
    pen.setWidthF(2);
    graph->graph(1)->setPen(pen);
    graph->graph(1)->setName("Average");


    // give the axes some labels:
    graph->xAxis->setLabel("Day");
    graph->yAxis->setLabel("Work Hours");
    // set axes ranges, so we see all data:
    graph->xAxis->setRange(0, 8);
    graph->yAxis->setRange(0, 12);
    graph->replot();

    /* fill x axis values correctly */
    QVector<double> xTicks;
    QVector<QString> piLabels;
    xTicks << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    piLabels << "" << QString::number(pos[0].day) << QString::number(pos[1].day) << QString::number(pos[2].day)
             << QString::number(pos[3].day) << QString::number(pos[4].day) << QString::number(pos[5].day)  << QString::number(pos[6].day);
    graph->xAxis->setAutoTicks(false);
    graph->xAxis->setAutoTickLabels(false);
    graph->xAxis->setTickVector(xTicks);
    graph->xAxis->setTickVectorLabels(piLabels);

    /* Plot Title */
    graph->plotLayout()->insertRow(0);
    QString graph_title = "Week: " +
            QString::number(sel_week)     + " - "   +
            + " - Statistics";
    graph->plotLayout()->addElement(0, 0, new QCPPlotTitle(graph, graph_title));

}

QVector<double> Stats_Weekly::get_hours(sw_pos sel_pos[7])
{
    int sel_hours, sel_minutes, sel_seconds;
    QVector<double> y(7);
    for (int i = 0; i < 7; i++) {
        if (status_ok != db->query(sel_pos[i].day, sel_pos[i].month, sel_pos[i].year,
                                   &sel_hours, &sel_minutes, &sel_seconds)) {
            qDebug() << "*** ERROR: db->query ***";
            y[i] = 0;
        } else {
            y[i] = sel_hours + sel_minutes / 60 + sel_seconds / 3600;
        }
    }

    return y;
}

int Stats_Weekly::days_in_month(int month)
{
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 2:
        return 28; // or 29 calculate
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    }
    return -1;
}

sw_pos Stats_Weekly::fill_next_pos(sw_pos prev)
{
    sw_pos next;

    next.day = prev.day;
    if (prev.day == days_in_month(prev.month)) {
        next.day = 1;
        next.month = prev.month + 1;
        if (next.month > 12) {
            next.month = 1;
            next.year = prev.year + 1;
        } else {
            next.year = prev.year;
        }
    } else {
        next.day = prev.day + 1;
        next.month = prev.month;
        next.year = prev.year;
    }
    return next;
}

void Stats_Weekly::week_changed_callback(int)
{
    qDebug() << ":: week_changed_callback ::";
}
