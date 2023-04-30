//
// Created by tobin on 4/29/2023.
//

#include "PureCStrings.h"


#define var __auto_type

int PureStringDoLogging = 0;

/// Performs a malloc with a helpful log message that the user puts in
/// \param size The size of the allocation
/// \param message The message to be logged
/// \return Same as malloc, may return null same as malloc but will printf

void *MallocLog(const size_t size, const char *message) {
    var dat = malloc(size);

    printf("Allocating for \"%s\" (%zu) \n", message, size);
    if (dat == NULL) {
        printf("Ran outta memory on %s", message);
    }

    return dat;
}

/// Gets the length of the purestring, this is the same as strlen(string->characters)
/// \param string
/// \return length of the string
unsigned int PureString_Length(PureString *string) {
    return strlen(string->characters);
}

/// Concatenates to the end of a purestring with the char * addition
/// \param ps
/// \param addition
/// \param length
void PureString_Concatenate(PureString *ps, const char *addition, size_t length) {
    if (length == 0) {
        length = strlen(addition);
        if (length == 0) {
            return;
        }
    }

    size_t increasedSize = length + 1;

    //ex.
    // imagine ps->characters = "1234567890\0"
    // imagine addition = "12345\0"
    // we want the size of the character at 0, to get its type more or less, so we are using chars now but we could switch
    // we do the length of the addition, which would be 4, (null term doesnt get included)
    // we do 1 * (10 + 4 + 1)
    // that gives us the legit size
    ps->characters = realloc(ps->characters, sizeof(ps->characters[0]) * (PureString_Length(ps) + increasedSize));

    unsigned int start = PureString_Length(ps);

    //Idk if this is as quick as strcpy but it seemed about the same, and this is a bit more readable
    //Go thru and assign the chars
    for (unsigned int i = start; i < start + increasedSize; i++) {
        ps->characters[i] = addition[i - start];
    }
}

/// Copies from source to destination, offset of 0 means a direct copy, an offset of any more, copies with a shift to the right
/// dest[0 + n] = src[0]
/// \param aString
/// \param bString
void PureString_Copy(PureString *dest, PureString *source, const unsigned int offset) {

    unsigned int srcLength = PureString_Length(source);

    //we need to expand the string so malloc some new
    char *dat;
    if (PureStringDoLogging) {
        dat = MallocLog(srcLength, "Pure string copy dat is no good");
    } else {
        dat = malloc(srcLength);
    }

    //Set the data to just be ' '
    memset(dat, ' ', srcLength);

    //Add the extra room onto the end
    PureString_Concatenate(dest, dat, 0);

    //Free it
    free(dat);

    //Loop thru the characters
    int i;
    for (i = 0; i < PureString_Length(source); i++) {
        //Set the destination character (+ offset) to the corresponding i value
        dest->characters[i + offset] = source->characters[i];
    }

    //Make sure to add null terminating char
    dest->characters[i + offset] = '\0';
}

/// Returns the index of the substring, -1 if it failed to get anything
/// \param aString
/// \param sub
/// \return
unsigned int PureString_Contains(PureString *aString, const char *sub, StringFlags flag) {
    int ignoreCase = flag & SF_IGNORECASE;

    char *dest;
    unsigned int pos = -1;

    if (!ignoreCase) {
        dest = strstr(aString->characters, sub);
        pos = dest - aString->characters;
    } else {

        var ps = PureString_Create(aString->characters);
        PureString_ToLower(ps);

        char * subClone;

        int sLen = strlen(sub);

        subClone = malloc(sLen + 1);
        subClone[sLen] = '\0';

        for(int i = 0; i < sLen; i++){
            subClone[i] = tolower(sub[i]);
        }

        dest = strstr(ps->characters, subClone);

        pos = dest - ps->characters;

        free(subClone);
        PureString_Destroy(ps);
    }

    if (dest == NULL) {
        return -1;
    }

    return pos;
}

void PureString_ToUpper(PureString *ps) {
    int len = PureString_Length(ps);
    for (int i = 0; i < len; i++) {
        ps->characters[i] = toupper(ps->characters[i]);
    }
}

void PureString_ToLower(PureString *ps) {
    int len = PureString_Length(ps);
    for (int i = 0; i < len; i++) {
        ps->characters[i] = tolower(ps->characters[i]);
    }
}

