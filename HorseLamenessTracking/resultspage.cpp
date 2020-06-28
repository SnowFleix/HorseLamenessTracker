#include "resultspage.h"
#include "ui_resultspage.h"

ResultsPage::ResultsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsPage)
{
    ui->setupUi(this);
}

ResultsPage::~ResultsPage()
{
    delete ui;
}
