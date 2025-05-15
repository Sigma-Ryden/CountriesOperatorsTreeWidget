#ifndef TCOUNTRIES_OPERATORS_DATABASE_H
#define TCOUNTRIES_OPERATORS_DATABASE_H

#include <QString>
#include <QSqlDatabase>

#include "SCountry.h"

class TCountriesOperatorsDatabase {
    public:
    bool Init(QString const& configFilePathName);

    public:
    QList<SCountry> const& Dump();

    public:
    QString QueryCountries() const;
    QString QueryCountryOperators() const;

    public:
    inline static QString const sSettingsBegingGroupPrefix = "Database";
    inline static QString const sSettingsDriverKey = "driver";
    inline static QString const sSettingsNameKey = "name";
    inline static QString const sSettingsHostKey = "host";
    inline static QString const sSettingsUserKey = "user";
    inline static QString const sSettingsPasswordKey = "password";

    public:
    inline static QString const sQueryCountriesFormat = "SELECT %1, %2, %3 FROM %4";
    inline static QString const sQueryCountryOperatorsFormat = "SELECT %1, %2, %3 FROM %4";

    protected:
    QSqlDatabase m_xDB;
    std::unique_ptr<QList<SCountry>> m_pCountries = nullptr;
};

#endif // TCOUNTRIES_OPERATORS_DATABASE_H
