#ifndef COMBOBOXDELEGATEFORMATIERES_H
#define COMBOBOXDELEGATEFORMATIERES_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QComboBox>

#include "bdd.h"

class ComboBoxDelegateForMatieres
        : public QItemDelegate {
    Q_OBJECT

public:
    ComboBoxDelegateForMatieres(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:

};



#endif // COMBOBOXDELEGATEFORMATIERES_H
