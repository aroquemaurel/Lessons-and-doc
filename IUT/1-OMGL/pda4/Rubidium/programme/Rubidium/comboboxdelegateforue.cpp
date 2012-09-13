#include <QtGui>

#include "comboboxdelegateforue.h"

ComboBoxDelegateForUe::ComboBoxDelegateForUe(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *ComboBoxDelegateForUe::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QComboBox *editor = new QComboBox(parent);
    editor->addItems(QStringList() << "1 - Informatique" << "2 - Général");

    return editor;
}

void ComboBoxDelegateForUe::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QComboBox *combo = static_cast<QComboBox*>(editor);
    combo->setCurrentIndex(((value-1) < 0) ? value : 0);
}

void ComboBoxDelegateForUe::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QComboBox *combo = static_cast<QComboBox*>(editor);
    model->setData(index, combo->currentIndex()+1, Qt::EditRole);
}

void ComboBoxDelegateForUe::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
