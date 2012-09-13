#ifndef COMBOBOXDELEGATEFORTYPECTRL_H
#define COMBOBOXDELEGATEFORTYPECTRL_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QComboBox>

#include "bdd.h"

class ComboBoxDelegateForTypeCtrl
        : public QItemDelegate {
    Q_OBJECT

public:
    ComboBoxDelegateForTypeCtrl(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:

};



#endif // COMBOBOXDELEGATEFORTYPECTRL_H
