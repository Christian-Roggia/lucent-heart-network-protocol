#ifndef BPACK_H
#define BPACK_H

#include "memory.h"

class CBPack {
public:
    char *PackData;             // +0
    int PackSize, PackPointer;  // +4, +8
public:
    CBPack(void); // -_- necessary
    CBPack(char *m_data, int m_size);

    class CBPack &operator>>(long &m_dest);
    class CBPack &operator>>(int &m_dest);
    class CBPack &operator>>(short &m_dest);
    class CBPack &operator>>(char &m_dest);

    int BufLen(void);
    bool Skip(int m_skip);
    int WSize(void);
};

#endif // BPACK_H
