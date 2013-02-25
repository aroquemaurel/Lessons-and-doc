QT       += core gui sql

TARGET = Rubidium
TEMPLATE = app


SOURCES += main.cpp\
	bdd.cpp \
	fenetreprincipale.cpp \
	dockprofil.cpp \
	dockfiltres.cpp \
	dialogconnexion.cpp \
	dialogajoutctrl.cpp \
	dialoginitctrl.cpp \
	dialogajouterutilisateur.cpp \
	dialogajoutermatiere.cpp \
	dialogchangerpass.cpp \
    salle.cpp \
    personne.cpp \
    controle.cpp \
    dialogtableajouterutilisateur.cpp \
    dialogtableajoutermatiere.cpp \
    dialogtableajoutersalle.cpp \
    dialoglisteajouterpole.cpp \
    dialoglisteajoutertypectrl.cpp \
    spinboxdelegate.cpp \
    comboboxdelegateforue.cpp \
    comboboxdelegateformatieres.cpp \
    comboboxdelegatefortypectrl.cpp \
    calendardelegate.cpp \
    checkboxdelegate.cpp \
    timedelegate.cpp \
    timedelegateforduree.cpp \
    spinboxdelegateforcoeff.cpp

HEADERS  += bdd.h \
	fenetreprincipale.h \
	dockprofil.h \
	dockfiltres.h \
	dialogconnexion.h \
	dialogajoutctrl.h \
	dialoginitctrl.h \
	dialogajouterutilisateur.h \
	dialogajoutermatiere.h \
	dialogchangerpass.h \
    salle.h \
    personne.h \
    controle.h \
    dialogtableajouterutilisateur.h \
    dialogtableajoutermatiere.h \
    dialogtableajoutersalle.h \
    dialoglisteajouterpole.h \
    dialoglisteajoutertypectrl.h \
    spinboxdelegate.h \
    exception.h \
    comboboxdelegateforue.h \
    comboboxdelegateformatieres.h \
    comboboxdelegatefortypectrl.h \
    calendardelegate.h \
    checkboxdelegate.h \
    timedelegate.h \
    timedelegateforduree.h \
    spinboxdelegateforcoeff.h

FORMS    += fenetreprincipale.ui \
	dockprofil.ui \
	dockfiltres.ui \
	dialogconnexion.ui \
	dialogajoutctrl.ui \
	dialoginitctrl.ui \
	dialogajouterutilisateur.ui \
	dialogajoutermatiere.ui \
        dialogchangerpass.ui \
    dialogtableajouterutilisateur.ui \
    dialogtableajoutermatiere.ui \
    dialogtableajoutersalle.ui \
    dialoglisteajouterpole.ui \
    dialoglisteajoutertypectrl.ui

RESOURCES += \
	ressources.qrc

OTHER_FILES += \
    creation.sql \
    jeuDEssai.sql \
    viderBdd.sql





contains(MEEGO_EDITION,harmattan) {
    target.path = /opt/Rubidium/bin
    INSTALLS += target
}
