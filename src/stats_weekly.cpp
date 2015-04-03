#include "../inc/stats_weekly.h"

Stats_Weekly::Stats_Weekly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Weekly)
{
    ui->setupUi(this);

    setWindowTitle("Weekly Statistics");

    stats_weekly_week = ui->stats_weekly_week;
    stats_weekly_label_from = ui->stats_weekly_label;
    stats_weekly_label_to = ui->stats_weekly_label_2;
    stats_weekly_weekly_statistics = ui->stats_weekly_weekly_statistics;
    stats_weekly_total_hours = ui->stats_weekly_total_hours;
    stats_weekly_average_hours = ui->stats_weekly_average_hours;
    stats_weekly_working_days = ui->stats_weekly_working_days;

    stats_weekly_weekly_statistics->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    connect(stats_weekly_week, SIGNAL(valueChanged(int)), this, SLOT(week_changed_callback(int)));

    no_graph = true;

    /* start by using current day infos */
    QDate *date = new QDate();
    *date = date->currentDate();
    d_o_w = date->dayOfWeek() - 1;
    pos[d_o_w].day = date->day();
    pos[d_o_w].month = date->month();
    pos[d_o_w].year = date->year();
    the_week = date->weekNumber();
    stats_weekly_week->setValue(the_week);

    update_graph();
}

Stats_Weekly::~Stats_Weekly()
{
    delete ui;
}

void Stats_Weekly::update_graph()
{
    int week_days = 7;
    QVector<double> x(week_days), y(week_days), y_av(week_days);
    QPen pen;

    /* finds position 0, according to selected date */
    pos[0].day = pos[d_o_w].day - d_o_w;
    if (pos[0].day < 1) {
        if (pos[d_o_w].month != 1) {
            pos[0].day = days_in_month(pos[d_o_w].month - 1, pos[d_o_w].year) + (pos[0].day);
            pos[0].month = pos[d_o_w].month - 1;
            pos[0].year = pos[d_o_w].year;
        } else {
            pos[0].day = days_in_month(12, pos[d_o_w].year - 1) + (pos[0].day);
            pos[0].month = 12;
            pos[0].year = pos[d_o_w].year - 1;
        }
    } else {
        pos[0].month = pos[d_o_w].month;
        pos[0].year = pos[d_o_w].year;
    }

    // calculates the days for the selected week */
    for (int i = 1; i < 7; i++)
        pos[i] = fill_next_pos(pos[i-1]);

    /* returns the y axis, based on the week days */
    y = get_hours(week_days, pos);

    double total_hours = 0;
    int working_days = 0;

    for (int i = 0; i < week_days; i++) {
        if(y[i] > 0) {
            working_days ++;
            total_hours += y[i];
        }
        /* setting decimal cases to 2 */
        decimal_cases(&y[i], 2);
    }

    /* x is 0 - 7 (monday to sunday 0 is discarded) */
    for (int i = 0; i < week_days; i++){
        if (working_days != 0)
            y_av[i] = total_hours / working_days;
        else
            y_av[i] = 0;

        /* setting decimal cases to 2 */
        decimal_cases(&y_av[i], 2);
        x[i] = i+1;
    }

    total_hours = (round(total_hours * 100))/100;
    stats_weekly_total_hours->setText(QString::number(total_hours));
    if (working_days != 0)
        stats_weekly_average_hours->setText(QString::number(y_av[0]));
    else
        stats_weekly_average_hours->setText(QString::number(0));
    stats_weekly_working_days->setText(QString::number(working_days));

    QString label = "From: " +
            QString::number(pos[0].day)     + " - "   +
            month_to_string(pos[0].month)   + " "  +
            QString::number(pos[0].year);

    stats_weekly_label_from->setText(label);
    stats_weekly_label_from->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    label = "To: " +
            QString::number(pos[week_days - 1].day)     + " - "   +
            month_to_string(pos[week_days - 1].month)   + " "  +
            QString::number(pos[week_days - 1].year);

    stats_weekly_label_to->setText(label);
    stats_weekly_label_to->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    // create graph and assign data to it:
    QCustomPlot *graph = ui->widget;
    graph->clearGraphs();
    graph->clearItems();

    graph->addGraph();
    graph->legend->setVisible(true);
    graph->graph(0)->setData(x, y);
    pen.setColor(QColor(0, 255, 0, 150));
    graph->graph(0)->setLineStyle(QCPGraph::lsNone);
    graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCrossSquare, 5));
    pen.setWidthF(5);
    graph->graph(0)->setPen(pen);
    graph->graph(0)->setName("Daily Hours");

    /* average hours graph */
    graph->addGraph();
    graph->graph(1)->setData(x, y_av);
    pen.setColor(QColor(0, 153, 51, 150));
    pen.setStyle(Qt::DotLine);
    pen.setWidthF(2);
    graph->graph(1)->setPen(pen);
    graph->graph(1)->setName("Average");

    // give the axes some labels:
    graph->yAxis->setLabel("Daily Hours");
    // set axes ranges, so we see all data:
    graph->xAxis->setRange(0, 8);
    graph->yAxis->setRange(0, 12);
    graph->replot();

    /* fill x axis values correctly */
    QVector<double> xTicks, yTicks;
    QVector<QString> xLabels;
    xTicks << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8;
    /*xLabels << "" << QString::number(pos[0].day) << QString::number(pos[1].day) << QString::number(pos[2].day)
             << QString::number(pos[3].day) << QString::number(pos[4].day) << QString::number(pos[5].day)  << QString::number(pos[6].day);
    */
    xLabels << "" << "Mon" << "Tue" << "Wed" << "Thu" << "Fri" << "Sat" << "Sun";
    graph->xAxis->setAutoTicks(false);
    graph->xAxis->setAutoTickLabels(false);
    graph->xAxis->setTickVector(xTicks);
    graph->xAxis->setTickVectorLabels(xLabels);

    yTicks << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12;
    graph->yAxis->setAutoTicks(false);
    graph->yAxis->setTickVector(yTicks);

    /* Plot Title */
    if (no_graph) {
        graph->plotLayout()->insertRow(0);
        QString graph_title = "Weekly Hours Statistics";
        graph->plotLayout()->addElement(0, 0, new QCPPlotTitle(graph, graph_title));
        no_graph = false;
    }

}

