//
//  VCLFunctions.h
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/12.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#ifndef VCLCppWorkshop_VCLFunctions_h
#define VCLCppWorkshop_VCLFunctions_h

#include <math.h>

namespace VCL {

    inline void swap(int& left, int& right)
    {
        left ^= right ^= left ^= right;
    }

    template <typename T>
    inline void swapObjects(T* left, T* right)
    {
        T tmp = *left;
        *left = *right;
        *right = tmp;
    }

    inline void toggleToCamel(char* camel, const char* toggle)
    {
        bool prevWordUpper = toggle[0] < 'a';
        char toLowerNumber = 'a' - 'A';

        long int index = 0;
        while (toggle[index] != '\0') {

            char c = toggle[index];
            bool toggleHead = (c >= 'a') ? prevWordUpper : !prevWordUpper;

            bool shifter = 0;
            shifter = (c >= 'a' && toggleHead) ? - toLowerNumber : shifter;
            shifter = (c >= 'a' && !toggleHead) ? toLowerNumber : shifter;

            camel[index++] = c + shifter;
            prevWordUpper = c < 'a';
        }

        camel[index] = '\0';
    }

    typedef union
    {
        struct { unsigned char r,g,b; };
        unsigned char v[3];

    } VCLRGB;

    inline VCLRGB webColorFromString(const char* colorCode)
    {
        if (strlen(colorCode) != 6) {
            return VCLRGB();
        }

        VCLRGB color = {0,0,0};

        int colorIndex = 0;
        for  (int i = 0; i < 6; i +=2) {
            char colorStr[2] = { colorCode[i], colorCode[i+1] };

            int value = 0;
            sscanf(colorStr, "%x", &value);

            color.v[colorIndex++]  = static_cast<unsigned char>(value);
        }

        return color;
    }

}

typedef unsigned long long u64;

inline u64 searchPrimeNumbers(u64* primeNumbers, u64 min, u64 max)
{
    u64 count = 0;

    if (max < min || max <= 1) { return 0; }

    if (min == 1) {
        min += 2;
        primeNumbers[count++] = 1;
    }

    if (min > 2 && min % 2 == 0) { ++min; }
    if (max > 2 && max % 2 == 0) { --max; }

    for(u64 i = min; i <= max; i += 2)
    {
        u64 chkMax = static_cast<u64>(sqrt(i));
        bool isPrime = true;
        for(u64 j = min; j <= chkMax; j += 2)
        {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime) {
            primeNumbers[count++] = i;
        }
    }

    return count;
}

#endif



















