#include "BPack.h"

CBPack::CBPack(void)
{
    this->PackData    = 0;
    this->PackSize    = 0;
    this->PackPointer = 0;
}

CBPack::CBPack(char *pData, int nSize)
{
    this->PackData    = pData;
    this->PackSize    = nSize;
    this->PackPointer = 0;
}

#define MACRO_SHIFT_RIGHT_TEMPLATE(t) \
{ \
	t temp_dest; \
    if(this->PackPointer + sizeof(t) > this->PackSize) \
        return *this; \
\
    memcpy(&temp_dest, this->PackData + this->PackPointer, sizeof(t)); \
    dest = temp_dest; \
\
    this->PackPointer += sizeof(t); \
\
    return *this; \
}

class CBPack &CBPack::operator>>(long &dest)
{
    MACRO_SHIFT_RIGHT_TEMPLATE(long)
}

class CBPack &CBPack::operator>>(int &dest)
{
    MACRO_SHIFT_RIGHT_TEMPLATE(int)
}

class CBPack &CBPack::operator>>(short &dest)
{
    MACRO_SHIFT_RIGHT_TEMPLATE(short)
}

class CBPack &CBPack::operator>>(char &dest)
{
    MACRO_SHIFT_RIGHT_TEMPLATE(char)
}

int CBPack::BufLen(void)
{
    return this->PackSize;
}

bool CBPack::Skip(int nSkip)
{
    if(nSkip >= 0 && nSkip + this->PackPointer <= this->PackSize)
    {
        if(nSkip)
            this->PackPointer += nSkip;

        return true;
    }

    this->PackSize = -1;
    return false;
}

int CBPack::WSize(void)
{
    return this->PackSize == -1 ? -1 : this->PackPointer;
}
