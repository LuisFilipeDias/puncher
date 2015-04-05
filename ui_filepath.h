/********************************************************************************
** Form generated from reading UI file 'filepath.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPATH_H
#define UI_FILEPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilePath
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *filepath_textedit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *filepath_ok;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *filepath_cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *FilePath)
    {
        if (FilePath->objectName().isEmpty())
            FilePath->setObjectName(QStringLiteral("FilePath"));
        FilePath->resize(487, 168);
        layoutWidget = new QWidget(FilePath);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 461, 153));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        filepath_textedit = new QTextEdit(layoutWidget);
        filepath_textedit->setObjectName(QStringLiteral("filepath_textedit"));
        filepath_textedit->setEnabled(true);

        verticalLayout->addWidget(filepath_textedit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        filepath_ok = new QPushButton(layoutWidget);
        filepath_ok->setObjectName(QStringLiteral("filepath_ok"));

        horizontalLayout->addWidget(filepath_ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        filepath_cancel = new QPushButton(layoutWidget);
        filepath_cancel->setObjectName(QStringLiteral("filepath_cancel"));

        horizontalLayout->addWidget(filepath_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FilePath);

        QMetaObject::connectSlotsByName(FilePath);
    } // setupUi

    void retranslateUi(QDialog *FilePath)
    {
        FilePath->setWindowTitle(QApplication::translate("FilePath", "Dialog", 0));
        label->setText(QApplication::translate("FilePath", "Paste database location here (e.g. /home/user/db_name.db):", 0));
        filepath_ok->setText(QApplication::translate("FilePath", "OK", 0));
        filepath_cancel->setText(QApplication::translate("FilePath", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class FilePath: public Ui_FilePath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPATH_H