QVector<double> Stats_Weekly::get_hours(int days, sw_pos sel_pos[])
{
    int sel_hours, sel_minutes, sel_seconds;
    QVector<double> y(days);
    for (int i = 0; i < days; i++) {
        if (status_ok != db->query(sel_pos[i].day, sel_pos[i].month, sel_pos[i].year,
                                   &sel_hours, &sel_minutes, &sel_seconds)) {
            qDebug() << "*** ERROR: db->query ***";
            y[i] = 0;
        } else {
            y[i] = sel_hours + ((double) sel_minutes) / 60 + ((double) sel_seconds) / 3600;
        }
    }
    return y;
}

sw_pos Stats_Weekly::fill_next_pos(sw_pos prev)
{
    sw_pos curr;

    curr.day = prev.day;
    if (prev.day == days_in_month(prev.month, prev.year)) {
        curr.day = 1;
        curr.month = prev.month + 1;
        if (curr.month > 12) {
            curr.month = 1;
            curr.year = prev.year + 1;
        } else {
            curr.year = prev.year;
        }
    } else {
        curr.day = prev.day + 1;
        curr.month = prev.month;
        curr.year = prev.year;
    }
    return curr;
}

sw_pos Stats_Weekly::fill_prev_pos(sw_pos next)
{
    sw_pos curr;

    curr.day = next.day;
    if (next.day == 1) {
        curr.day = days_in_month(next.month - 1, next.year);
        curr.month = next.month - 1;
        curr.year = next.year;
        if (curr.month == 0) {
            curr.day = days_in_month(12, next.year-1);
            curr.month = 12;
            curr.year = next.year - 1;
        }
    } else {
        curr.day = next.day - 1;
        curr.month = next.month;
        curr.year = next.year;
    }
    return curr;
}

void Stats_Weekly::week_changed_callback(int val)
{
    qDebug() << ":: week_changed_callback ::";

    /* use d_o_w because it's the reference */
    /* if val is bigger, go forward 7 houses */
    if (val > the_week)
        for( int i = 1; i <= 7 * (val - the_week); i++)
            pos[d_o_w] = fill_next_pos(pos[d_o_w]);
    /* if val is bigger, go bacl 7 houses */
    else if (val < the_week)
        for( int i = 1; i <= 7 * (the_week - val); i++)
            pos[d_o_w] = fill_prev_pos(pos[d_o_w]);

    /* prevent reflux */
    if (the_week != val) {
        the_week = val;
        update_graph();
    }
}
