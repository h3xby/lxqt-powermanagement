/*
* Copyright (c) LXQt contributors.
*
* This file is part of the LXQt project. <http://lxqt.org>
* It is distributed under the LGPL 2.1 or later license.
* Please refer to the LICENSE file for a copy of the license, and
* the AUTHORS file for copyright and authorship information.
*/

#ifndef DPMSSETTINGS_H
#define DPMSSETTINGS_H

#include <QWidget>
#include "powermanagementsettings.h"

namespace Ui {
    class DPMSSettings;
};

class DPMSSettings: public QWidget
{
    Q_OBJECT

public:
    explicit DPMSSettings(QWidget *parent = nullptr);
    virtual ~DPMSSettings();

public slots:
    void loadSettings();

private slots:
    void standbyChanged(int timeout);
    void suspendChanged(int timeout);
    void offChanged(int timeout);
    void saveSettings();

private:
    PowerManagementSettings mSettings;
    Ui::DPMSSettings *ui;
};

#endif
