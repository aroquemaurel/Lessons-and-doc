#include <QtGui>

#include "calendardelegate.h"

CalendarDelegate::CalendarDelegate(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *CalendarDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QCalendarWidget *editor = new QCalendarWidget(parent);
    editor->setFixedSize(250,150);
    return editor;
}

void CalendarDelegate::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QCalendarWidget *calendar = static_cast<QCalendarWidget*>(editor);

    model->setData(index, calendar->selectedDate().toString("yyyy-MM-dd")+":00:00", Qt::EditRole);
}

