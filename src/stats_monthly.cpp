#include "../inc/stats_monthly.h"

Stats_Monthly::Stats_Monthly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats_Monthly)
{
    setWindowTitle("Monthly Statistics");


    ui->setupUi(this);
    stats_monthly_month = ui->stats_monthly_month;
    stats_monthly_year = ui->stats_monthly_year;
    stats_monthly_label_from = ui->stats_monthly_label;
    stats_monthly_label_to = ui->stats_monthly_label_2;
    stats_monthly_monthly_statistics = ui->stats_monthly_monthly_statistics;
    stats_monthly_total_hours = ui->stats_monthly_total_hours;
    stats_monthly_average_hours = ui->stats_monthly_average_hours;
    stats_monthly_working_days = ui->stats_monthly_working_days;

    stats_monthly_monthly_statistics->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    stats_monthly_year->setRange(1970,2120);

    connect(ui->stats_monthly_month, SIGNAL(valueChanged(int)), this, SLOT(month_changed_callback(int)));
    connect(ui->stats_monthly_year, SIGNAL(valueChanged(int)), this, SLOT(year_changed_callback(int)));

    no_graph = true;

    /* start by using current day infos */
    QDate *date = new QDate();
    *date = date->currentDate();
    the_month = date->month();
    the_year = date->year();
    stats_monthly_month->setValue(the_month);
    stats_monthly_year->setValue(the_year);

    //update_graph();

}

Stats_Monthly::~Stats_Monthly()
{
    delete ui;
}

void Stats_Monthly::update_graph()
{
    int month_days = days_in_month(the_month, the_year);
    QVector<double> x(month_days), y(month_days), y_av(month_days);
    QPen pen;

    // calculates the days for the selected month */
    for (int i = 0; i < month_days; i++) {
        pos[i].day = i + 1;
        pos[i].month = the_month;
        pos[i].year = the_year;
    }

    /* returns the y axis, based on the month days */
    y = get_hours(month_days, pos);

    int total_hours = 0, working_days = 0;
    for (int i = 0; i < month_days; i++) {
        if(y[i] > 0) {
            working_days ++;
            total_hours += y[i];
        }
    }

    stats_monthly_total_hours->setText(QString::number(total_hours));
    if (working_days != 0)
        stats_monthly_average_hours->setText(QString::number(total_hours / working_days));
    else
        stats_monthly_average_hours->setText(QString::number(0));
    stats_monthly_working_days->setText(QString::number(working_days));

    for (int i = 0; i < month_days; i++){
        if (working_days != 0)
            y_av[i] = total_hours / working_days;
        else
            y_av[i] = 0;
        x[i] = i+1;
    }

    QString label = "From: " +
            QString::number(pos[0].day)     + " "   +
            month_to_string(pos[0].month)   + " "  +
            QString::number(pos[0].year);

    stats_monthly_label_from->setText(label);
    stats_monthly_label_from->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    label = "To: " +
            QString::number(pos[month_days - 1].day)     + " "   +
            month_to_string(pos[month_days - 1].month)   + " "  +
            QString::number(pos[month_days - 1].year);

    stats_monthly_label_to->setText(label);
    stats_monthly_label_to->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    // create graph and assign data to it:
    QCustomPlot *graph = ui->widget;
    graph->clearGraphs();
    graph->clearItems();

    graph->addGraph();
    graph->legend->setVisible(true);
    graph->graph(0)->setData(x, y);
    pen.setColor(QColor(30, 40, 255, 150));
    graph->graph(0)->setLineStyle(QCPGraph::lsLine);
    graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    pen.setWidthF(2);
    graph->graph(0)->setPen(pen);
    graph->graph(0)->setName("Working Hours");

    /* average hours graph */
    graph->addGraph();
    graph->graph(1)->setData(x, y_av);
    pen.setColor(QColor(255, 40, 0, 150));
    pen.setStyle(Qt::DotLine);
    pen.setWidthF(2);
    graph->graph(1)->setPen(pen);
    graph->graph(1)->setName("Average");

    // give the axes some labels:
    graph->yAxis->setLabel("Work Hours");
    // set axes ranges, so we see all data:
    graph->xAxis->setRange(0, month_days + 1);
    graph->yAxis->setRange(0, 12);
    graph->replot();

    /* fill x axis values correctly */
    QVector<double> xTicks, yTicks;
    QVector<QString> xLabels;
    xTicks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9
           << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19
           << 20 << 21 << 22 << 23 << 24 << 25 << 26 << 27 << 28;

    xLabels << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9"
            << "10" << "11" << "12" << "13" << "14" << "15" << "16" << "17" << "18" << "19"
            << "20" << "21" << "22" << "23" << "24" << "25" << "26" << "27";

    switch (month_days){
    case 28:
        break;
    case 29:
        xTicks << 29;
        xLabels << "29";
        break;
    case 30:
        xTicks << 29 << 30;
        xLabels << "29" << "30";
        break;
    case 31:
        xTicks << 29 << 30 << 31;
        xLabels << "29" << "30" << "31";
        break;
    }

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
        QString graph_title = "Monthly Hours Statistics";
        graph->plotLayout()->addElement(0, 0, new QCPPlotTitle(graph, graph_title));
        no_graph = false;
    }

}

QVector<double> Stats_Monthly::get_hours(int days, sw_pos sel_pos[])
{
    int sel_hours, sel_minutes, sel_seconds;
    QVector<double> y(days);
    for (int i = 0; i < days; i++) {
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

void Stats_Monthly::month_changed_callback(int val)
{
    qDebug() << ":: month_changed_callback ::";

    if (val == 0) {
        the_month = 12;
        the_year--;
    } else if (val == 13) {
        the_month = 1;
        the_year++;
    } else {
        the_month = val;
    }

    stats_monthly_month->setValue(the_month);
    stats_monthly_year->setValue(the_year);
    update_graph();
}

void Stats_Monthly::year_changed_callback(int val)
{
    qDebug() << ":: year_changed_callback ::";

    the_year = val;

    update_graph();
}

