#ifndef ZIPPROFILE_H
#define ZIPPROFILE_H

class CZipProfile
{
public:
    long Unk0, Unk4, Unk8, Unk12, Unk16, Unk20, Unk24, Unk28, Unk32, Unk36, Unk40, Unk44, Unk48; // +0, +4, +8, +12, +16, +20, +24, +28, +32, +36, +40, +44, +48
public:
    CZipProfile();
    CZipProfile(CZipProfile const &m_zip_profile);

#ifdef __DEBUG__COMPILE__
    class CZipProfile &operator=(class CZipProfile const &m_zip_profile);
#endif

    void Reset(void);
};

#endif // ZIPPROFILE_H