/// Creates a new purestring with the initial data
/// \param initial
/// \return
PureString *PureString_Create(const char *initial) {

    PureString *ps;

    //we do +1 cuz null terminating char
    size_t initialSize = strlen(initial) + 1;

    //Malloc the ps and its characters
    if (PureStringDoLogging) {
        ps = MallocLog(sizeof(PureString), "Purestring malloc");
        ps->characters = MallocLog(initialSize, "Characters malloc");
    } else {
        ps = malloc(sizeof(PureString));
        ps->characters = malloc(initialSize);
    }

    //if we are initializing with "" or the like
    if (initialSize == 1) {
        ps->characters[0] = '\0';
    }
        //We have a regular char * input
    else {
        for (int i = 0; i < initialSize; i++) {
            ps->characters[i] = initial[i];
        }
    }

    return ps;
}

/// Trims a string at the index, trims everything to the right of the character at index. Done inclusively
/// \param ps
/// \param index Imagine this as the number of characters that actually gets displayed
void PureString_Trim(PureString *ps, const unsigned int index) {
    var newLen = (index);

    //If its zero,do this so we don't realloc a length of zero
    if (newLen == 0) {
        ps->characters = NULL;
        return;
    }

    //If theyre the same, then its not gonna do anything
    if (newLen == PureString_Length(ps)) {
        return;
    }

    // Realloc is beautiful, this'd be a pain without realloc
    ps->characters = realloc(ps->characters, sizeof(ps->characters[0]) * newLen);
    ps->characters[newLen] = '\0';
}

/// Removes the range from start to end
/// \param ps
/// \param start inclusive
/// \param end exclusive
void PureString_RemoveRange(PureString *ps, const unsigned int start, const unsigned int end) {

    const unsigned int oldLen = PureString_Length(ps);

    //printf("%d", oldLen);

    if (start < 0 || start > oldLen || end < 0 || end > oldLen) {
        return;
    }

    if (oldLen == 0) {
        return;
    }

    const unsigned int newLen = oldLen - (end - start);

    //Allocate the new string
    size_t size = (sizeof(ps->characters[0]) * newLen) + 1;

    char *newDat;

    if (PureStringDoLogging) {
        newDat = MallocLog(size, "Remove range malloc");
    } else {
        newDat = malloc(size);
    }

    //End of allocating new string

    unsigned int skipped = 0;

    for (unsigned int i = 0; i < oldLen; i++) {
        //If its within start and end increment skip
        if (i >= start && i < end) {
            skipped++;
        }
            //Otherwise, add the data - skipped
        else {
            newDat[i - skipped] = ps->characters[i];
        }
    }

    newDat[newLen] = '\0';

    //Free and assign the new data
    free(ps->characters);
    ps->characters = newDat;
}

/// Frees the purestring and its characters, use this for destroying purestrings
/// \param ps
void PureString_Destroy(PureString *ps) {
    free(ps->characters);
    free(ps);
}

/// Removes a range from start (inclusive) to end (exclusive)
/// \param ps
/// \param start inclusive start
/// \param end exclusive end
void PureString_Substring(PureString *ps, const unsigned int start, const unsigned int end) {
    var newLen = (end - start);

    //If its zero,do this so we don't realloc a length of zero
    if (newLen == 0) {
        ps->characters = NULL;
        return;
    }

    //Out of bounds check
    if (start >= end || end >= PureString_Length(ps) || start < 0) {
        return;
    }

    var oldLen = PureString_Length(ps);

    //If theyre the same, then its not gonna do anything
    if (newLen == oldLen) {
        return;
    }


    //Allocate the new string
    size_t size = sizeof(ps->characters[0]) * newLen + 1;
    char *array_temporaryString;

    if (PureStringDoLogging) {
        array_temporaryString = MallocLog(size, "Substring range malloc");
    } else {
        array_temporaryString = malloc(size);
    }
    //End of allocating new string

    //Go thru the current characters within these bounds, write that into the temporary string from 0
    for (unsigned int i = start; i < end; i++) {
        // [i - start]
        array_temporaryString[i - start] = ps->characters[i];
    }

    //We can free this because it will be replaced
    free(ps->characters);

    //Do the replacing and set the null term character
    ps->characters = array_temporaryString;
    ps->characters[newLen] = '\0';
}

