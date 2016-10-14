#include "Package.h"

char byte_1003F190[50][21] =
{
	"8sdk32cs90d8a6215xg3", "2334546dgfdf6215hxg3",
	"dgf345dghj6773232xg9", "c45bnnxs90dsdfax5xg6",
	"9873lkjghdjklo9gscg5", "67flaiwlthsixxiqaxg8",
	"8sdk32cs90d8a6215xg6", "s2sdfggfhgjhklioy61d",
	"4fgyyuiuiojklwkwss7d", "4tnhjggsgjkkljkfixfa",
	"1a6212cs90d8a6215xg3", "5621546dgfdf6215hxg3",
	"373235dghj6773232xg9", "xdfaxnxs90dsdfax5xg6",
	"glo9gkjghdjklo9gscg5", "qxaaqiwlyhssxxiqaxu8",
	"1a6212cs90d8a6215xg6", "oklioggfhgjhklioy61d",
	"wlwkwuiuiojklwkwss7d", "fljkfggsgjkkljkfixfa",
	"cs9k32cs90d8a6215xg3", "6dg4546dgfdf6215hxg3",
	"dgh345dghj6773232xg9", "xs9bnnxs90dsdfax5xg6",
	"jgh3lkjghdjklo9gscg5", "wltlaiwlthsixxiqaxg8",
	"cs9k32cs90d8a6215xg6", "gfhdfggfhgjhklioy61d",
	"iuiyuuppiojkuwkvss7d", "gsghjggsgjkkljkfixfa",
	"9sdk32cs90d8a62cs9g3", "g334546dgfdf6216dgg3",
	"hgf345dghj67732dghg9", "945bnnxs90dsdfaxs9g6",
	"h873lkjghdjklo9jghg5", "t7flaiwlthsixxiwltg8",
	"9sdk32cs90d8a62cs9g6", "h2sdfggfhgjhkligfh1d",
	"ifgyyuiuiojklwkiui7d", "gtnhjggsgjkkljkgsgfa",
	"dsdk32cs90d8cs915xg3", "d334546dgfdf6dg5hxg3",
	"6gf345dghj67dgh32xg9", "d45bnnxs90dsxs9x5xg6",
	"j873lkjghdjkjghgscg5", "s7flaiwlthsiwltqaxg8",
	"dsdk32cs90d8cs915xg6", "j2sdfggfhgjhgfhoy61d",
	"jfgyyuiuiojkiuiwss7d", "ktnhjggsgjkkgsgfixfa"
};

CPackage::CPackage(char *m_data, int m_size, short a4, char a5)
{
    this->BPack = CBPack(m_data, m_size);

    this->Unk12 = 0;
    this->Unk16 = 1;
    this->Unk20 = 0;
    this->Unk24 = a4;
    this->Unk26 = a5;
    this->Unk28 = 0;
    this->Unk32 = 0;
    this->Unk36 = 0;

    if(a5 == 58)
    {
        this->Unk16 = 58;
        this->Unk12 = 168168;
    }
}

int CPackage::GetCheckSumLen(void)
{
  if(this->Unk26)
  {
      if(this->Unk26 == 1 || this->Unk26 == 58)
          return 21;
  }

  return 5;
}

void CPackage::GenerateKey(short m_restored_key)
{
    this->Unk20 = m_restored_key;
    this->Unk20 = m_restored_key | (this->Unk20 << 16);
    this->Unk20 ^= this->Unk26 << 8;
}

unsigned short CPackage::RestoreKey(void)
{
    unsigned short m_restored_key;

    if(this->BPack.PackSize >= 8)
    {
        memcpy(&m_restored_key, this->BPack.PackData + this->BPack.PackSize - sizeof(short), sizeof(short));
        m_restored_key ^= this->Unk26;
        this->GenerateKey(m_restored_key);

        return m_restored_key;
    }

    return 0;
}

int CPackage::VerifyAll(int &a2, unsigned short &Src, int Size, int &a5)
{
    unsigned short m_key = this->RestoreKey(), v12;
    long Dst, v14;
    char *v16, v15;

    if((m_key <= Src) && (m_key || Src != 65535))
    {
        printf("Serial Number Error...");
        a5 = m_key;
        return -3;
    }

    Src = m_key;

    memcpy(this->BPack.PackData + this->BPack.PackSize - sizeof(short), &Src, sizeof(short));
    memcpy(&Dst, this->BPack.PackData + 12, sizeof(long));

    Dst ^= this->Unk20;

    memcpy(this->BPack.PackData + 12, &Dst, sizeof(long));
    memcpy(&this->Unk26, this->BPack.PackData + 16, sizeof(char));

    if(Dst != this->GetCheckSumLen())
    {
        printf("Reading CProtocol's ID , Length , CheckSum Failed...");
        a5 = Dst;
        return -2;
    }

    memcpy(&a2, this->BPack.PackData + 4, sizeof(long));
    a2 ^= this->Unk20;

    memcpy(this->BPack.PackData + 4, &a2, sizeof(long));
    v12 = (a2 & 0xFFFF0000) >> 16;
    a2 &= 0xFFFF;

    if(v12 != this->Unk24)
    {
        a5 = v12;
        return -8;
    }

    v16 = (char *)malloc(Dst);
    memcpy(v16, this->BPack.PackData + 16, Dst);

    //v18 = 0;

    if(this->Unk26 != this->Unk16)
    {
        if(v16)
            delete v16;

        a5 = this->Unk26;
        return -4;
    }

    memcpy(this->BPack.PackData + 8 , &Size, sizeof(long));
    memset(this->BPack.PackData + 12, 0,     sizeof(long));
    memset(this->BPack.PackData + 16, 0,     Dst);

    v14 = 0;
    v15 = *(char *)&Src;

    for(long i = 37; i < Size - 2; ++i)
    {
        this->BPack.PackData[i] ^= v15;
        this->BPack.PackData[i] ^= byte_1003F190[v12][v14++];

        if(v14 >= 20)
            v14 = 0;
    }

#ifdef DUMP_DATA
    FILE *m_file = fopen("dump.txt", "wb");
    fwrite(this->BPack.PackData, this->BPack.PackSize, 1, m_file);
    fclose(m_file);
#endif // DUMP_DATA

    /*** .... SHA ... ***/

    return 1;
}
