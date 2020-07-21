#ifndef CONFIGURATIONPAGE_H
#define CONFIGURATIONPAGE_H

#include <QWidget>
#include "Definitions.h"

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
    void h_max_Changed();
    void h_min_Changed();
    void s_max_Changed();
    void s_min_Changed();
    void v_max_Changed();
    void v_min_Changed();
private:
    Ui::ConfigurationPage *ui;
};

#endif // CONFIGURATIONPAGE_H
