#include "TCountriesOperatorsDatabase.h"

#include <QSettings>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

bool TCountriesOperatorsDatabase::Init(QString const& configFilePathName) {
    auto settings = QSettings(configFilePathName, QSettings::IniFormat);
    settings.beginGroup(sSettingsBegingGroupPrefix);

    m_xDB = QSqlDatabase::addDatabase( settings.value(sSettingsDriverKey).toString() );
    m_xDB.setDatabaseName( settings.value(sSettingsNameKey).toString() );
    m_xDB.setHostName( settings.value(sSettingsHostKey).toString() );
    m_xDB.setUserName( settings.value(sSettingsUserKey).toString() );
    m_xDB.setPassword( settings.value(sSettingsPasswordKey).toString() );

    if(!m_xDB.open()) {
        qCritical() << "Failed to open database:" << m_xDB.lastError().text();
    } else {
        qDebug() << "Connected to database successfully.";
    }

    return m_xDB.isOpen();
}

QList<SCountry> const& TCountriesOperatorsDatabase::Dump() {
    if(m_pCountries != nullptr) {
        return *m_pCountries;
    }

    m_pCountries = std::make_unique<QList<SCountry>>();
    QMap<QString, SCountry> codeAndCountryRelation;

    QSqlQuery countryQuery(m_xDB);
    if( !countryQuery.exec(QueryCountries()) ) {
        qCritical() << "Failed to query countries:" << countryQuery.lastError().text();
        return *m_pCountries;
    }
    while(countryQuery.next()) {
        auto mcc = countryQuery.value(SCountry::sMCCKey).toString();
        auto code = countryQuery.value(SCountry::sCodeKey).toString();
        auto name = countryQuery.value(SCountry::sNameKey).toString();

        if(!codeAndCountryRelation.contains(code)) {
            SCountry country;
            country.code = code;
            country.name = name;
            codeAndCountryRelation.insert(code, country);
        }

        codeAndCountryRelation[code].mcc = mcc;
    }

    QSqlQuery countryOperatorQuery(m_xDB);
    if( !countryOperatorQuery.exec(QueryCountryOperators()) ) {
        qCritical() << "Failed to query operators:" << countryOperatorQuery.lastError().text();
        return *m_pCountries;
    }
    while(countryOperatorQuery.next()) {
        auto mcc = countryOperatorQuery.value(SCountry::sMCCKey).toString();
        auto mnc = countryOperatorQuery.value(SCountryOperator::sMNCKey).toString();
        auto name = countryOperatorQuery.value(SCountryOperator::sNameKey).toString();

        for(auto& country : codeAndCountryRelation) if(country.mcc == mcc) {
            SCountryOperator countryOperator;
            countryOperator.mcc = mcc;
            countryOperator.mnc = mnc;
            countryOperator.name = name;
            country.operators.append(countryOperator);
            break;
        }
    }

    m_pCountries->append(codeAndCountryRelation.values());
    return *m_pCountries;
}

QString TCountriesOperatorsDatabase::QueryCountries() const {
    return sQueryCountriesFormat.arg(SCountry::sMCCKey, SCountry::sCodeKey, SCountry::sNameKey, SCountry::sSelfKey);
}

QString TCountriesOperatorsDatabase::QueryCountryOperators() const {
    return sQueryCountryOperatorsFormat.arg(SCountry::sMCCKey, SCountryOperator::sMNCKey, SCountryOperator::sNameKey, SCountryOperator::sSelfKey);
}
