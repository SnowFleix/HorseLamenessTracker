#include "trackingpage.h"
#include "ui_trackingpage.h"

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::TrackingPage
/// Default constructor, connects all the ui elements to
/// functions in the class
///
/// \param parent
/// The parent widget that called this constructor
///
TrackingPage::TrackingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrackingPage)
{
    connect(ui->btnStart, SIGNAL(released()), this, SLOT(btnStart_Clicked()));
    connect(ui->btnCalibrate, SIGNAL(released()), this, SLOT(btnCalibrate_Clicked()));
    connect(ui->btnStop, SIGNAL(released()), this, SLOT(btnStop_Clicked()));
    connect(ui->btnBack, SIGNAL(released()), this, SLOT(btnBack_Clicked()));

    ui->setupUi(this);
}

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::~TrackingPage
/// Default destructor, just deletes the UI once the destructor
/// is called
///
TrackingPage::~TrackingPage()
{
    delete ui;
}

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::btnStart_Clicked
/// Handles the user clicking the start button
///
void TrackingPage::btnStart_Clicked() {

}

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::btnStop_Clicked
/// Handles the user clicking the stop button
///
void TrackingPage::btnStop_Clicked() {
    this->close();
}

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::btnCalibrate_Clicked
/// Handles the user clicking the calibrate button
///
void TrackingPage::btnCalibrate_Clicked() {

}

/////////////////////////////////////////////////////////////
/// \brief TrackingPage::btnBack_Clicked
/// Handles the user clicking the back button
///
void TrackingPage::btnBack_Clicked() {
    delete ui;
}
