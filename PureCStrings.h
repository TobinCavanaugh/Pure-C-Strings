//
// Created by tobin on 4/29/2023.
//

#ifndef TEXTRPG_PURECSTRINGS_H
#define TEXTRPG_PURECSTRINGS_H

#endif //TEXTRPG_PURECSTRINGS_H


typedef struct PureString{
    char * characters;
} PureString ;

typedef enum StringFlags{
    SF_NONE = 0,
    SF_IGNORECASE = 1 << 0,   // bit 0
} StringFlags;

void *MallocLog(size_t size, const char *message);
unsigned int PureString_Length(PureString *string);
void PureString_Concatenate(PureString *ps, const char *addition, size_t length);
void PureString_Copy(PureString *dest, PureString *source, unsigned int offset);
unsigned int PureString_Contains(PureString *aString, const char *sub);
PureString *PureString_Create(const char *initial);
void PureString_Trim(PureString *ps, unsigned int index);
void PureString_RemoveRange(PureString *ps, unsigned int start, unsigned int end);
void PureString_Destroy(PureString * ps);
void PureString_Substring(PureString *ps, unsigned int start, unsigned int end);
void PureString_ReplaceChar(PureString *ps, char from, char to, StringFlags flags);