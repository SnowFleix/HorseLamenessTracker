#ifndef TRACKINGPAGE_H
#define TRACKINGPAGE_H

#include <QWidget>

namespace Ui {
class TrackingPage;
}

class TrackingPage : public QWidget
{
    Q_OBJECT

public:
    explicit TrackingPage(QWidget *parent = nullptr);
    ~TrackingPage();

private:
    Ui::TrackingPage *ui;
};

#endif // TRACKINGPAGE_H
