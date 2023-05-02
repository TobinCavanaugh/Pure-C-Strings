# Pure-C-Strings
A simple .c and .h file for making mutable strings in pure C

Pure C Strings using char arrays inside of a special struct named PureString.

The main concept is to create a system of easy to mutate strings, that is reasonably quick and effective.

Everything has been manually tested, though NOT unit tested. I am aware of some bugs surrounding the PureString_Replace method, and its also dirt slow, so be wary with that one. PureString_ReplaceChar is plenty fast though.

If weird stuff is happening and you need to see whats getting malloced before the crash, set PureStringDoLogging equal to 1, and this will print out all the mallocs I do, as well as their size or if its running out of memory.

## Example:

```
#include "PureCStrings.h"
#include <stdio.h>

int main() {

    // Creating a purestring, note the initial text \/
    PureString * ps = PureString_Create("Starting-Text");
    printf("%s\n", ps->characters);

    // Trim from index 8 and onwards
    PureString_Trim(ps,8);
    printf("%s\n", ps->characters);

    // Add on !!! to the end of the string, note the length of 0, this means it will
    // automatically determine the length of the addition
    PureString_Concatenate(ps, "!!!zZ", 0);
    printf("%s\n", ps->characters);

    // Replace the character z with ?, note the use of SF_NONE, meaning that case IS
    // accounted for, the alternate is to use SF_IGNORECASE
    PureString_ReplaceChar(ps, 'z', '?', SF_NONE);
    printf("%s\n", ps->characters);

    // Remove the last 3 digits of the string
    unsigned int length = PureString_Length(ps);
    PureString_RemoveRange(ps, length - 3, length);
    printf("%s\n", ps->characters);

    // Print out the where "St" is found, if it fails, it prints -1, note the IgnoreCase
    // string flag which means that neither the case of ps->characters nor sub matter
    unsigned int index = PureString_Contains(ps, "Ti", SF_IGNORECASE);
    printf("%d\n", index);

    // Converts it to upper case
    PureString_ToUpper(ps);
    printf("%s\n", ps->characters);

    return 0;
}
```
```
Starting-Text
Starting     
Starting!!!zZ
Starting!!!?Z
Starting!!   
4            
STARTING!!   
```

## Methods
<img src="https://raw.githubusercontent.com/TobinCavanaugh/Pure-C-Strings/master/gitpage/header.png" height="500" />


## Types
<img src="https://raw.githubusercontent.com/TobinCavanaugh/Pure-C-Strings/master/gitpage/typedef.png?token=GHSAT0AAAAAACBV3GXMU5V7DLZVXKO2635CZCO4OMQ" height="350" />

## Building With Pure C Strings

My CMake File just looks like this, I just put the .c and .h files directly into the folder where my main.c file is. You probably know more about including and linking than I do, and it should be a simple process.
```
cmake_minimum_required(VERSION 3.25)
project(PureCStrings C)

set(CMAKE_C_STANDARD 11)

add_executable(PureCStrings main.c PureCStrings.c)
```

## Performance
Overall PureCStrings should be pretty fast. In my benchmarks I got acceptable results for everything but ReplaceChar, this is a known issue and will be fixed when I feel like it.

Heres the benchmark I got, you can run this by including Benchmark.c and running it by calling BenchMark() with an arg of an unsigned int. 

In my benchmark I did 10000 iterations with a string about 1800 characters long.
(time in ms, lower is better)
<img src="https://raw.githubusercontent.com/TobinCavanaugh/Pure-C-Strings/master/gitpage/benchmark.png?token=GHSAT0AAAAAACBV3GXNDUXDR4PKBG75GQWGZCO4OLA" height="350" />

This benchmark isn't very thorough and I'd recommend benchmarking this yourself to see if it would fit your needs.



