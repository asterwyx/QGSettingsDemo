#ifndef MYQGSETTINGS_H
#define MYQGSETTINGS_H

#include <QWidget>
#include <QGSettings/QGSettings>

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
    void on_btn_queryInfo_clicked();
    void on_btn_setAge_clicked();
    void on_btn_setSex_clicked();

private:
    Ui::MyQGSettings *ui;
    QGSettings *m_settings
};

#endif // MYQGSETTINGS_H
