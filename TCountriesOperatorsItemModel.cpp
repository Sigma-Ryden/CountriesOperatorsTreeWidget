#include "TCountriesOperatorsItemModel.h"

void TCountriesOperatorsItemModel::AddCountries(QList<SCountry> const& countries) {
    for(auto const& country : countries) {
        auto countryTreeNode = new QStandardItem( QIcon(CountyIconFileNamePath(country)), CountyText(country) );

        for(auto const& countryOperator : country.operators) {
            auto countryOperatorNode = new QStandardItem( QIcon(CountyOperatorIconFileNamePath(countryOperator)), CountyOperatorText(countryOperator) );
            countryTreeNode->appendRow(countryOperatorNode);
        }

        appendRow(countryTreeNode);
    }
}

void TCountriesOperatorsItemModel::RemoveCountries(QList<SCountry> const& countries) {
    for(auto const& country : countries) {
        auto countryTextToRemove = CountyText(country);

        for(auto rowIndex = 0; rowIndex < rowCount(); ++rowIndex) {
            auto itemToRemove = item(rowIndex);
            if(!itemToRemove) continue;

            auto itemText = itemToRemove->text();
            if(itemText.contains(countryTextToRemove)) {
                removeRow(rowIndex);
                break;
            }
        } // for(row)
    } // for(country)
}

QString TCountriesOperatorsItemModel::CountyIconFileNamePath(const SCountry &country) const {
    return sCountyIconFileNamePathFormat.arg(country.code);
}

QString TCountriesOperatorsItemModel::CountyText(const SCountry &country) const {
    return sCountyTextFormat.arg(country.name, country.code);
}

QString TCountriesOperatorsItemModel::CountyOperatorIconFileNamePath(const SCountryOperator &countryOperator) const {
    return sCountryOperatorIconFileNamePathFormat.arg(countryOperator.mcc, countryOperator.mnc);
}

QString TCountriesOperatorsItemModel::CountyOperatorText(const SCountryOperator &countryOperator) const {
    return sCountryOperatorTextFormat.arg(countryOperator.name, countryOperator.mcc, countryOperator.mnc);
}
