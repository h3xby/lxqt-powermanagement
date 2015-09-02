/*
* Copyright (c) LXQt contributors.
*
* This file is part of the LXQt project. <http://lxqt.org>
* It is distributed under the LGPL 2.1 or later license.
* Please refer to the LICENSE file for a copy of the license, and
* the AUTHORS file for copyright and authorship information.
*/

#include <xcb/dpms.h>
#include <QDebug>
#include "x11helper.h"
#include "dpms.h"

DPMS::DPMS(QObject *parent): QObject(parent)
{
    connection = X11Helper::connection();
    
    if(!connection){
        qWarning("no xcb connection");
        return;
    }

    QScopedPointer<xcb_dpms_get_version_reply_t> verReply(xcb_dpms_get_version_reply(connection,
                xcb_dpms_get_version_unchecked(connection, XCB_DPMS_MAJOR_VERSION, XCB_DPMS_MINOR_VERSION),
                nullptr));
    if(!verReply) {
        qWarning() << "DPMS query version returned null";
        connection = nullptr;
        return;
    }

    connect(&mPSettings, &PowerManagementSettings::settingsChanged,
            this, &DPMS::updateTimeouts);

    updateTimeouts();
}

DPMS::~DPMS()
{
}

void DPMS::updateTimeouts()
{
    if(!connection)
        return;

    int standby, suspend, off; // Timeouts in minutes

    standby = mPSettings.getDisplayStandbyTimeout();
    suspend = mPSettings.getDisplaySuspendTimeout();
    off = mPSettings.getDisplayOffTimeout();

    qDebug("Setting DPMS timeouts %d; %d; %d", standby, suspend, off);

    xcb_dpms_set_timeouts(connection, standby*60, suspend*60, off*60);
}
