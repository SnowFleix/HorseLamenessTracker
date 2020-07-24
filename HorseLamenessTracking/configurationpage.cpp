#include "configurationpage.h"
#include "ui_configurationpage.h"

ConfigurationPage::ConfigurationPage(QWidget *parent, bool isVideo) :
    QWidget(parent),
    ui(new Ui::ConfigurationPage)
{
    ui->setupUi(this);
    //connect(ui->btnStartNew, SIGNAL(released()), this, SLOT(btnStartNew_Clicked()));
    connect(ui->btnRed, SIGNAL(released()), this, SLOT(btnRed_Clicked()));
    connect(ui->btnBlue, SIGNAL(released()), this, SLOT(btnBlue_Clicked()));
    connect(ui->btnYellow, SIGNAL(released()), this, SLOT(btnYellow_Clicked()));
    connect(ui->btnGreen, SIGNAL(released()), this, SLOT(btnGreen_Clicked()));
    connect(ui->btnBlack, SIGNAL(released()), this, SLOT(btnBlack_Clicked()));
    connect(ui->btnWhite, SIGNAL(released()), this, SLOT(btnWhite_Clicked()));
    connect(ui->btnStartNew, SIGNAL(released()), this, SLOT(btnStartNew_Clicked()));
}

ConfigurationPage::~ConfigurationPage()
{
    delete ui;
}

// TODO : Check if all these are accurate

void ConfigurationPage::btnRed_Click() {
    ChangeHSVValues(0,5,75,125,75,125);
}

void ConfigurationPage::btnBlue_Click() {
    ChangeHSVValues(225,255,75,125,75,125);
}

void ConfigurationPage::btnYellow_Click() {
    ChangeHSVValues(50,70,75,125,75,125);
}

void ConfigurationPage::btnGreen_Click() {
    ChangeHSVValues(100,135,75,125,75,125);
}

void ConfigurationPage::btnBlack_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnWhite_Click() {
    ChangeHSVValues(0,0,0,0,100,100);
}

void ConfigurationPage::h_max_Changed(int hue) {
    H_MAX = hue;
}

void ConfigurationPage::h_min_Changed(int hue) {
    H_MIN = hue;
}

void ConfigurationPage::s_max_Changed(int saturation) {
    S_MAX = saturation;
}

void ConfigurationPage::s_min_Changed(int saturation) {
    S_MIN = saturation;
}

void ConfigurationPage::v_max_Changed(int value) {
    V_MAX = value;
}

void ConfigurationPage::v_min_Changed(int value) {
    V_MIN = value;
}
