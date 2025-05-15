#ifndef TCOUNTRIES_OPERATORS_TREE_WIDGET_H
#define TCOUNTRIES_OPERATORS_TREE_WIDGET_H

#include <QTreeView>

class TCountriesOperatorsStyledItemDelegate;
class TCountriesOperatorsItemModel;

class TCountriesOperatorsTreeViewWidget : public QTreeView {
    public:
    TCountriesOperatorsTreeViewWidget(QWidget* parent = nullptr);

    public:
    TCountriesOperatorsStyledItemDelegate* CountriesOperatorsStyledItemDelegate() const;
    TCountriesOperatorsItemModel* CountriesOperatorsItemModel() const;

    protected:
    TCountriesOperatorsStyledItemDelegate* m_pCountriesOperatorsStyledItemDelegate = nullptr;
    TCountriesOperatorsItemModel* m_pCountriesOperatorsItemModel = nullptr;
};

#endif // TCOUNTRIES_OPERATORS_TREE_WIDGET_H
