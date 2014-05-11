//
//  VCLFunctions.hpp
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/11.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#ifndef VCLOCppWorkshop_VCLOFunctions_hpp
#define VCLOCppWorkshop_VCLOFunctions_hpp

#include <iostream>
#include <math.h>

namespace VCL
{
    //###Q1
    //1. 任意の整数2値を入れ替える関数 VCL::swap を実装する
    //2. 関数が正しく動くかテストする
    // 10min

    inline void VCLSwap(int& left, int& right)
    {
        left ^= right ^= left ^= right;
    }

    //###Q2
    //1. 任意のポインタ型を入れ替える関数 VCL::swapObjects を実装する
    //2. 関数が正しく動くかテストする
    // 10min

    template <typename T>
    inline void swapObjects(T* left, T* right)
    {
        T tmp = *left;
        *left = *right;
        *right = tmp;
    }

    //###Q3
    //1. 任意の正の整数の値域を指定し、その範囲にある素数を全て取得する関数 VCL::searchPrimeNumbers を実装する
    //2. 素数が存在しない場合は、そのことがわかるような結果を返す
    //3. 取得した素数を全てコンソールに出力する
    // 30min
    
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

    //###Q4
    //1. A(a)-Z(z)以外を含まないトグルケースの文字列からキャメルケースの文字列を取得する関数 VCL::toggleToCamel を実装する
    //(例: VISUALcomputingLAB => visualComputingLab)
    //2. 関数が正しく動くかテストする
    // 30min
    
    inline void toggleToCamel(char* camel, const char* toggle)
    {
        bool prevWordUpper = toggle[0] < 'a';
        char toLowerNumber = 'a' - 'A';
        
        long index = 0;
        while (toggle[index] != '\0') {
            
            char c = toggle[index];
            bool toggleHead = (c >= 'a') ? prevWordUpper : !prevWordUpper;

            char shifter = 0;
            shifter = (c >= 'a' &&  toggleHead) ? -toLowerNumber : shifter;
            shifter = (c <  'a' && !toggleHead) ?  toLowerNumber : shifter;
            
            camel[index++] = c + shifter;
            prevWordUpper = c < 'a';
        }
        
        camel[index] = '\0';
    }

    //###Q5
    //1. Webカラーコードの文字列を入力数すると、そのRGB各値を整数で取得できる関数 VCL::webColorFromString を実装する
    //(例: "12FF0E" => { 18, 255, 14 })
    //2. 関数が正しく動くかテストする
    
    typedef union
    {
        struct { unsigned char r, g, b; };
        unsigned char v[3];
        
    } VCLRGB;
    
    inline VCLRGB webColorFromString(const char* colorCode)
    {
        if (strlen(colorCode) != 6) {
            return VCLRGB();
        }
        
        VCLRGB color = { 0, 0, 0 };
        
        int colorIndex = 0;
        for (int i = 0; i < 6; i += 2) {

            char colorStr[2] = { colorCode[i], colorCode[i] };
            
            int value = 0;
            sscanf(colorStr, "%x", &value);
            
            color.v[colorIndex++] = static_cast<unsigned char>(value);
        }
        
        return color;
    }

} // VCL

#endif
