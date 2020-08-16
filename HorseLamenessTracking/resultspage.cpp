#include "resultspage.h"
#include "ui_resultspage.h"

/////////////////////////////////////////////////////////////
/// \brief ResultsPage::ResultsPage
/// Default constructor, connects all the ui elements to
/// functions in the class
///
/// \param parent
/// The parent widget that called this constructor
///
ResultsPage::ResultsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultsPage)
{
    ui->setupUi(this);

    connect(ui->btnBack, SIGNAL(released()), this, SLOT(btnBack_Clicked()));
    connect(ui->btnClose, SIGNAL(released()), this, SLOT(btnClose_Clicked()));
}

/////////////////////////////////////////////////////////////
/// \brief ResultsPage::~ResultsPage
/// Default destructor, deletes UI before closing
///
ResultsPage::~ResultsPage()
{
    delete ui;
}

/////////////////////////////////////////////////////////////
/// \brief ResultsPage::btnBack_Clicked
/// Handles the user trying to go back
///
void ResultsPage::btnBack_Clicked() {
    this->close();
}

/////////////////////////////////////////////////////////////
/// \brief ResultsPage::btnClose_Clicked
/// Handles the user closing the game
///
void ResultsPage::btnClose_Clicked() {
    this->close();
}
