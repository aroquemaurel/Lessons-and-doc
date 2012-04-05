#ifndef COMBOBOXDELEGATEFORUE_H
#define COMBOBOXDELEGATEFORUE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QComboBox>

class ComboBoxDelegateForUe
        : public QItemDelegate {
    Q_OBJECT

public:
    ComboBoxDelegateForUe(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // COMBOBOXDELEGATEFORUE_H
