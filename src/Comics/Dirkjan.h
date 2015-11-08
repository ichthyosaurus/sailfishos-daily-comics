/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DIRKJAN_H
#define DIRKJAN_H

#include "../Comic.h"

class Dirkjan : public Comic
{
    Q_OBJECT

public:
    explicit Dirkjan(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DIRKJAN_H
