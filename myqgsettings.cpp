#include "myqgsettings.h"
#include "ui_myqgsettings.h"
#include <QMessageBox>
#include <QDebug>

MyQGSettings::MyQGSettings(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::MyQGSettings)
{
    mUi->setupUi(this);
    mSettings = new QGSettings("com.uniontech.dde.astrea", "/com/uniontech/dde/astrea/");
    connect(mSettings, static_cast<void (QGSettings::*)(const QString &)>(&QGSettings::changed), [=](const QString &key)
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
}

void MyQGSettings::on_queryBtn_clicked()
{
    if (mSettings)
    {
        QString sex = mSettings->get("sex").toString();
        QString age = mSettings->get("age").toString();
        mUi->sexEdit->setText(sex);
        mUi->ageEdit->setText(age);
    }
}

void MyQGSettings::on_saveSexBtn_clicked()
{
    if (!mUi->sexEdit->text().isEmpty())
    {
        QString sex = mUi->sexEdit->text();
        if (sex == QString::fromUtf8("男") || sex == QString::fromUtf8("女"))
        {
            if (mSettings)
            {
                if (!(sex == mSettings->get("sex")))
                    mSettings->trySet("sex", sex);
            }
        }
        else
        {
            QMessageBox::critical(this, tr("错误提示"), tr("性别必须是\"男\"或者\"女\"。"), QMessageBox::Close);
        }
    }
}

void MyQGSettings::on_saveAgeBtn_clicked()
{
    if (!mUi->ageEdit->text().isEmpty())
    {
        bool canConvert;
        int age = mUi->ageEdit->text().toInt(&canConvert);
        if (canConvert && age >= 0)
        {
            if (age >= 200)
            {
                QMessageBox::warning(this, tr("警告"), tr("年龄是否有点不合实际？请检查！"), QMessageBox::Close);
            }
            if (mSettings)
            {
                if (!(mSettings->get("age") == age))
                   mSettings->trySet("age", age);
            }
        }
        else
        {
            QMessageBox::critical(this, tr("错误提示"), tr("年龄必须是整数"), QMessageBox::Close);
        }
    }
}

MyQGSettings::~MyQGSettings()
{
    delete mUi;
    delete mSettings;
}

void MyQGSettings::on_resetBtn_clicked()
{
    if (mSettings)
    {
        mSettings->reset("sex");
        mSettings->reset("age");
        mUi->sexEdit->setText(mSettings->get("sex").toString());
        mUi->ageEdit->setText(mSettings->get("age").toString());
    }
}
