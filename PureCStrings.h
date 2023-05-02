//
// Created by tobin on 4/29/2023.
//

#ifndef TEXTRPG_PURECSTRINGS_H
#define TEXTRPG_PURECSTRINGS_H
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#endif //TEXTRPG_PURECSTRINGS_H


typedef struct PureString{
    char * characters;
} PureString ;

typedef enum StringFlags{
    SF_NONE = 0,
    SF_IGNORECASE = 1 << 0,   // bit 0
} StringFlags;

PureString *PureString_Create(const char *initial);
PureString *PureString_CreateEmpty(unsigned int length);

void *MallocLog(size_t size, const char *message);

void PureString_Concatenate(PureString *ps, const char *addition, size_t length);
void PureString_Copy(PureString *dest, PureString *source, unsigned int offset);
void PureString_Destroy(PureString * ps);
void PureString_RemoveRange(PureString *ps, unsigned int start, unsigned int end);
void PureString_Replace(PureString *ps, char *from, char *to, StringFlags sf);
void PureString_ReplaceChar(PureString *ps, char from, char to, StringFlags flags);
void PureString_Substring(PureString *ps, unsigned int start, unsigned int end);
void PureString_ToLower(PureString *ps);
void PureString_ToUpper(PureString *ps);
void PureString_Trim(PureString *ps, unsigned int index);

unsigned int PureString_Length(PureString *string);
unsigned int PureString_Contains(PureString *aString, const char *sub, StringFlags flag);
