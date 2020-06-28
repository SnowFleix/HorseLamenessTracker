#include "trackingpage.h"
#include "ui_trackingpage.h"

TrackingPage::TrackingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrackingPage)
{
    ui->setupUi(this);
}

TrackingPage::~TrackingPage()
{
    delete ui;
}
