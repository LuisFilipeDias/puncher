/********************************************************************************
** Form generated from reading UI file 'stats_monthly.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_MONTHLY_H
#define UI_STATS_MONTHLY_H

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

class Ui_Stats_Monthly
{
public:
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *stats_monthly_working_days;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *stats_monthly_total_hours;
    QLabel *label_3;
    QLabel *stats_weekly_working_days_a;
    QLabel *stats_weekly_average_hours_b;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *stats_monthly_average_hours;
    QSpacerItem *horizontalSpacer_5;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpinBox *stats_monthly_month;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QSpinBox *stats_monthly_year;
    QSpacerItem *horizontalSpacer_3;
    QLabel *stats_monthly_label;
    QSpacerItem *horizontalSpacer;
    QLabel *stats_monthly_label_2;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *line_2;
    QLabel *stats_monthly_monthly_statistics;

    void setupUi(QDialog *Stats_Monthly)
    {
        if (Stats_Monthly->objectName().isEmpty())
            Stats_Monthly->setObjectName(QStringLiteral("Stats_Monthly"));
        Stats_Monthly->resize(594, 695);
        widget = new QCustomPlot(Stats_Monthly);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 79, 571, 501));
        layoutWidget = new QWidget(Stats_Monthly);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 639, 571, 29));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stats_monthly_working_days = new QLineEdit(layoutWidget);
        stats_monthly_working_days->setObjectName(QStringLiteral("stats_monthly_working_days"));

        gridLayout_2->addWidget(stats_monthly_working_days, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        stats_monthly_total_hours = new QLineEdit(layoutWidget);
        stats_monthly_total_hours->setObjectName(QStringLiteral("stats_monthly_total_hours"));

        gridLayout_2->addWidget(stats_monthly_total_hours, 1, 4, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        stats_weekly_working_days_a = new QLabel(layoutWidget);
        stats_weekly_working_days_a->setObjectName(QStringLiteral("stats_weekly_working_days_a"));

        gridLayout_2->addWidget(stats_weekly_working_days_a, 1, 1, 1, 1);

        stats_weekly_average_hours_b = new QLabel(layoutWidget);
        stats_weekly_average_hours_b->setObjectName(QStringLiteral("stats_weekly_average_hours_b"));

        gridLayout_2->addWidget(stats_weekly_average_hours_b, 1, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 8, 1, 1);

        stats_monthly_average_hours = new QLineEdit(layoutWidget);
        stats_monthly_average_hours->setObjectName(QStringLiteral("stats_monthly_average_hours"));

        gridLayout_2->addWidget(stats_monthly_average_hours, 1, 7, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        layoutWidget_2 = new QWidget(Stats_Monthly);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 571, 61));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(layoutWidget_2);
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

        stats_monthly_month = new QSpinBox(layoutWidget_2);
        stats_monthly_month->setObjectName(QStringLiteral("stats_monthly_month"));

        horizontalLayout->addWidget(stats_monthly_month);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        stats_monthly_year = new QSpinBox(layoutWidget_2);
        stats_monthly_year->setObjectName(QStringLiteral("stats_monthly_year"));

        horizontalLayout->addWidget(stats_monthly_year);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        stats_monthly_label = new QLabel(layoutWidget_2);
        stats_monthly_label->setObjectName(QStringLiteral("stats_monthly_label"));
        stats_monthly_label->setFont(font);

        horizontalLayout->addWidget(stats_monthly_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stats_monthly_label_2 = new QLabel(layoutWidget_2);
        stats_monthly_label_2->setObjectName(QStringLiteral("stats_monthly_label_2"));
        stats_monthly_label_2->setFont(font);

        horizontalLayout->addWidget(stats_monthly_label_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(layoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        layoutWidget_3 = new QWidget(Stats_Monthly);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 600, 571, 30));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(layoutWidget_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        stats_monthly_monthly_statistics = new QLabel(layoutWidget_3);
        stats_monthly_monthly_statistics->setObjectName(QStringLiteral("stats_monthly_monthly_statistics"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        stats_monthly_monthly_statistics->setFont(font1);

        verticalLayout_2->addWidget(stats_monthly_monthly_statistics);


        retranslateUi(Stats_Monthly);

        QMetaObject::connectSlotsByName(Stats_Monthly);
    } // setupUi

    void retranslateUi(QDialog *Stats_Monthly)
    {
        Stats_Monthly->setWindowTitle(QApplication::translate("Stats_Monthly", "Dialog", 0));
        label_3->setText(QApplication::translate("Stats_Monthly", "Total Hours", 0));
        stats_weekly_working_days_a->setText(QApplication::translate("Stats_Monthly", "Working Days", 0));
        stats_weekly_average_hours_b->setText(QApplication::translate("Stats_Monthly", "Average Hours", 0));
        label->setText(QApplication::translate("Stats_Monthly", "Month", 0));
        label_2->setText(QApplication::translate("Stats_Monthly", "Year", 0));
        stats_monthly_label->setText(QApplication::translate("Stats_Monthly", "From", 0));
        stats_monthly_label_2->setText(QApplication::translate("Stats_Monthly", "To", 0));
        stats_monthly_monthly_statistics->setText(QApplication::translate("Stats_Monthly", "Monthly Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class Stats_Monthly: public Ui_Stats_Monthly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_MONTHLY_H
