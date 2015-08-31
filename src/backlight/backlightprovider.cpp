/*
* Copyright (c) LXQt contributors.
*
* This file is part of the LXQt project. <http://lxqt.org>
* It is distributed under the LGPL 2.1 or later license.
* Please refer to the LICENSE file for a copy of the license, and
* the AUTHORS file for copyright and authorship information.
*/

#include "backlight.h"

BacklightProvider::BacklightProvider(QObject *parent):
    QObject(parent)
{
}

BacklightProvider::~BacklightProvider() {}
