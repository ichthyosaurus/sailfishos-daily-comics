/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Dilbert.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Dilbert::Dilbert(QObject *parent) :
    Comic(parent)
{
}

const QString Dilbert::_id                 = QString("dilbert");
const QString Dilbert::_name               = QString("Dilbert");
const QColor Dilbert::_color               = QColor(69, 142, 197);
const QString Dilbert::_author             = QString("Scott Adams");
const QUrl Dilbert::_homepage              = QUrl("http://dilbert.com/");
const QLocale::Country Dilbert::_country   = QLocale::UnitedStates;
const QLocale::Language Dilbert::_language = QLocale::English;
const QDate Dilbert::_startDate            = QDate::fromString("1989-04-16", Qt::ISODate);
const QDate Dilbert::_endDate              = QDate::currentDate();
const QUrl Dilbert::_stripSourceUrl        = QUrl("http://dilbert.com/");

QUrl Dilbert::extractStripUrl(QByteArray data)
{
    QString html(data);

    QRegularExpression reg("<img[^>]*img-comic.*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}