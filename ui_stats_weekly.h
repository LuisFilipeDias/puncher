/********************************************************************************
** Form generated from reading UI file 'stats_weekly.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_WEEKLY_H
#define UI_STATS_WEEKLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "libs/qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Stats_Weekly
{
public:
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpinBox *stats_weekly_week;
    QSpacerItem *horizontalSpacer_3;
    QLabel *stats_weekly_label;
    QSpacerItem *horizontalSpacer;
    QLabel *stats_weekly_label_2;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *stats_weekly_working_days;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *stats_weekly_total_hours;
    QLabel *label_3;
    QLabel *stats_weekly_working_days_a;
    QLabel *stats_weekly_average_hours_b;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *stats_weekly_average_hours;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_2;
    QLabel *stats_weekly_weekly_statistics;

    void setupUi(QDialog *Stats_Weekly)
    {
        if (Stats_Weekly->objectName().isEmpty())
            Stats_Weekly->setObjectName(QStringLiteral("Stats_Weekly"));
        Stats_Weekly->resize(590, 713);
        widget = new QCustomPlot(Stats_Weekly);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 571, 501));
        layoutWidget = new QWidget(Stats_Weekly);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 571, 40));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        stats_weekly_week = new QSpinBox(layoutWidget);
        stats_weekly_week->setObjectName(QStringLiteral("stats_weekly_week"));

        horizontalLayout->addWidget(stats_weekly_week);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        stats_weekly_label = new QLabel(layoutWidget);
        stats_weekly_label->setObjectName(QStringLiteral("stats_weekly_label"));
        stats_weekly_label->setFont(font);

        horizontalLayout->addWidget(stats_weekly_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stats_weekly_label_2 = new QLabel(layoutWidget);
        stats_weekly_label_2->setObjectName(QStringLiteral("stats_weekly_label_2"));
        stats_weekly_label_2->setFont(font);

        horizontalLayout->addWidget(stats_weekly_label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        layoutWidget1 = new QWidget(Stats_Weekly);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 640, 571, 29));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stats_weekly_working_days = new QLineEdit(layoutWidget1);
        stats_weekly_working_days->setObjectName(QStringLiteral("stats_weekly_working_days"));

        gridLayout_2->addWidget(stats_weekly_working_days, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        stats_weekly_total_hours = new QLineEdit(layoutWidget1);
        stats_weekly_total_hours->setObjectName(QStringLiteral("stats_weekly_total_hours"));

        gridLayout_2->addWidget(stats_weekly_total_hours, 1, 4, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        stats_weekly_working_days_a = new QLabel(layoutWidget1);
        stats_weekly_working_days_a->setObjectName(QStringLiteral("stats_weekly_working_days_a"));

        gridLayout_2->addWidget(stats_weekly_working_days_a, 1, 1, 1, 1);

        stats_weekly_average_hours_b = new QLabel(layoutWidget1);
        stats_weekly_average_hours_b->setObjectName(QStringLiteral("stats_weekly_average_hours_b"));

        gridLayout_2->addWidget(stats_weekly_average_hours_b, 1, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 8, 1, 1);

        stats_weekly_average_hours = new QLineEdit(layoutWidget1);
        stats_weekly_average_hours->setObjectName(QStringLiteral("stats_weekly_average_hours"));

        gridLayout_2->addWidget(stats_weekly_average_hours, 1, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        widget1 = new QWidget(Stats_Weekly);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 600, 571, 30));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(widget1);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        stats_weekly_weekly_statistics = new QLabel(widget1);
        stats_weekly_weekly_statistics->setObjectName(QStringLiteral("stats_weekly_weekly_statistics"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        stats_weekly_weekly_statistics->setFont(font1);

        verticalLayout_2->addWidget(stats_weekly_weekly_statistics);


        retranslateUi(Stats_Weekly);

        QMetaObject::connectSlotsByName(Stats_Weekly);
    } // setupUi

    void retranslateUi(QDialog *Stats_Weekly)
    {
        Stats_Weekly->setWindowTitle(QApplication::translate("Stats_Weekly", "Dialog", 0));
        label->setText(QApplication::translate("Stats_Weekly", "Week", 0));
        stats_weekly_label->setText(QApplication::translate("Stats_Weekly", "From", 0));
        stats_weekly_label_2->setText(QApplication::translate("Stats_Weekly", "To", 0));
        label_3->setText(QApplication::translate("Stats_Weekly", "Total Hours", 0));
        stats_weekly_working_days_a->setText(QApplication::translate("Stats_Weekly", "Working Days", 0));
        stats_weekly_average_hours_b->setText(QApplication::translate("Stats_Weekly", "Average Hours", 0));
        stats_weekly_weekly_statistics->setText(QApplication::translate("Stats_Weekly", "Weekly Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class Stats_Weekly: public Ui_Stats_Weekly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_WEEKLY_H
