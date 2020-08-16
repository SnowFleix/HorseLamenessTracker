#ifndef CONFIGURATIONPAGE_H
#define CONFIGURATIONPAGE_H

#include <QThread>
#include <QWidget>
#include <QCloseEvent>

#include "utilfunctions.h"
#include "graphicsworker.h"

namespace Ui {
class ConfigurationPage;
}

class ConfigurationPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigurationPage(QWidget *parent = nullptr);
    ~ConfigurationPage();
    //Overrides the default show function
    void open(bool isVideo);
    void closeEvent(QCloseEvent *event);
    // make a call operator so I can recall the object to set
    // the parent widget later
    void operator()(QWidget* parent);
private slots:
    // Slots for buttons
    void btnRed_Click();
    void btnBlue_Click();
    void btnYellow_Click();
    void btnGreen_Click();
    void btnBlack_Click();
    void btnWhite_Click();
    void btnFinish_Click();
    void btnPause_Click();
    // Slots for horizontal bars
    void h_max_Changed(int);
    void h_min_Changed(int);
    void s_max_Changed(int);
    void s_min_Changed(int);
    void v_max_Changed(int);
    void v_min_Changed(int);
private:
    Ui::ConfigurationPage *ui;
    // set to nullptr so we can check later
    QWidget* _parent = nullptr;
    QThread* thread = new QThread;
    bool _isVideo;
};

#endif // CONFIGURATIONPAGE_H
