/********************************************************************************
** Form generated from reading UI file 'edit_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_DIALOG_H
#define UI_EDIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *edit_dialog_hours;
    QSpinBox *edit_dialog_input_hours;
    QLabel *edit_dialog_minutes;
    QSpinBox *edit_dialog_input_minutes;
    QLabel *edit_dialog_seconds;
    QSpinBox *edit_dialog_input_seconds;
    QHBoxLayout *horizontalLayout;
    QPushButton *edit_dialog_ok;
    QPushButton *edit_dialog_cancel;

    void setupUi(QDialog *edit_dialog)
    {
        if (edit_dialog->objectName().isEmpty())
            edit_dialog->setObjectName(QStringLiteral("edit_dialog"));
        edit_dialog->resize(301, 103);
        verticalLayoutWidget = new QWidget(edit_dialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 275, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        edit_dialog_hours = new QLabel(verticalLayoutWidget);
        edit_dialog_hours->setObjectName(QStringLiteral("edit_dialog_hours"));

        horizontalLayout_2->addWidget(edit_dialog_hours);

        edit_dialog_input_hours = new QSpinBox(verticalLayoutWidget);
        edit_dialog_input_hours->setObjectName(QStringLiteral("edit_dialog_input_hours"));

        horizontalLayout_2->addWidget(edit_dialog_input_hours);

        edit_dialog_minutes = new QLabel(verticalLayoutWidget);
        edit_dialog_minutes->setObjectName(QStringLiteral("edit_dialog_minutes"));

        horizontalLayout_2->addWidget(edit_dialog_minutes);

        edit_dialog_input_minutes = new QSpinBox(verticalLayoutWidget);
        edit_dialog_input_minutes->setObjectName(QStringLiteral("edit_dialog_input_minutes"));

        horizontalLayout_2->addWidget(edit_dialog_input_minutes);

        edit_dialog_seconds = new QLabel(verticalLayoutWidget);
        edit_dialog_seconds->setObjectName(QStringLiteral("edit_dialog_seconds"));

        horizontalLayout_2->addWidget(edit_dialog_seconds);

        edit_dialog_input_seconds = new QSpinBox(verticalLayoutWidget);
        edit_dialog_input_seconds->setObjectName(QStringLiteral("edit_dialog_input_seconds"));

        horizontalLayout_2->addWidget(edit_dialog_input_seconds);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        edit_dialog_ok = new QPushButton(verticalLayoutWidget);
        edit_dialog_ok->setObjectName(QStringLiteral("edit_dialog_ok"));

        horizontalLayout->addWidget(edit_dialog_ok);

        edit_dialog_cancel = new QPushButton(verticalLayoutWidget);
        edit_dialog_cancel->setObjectName(QStringLiteral("edit_dialog_cancel"));

        horizontalLayout->addWidget(edit_dialog_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(edit_dialog);

        QMetaObject::connectSlotsByName(edit_dialog);
    } // setupUi

    void retranslateUi(QDialog *edit_dialog)
    {
        edit_dialog->setWindowTitle(QApplication::translate("edit_dialog", "Dialog", 0));
        edit_dialog_hours->setText(QApplication::translate("edit_dialog", "Hours", 0));
        edit_dialog_minutes->setText(QApplication::translate("edit_dialog", "Min", 0));
        edit_dialog_seconds->setText(QApplication::translate("edit_dialog", "Secs", 0));
        edit_dialog_ok->setText(QApplication::translate("edit_dialog", "OK", 0));
        edit_dialog_cancel->setText(QApplication::translate("edit_dialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class edit_dialog: public Ui_edit_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_DIALOG_H
