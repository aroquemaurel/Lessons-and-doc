#include <QtGui/QApplication>
#include "fenetreprincipale.h"

#include "bdd.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    qDebug();

    // Définis le codec UTF-8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //*/

    // Définis la langue de l'utilisateur
    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;
    translator.load(QString("klimasoft_") + locale);
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);
    a.installTranslator(&translator);
    //*/

	Bdd::getInstance();

	FenetrePrincipale w;
	w.show();

	return a.exec();
}
