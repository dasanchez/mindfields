/********************************************************************************
** Form generated from reading UI file 'mindfieldsclient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINDFIELDSCLIENT_H
#define UI_MINDFIELDSCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MindfieldsClient
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *messageBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *typeEdit;
    QLabel *label_2;
    QLineEdit *keyEdit;
    QLabel *label_4;
    QLineEdit *valueEdit;
    QLabel *label;
    QSpinBox *portBox;
    QPushButton *sendDataButton;
    QPushButton *connectButton;
    QPushButton *playerButton;
    QPushButton *teamButton;
    QPushButton *roleButton;
    QPushButton *disconnectButton;

    void setupUi(QWidget *MindfieldsClient)
    {
        if (MindfieldsClient->objectName().isEmpty())
            MindfieldsClient->setObjectName(QStringLiteral("MindfieldsClient"));
        MindfieldsClient->resize(400, 300);
        verticalLayout = new QVBoxLayout(MindfieldsClient);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        messageBox = new QPlainTextEdit(MindfieldsClient);
        messageBox->setObjectName(QStringLiteral("messageBox"));
        messageBox->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(messageBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(MindfieldsClient);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        typeEdit = new QLineEdit(MindfieldsClient);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));

        horizontalLayout->addWidget(typeEdit);

        label_2 = new QLabel(MindfieldsClient);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        keyEdit = new QLineEdit(MindfieldsClient);
        keyEdit->setObjectName(QStringLiteral("keyEdit"));

        horizontalLayout->addWidget(keyEdit);

        label_4 = new QLabel(MindfieldsClient);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        valueEdit = new QLineEdit(MindfieldsClient);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));

        horizontalLayout->addWidget(valueEdit);

        label = new QLabel(MindfieldsClient);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        portBox = new QSpinBox(MindfieldsClient);
        portBox->setObjectName(QStringLiteral("portBox"));
        portBox->setMaximum(99999);
        portBox->setValue(8888);

        horizontalLayout->addWidget(portBox);


        verticalLayout->addLayout(horizontalLayout);

        sendDataButton = new QPushButton(MindfieldsClient);
        sendDataButton->setObjectName(QStringLiteral("sendDataButton"));

        verticalLayout->addWidget(sendDataButton);

        connectButton = new QPushButton(MindfieldsClient);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        verticalLayout->addWidget(connectButton);

        playerButton = new QPushButton(MindfieldsClient);
        playerButton->setObjectName(QStringLiteral("playerButton"));

        verticalLayout->addWidget(playerButton);

        teamButton = new QPushButton(MindfieldsClient);
        teamButton->setObjectName(QStringLiteral("teamButton"));

        verticalLayout->addWidget(teamButton);

        roleButton = new QPushButton(MindfieldsClient);
        roleButton->setObjectName(QStringLiteral("roleButton"));

        verticalLayout->addWidget(roleButton);

        disconnectButton = new QPushButton(MindfieldsClient);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        verticalLayout->addWidget(disconnectButton);


        retranslateUi(MindfieldsClient);

        QMetaObject::connectSlotsByName(MindfieldsClient);
    } // setupUi

    void retranslateUi(QWidget *MindfieldsClient)
    {
        MindfieldsClient->setWindowTitle(QApplication::translate("MindfieldsClient", "MindfieldsClient", Q_NULLPTR));
        label_3->setText(QApplication::translate("MindfieldsClient", "Type", Q_NULLPTR));
        typeEdit->setText(QApplication::translate("MindfieldsClient", "newplayerrequest", Q_NULLPTR));
        label_2->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        keyEdit->setText(QApplication::translate("MindfieldsClient", "name", Q_NULLPTR));
        label_4->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        valueEdit->setText(QApplication::translate("MindfieldsClient", "psych_", Q_NULLPTR));
        label->setText(QApplication::translate("MindfieldsClient", "Port", Q_NULLPTR));
        sendDataButton->setText(QApplication::translate("MindfieldsClient", "Send Data", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MindfieldsClient", "Connect", Q_NULLPTR));
        playerButton->setText(QApplication::translate("MindfieldsClient", "New Player Request", Q_NULLPTR));
        teamButton->setText(QApplication::translate("MindfieldsClient", "Team Request", Q_NULLPTR));
        roleButton->setText(QApplication::translate("MindfieldsClient", "Role Request", Q_NULLPTR));
        disconnectButton->setText(QApplication::translate("MindfieldsClient", "Disconnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MindfieldsClient: public Ui_MindfieldsClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINDFIELDSCLIENT_H
