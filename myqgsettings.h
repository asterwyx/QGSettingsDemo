#ifndef MYQGSETTINGS_H
#define MYQGSETTINGS_H

#include <QWidget>
#include <QString>
#include <QGSettings>

namespace Ui {
class MyQGSettings;
}

class MyQGSettings : public QWidget
{
    Q_OBJECT
public:
    explicit MyQGSettings(QWidget *parent = nullptr);
    ~MyQGSettings();
private slots:
    void on_resetBtn_clicked();
    void on_queryBtn_clicked();
    void on_saveSexBtn_clicked();
    void on_saveAgeBtn_clicked();

private:
    Ui::MyQGSettings    *mUi;
    QGSettings          *mSettings;
};

#endif // MYQGSETTINGS_H
