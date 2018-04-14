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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MindfieldsClient
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QPlainTextEdit *p1MessageBox;
    QGridLayout *gridLayout_3;
    QPushButton *p1ConnectButton;
    QLabel *label;
    QPushButton *p1DisconnectButton;
    QSpinBox *p1PortBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *p1TypeEdit;
    QPushButton *p1SendButton;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *p1Key1Edit;
    QLabel *label_5;
    QLineEdit *p1Key2Edit;
    QLabel *label_4;
    QLineEdit *p1Value1Edit;
    QLabel *label_6;
    QLineEdit *p1Value2Edit;
    QGridLayout *gridLayout;
    QLineEdit *p1NameEdit;
    QPushButton *p1PlayerButton;
    QPushButton *p1BlueButton;
    QPushButton *p1OrangeButton;
    QPushButton *p1LeaderButton;
    QPushButton *p1MemberButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_14;
    QPlainTextEdit *p2MessageBox;
    QGridLayout *gridLayout_4;
    QPushButton *p2DisconnectButton;
    QSpinBox *p2PortBox;
    QLabel *label_7;
    QPushButton *p2ConnectButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QLineEdit *p2TypeEdit;
    QPushButton *p2SendButton;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLineEdit *p2Key1Edit;
    QLabel *label_10;
    QLineEdit *p2Key2Edit;
    QLabel *label_11;
    QLineEdit *p2Value1Edit;
    QLabel *label_12;
    QLineEdit *p2Value2Edit;
    QGridLayout *gridLayout_6;
    QLineEdit *p2NameEdit;
    QPushButton *p2PlayerButton;
    QPushButton *p2BlueButton;
    QPushButton *p2OrangeButton;
    QPushButton *p2LeaderButton;
    QPushButton *p2MemberButton;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_15;
    QPlainTextEdit *p3MessageBox;
    QGridLayout *gridLayout_7;
    QPushButton *p3DisconnectButton;
    QSpinBox *p3PortBox;
    QLabel *label_16;
    QPushButton *p3ConnectButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QLineEdit *p3TypeEdit;
    QPushButton *p3SendButton;
    QGridLayout *gridLayout_8;
    QLabel *label_18;
    QLineEdit *p3Key1Edit;
    QLabel *label_19;
    QLineEdit *p3Key2Edit;
    QLabel *label_20;
    QLineEdit *p3Value1Edit;
    QLabel *label_21;
    QLineEdit *p3Value2Edit;
    QGridLayout *gridLayout_9;
    QLineEdit *p3NameEdit;
    QPushButton *p3PlayerButton;
    QPushButton *p3BlueButton;
    QPushButton *p3OrangeButton;
    QPushButton *p3LeaderButton;
    QPushButton *p3MemberButton;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_22;
    QPlainTextEdit *p4MessageBox;
    QGridLayout *gridLayout_10;
    QPushButton *p4DisconnectButton;
    QSpinBox *p4PortBox;
    QLabel *label_23;
    QPushButton *p4ConnectButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_24;
    QLineEdit *p4TypeEdit;
    QPushButton *p4SendButton;
    QGridLayout *gridLayout_11;
    QLabel *label_25;
    QLineEdit *p4Key1Edit;
    QLabel *label_26;
    QLineEdit *p4Key2Edit;
    QLabel *label_27;
    QLineEdit *p4Value1Edit;
    QLabel *label_28;
    QLineEdit *p4Value2Edit;
    QGridLayout *gridLayout_12;
    QLineEdit *p4NameEdit;
    QPushButton *p4PlayerButton;
    QPushButton *p4BlueButton;
    QPushButton *p4OrangeButton;
    QPushButton *p4LeaderButton;
    QPushButton *p4MemberButton;

    void setupUi(QWidget *MindfieldsClient)
    {
        if (MindfieldsClient->objectName().isEmpty())
            MindfieldsClient->setObjectName(QStringLiteral("MindfieldsClient"));
        MindfieldsClient->resize(1136, 423);
        horizontalLayout_5 = new QHBoxLayout(MindfieldsClient);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_13 = new QLabel(MindfieldsClient);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setTextFormat(Qt::AutoText);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);

        p1MessageBox = new QPlainTextEdit(MindfieldsClient);
        p1MessageBox->setObjectName(QStringLiteral("p1MessageBox"));
        p1MessageBox->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(p1MessageBox);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        p1ConnectButton = new QPushButton(MindfieldsClient);
        p1ConnectButton->setObjectName(QStringLiteral("p1ConnectButton"));

        gridLayout_3->addWidget(p1ConnectButton, 0, 0, 1, 1);

        label = new QLabel(MindfieldsClient);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        p1DisconnectButton = new QPushButton(MindfieldsClient);
        p1DisconnectButton->setObjectName(QStringLiteral("p1DisconnectButton"));

        gridLayout_3->addWidget(p1DisconnectButton, 1, 0, 1, 1);

        p1PortBox = new QSpinBox(MindfieldsClient);
        p1PortBox->setObjectName(QStringLiteral("p1PortBox"));
        p1PortBox->setMaximum(99999);
        p1PortBox->setValue(8888);

        gridLayout_3->addWidget(p1PortBox, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(MindfieldsClient);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        p1TypeEdit = new QLineEdit(MindfieldsClient);
        p1TypeEdit->setObjectName(QStringLiteral("p1TypeEdit"));

        horizontalLayout->addWidget(p1TypeEdit);

        p1SendButton = new QPushButton(MindfieldsClient);
        p1SendButton->setObjectName(QStringLiteral("p1SendButton"));

        horizontalLayout->addWidget(p1SendButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(MindfieldsClient);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        p1Key1Edit = new QLineEdit(MindfieldsClient);
        p1Key1Edit->setObjectName(QStringLiteral("p1Key1Edit"));

        gridLayout_2->addWidget(p1Key1Edit, 0, 1, 1, 1);

        label_5 = new QLabel(MindfieldsClient);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        p1Key2Edit = new QLineEdit(MindfieldsClient);
        p1Key2Edit->setObjectName(QStringLiteral("p1Key2Edit"));

        gridLayout_2->addWidget(p1Key2Edit, 0, 3, 1, 1);

        label_4 = new QLabel(MindfieldsClient);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        p1Value1Edit = new QLineEdit(MindfieldsClient);
        p1Value1Edit->setObjectName(QStringLiteral("p1Value1Edit"));

        gridLayout_2->addWidget(p1Value1Edit, 1, 1, 1, 1);

        label_6 = new QLabel(MindfieldsClient);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 2, 1, 1);

        p1Value2Edit = new QLineEdit(MindfieldsClient);
        p1Value2Edit->setObjectName(QStringLiteral("p1Value2Edit"));

        gridLayout_2->addWidget(p1Value2Edit, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        p1NameEdit = new QLineEdit(MindfieldsClient);
        p1NameEdit->setObjectName(QStringLiteral("p1NameEdit"));

        gridLayout->addWidget(p1NameEdit, 0, 0, 1, 1);

        p1PlayerButton = new QPushButton(MindfieldsClient);
        p1PlayerButton->setObjectName(QStringLiteral("p1PlayerButton"));

        gridLayout->addWidget(p1PlayerButton, 0, 1, 1, 1);

        p1BlueButton = new QPushButton(MindfieldsClient);
        p1BlueButton->setObjectName(QStringLiteral("p1BlueButton"));

        gridLayout->addWidget(p1BlueButton, 1, 0, 1, 1);

        p1OrangeButton = new QPushButton(MindfieldsClient);
        p1OrangeButton->setObjectName(QStringLiteral("p1OrangeButton"));

        gridLayout->addWidget(p1OrangeButton, 1, 1, 1, 1);

        p1LeaderButton = new QPushButton(MindfieldsClient);
        p1LeaderButton->setObjectName(QStringLiteral("p1LeaderButton"));

        gridLayout->addWidget(p1LeaderButton, 2, 0, 1, 1);

        p1MemberButton = new QPushButton(MindfieldsClient);
        p1MemberButton->setObjectName(QStringLiteral("p1MemberButton"));

        gridLayout->addWidget(p1MemberButton, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_5->addLayout(verticalLayout);

        line = new QFrame(MindfieldsClient);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_14 = new QLabel(MindfieldsClient);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_14);

        p2MessageBox = new QPlainTextEdit(MindfieldsClient);
        p2MessageBox->setObjectName(QStringLiteral("p2MessageBox"));
        p2MessageBox->setFrameShadow(QFrame::Plain);

        verticalLayout_2->addWidget(p2MessageBox);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        p2DisconnectButton = new QPushButton(MindfieldsClient);
        p2DisconnectButton->setObjectName(QStringLiteral("p2DisconnectButton"));

        gridLayout_4->addWidget(p2DisconnectButton, 1, 0, 1, 1);

        p2PortBox = new QSpinBox(MindfieldsClient);
        p2PortBox->setObjectName(QStringLiteral("p2PortBox"));
        p2PortBox->setMaximum(99999);
        p2PortBox->setValue(8888);

        gridLayout_4->addWidget(p2PortBox, 1, 1, 1, 1);

        label_7 = new QLabel(MindfieldsClient);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 1, 1, 1);

        p2ConnectButton = new QPushButton(MindfieldsClient);
        p2ConnectButton->setObjectName(QStringLiteral("p2ConnectButton"));

        gridLayout_4->addWidget(p2ConnectButton, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(MindfieldsClient);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        p2TypeEdit = new QLineEdit(MindfieldsClient);
        p2TypeEdit->setObjectName(QStringLiteral("p2TypeEdit"));

        horizontalLayout_2->addWidget(p2TypeEdit);

        p2SendButton = new QPushButton(MindfieldsClient);
        p2SendButton->setObjectName(QStringLiteral("p2SendButton"));

        horizontalLayout_2->addWidget(p2SendButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_9 = new QLabel(MindfieldsClient);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        p2Key1Edit = new QLineEdit(MindfieldsClient);
        p2Key1Edit->setObjectName(QStringLiteral("p2Key1Edit"));

        gridLayout_5->addWidget(p2Key1Edit, 0, 1, 1, 1);

        label_10 = new QLabel(MindfieldsClient);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 0, 2, 1, 1);

        p2Key2Edit = new QLineEdit(MindfieldsClient);
        p2Key2Edit->setObjectName(QStringLiteral("p2Key2Edit"));

        gridLayout_5->addWidget(p2Key2Edit, 0, 3, 1, 1);

        label_11 = new QLabel(MindfieldsClient);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 1, 0, 1, 1);

        p2Value1Edit = new QLineEdit(MindfieldsClient);
        p2Value1Edit->setObjectName(QStringLiteral("p2Value1Edit"));

        gridLayout_5->addWidget(p2Value1Edit, 1, 1, 1, 1);

        label_12 = new QLabel(MindfieldsClient);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 1, 2, 1, 1);

        p2Value2Edit = new QLineEdit(MindfieldsClient);
        p2Value2Edit->setObjectName(QStringLiteral("p2Value2Edit"));

        gridLayout_5->addWidget(p2Value2Edit, 1, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        p2NameEdit = new QLineEdit(MindfieldsClient);
        p2NameEdit->setObjectName(QStringLiteral("p2NameEdit"));

        gridLayout_6->addWidget(p2NameEdit, 0, 0, 1, 1);

        p2PlayerButton = new QPushButton(MindfieldsClient);
        p2PlayerButton->setObjectName(QStringLiteral("p2PlayerButton"));

        gridLayout_6->addWidget(p2PlayerButton, 0, 1, 1, 1);

        p2BlueButton = new QPushButton(MindfieldsClient);
        p2BlueButton->setObjectName(QStringLiteral("p2BlueButton"));

        gridLayout_6->addWidget(p2BlueButton, 1, 0, 1, 1);

        p2OrangeButton = new QPushButton(MindfieldsClient);
        p2OrangeButton->setObjectName(QStringLiteral("p2OrangeButton"));

        gridLayout_6->addWidget(p2OrangeButton, 1, 1, 1, 1);

        p2LeaderButton = new QPushButton(MindfieldsClient);
        p2LeaderButton->setObjectName(QStringLiteral("p2LeaderButton"));

        gridLayout_6->addWidget(p2LeaderButton, 2, 0, 1, 1);

        p2MemberButton = new QPushButton(MindfieldsClient);
        p2MemberButton->setObjectName(QStringLiteral("p2MemberButton"));

        gridLayout_6->addWidget(p2MemberButton, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_6);


        horizontalLayout_5->addLayout(verticalLayout_2);

        line_2 = new QFrame(MindfieldsClient);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_15 = new QLabel(MindfieldsClient);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_15);

        p3MessageBox = new QPlainTextEdit(MindfieldsClient);
        p3MessageBox->setObjectName(QStringLiteral("p3MessageBox"));
        p3MessageBox->setFrameShadow(QFrame::Plain);

        verticalLayout_3->addWidget(p3MessageBox);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        p3DisconnectButton = new QPushButton(MindfieldsClient);
        p3DisconnectButton->setObjectName(QStringLiteral("p3DisconnectButton"));

        gridLayout_7->addWidget(p3DisconnectButton, 1, 0, 1, 1);

        p3PortBox = new QSpinBox(MindfieldsClient);
        p3PortBox->setObjectName(QStringLiteral("p3PortBox"));
        p3PortBox->setMaximum(99999);
        p3PortBox->setValue(8888);

        gridLayout_7->addWidget(p3PortBox, 1, 1, 1, 1);

        label_16 = new QLabel(MindfieldsClient);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_7->addWidget(label_16, 0, 1, 1, 1);

        p3ConnectButton = new QPushButton(MindfieldsClient);
        p3ConnectButton->setObjectName(QStringLiteral("p3ConnectButton"));

        gridLayout_7->addWidget(p3ConnectButton, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_17 = new QLabel(MindfieldsClient);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_3->addWidget(label_17);

        p3TypeEdit = new QLineEdit(MindfieldsClient);
        p3TypeEdit->setObjectName(QStringLiteral("p3TypeEdit"));

        horizontalLayout_3->addWidget(p3TypeEdit);

        p3SendButton = new QPushButton(MindfieldsClient);
        p3SendButton->setObjectName(QStringLiteral("p3SendButton"));

        horizontalLayout_3->addWidget(p3SendButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_18 = new QLabel(MindfieldsClient);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_8->addWidget(label_18, 0, 0, 1, 1);

        p3Key1Edit = new QLineEdit(MindfieldsClient);
        p3Key1Edit->setObjectName(QStringLiteral("p3Key1Edit"));

        gridLayout_8->addWidget(p3Key1Edit, 0, 1, 1, 1);

        label_19 = new QLabel(MindfieldsClient);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_8->addWidget(label_19, 0, 2, 1, 1);

        p3Key2Edit = new QLineEdit(MindfieldsClient);
        p3Key2Edit->setObjectName(QStringLiteral("p3Key2Edit"));

        gridLayout_8->addWidget(p3Key2Edit, 0, 3, 1, 1);

        label_20 = new QLabel(MindfieldsClient);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_8->addWidget(label_20, 1, 0, 1, 1);

        p3Value1Edit = new QLineEdit(MindfieldsClient);
        p3Value1Edit->setObjectName(QStringLiteral("p3Value1Edit"));

        gridLayout_8->addWidget(p3Value1Edit, 1, 1, 1, 1);

        label_21 = new QLabel(MindfieldsClient);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_8->addWidget(label_21, 1, 2, 1, 1);

        p3Value2Edit = new QLineEdit(MindfieldsClient);
        p3Value2Edit->setObjectName(QStringLiteral("p3Value2Edit"));

        gridLayout_8->addWidget(p3Value2Edit, 1, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_8);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        p3NameEdit = new QLineEdit(MindfieldsClient);
        p3NameEdit->setObjectName(QStringLiteral("p3NameEdit"));

        gridLayout_9->addWidget(p3NameEdit, 0, 0, 1, 1);

        p3PlayerButton = new QPushButton(MindfieldsClient);
        p3PlayerButton->setObjectName(QStringLiteral("p3PlayerButton"));

        gridLayout_9->addWidget(p3PlayerButton, 0, 1, 1, 1);

        p3BlueButton = new QPushButton(MindfieldsClient);
        p3BlueButton->setObjectName(QStringLiteral("p3BlueButton"));

        gridLayout_9->addWidget(p3BlueButton, 1, 0, 1, 1);

        p3OrangeButton = new QPushButton(MindfieldsClient);
        p3OrangeButton->setObjectName(QStringLiteral("p3OrangeButton"));

        gridLayout_9->addWidget(p3OrangeButton, 1, 1, 1, 1);

        p3LeaderButton = new QPushButton(MindfieldsClient);
        p3LeaderButton->setObjectName(QStringLiteral("p3LeaderButton"));

        gridLayout_9->addWidget(p3LeaderButton, 2, 0, 1, 1);

        p3MemberButton = new QPushButton(MindfieldsClient);
        p3MemberButton->setObjectName(QStringLiteral("p3MemberButton"));

        gridLayout_9->addWidget(p3MemberButton, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_3);

        line_3 = new QFrame(MindfieldsClient);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_22 = new QLabel(MindfieldsClient);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_22);

        p4MessageBox = new QPlainTextEdit(MindfieldsClient);
        p4MessageBox->setObjectName(QStringLiteral("p4MessageBox"));
        p4MessageBox->setFrameShadow(QFrame::Plain);

        verticalLayout_4->addWidget(p4MessageBox);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        p4DisconnectButton = new QPushButton(MindfieldsClient);
        p4DisconnectButton->setObjectName(QStringLiteral("p4DisconnectButton"));

        gridLayout_10->addWidget(p4DisconnectButton, 1, 0, 1, 1);

        p4PortBox = new QSpinBox(MindfieldsClient);
        p4PortBox->setObjectName(QStringLiteral("p4PortBox"));
        p4PortBox->setMaximum(99999);
        p4PortBox->setValue(8888);

        gridLayout_10->addWidget(p4PortBox, 1, 1, 1, 1);

        label_23 = new QLabel(MindfieldsClient);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_10->addWidget(label_23, 0, 1, 1, 1);

        p4ConnectButton = new QPushButton(MindfieldsClient);
        p4ConnectButton->setObjectName(QStringLiteral("p4ConnectButton"));

        gridLayout_10->addWidget(p4ConnectButton, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_24 = new QLabel(MindfieldsClient);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_4->addWidget(label_24);

        p4TypeEdit = new QLineEdit(MindfieldsClient);
        p4TypeEdit->setObjectName(QStringLiteral("p4TypeEdit"));

        horizontalLayout_4->addWidget(p4TypeEdit);

        p4SendButton = new QPushButton(MindfieldsClient);
        p4SendButton->setObjectName(QStringLiteral("p4SendButton"));

        horizontalLayout_4->addWidget(p4SendButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_25 = new QLabel(MindfieldsClient);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_11->addWidget(label_25, 0, 0, 1, 1);

        p4Key1Edit = new QLineEdit(MindfieldsClient);
        p4Key1Edit->setObjectName(QStringLiteral("p4Key1Edit"));

        gridLayout_11->addWidget(p4Key1Edit, 0, 1, 1, 1);

        label_26 = new QLabel(MindfieldsClient);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_11->addWidget(label_26, 0, 2, 1, 1);

        p4Key2Edit = new QLineEdit(MindfieldsClient);
        p4Key2Edit->setObjectName(QStringLiteral("p4Key2Edit"));

        gridLayout_11->addWidget(p4Key2Edit, 0, 3, 1, 1);

        label_27 = new QLabel(MindfieldsClient);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_11->addWidget(label_27, 1, 0, 1, 1);

        p4Value1Edit = new QLineEdit(MindfieldsClient);
        p4Value1Edit->setObjectName(QStringLiteral("p4Value1Edit"));

        gridLayout_11->addWidget(p4Value1Edit, 1, 1, 1, 1);

        label_28 = new QLabel(MindfieldsClient);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_11->addWidget(label_28, 1, 2, 1, 1);

        p4Value2Edit = new QLineEdit(MindfieldsClient);
        p4Value2Edit->setObjectName(QStringLiteral("p4Value2Edit"));

        gridLayout_11->addWidget(p4Value2Edit, 1, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout_11);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        p4NameEdit = new QLineEdit(MindfieldsClient);
        p4NameEdit->setObjectName(QStringLiteral("p4NameEdit"));

        gridLayout_12->addWidget(p4NameEdit, 0, 0, 1, 1);

        p4PlayerButton = new QPushButton(MindfieldsClient);
        p4PlayerButton->setObjectName(QStringLiteral("p4PlayerButton"));

        gridLayout_12->addWidget(p4PlayerButton, 0, 1, 1, 1);

        p4BlueButton = new QPushButton(MindfieldsClient);
        p4BlueButton->setObjectName(QStringLiteral("p4BlueButton"));

        gridLayout_12->addWidget(p4BlueButton, 1, 0, 1, 1);

        p4OrangeButton = new QPushButton(MindfieldsClient);
        p4OrangeButton->setObjectName(QStringLiteral("p4OrangeButton"));

        gridLayout_12->addWidget(p4OrangeButton, 1, 1, 1, 1);

        p4LeaderButton = new QPushButton(MindfieldsClient);
        p4LeaderButton->setObjectName(QStringLiteral("p4LeaderButton"));

        gridLayout_12->addWidget(p4LeaderButton, 2, 0, 1, 1);

        p4MemberButton = new QPushButton(MindfieldsClient);
        p4MemberButton->setObjectName(QStringLiteral("p4MemberButton"));

        gridLayout_12->addWidget(p4MemberButton, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_12);


        horizontalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(MindfieldsClient);

        QMetaObject::connectSlotsByName(MindfieldsClient);
    } // setupUi

    void retranslateUi(QWidget *MindfieldsClient)
    {
        MindfieldsClient->setWindowTitle(QApplication::translate("MindfieldsClient", "MindfieldsClient", Q_NULLPTR));
        label_13->setText(QApplication::translate("MindfieldsClient", "PLAYER 1", Q_NULLPTR));
        p1ConnectButton->setText(QApplication::translate("MindfieldsClient", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("MindfieldsClient", "Port", Q_NULLPTR));
        p1DisconnectButton->setText(QApplication::translate("MindfieldsClient", "Disconnect", Q_NULLPTR));
        label_3->setText(QApplication::translate("MindfieldsClient", "Type", Q_NULLPTR));
        p1TypeEdit->setText(QApplication::translate("MindfieldsClient", "newplayerrequest", Q_NULLPTR));
        p1SendButton->setText(QApplication::translate("MindfieldsClient", "Send Data", Q_NULLPTR));
        label_2->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p1Key1Edit->setText(QApplication::translate("MindfieldsClient", "hint", Q_NULLPTR));
        label_5->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p1Key2Edit->setText(QApplication::translate("MindfieldsClient", "count", Q_NULLPTR));
        label_4->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p1Value1Edit->setText(QApplication::translate("MindfieldsClient", "APPLE", Q_NULLPTR));
        label_6->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p1Value2Edit->setText(QApplication::translate("MindfieldsClient", "1", Q_NULLPTR));
        p1NameEdit->setText(QApplication::translate("MindfieldsClient", "albert", Q_NULLPTR));
        p1PlayerButton->setText(QApplication::translate("MindfieldsClient", "New Player Request", Q_NULLPTR));
        p1BlueButton->setText(QApplication::translate("MindfieldsClient", "Request Blue", Q_NULLPTR));
        p1OrangeButton->setText(QApplication::translate("MindfieldsClient", "Request Orange", Q_NULLPTR));
        p1LeaderButton->setText(QApplication::translate("MindfieldsClient", "Request Leader", Q_NULLPTR));
        p1MemberButton->setText(QApplication::translate("MindfieldsClient", "Request Member", Q_NULLPTR));
        label_14->setText(QApplication::translate("MindfieldsClient", "PLAYER 2", Q_NULLPTR));
        p2DisconnectButton->setText(QApplication::translate("MindfieldsClient", "Disconnect", Q_NULLPTR));
        label_7->setText(QApplication::translate("MindfieldsClient", "Port", Q_NULLPTR));
        p2ConnectButton->setText(QApplication::translate("MindfieldsClient", "Connect", Q_NULLPTR));
        label_8->setText(QApplication::translate("MindfieldsClient", "Type", Q_NULLPTR));
        p2TypeEdit->setText(QApplication::translate("MindfieldsClient", "newplayerrequest", Q_NULLPTR));
        p2SendButton->setText(QApplication::translate("MindfieldsClient", "Send Data", Q_NULLPTR));
        label_9->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p2Key1Edit->setText(QApplication::translate("MindfieldsClient", "hint", Q_NULLPTR));
        label_10->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p2Key2Edit->setText(QApplication::translate("MindfieldsClient", "count", Q_NULLPTR));
        label_11->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p2Value1Edit->setText(QApplication::translate("MindfieldsClient", "APPLE", Q_NULLPTR));
        label_12->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p2Value2Edit->setText(QApplication::translate("MindfieldsClient", "1", Q_NULLPTR));
        p2NameEdit->setText(QApplication::translate("MindfieldsClient", "brianna", Q_NULLPTR));
        p2PlayerButton->setText(QApplication::translate("MindfieldsClient", "New Player Request", Q_NULLPTR));
        p2BlueButton->setText(QApplication::translate("MindfieldsClient", "Request Blue", Q_NULLPTR));
        p2OrangeButton->setText(QApplication::translate("MindfieldsClient", "Request Orange", Q_NULLPTR));
        p2LeaderButton->setText(QApplication::translate("MindfieldsClient", "Request Leader", Q_NULLPTR));
        p2MemberButton->setText(QApplication::translate("MindfieldsClient", "Request Member", Q_NULLPTR));
        label_15->setText(QApplication::translate("MindfieldsClient", "PLAYER 3", Q_NULLPTR));
        p3DisconnectButton->setText(QApplication::translate("MindfieldsClient", "Disconnect", Q_NULLPTR));
        label_16->setText(QApplication::translate("MindfieldsClient", "Port", Q_NULLPTR));
        p3ConnectButton->setText(QApplication::translate("MindfieldsClient", "Connect", Q_NULLPTR));
        label_17->setText(QApplication::translate("MindfieldsClient", "Type", Q_NULLPTR));
        p3TypeEdit->setText(QApplication::translate("MindfieldsClient", "newplayerrequest", Q_NULLPTR));
        p3SendButton->setText(QApplication::translate("MindfieldsClient", "Send Data", Q_NULLPTR));
        label_18->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p3Key1Edit->setText(QApplication::translate("MindfieldsClient", "hint", Q_NULLPTR));
        label_19->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p3Key2Edit->setText(QApplication::translate("MindfieldsClient", "count", Q_NULLPTR));
        label_20->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p3Value1Edit->setText(QApplication::translate("MindfieldsClient", "APPLE", Q_NULLPTR));
        label_21->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p3Value2Edit->setText(QApplication::translate("MindfieldsClient", "1", Q_NULLPTR));
        p3NameEdit->setText(QApplication::translate("MindfieldsClient", "chuck", Q_NULLPTR));
        p3PlayerButton->setText(QApplication::translate("MindfieldsClient", "New Player Request", Q_NULLPTR));
        p3BlueButton->setText(QApplication::translate("MindfieldsClient", "Request Blue", Q_NULLPTR));
        p3OrangeButton->setText(QApplication::translate("MindfieldsClient", "Request Orange", Q_NULLPTR));
        p3LeaderButton->setText(QApplication::translate("MindfieldsClient", "Request Leader", Q_NULLPTR));
        p3MemberButton->setText(QApplication::translate("MindfieldsClient", "Request Member", Q_NULLPTR));
        label_22->setText(QApplication::translate("MindfieldsClient", "PLAYER 4", Q_NULLPTR));
        p4DisconnectButton->setText(QApplication::translate("MindfieldsClient", "Disconnect", Q_NULLPTR));
        label_23->setText(QApplication::translate("MindfieldsClient", "Port", Q_NULLPTR));
        p4ConnectButton->setText(QApplication::translate("MindfieldsClient", "Connect", Q_NULLPTR));
        label_24->setText(QApplication::translate("MindfieldsClient", "Type", Q_NULLPTR));
        p4TypeEdit->setText(QApplication::translate("MindfieldsClient", "newplayerrequest", Q_NULLPTR));
        p4SendButton->setText(QApplication::translate("MindfieldsClient", "Send Data", Q_NULLPTR));
        label_25->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p4Key1Edit->setText(QApplication::translate("MindfieldsClient", "hint", Q_NULLPTR));
        label_26->setText(QApplication::translate("MindfieldsClient", "Key", Q_NULLPTR));
        p4Key2Edit->setText(QApplication::translate("MindfieldsClient", "count", Q_NULLPTR));
        label_27->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p4Value1Edit->setText(QApplication::translate("MindfieldsClient", "APPLE", Q_NULLPTR));
        label_28->setText(QApplication::translate("MindfieldsClient", "Value", Q_NULLPTR));
        p4Value2Edit->setText(QApplication::translate("MindfieldsClient", "1", Q_NULLPTR));
        p4NameEdit->setText(QApplication::translate("MindfieldsClient", "dani", Q_NULLPTR));
        p4PlayerButton->setText(QApplication::translate("MindfieldsClient", "New Player Request", Q_NULLPTR));
        p4BlueButton->setText(QApplication::translate("MindfieldsClient", "Request Blue", Q_NULLPTR));
        p4OrangeButton->setText(QApplication::translate("MindfieldsClient", "Request Orange", Q_NULLPTR));
        p4LeaderButton->setText(QApplication::translate("MindfieldsClient", "Request Leader", Q_NULLPTR));
        p4MemberButton->setText(QApplication::translate("MindfieldsClient", "Request Member", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MindfieldsClient: public Ui_MindfieldsClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINDFIELDSCLIENT_H
