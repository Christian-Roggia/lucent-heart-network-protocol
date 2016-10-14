#include "global.h"

#ifdef __DEBUG__COMPILE__
int g_nNetthreadVersion;
int g_nCreateDumpThread;
int g_nMAX_MSG_LENGTH;

int dword_1003F654 = 0;
int dword_1003F658 = 0;

struct _RTL_CRITICAL_SECTION g_csSessionPoolLock;
struct _RTL_CRITICAL_SECTION g_csViewLock;
struct _RTL_CRITICAL_SECTION g_csZipProfileLock;
struct _RTL_CRITICAL_SECTION g_csWorkingThreadPoolLock;
struct _RTL_CRITICAL_SECTION g_csConnectThreadPoolLock;

int g_iLastVital;
int g_bCoreDumpCrashTest;
int g_iReCreateServerThreadTest;

void InitLock(struct _RTL_CRITICAL_SECTION *pRtlCrtSect)
{
    InitializeCriticalSection(pRtlCrtSect);
}

void DeleteLock(struct _RTL_CRITICAL_SECTION *pRtlCrtSect)
{
    DeleteCriticalSection(pRtlCrtSect);
}

void Lock(struct _RTL_CRITICAL_SECTION *pRtlCrtSect)
{
    EnterCriticalSection(pRtlCrtSect);
}

void UnLock(struct _RTL_CRITICAL_SECTION *pRtlCrtSect)
{
    LeaveCriticalSection(pRtlCrtSect);
}
#endif
