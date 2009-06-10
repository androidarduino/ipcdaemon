#include "test.h"

QTEST_MAIN(IPCDaemonTest)

void IPCDaemonTest::serviceManagerListen()
{
    ServiceManager manager;
    bool ret=manager.listen(9312);
    QVERIFY(ret==true);
}
