//
// Created by tobin on 9/3/2023.
//

#include "PureStringTests.h"
#include "PureCStrings.h"

#define var __auto_type

void Test() {
    {
        printf("Test of string creation and concatenation: ");
        var test0 = PureString_Create("AAA");
        PureString_Concatenate(test0, "BBB", 3);
        var test1 = PureString_Create("AAABBB");
        printf("%d\n", PureString_Equals(test0, test1));
    }

    {
        printf("Test of copying. No offset: ");
        var test0 = PureString_Create("1234567890");
        var copy = PureString_Create("");
        PureString_Copy(copy, test0, 0);
        printf("%d\n", PureString_Equals(test0, copy));
    }

    {
        printf("Test of copying, with negative offset: ");
        var test0 = PureString_Create("abcdef");
        var offset = PureString_Create("");
        PureString_Copy(offset, test0, -2);

        var final = PureString_Create("cdef");
        printf("%d\n", PureString_Equals(final, offset));
    }

    {
        printf("Test of copying, with positive offset: ");

        var test0 = PureString_Create("xyz");
        var offset = PureString_Create("");
        PureString_Copy(offset, test0, 3);

        var final = PureString_Create("   xyz");
        printf("%d\n", PureString_Equals(final, offset));
    }

    {
        printf("Char replacement test: ");

        var test0 = PureString_Create("A B C D E F G H I ");
        var test1 = PureString_Create("A,B,C,D,E,F,G,H,I,");

        PureString_ReplaceChar(test0, ' ', ',', SF_NONE);

        printf("%d\n", PureString_Equals(test0, test1));
    }

    {
        printf()
    }

//    {
//        printf("String replacement test: ");
//
//        var test0 = PureString_Create("abc abc acb 124 wakdnajw acb");
//        var final = PureString_Create("Z Z Z 124 wakdanjw Z");
//
//        PureString_Replace(test0, "abc", "Z", SF_NONE);
//
//        printf("%d\n", PureString_Equals(test0,final));
//
//        printf("");
//    }
}