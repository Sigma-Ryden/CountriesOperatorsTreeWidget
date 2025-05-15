#ifndef SCOUNTRY_OPERATOR_H
#define SCOUNTRY_OPERATOR_H

#include <QString>

struct SCountryOperator {
    QString mcc;
    QString mnc;
    QString name;

    inline static QString const sSelfKey = "operators";
    inline static QString const sMNCKey = "mnc";
    inline static QString const sNameKey = "name";
};

#endif // SCOUNTRY_OPERATOR_H
