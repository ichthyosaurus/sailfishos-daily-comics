/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "pages"
import "cover"

ApplicationWindow
{
    id: window

    property bool portrait: orientation === Orientation.Portrait || orientation === Orientation.PortraitInverted

    initialPage: Component { FavoritesPage { } }
    cover: DefaultCover { }
}

