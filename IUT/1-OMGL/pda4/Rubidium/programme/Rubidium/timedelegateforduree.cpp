#include <QtGui>

#include "timedelegateforduree.h"

TimeDelegateForDuree::TimeDelegateForDuree(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *TimeDelegateForDuree::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QTimeEdit *editor = new QTimeEdit(parent);
    return editor;
}

void TimeDelegateForDuree::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    int nbMinutes = index.model()->data(index, Qt::EditRole).toInt();
    QTime duree(nbMinutes/60, nbMinutes%60);

    QTimeEdit *time = static_cast<QTimeEdit*>(editor);
    time->setTime(duree);
}

void TimeDelegateForDuree::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QTimeEdit *qtime = static_cast<QTimeEdit*>(editor);
    int nbMinutes = qtime->time().minute() + qtime->time().hour() * 60 ;
    model->setData(index, nbMinutes, Qt::EditRole);
}

void TimeDelegateForDuree::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
