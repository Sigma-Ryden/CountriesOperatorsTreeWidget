#ifndef SCOUNTRY_H
#define SCOUNTRY_H

#include <QString>
#include <QList>

#include "SCountryOperator.h"

struct SCountry {
    QString mcc;
    QString code;
    QString name;
    QList<SCountryOperator> operators;

    inline static QString const sSelfKey = "countries";
    inline static QString const sMCCKey = "mcc";
    inline static QString const sCodeKey = "code";
    inline static QString const sNameKey = "name";
};

#endif // SCOUNTRY_H
