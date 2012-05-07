#include <QtGui>

#include "comboboxdelegateformatieres.h"

ComboBoxDelegateForMatieres::ComboBoxDelegateForMatieres(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *ComboBoxDelegateForMatieres::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QComboBox *editor = new QComboBox(parent);
    editor->addItems(Bdd::getInstance()->getListeMatieres()
                     );

    return editor;
}

void ComboBoxDelegateForMatieres::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QComboBox *combo = static_cast<QComboBox*>(editor);
    combo->setCurrentIndex(((value-1) < 0) ? value : 0);
}

void ComboBoxDelegateForMatieres::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QComboBox *combo = static_cast<QComboBox*>(editor);
    model->setData(index, combo->currentIndex()+1, Qt::EditRole);
}

void ComboBoxDelegateForMatieres::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
