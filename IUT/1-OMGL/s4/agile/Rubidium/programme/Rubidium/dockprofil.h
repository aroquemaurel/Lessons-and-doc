#ifndef DOCKPROFIL_H
#define DOCKPROFIL_H

#include <QWidget>

#include "ui_dockprofil.h"
#include "personne.h"

class DockProfil : public QWidget, private Ui::DockProfil {
		Q_OBJECT
	public:
        explicit DockProfil(const Personne& pPersonne,
                            QWidget *parent = 0);
        ~DockProfil();
};

#endif // DOCKPROFIL_H
