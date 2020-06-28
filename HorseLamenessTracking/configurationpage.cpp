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
