#ifndef CALENDARDELEGATE_H
#define CALENDARDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QCheckBox>
#include "bdd.h"

class CalendarDelegate
        : public QItemDelegate {
    Q_OBJECT

public:
    CalendarDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

private:

};



#endif // CALENDARDELEGATE_H
