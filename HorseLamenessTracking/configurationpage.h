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
    explicit ConfigurationPage(QWidget *parent = nullptr);
    ~ConfigurationPage();

private:
    Ui::ConfigurationPage *ui;
};

#endif // CONFIGURATIONPAGE_H
