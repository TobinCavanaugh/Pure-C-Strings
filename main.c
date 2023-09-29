#include "PureCStrings.h"
#include <stdio.h>
#include "PureStringTests.h"

int main() {

    Test();

//    // Creating a purestring, note the initial text \/
//    PureString * ps = PureString_Create("Starting-Text");
//    printf("%s\n", ps->characters);
//
//    // Trim from index 8 and onwards
//    PureString_Trim(ps,8);
//    printf("%s\n", ps->characters);
//
//    // Add on !!! to the end of the string, note the length of 0, this means it will
//    // automatically determine the length of the addition
//    PureString_Concatenate(ps, "!!!zZ", 0);
//    printf("%s\n", ps->characters);
//
//    // Replace the character z with ?, note the use of SF_NONE, meaning that case IS
//    // accounted for, the alternate is to use SF_IGNORECASE
//    PureString_ReplaceChar(ps, 'z', '?', SF_NONE);
//    printf("%s\n", ps->characters);
//
//    // Remove the last 3 digits of the string
//    unsigned int length = PureString_Length(ps);
//    PureString_RemoveRange(ps, length - 3, length);
//    printf("%s\n", ps->characters);
//
//    // Print out the where "St" is found, if it fails, it prints -1, note the IgnoreCase
//    // string flag which means that neither the case of ps->characters nor sub matter
//    unsigned int index = PureString_Contains(ps, "Ti", SF_IGNORECASE);
//    printf("%d\n", index);
//
//    // Converts it to upper case
//    PureString_ToUpper(ps);
//    printf("%s\n", ps->characters);

    return 0;
}
