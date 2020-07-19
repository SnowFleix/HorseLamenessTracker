#ifndef CONFIGURATIONPAGE_H
#define CONFIGURATIONPAGE_H

#include <QWidget>

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
private:
    Ui::ConfigurationPage *ui;
};

#endif // CONFIGURATIONPAGE_H
