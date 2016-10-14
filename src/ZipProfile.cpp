#include "ZipProfile.h"

CZipProfile::CZipProfile(void)
{
    this->Reset();
}

CZipProfile::CZipProfile(CZipProfile const &m_zip_profile)
{
    this->Unk0  = m_zip_profile.Unk0;
    this->Unk4  = m_zip_profile.Unk4;
    this->Unk8  = m_zip_profile.Unk8;
    this->Unk12 = m_zip_profile.Unk12;
    this->Unk16 = m_zip_profile.Unk16;
    this->Unk20 = m_zip_profile.Unk20;
    this->Unk24 = m_zip_profile.Unk24;
    this->Unk28 = m_zip_profile.Unk28;
    this->Unk32 = m_zip_profile.Unk32;
    this->Unk36 = m_zip_profile.Unk36;
    this->Unk40 = m_zip_profile.Unk40;
    this->Unk44 = m_zip_profile.Unk44;
    this->Unk48 = m_zip_profile.Unk48;
}

void CZipProfile::Reset(void)
{
    this->Unk0  = 0;
    this->Unk4  = 0;
    this->Unk8  = 0;
    this->Unk12 = 0;
    this->Unk16 = 0;
    this->Unk20 = 0;
    this->Unk24 = 0;
    this->Unk28 = 0;
    this->Unk32 = 0;
    this->Unk36 = 0;
    this->Unk40 = 0;
    this->Unk44 = 0;
    this->Unk48 = 0;
}

#ifdef __DEBUG__COMPILE__
class CZipProfile &CZipProfile::operator=(class CZipProfile const &m_zip_profile)
{
    if(&m_zip_profile != *this)
    {
        this->Unk0  = m_zip_profile.Unk0;
        this->Unk4  = m_zip_profile.Unk4;
        this->Unk8  = m_zip_profile.Unk8;
        this->Unk12 = m_zip_profile.Unk12;
        this->Unk16 = m_zip_profile.Unk16;
        this->Unk20 = m_zip_profile.Unk20;
        this->Unk24 = m_zip_profile.Unk24;
        this->Unk28 = m_zip_profile.Unk28;
        this->Unk32 = m_zip_profile.Unk32;
        this->Unk36 = m_zip_profile.Unk36;
        this->Unk40 = m_zip_profile.Unk40;
        this->Unk44 = m_zip_profile.Unk44;
        this->Unk48 = m_zip_profile.Unk48;
    }

    return *this;
}
#endif
