/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

    static const QString _favoritesField;
    static const QStringList _initialFavoriteIds;

public:
    static Settings* instance();
    ~Settings();
    Q_INVOKABLE QStringList favoriteIds();
    Q_INVOKABLE void saveFavoriteIds(QStringList favoriteIds);

protected:
    QVariant value(const QString &key);
    void setValue(const QString &key, const QVariant &value);

private:
    explicit Settings(QObject *parent = 0);

signals:
    void favoritesChanged();

private:
    QSettings* m_settings;
    static Settings* m_instance;
};

#endif // SETTINGS_H