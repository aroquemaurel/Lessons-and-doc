#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QCheckBox>
#include "bdd.h"

class CheckboxDelegate
        : public QItemDelegate {
    Q_OBJECT

public:
    CheckboxDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;


private:

};



#endif // CHECKBOXDELEGATE_H
