#include "myqgsettings.h"
#include "ui_myqgsettings.h"

MyQGSettings::MyQGSettings(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::MyQGSettings)
{
    mUi->setupUi(this);
    mSettings = new QGSettings("com.uniontech.dde.astrea", "/com/uniontech/dde/astrea/");
    connect(mSettings, &QGSettings::changed, [=](const QString key)
    {
        if (key == "sex")
        {
            mUi->sexEdit->setText(mSettings->get(key).toString());
        }
        else if (key == "age")
        {
            mUi->ageEdit->setText(mSettings->get(key).toString());
        }
    });
    connect(mUi->queryBtn, &QPushButton::clicked, this, &MyQGSettings::onBtnQueryInfoClicked);
    connect(mUi->resetBtn, &QPushButton::clicked, this, &MyQGSettings::onBtnResetInfoClicked);
    connect(mUi->saveSexBtn, &QPushButton::clicked, this, &MyQGSettings::onBtnSaveSexClicked);
    connect(mUi->saveAgeBtn, &QPushButton::clicked, this, &MyQGSettings::onBtnSaveAgeClicked);
}

void MyQGSettings::onBtnQueryInfoClicked()
{
    if (mSettings)
    {
        QString sex = mSettings->get("sex").toString();
        QString age = mSettings->get("age").toString();
        mUi->sexEdit->setText(sex);
        mUi->ageEdit->setText(age);
    }
}

void MyQGSettings::onBtnSaveSexClicked()
{
    if (!mUi->sexEdit->text().isEmpty())
    {
        QString sex = mUi->sexEdit->text();
        if (mSettings)
        {
            mSettings->trySet("sex", sex);
        }
    }
}

void MyQGSettings::onBtnSaveAgeClicked()
{
    if (!mUi->ageEdit->text().isEmpty())
    {
        int age = mUi->ageEdit->text().toInt();
        if (mSettings)
        {
            mSettings->trySet("age", age);
        }
    }
}

MyQGSettings::~MyQGSettings()
{
    delete mUi;
    delete mSettings;
}

void MyQGSettings::onBtnResetInfoClicked()
{
    if (mSettings)
    {
        mSettings->reset("sex");
        mSettings->reset("age");
        mUi->sexEdit->setText(mSettings->get("sex").toString());
        mUi->ageEdit->setText(mSettings->get("age").toString());
    }
}
