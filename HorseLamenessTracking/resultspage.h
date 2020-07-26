#ifndef RESULTSPAGE_H
#define RESULTSPAGE_H

#include <QWidget>
#include <QtCharts>

namespace Ui {
class ResultsPage;
}

class ResultsPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsPage(QWidget *parent = nullptr);
    ~ResultsPage();

private slots:
    void btnClose_Clicked();
    void btnBack_Clicked();

private:
    Ui::ResultsPage *ui;
};

#endif // RESULTSPAGE_H
