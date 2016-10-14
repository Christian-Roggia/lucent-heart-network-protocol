#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "global.h"
#include "Package.h"
#include "ZipProfile.h"

#define HEADER_TYPE_2  0x000290e8
#define MAX_MSG_LENGTH 0x10000

class CProtocol {
private:
    // Virtual Table        // +0
    int Unk4;               // +4
    // CBString m_string;   // +8
    int Unk32, Unk36;       // +32, +36
    char Unk40;             // +40
public:
    CProtocol(class CProtocol const &m_protocol);
    CProtocol(void);

#ifdef PROTOCOL_VIRTUAL_ENABLED
    virtual class CProtocol *Clone(void)                    { return 0;     }
    virtual bool Dump(char *a1, unsigned int a2, int a3)    { return false; }
    virtual int Read(CPackage &a1)                          { return 0;     }
    virtual int Write(class CPackage &a1)                   { return 0;     }
    virtual bool ToDo(class CNetSession *a1)                { return true;  }
#endif // PROTOCOL_VIRTUAL_ENABLED

    class CProtocol &operator=(class CProtocol const &m_protocol);

#ifdef __DEBUG__COMPILE__
    static void GetProfileData(class CZipProfile &m_zip_profile);
    static void ResetZipProfile(void);
    static void SetProfile(bool m_bool_profile);
#endif // __DEBUG__COMPILE__

    void Clone(class CProtocol *m_protocol);
    int  Read(CPackage &m_pack, CProtocol * &m_protocol, unsigned short &a4, char &a5, int &a6);
    int  Read2(CPackage &m_pack, CProtocol * &m_protocol, unsigned short &a4, char &a5, int m_xor_size1, int m_xor_size2, int &a8);

    static bool m_bProfile;
    static CZipProfile m_profile;
    static unsigned long m_nMustZipSize;
};

#endif // PROTOCOL_H
