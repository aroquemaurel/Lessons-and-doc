#include <QtGui>

#include "checkboxdelegate.h"

CheckboxDelegate::CheckboxDelegate(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *CheckboxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QCheckBox *editor = new QCheckBox(parent);

    return editor;
}

void CheckboxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    QString checked = index.model()->data(index, Qt::EditRole).toString();

    QCheckBox *checkbox = static_cast<QCheckBox*>(editor);
    checkbox->setChecked(checked == "True");
}

void CheckboxDelegate::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
     QCheckBox *checkbox = static_cast<QCheckBox*>(editor);

     model->setData(index, (checkbox->isChecked()) ? "True" : "False", Qt::EditRole);
}

