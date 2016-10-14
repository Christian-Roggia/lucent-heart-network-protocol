#ifndef PACKAGE_H
#define PACKAGE_H

#include <malloc.h>
#include <stdio.h>
#include <fstream>

#include "BPack.h"

using namespace std;

extern char byte_1003F190[50][21];

class CPackage {
public:
    CBPack BPack;               // +0
    long Unk12, Unk16, Unk20;   // +12, +16, +20
    short Unk24;                // +24
    char Unk26;                 // +26
    long Unk28, Unk32, Unk36;   // +28, +32, +36
public:
    CPackage(char *m_data, int a3, short a4, char a5);

    int GetCheckSumLen(void);
    void GenerateKey(short m_restored_key);
    unsigned short RestoreKey(void);
    int VerifyAll(int &a2, unsigned short &Src, int Size, int &a5);
};

#endif // PACKAGE_H
