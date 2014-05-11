//
//  day1Tests.hpp
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/11.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#ifndef VCLOCppWorkshop_day1Tests_hpp
#define VCLOCppWorkshop_day1Tests_hpp

#include <assert.h>
#include "VCLOFunctions.hpp"

namespace VCL
{

    void testDay1();

    void testDay1Q1();
    void testDay1Q2();
    void testDay1Q3();
    void testDay1Q4();
    void testDay1Q5();
    void testDay1Q6();
    void testDay1Q7();

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
        
        printf("[OFFLINE] VCL DAY1 TEST FINISHED\n");
    }

    void testDay1Q1()
    {
        printf("===== %s =====\n", __FUNCTION__);
        
        int left = rand(), right = rand();
        int leftBuf = left, rightBuf = right;
        
        printf("left(%d), right(%d)\n", left, right);
        
        VCLSwap(left, right);
        
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

    void testDay1Q4()
    {
        printf("===== %s =====\n", __FUNCTION__);
        
        printf("===== %s END =====\n", __FUNCTION__);
    }

    void testDay1Q5()
    {
        printf("===== %s =====\n", __FUNCTION__);
        
        printf("===== %s END =====\n", __FUNCTION__);
    }
    
} // VCL

#endif
