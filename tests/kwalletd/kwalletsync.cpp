#include <QTextStream>
#include <QApplication>
#include <QTimer>
#include <QTest>

#include <kaboutdata.h>
#include <kwallet.h>
#include <QDBusConnectionInterface>
#include <QDBusConnection>
#include <QDBusReply>
#include <KLocalizedString>

#include "kwalletsync.h"

static QTextStream _out(stdout, QIODevice::WriteOnly);

void KWalletSyncTest::init()
{
    if (!qEnvironmentVariableIsSet("DISPLAY")) {
        QSKIP("$DISPLAY is not set. These tests cannot be done without a graphical system.");
    }
}

void KWalletSyncTest::openWallet()
{
    _out << "About to ask for wallet sync" << endl;

    KWallet::Wallet *w = KWallet::Wallet::openWallet(KWallet::Wallet::NetworkWallet(), 0, KWallet::Wallet::Synchronous);
    QVERIFY(w != nullptr);

    _out << "Got sync wallet: " << (w != nullptr) << endl;
}

QTEST_GUILESS_MAIN(KWalletSyncTest)

