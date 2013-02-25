#ifndef DIALOGCHANGERPASS_H
#define DIALOGCHANGERPASS_H

#include "ui_dialogchangerpass.h"

class DialogChangerPass : public QDialog, private Ui::DialogChangerPass
{
    Q_OBJECT
    
public:
    explicit DialogChangerPass(QWidget *parent = 0);
};

#endif // DIALOGCHANGERPASS_H
