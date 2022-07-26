#include "myqgsettings.h"
#include "ui_myqgsettings.h"

MyQGSettings::MyQGSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyQGSettings)
{
    ui->setupUi(this);
}

MyQGSettings::~MyQGSettings()
{
    delete ui;
}
