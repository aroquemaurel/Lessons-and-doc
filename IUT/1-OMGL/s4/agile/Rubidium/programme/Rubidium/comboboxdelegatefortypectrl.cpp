#include <QtGui>

#include "comboboxdelegatefortypectrl.h"

ComboBoxDelegateForTypeCtrl::ComboBoxDelegateForTypeCtrl(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *ComboBoxDelegateForTypeCtrl::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QComboBox *editor = new QComboBox(parent);
    editor->addItems(Bdd::getInstance()->getListeTypeCtrl());

    return editor;
}

void ComboBoxDelegateForTypeCtrl::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QComboBox *combo = static_cast<QComboBox*>(editor);
    combo->setCurrentIndex(((value-1) < 0) ? value : 0);
}

void ComboBoxDelegateForTypeCtrl::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QComboBox *combo = static_cast<QComboBox*>(editor);
    model->setData(index, combo->currentIndex()+1, Qt::EditRole);
}

void ComboBoxDelegateForTypeCtrl::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
