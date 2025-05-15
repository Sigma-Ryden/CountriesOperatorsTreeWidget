#ifndef TCOUNTRIES_OPERATORS_STYLED_ITEM_DELEGATE_H
#define TCOUNTRIES_OPERATORS_STYLED_ITEM_DELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class TCountriesOperatorsStyledItemDelegate : public QStyledItemDelegate {
    public:
    using QStyledItemDelegate::QStyledItemDelegate;

    public:
    void paint(QPainter* painter, QStyleOptionViewItem const& option, QModelIndex const& index) const override;
    QSize sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const override;
};

#endif // TCOUNTRIES_OPERATORS_STYLED_ITEM_DELEGATE_H
