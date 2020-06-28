#ifndef RESULTSPAGE_H
#define RESULTSPAGE_H

#include <QWidget>

namespace Ui {
class ResultsPage;
}

class ResultsPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsPage(QWidget *parent = nullptr);
    ~ResultsPage();

private:
    Ui::ResultsPage *ui;
};

#endif // RESULTSPAGE_H
