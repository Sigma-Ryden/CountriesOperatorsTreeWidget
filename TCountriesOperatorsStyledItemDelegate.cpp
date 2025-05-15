#include "TCountriesOperatorsStyledItemDelegate.h"

void TCountriesOperatorsStyledItemDelegate::paint(QPainter* painter, QStyleOptionViewItem const& option, QModelIndex const& index) const {
    // TODO: custom impl
    QStyledItemDelegate::paint(painter, option, index);
}

QSize TCountriesOperatorsStyledItemDelegate::sizeHint(QStyleOptionViewItem const& option, QModelIndex const& index) const {
    // TODO: custom impl
    return QStyledItemDelegate::sizeHint(option, index);
}
