#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef __DEBUG__COMPILE__
extern int g_nNetthreadVersion;
extern int g_nCreateDumpThread;
extern int g_nMAX_MSG_LENGTH;
//DWORD dwMilliseconds;
extern int dword_1003F654;
extern int dword_1003F658;

#define ___security_cookie 0x0BB40E64E;

extern struct _RTL_CRITICAL_SECTION g_csSessionPoolLock;
extern struct _RTL_CRITICAL_SECTION g_csViewLock;
extern struct _RTL_CRITICAL_SECTION g_csZipProfileLock;
extern struct _RTL_CRITICAL_SECTION g_csWorkingThreadPoolLock;
extern struct _RTL_CRITICAL_SECTION g_csConnectThreadPoolLock;

extern int g_iLastVital;
extern int g_bCoreDumpCrashTest;
extern int g_iReCreateServerThreadTest;

/*int (*lpfnMiniDumpWriteDump)(void *,ulong,void *,_MINIDUMP_TYPE,_MINIDUMP_EXCEPTION_INFORMATION *,_MINIDUMP_USER_STREAM_INFORMATION *,_MINIDUMP_CALLBACK_INFORMATION *);
CBString g_sLastIP;
CBString g_sLastLoginName;
MyTPool<CNetWorkingThread,100,100> g_WorkingThreadPool;
CBString g_sFateProcessMsg;
CBString g_sLastMsg;
std::vector<CNetServerThread *,std::allocator<CNetServerThread *>> g_pServerThreadPool;
CBString g_sLastName;
CBString g_sPatchNo;
CBString g_sQuestLastMsg;
MyTPool<CNetSession,4000,100> g_NetSessionPool;
struct _RTL_CRITICAL_SECTION CriticalSection;
CBString g_sRandomQuestLastMsg;
MyTPool<CNetConnectThread,100,100> g_ConnectThreadPool;*/

void InitLock(struct _RTL_CRITICAL_SECTION *m_struct);
void DeleteLock(struct _RTL_CRITICAL_SECTION *m_struct);
void Lock(struct _RTL_CRITICAL_SECTION *m_struct);
void UnLock(struct _RTL_CRITICAL_SECTION *m_struct);

#endif
#endif // GLOBAL_H
