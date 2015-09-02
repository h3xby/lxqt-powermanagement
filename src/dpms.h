/*
* Copyright (c) LXQt contributors.
*
* This file is part of the LXQt project. <http://lxqt.org>
* It is distributed under the LGPL 2.1 or later license.
* Please refer to the LICENSE file for a copy of the license, and
* the AUTHORS file for copyright and authorship information.
*/

#ifndef DPMS_H
#define DPMS_H

#include <QObject>
#include <xcb/dpms.h>
#include "../config/powermanagementsettings.h"

class DPMS : public QObject
{
    Q_OBJECT

public:
    DPMS(QObject *parent=nullptr);
    virtual ~DPMS();

private:
    PowerManagementSettings mPSettings;
    xcb_connection_t *connection;

private slots:
    void updateTimeouts();
};

#endif
