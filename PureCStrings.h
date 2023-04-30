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
