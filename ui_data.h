/********************************************************************************
** Form generated from reading UI file 'data.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_H
#define UI_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QLabel *data_title;
    QHBoxLayout *horizontalLayout;
    QLabel *data_hours;
    QSpinBox *data_input_hours;
    QLabel *data_minutes;
    QSpinBox *data_input_minutes;
    QLabel *data_seconds;
    QSpinBox *data_input_seconds;
    QFrame *line_3;
    QPushButton *data_update;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *data_raw;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *data_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Data)
    {
        if (Data->objectName().isEmpty())
            Data->setObjectName(QStringLiteral("Data"));
        Data->resize(430, 353);
        verticalLayoutWidget = new QWidget(Data);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 404, 330));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(verticalLayoutWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        data_title = new QLabel(verticalLayoutWidget);
        data_title->setObjectName(QStringLiteral("data_title"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        data_title->setFont(font);

        verticalLayout->addWidget(data_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        data_hours = new QLabel(verticalLayoutWidget);
        data_hours->setObjectName(QStringLiteral("data_hours"));

        horizontalLayout->addWidget(data_hours);

        data_input_hours = new QSpinBox(verticalLayoutWidget);
        data_input_hours->setObjectName(QStringLiteral("data_input_hours"));

        horizontalLayout->addWidget(data_input_hours);

        data_minutes = new QLabel(verticalLayoutWidget);
        data_minutes->setObjectName(QStringLiteral("data_minutes"));

        horizontalLayout->addWidget(data_minutes);

        data_input_minutes = new QSpinBox(verticalLayoutWidget);
        data_input_minutes->setObjectName(QStringLiteral("data_input_minutes"));

        horizontalLayout->addWidget(data_input_minutes);

        data_seconds = new QLabel(verticalLayoutWidget);
        data_seconds->setObjectName(QStringLiteral("data_seconds"));

        horizontalLayout->addWidget(data_seconds);

        data_input_seconds = new QSpinBox(verticalLayoutWidget);
        data_input_seconds->setObjectName(QStringLiteral("data_input_seconds"));

        horizontalLayout->addWidget(data_input_seconds);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        data_update = new QPushButton(verticalLayoutWidget);
        data_update->setObjectName(QStringLiteral("data_update"));

        horizontalLayout->addWidget(data_update);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        data_raw = new QPushButton(verticalLayoutWidget);
        data_raw->setObjectName(QStringLiteral("data_raw"));

        horizontalLayout_2->addWidget(data_raw);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        data_cancel = new QPushButton(verticalLayoutWidget);
        data_cancel->setObjectName(QStringLiteral("data_cancel"));

        horizontalLayout_2->addWidget(data_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Data);

        QMetaObject::connectSlotsByName(Data);
    } // setupUi

    void retranslateUi(QDialog *Data)
    {
        Data->setWindowTitle(QApplication::translate("Data", "Dialog", 0));
        data_title->setText(QApplication::translate("Data", "Select a day", 0));
        data_hours->setText(QApplication::translate("Data", "Hours", 0));
        data_minutes->setText(QApplication::translate("Data", "Min", 0));
        data_seconds->setText(QApplication::translate("Data", "Secs", 0));
        data_update->setText(QApplication::translate("Data", "Update", 0));
        data_raw->setText(QApplication::translate("Data", "Raw", 0));
        data_cancel->setText(QApplication::translate("Data", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Data: public Ui_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_H
