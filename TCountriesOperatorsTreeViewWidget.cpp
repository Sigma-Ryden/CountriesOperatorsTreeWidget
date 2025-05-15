#include "TCountriesOperatorsTreeViewWidget.h"
#include "TCountriesOperatorsStyledItemDelegate.h"
#include "TCountriesOperatorsItemModel.h"

TCountriesOperatorsTreeViewWidget::TCountriesOperatorsTreeViewWidget(QWidget* parent): QTreeView(parent) {
    m_pCountriesOperatorsStyledItemDelegate = new TCountriesOperatorsStyledItemDelegate(this);
    setItemDelegate(m_pCountriesOperatorsStyledItemDelegate);

    m_pCountriesOperatorsItemModel = new TCountriesOperatorsItemModel(this);
    setModel(m_pCountriesOperatorsItemModel);
}

TCountriesOperatorsStyledItemDelegate *TCountriesOperatorsTreeViewWidget::CountriesOperatorsStyledItemDelegate() const {
    return m_pCountriesOperatorsStyledItemDelegate;
}

TCountriesOperatorsItemModel* TCountriesOperatorsTreeViewWidget::CountriesOperatorsItemModel() const {
    return m_pCountriesOperatorsItemModel;
}
