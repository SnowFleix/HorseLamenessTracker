#ifndef CONFIGURATIONPAGE_H
#define CONFIGURATIONPAGE_H

#include <QWidget>
#include "definitions.h"

namespace Ui {
class ConfigurationPage;
}

class ConfigurationPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigurationPage(QWidget *parent = nullptr, bool isVideo = false);
    ~ConfigurationPage();
private slots:
    void btnRed_Click();
    void btnBlue_Click();
    void btnYellow_Click();
    void btnGreen_Click();
    void btnBlack_Click();
    void btnWhite_Click();

    void btnFinish_Click();
    void btnPause_Click();

    void h_max_Changed(int);
    void h_min_Changed(int);
    void s_max_Changed(int);
    void s_min_Changed(int);
    void v_max_Changed(int);
    void v_min_Changed(int);
private:
    Ui::ConfigurationPage *ui;

    bool _isVideo;
};

#endif // CONFIGURATIONPAGE_H
