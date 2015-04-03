/********************************************************************************
** Form generated from reading UI file 'data_raw.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_RAW_H
#define UI_DATA_RAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_raw
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *data_raw_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Data_raw)
    {
        if (Data_raw->objectName().isEmpty())
            Data_raw->setObjectName(QStringLiteral("Data_raw"));
        Data_raw->resize(648, 229);
        layoutWidget = new QWidget(Data_raw);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 631, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        data_raw_cancel = new QPushButton(layoutWidget);
        data_raw_cancel->setObjectName(QStringLiteral("data_raw_cancel"));

        horizontalLayout->addWidget(data_raw_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Data_raw);

        QMetaObject::connectSlotsByName(Data_raw);
    } // setupUi

    void retranslateUi(QDialog *Data_raw)
    {
        Data_raw->setWindowTitle(QApplication::translate("Data_raw", "Dialog", 0));
        data_raw_cancel->setText(QApplication::translate("Data_raw", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Data_raw: public Ui_Data_raw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_RAW_H
