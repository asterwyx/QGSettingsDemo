#include "myqgsettings.h"
#include "ui_myqgsettings.h"

MyQGSettings::MyQGSettings(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::MyQGSettings)
{
    mUi->setupUi(this);
}

MyQGSettings::~MyQGSettings()
{
    delete mUi;
}
