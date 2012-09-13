#include <QtGui>

#include "timedelegate.h"

TimeDelegate::TimeDelegate(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *TimeDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &/* option */,
                                    const QModelIndex &/* index */) const {
    QTimeEdit *editor = new QTimeEdit(parent);
    return editor;

}

void TimeDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const {
    QString contenu = index.model()->data(index, Qt::EditRole).toString();
    int heures = (contenu.isEmpty()) ? 0 : contenu.split(":").first().toInt() ;
    int minutes = (contenu.isEmpty()) ? 0 : contenu.split(":").at(1).toInt();

    QTimeEdit *time = static_cast<QTimeEdit*>(editor);
    time->setTime(QTime(heures, minutes, 0));
}

void TimeDelegate::setModelData(QWidget *editor,
                                QAbstractItemModel *model,
                                const QModelIndex &index) const {
    QTimeEdit *qtime = static_cast<QTimeEdit*>(editor);
    model->setData(index, qtime->time(), Qt::EditRole);
}

void TimeDelegate::updateEditorGeometry(QWidget *editor,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
