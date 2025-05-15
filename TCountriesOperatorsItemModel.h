#ifndef TCOUNTRIES_OPERATORS_ITEM_MODEL_H
#define TCOUNTRIES_OPERATORS_ITEM_MODEL_H

#include <QStandardItemModel>

#include "SCountry.h"

class TCountriesOperatorsItemModel : public QStandardItemModel {
    public:
    using QStandardItemModel::QStandardItemModel;

    public:
    void AddCountries(QList<SCountry> const& countries);
    void RemoveCountries(QList<SCountry> const& countries);

    public:
    QString CountyIconFileNamePath(SCountry const& country) const;
    QString CountyText(SCountry const& country) const;
    QString CountyOperatorIconFileNamePath(SCountryOperator const& countryOperator) const;
    QString CountyOperatorText(SCountryOperator const& countryOperator) const;

    public:
    inline static QString const sCountyIconFileNamePathFormat = "Icons/Countries/%1.png";
    inline static QString const sCountyTextFormat = "%1 (%2)";
    inline static QString const sCountryOperatorIconFileNamePathFormat = "Icons/Operators/%1_%2.png";
    inline static QString const sCountryOperatorTextFormat = "%1 (%2-%3)";
};

#endif // TCOUNTRIES_OPERATORS_ITEM_MODEL_H
