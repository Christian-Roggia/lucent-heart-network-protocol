#include "Protocol.h"

CProtocol::CProtocol(class CProtocol const &m_protocol)
{
    //*(_DWORD *)this = CProtocol::_vftable_;
    this->Unk4  = m_protocol.Unk4;
    //CBString::CBString(this + 8, a2 + 8);
    this->Unk32 = m_protocol.Unk32;
    this->Unk36 = m_protocol.Unk36;
    this->Unk40 = m_protocol.Unk40;
}

CProtocol::CProtocol(void)
{
    //*(_DWORD *)this = CProtocol::_vftable_;
    this->Unk4  = 0;
    //CBString::CBString(this + 8);
    this->Unk32 = 0;
    this->Unk36 = 0;
    this->Unk40 = 1;
}

class CProtocol &CProtocol::operator=(class CProtocol const &m_protocol)
{
    //*(_DWORD *)this = CProtocol::_vftable_;
    this->Unk4  = m_protocol.Unk4;
    //CBString::CBString(this + 8, a2 + 8);
    this->Unk32 = m_protocol.Unk32;
    this->Unk36 = m_protocol.Unk36;
    this->Unk40 = m_protocol.Unk40;
}
#ifdef __DEBUG__COMPILE__
void CProtocol::GetProfileData(class CZipProfile &m_zip_profile)
{
    Lock(&g_csZipProfileLock);
    m_zip_profile = CProtocol::m_profile;
    UnLock(&g_csZipProfileLock);
}

void CProtocol::ResetZipProfile(void)
{
    Lock(&g_csZipProfileLock);
    CProtocol::m_profile.Reset();
    UnLock(&g_csZipProfileLock);
}

void CProtocol::SetProfile(bool m_bool_profile)
{
    CProtocol::m_bProfile = m_bool_profile;
}
#endif

void CProtocol::Clone(class CProtocol *m_protocol)
{
    m_protocol->Unk32 = this->Unk32;
}

int CProtocol::Read(CPackage &m_pack, CProtocol * &m_protocol, unsigned short &a4, char &a5, int &a6)
{
    int m_header, m_xor_size1, m_xor_size2;

    if(m_pack.BPack.BufLen() >= 13)
    {
        m_pack.BPack >> m_header;
        m_pack.BPack >> m_xor_size1;
        m_pack.BPack >> m_xor_size2;

        if(m_header == HEADER_TYPE_2)
        {
            m_pack.Unk16 = 58;
            m_pack.Unk12 = HEADER_TYPE_2;
            m_pack.Unk26 = 58;

            return this->Read2(m_pack, m_protocol, a4, a5, m_xor_size1, m_xor_size2, a6);
        }
    }

    return 0;
}

int CProtocol::Read2(CPackage &m_pack, CProtocol * &m_protocol, unsigned short &a4, char &a5, int m_xor_size1, int m_xor_size2, int &a8)
{
    int m_verification, v55;
    short v42;
    char m_unk1;

    this->Unk32  = m_xor_size1;
    this->Unk32 ^= m_xor_size2;
    m_pack.Unk36 = 9000;

    if(this->Unk32 > MAX_MSG_LENGTH)
    {
        printf("Protocol's Len:%d > MAX_MSG_LENGTH", this->Unk32);
        a8 = this->Unk32;
        return -12;
    }

    if(this->Unk32 <= 0)
    {
        printf("Protocol's Len:%d <= 0", this->Unk32);
        a8 = this->Unk32;
        return -9;
    }

    if(m_pack.BPack.BufLen() < this->Unk32)
        return 0;

    if(m_pack.BPack.BufLen() > this->Unk32)
    {
        printf("receive data's Len:%d > Protocol's Len:%d", m_pack.BPack.BufLen(), this->Unk32);
        a8 = m_pack.BPack.BufLen();
        return -10;
    }

    m_pack.Unk36 = 10000;
    m_verification = m_pack.VerifyAll(m_xor_size1, a4, this->Unk32, a8);

    if(m_verification != 1)
        return m_verification;

    /*** ........ ***/

    m_pack.Unk36 = 11000;
    if(!m_pack.BPack.Skip(25))
    {
        a8 = -11;
        return -11;
    }

    m_pack.BPack >> m_unk1;
    if(m_unk1 == -3)
    {
        this->Unk40 = 1;
    }
    else
    {
        if(m_unk1 != -2)
        {
            /*** ........ ***/
            return -23;
        }

        this->Unk40 = 0;
    }
#ifdef __DEBUG__COMPILE__
    if(CProtocol::m_bProfile)
    {
        Lock(&g_csZipProfileLock);
        ++dword_1003F654;
        UnLock(&g_csZipProfileLock);
    }

    if(!this->Unk40)
    {
        if(CProtocol::m_bProfile)
        {
            Lock(&g_csZipProfileLock);
            ++dword_1003F658;
            UnLock(&g_csZipProfileLock);
        }

LABEL_65:
        m_pack.Unk36 = 15000;

        /*** ........ ***/

        m_pack.Unk36 = 16000;
        //if ( v59 > -12 )
        {
            if(!this->Unk40)
            {
                m_pack.BPack >> v42;
                v55 = m_pack.BPack.WSize(); // RSize() == WSize()
            }

            m_pack.Unk36 = 17000;
            if(v55 >= 0 && v55 == this->Unk32)
            {
                //*(_DWORD *)a3 = v56;
                m_protocol->Unk32 = this->Unk32;
                m_protocol->Unk36 = a8;
                m_pack.Unk36 = 18000;
                return v55;
            }
            else
            {
                /*** ........ ***/

                a8 = v55;
                return -13;
            }
        }
        //else
        {
            /*** ........ ***/
        }
    }

    /*** ........ ***/
#endif
    return 0;
}