/// Replaces all of the [from] characters with the [to] characters
/// \param ps the purestring this should be done on
/// \param from the value to be changed
/// \param to the value to replace instances of from
/// \param flags Only supports SF_IGNORECASE, otherwise just to SF_NONE
void PureString_ReplaceChar(PureString *ps, char from, char to, StringFlags flags) {
    var len = PureString_Length(ps);

    //Get the flag
    int ignoreCase = 0;
    if (flags & SF_IGNORECASE) {
        ignoreCase = 1;
    }

    //Loop thru each char
    for (int i = 0; i < len; i++) {
        //If we are ignoring the case, get them both in lower and compare that
        if (ignoreCase) {
            if (tolower(ps->characters[i]) == tolower(from)) {
                ps->characters[i] = to;
            }
        }
            //Otherwise just get the case
        else {
            if (ps->characters[i] == from) {
                ps->characters[i] = to;
            }
        }
    }
}

/// Replace the from characters with the to characters TODO array isnt resized with larger value of to, segfault. Also pretty slow, look into regex perhaps
/// \param ps
/// \param from The string to be replaced
/// \param to The string to replace from with
/// \param sf only SF_IGNORECASE works

void PureString_Replace(PureString *ps, char *from, char *to, StringFlags sf) {
    unsigned int ignoreCase = sf & SF_IGNORECASE;
    unsigned int len = PureString_Length(ps);
    unsigned int fromLen = strlen(from);
    unsigned int toLen = strlen(to);

    int instancesOfFrom = 0;

    //Iterate through each character
    for (unsigned int i = 0; i < len; i++) {

        //If its out of bounds
        if (i + fromLen > len) {
            break;
        }

        char *selected = malloc(sizeof(ps->characters[0]) * fromLen);
        for (unsigned int v = 0; v < fromLen; v++) {
            selected[v] = ps->characters[i + v];
        }

        int match = 0;
        if (ignoreCase) {
            //If the compare fails then match = 0, otherwise it = 1
            match = strncasecmp(selected, from, fromLen) == 0;
        } else {
            match = strncmp(selected, from, fromLen) == 0;
        }

        if (match) {
            instancesOfFrom++;

            //Calculate new string length
            unsigned int diff = toLen - fromLen;
            unsigned int newLen = len + diff * instancesOfFrom;

            //Allocate the newdat string
            char *newDat;
            if (PureStringDoLogging) {
                newDat = MallocLog(sizeof(ps->characters[0]) * newLen + 1, "Replace malloc");
            } else {
                newDat = malloc(sizeof(ps->characters[0]) * newLen + 1);
            }

            //Copy from the characters to the new dat with the length of i
            strncpy(newDat, ps->characters, i);
            newDat[i] = '\0';

            //Concatenate the replacement string
            strcat(newDat, to);

            //Concatenate the part that should be after the replacement string
            strcat(newDat, ps->characters + i + fromLen);

            //Free and re-assign
            free(ps->characters);
            ps->characters = newDat;
            len = newLen;
        }

        free(selected);
    }
}

//PureString **PureString_Split(PureString *ps, const char *separator, int *count) {
//
//    int numSplits = 0;
//    int len = PureString_Length(ps);
//    int sepLen = strlen(separator);
//
//    if(strstr(ps->characters, separator) == NULL){
//        return NULL;
//    }
//
//    int *indices = malloc(100);
//
//    for (int c = 0; c < len - sepLen + 1; c++) {
//        if (*strstr(ps->characters + c, separator) == ps->characters[c]) {
//            indices = realloc(indices, (numSplits + 1) * sizeof(int));
//            indices[numSplits] = c;
//            numSplits++;
//            c += sepLen;
//        }
//    }
//
//    if (numSplits == 0) {
//        *count = 0;
//    } else {
//        *count = numSplits - 1;
//    }
//
//    PureString **array_newStrings = malloc(sizeof(PureString) * (numSplits + 1));
//
//    int iterator = 0;
//    for (int i = 0; i < len - 1; i++) {
//
//        if (i == indices[iterator]) {
//
//
//            int diff = indices[iterator + 1] - indices[iterator];
//            char *sub = malloc(diff + 1);
//
//            //printf("diff : %d\n", diff);
//
//            strncpy(sub, ps->characters + indices[iterator] + 1, diff);
//            sub[diff] = '\0';
//
//            array_newStrings[iterator] = PureString_Create(sub);
//
//            iterator++;
//
//            free(sub);
//        }
//    }
//
//    return array_newStrings;
//}