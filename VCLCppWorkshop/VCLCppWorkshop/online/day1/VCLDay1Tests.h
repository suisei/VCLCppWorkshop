//
//  VCLDay1Tests.h
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/12.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#ifndef VCLCppWorkshop_VCLDay1Tests_h
#define VCLCppWorkshop_VCLDay1Tests_h

#include "VCLFunctions.h"
#include <assert.h>

namespace VCL {

    void testDay1();

    void testDay1Q1();
    void testDay1Q2();
    void testDay1Q3();
    void testDay1Q4();
    void testDay1Q3t5();

    // テスト用クラス
    class VCLObject {
    public:
        int num;

        VCLObject(int num = 0) : num(num) {}
        virtual ~VCLObject() {}
    };

#pragma mark - Functions

    void testDay1()
    {
        printf("[OFFLINE] VCL DAY1 TEST START\n");

        testDay1Q1();
        testDay1Q2();
        testDay1Q3();
        testDay1Q4();
        testDay1Q3t5();

        printf("[OFFLINE] VCL DAY1 TEST FINISHED\n");
    }

    void testDay1Q1()
    {
        printf("===== %s =====\n", __FUNCTION__);

        int left = rand(), right = rand();
        int leftBuf = left, rightBuf = right;

        printf("left(%d), right(%d)\n", left, right);

        swap(left, right);

        printf("left(%d), right(%d)\n", left, right);

        assert(left == rightBuf && right == leftBuf);

        printf("===== %s END =====\n", __FUNCTION__);
    }

    void testDay1Q2()
    {
        printf("===== %s =====\n", __FUNCTION__);

        VCLObject* left = new VCLObject(1);
        VCLObject* right = new VCLObject(2);
        int leftNum = left->num;
        int rightNUm = right->num;

        printf("left(%d), right(%d)\n", left->num, right->num);

        swapObjects(left, right);

        printf("left(%d), right(%d)\n", left->num, right->num);

        assert(left->num == rightNUm && right->num == leftNum);

        delete left;
        delete right;

        printf("===== %s END =====\n", __FUNCTION__);
    }

    void testDay1Q3()
    {
        printf("===== %s =====\n", __FUNCTION__);

        const char* toggle1 = "VISUALcomputingLAB";
        const char* toggle2 = "copyrightVISUALcomputingLAB";
        char camel[128] = "";

        toggleToCamel(camel, toggle1);
        printf("toggle(%s), camel(%s)\n", toggle1, camel);
        toggleToCamel(camel, toggle2);
        printf("toggle(%s), camel(%s)\n", toggle2, camel);

        printf("===== %s END =====\n", __FUNCTION__);
    }

    void testDay1Q4()
    {
        printf("===== %s =====\n", __FUNCTION__);

        const char* colorCode = "11FF5A";
        VCLRGB color = webColorFromString(colorCode);
        printf("color %s, (%d, %d, %d)\n", colorCode, color.r, color.g, color.b);

        printf("===== %s END =====\n", __FUNCTION__);
    }

    void testDay1Q3t5()
    {
        printf("===== %s =====\n", __FUNCTION__);

        u64 min = 1;
        u64 max = 100;

        u64 primeNumbers[max - min];
        u64 primeCount = searchPrimeNumbers(primeNumbers, min, max);

        printf("PrimeNumbers: ");
        for (u64 i = 0; i < primeCount; ++i) {
            printf("%lld, ", primeNumbers[i]);
        }
        printf("\n");

        printf("===== %s END =====\n", __FUNCTION__);
    }
}


#endif
