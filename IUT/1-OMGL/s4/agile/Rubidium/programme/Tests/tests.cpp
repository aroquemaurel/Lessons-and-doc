#include <QtCore/QString>
#include <QtTest/QtTest>

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests();

private Q_SLOTS:
    void testCase1();
};

Tests::Tests() {
}

void Tests::testCase1() {
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Tests)

#include "tests.moc"
