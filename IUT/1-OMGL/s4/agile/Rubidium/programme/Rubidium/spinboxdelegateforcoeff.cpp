#include <QtGui>

#include "spinboxdelegateforcoeff.h"

SpinBoxDelegateForCoeff::SpinBoxDelegateForCoeff(QObject *parent)
    : QItemDelegate(parent) {
}

QWidget *SpinBoxDelegateForCoeff::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const {
    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);

//    editor->setMinimum(0);
//    editor->setMaximum(100);

    return editor;
}

void SpinBoxDelegateForCoeff::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegateForCoeff::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const {
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->interpretText();
    double value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegateForCoeff::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &/* index */) const {
    editor->setGeometry(option.rect);
}
