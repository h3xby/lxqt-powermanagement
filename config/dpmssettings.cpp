/*
* Copyright (c) LXQt contributors.
*
* This file is part of the LXQt project. <http://lxqt.org>
* It is distributed under the LGPL 2.1 or later license.
* Please refer to the LICENSE file for a copy of the license, and
* the AUTHORS file for copyright and authorship information.
*/

#include "dpmssettings.h"
#include "ui_dpmssettings.h"

DPMSSettings::DPMSSettings(QWidget *parent):
    QWidget(parent),
    ui(new Ui::DPMSSettings)
{
    ui->setupUi(this);
    connect(ui->standbySlider, &QSlider::valueChanged,
            this, &DPMSSettings::standbyChanged);
    connect(ui->suspendSlider, &QSlider::valueChanged,
            this, &DPMSSettings::suspendChanged);
    connect(ui->offSlider, &QSlider::valueChanged,
            this, &DPMSSettings::offChanged);
    connect(ui->groupBox, &QGroupBox::clicked,
            this, &DPMSSettings::saveSettings);
}

DPMSSettings::~DPMSSettings()
{
    delete ui;
}

void setTimeoutLabelValue(QLabel* label, int timeout)
{
    if(timeout == 0)
    {
        label->setText(QObject::tr("Never"));
    } else {
        label->setText(QObject::tr("%1 minutes").arg(timeout));
    }
}

void DPMSSettings::standbyChanged(int timeout)
{
    setTimeoutLabelValue(ui->standbyValueLabel, timeout);
    saveSettings();
}

void DPMSSettings::suspendChanged(int timeout)
{
    setTimeoutLabelValue(ui->suspendValueLabel, timeout);
    saveSettings();
}

void DPMSSettings::offChanged(int timeout)
{
    setTimeoutLabelValue(ui->offValueLabel, timeout);
    saveSettings();
}

void DPMSSettings::loadSettings()
{
    ui->groupBox->setChecked(mSettings.isDPMSEnabled());
    ui->standbySlider->setValue(mSettings.getDisplayStandbyTimeout());
    ui->offSlider->setValue(mSettings.getDisplayOffTimeout());
    ui->suspendSlider->setValue(mSettings.getDisplaySuspendTimeout());
}

void DPMSSettings::saveSettings()
{
    mSettings.setDPMSEnabled(ui->groupBox->isChecked());
    mSettings.setDisplayStandbyTimeout(ui->standbySlider->value());
    mSettings.setDisplaySuspendTimeout(ui->suspendSlider->value());
    mSettings.setDisplayOffTimeout(ui->offSlider->value());
}

