#include "configurationpage.h"
#include "ui_configurationpage.h"

ConfigurationPage::ConfigurationPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigurationPage)
{
    ui->setupUi(this);
}

ConfigurationPage::~ConfigurationPage()
{
    delete ui;
}

void ConfigurationPage::btnRed_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnBlue_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnYellow_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnGreen_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnBlack_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}

void ConfigurationPage::btnWhite_Click() {
    ChangeHSVValues(0,0,0,0,0,0);
}
