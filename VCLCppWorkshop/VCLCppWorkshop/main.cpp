//
//  main.cpp
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/11.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#include <iostream>

#define VCL_ONLINE


#ifdef VCL_ONLINE
    #include "VCLDay1Tests.h"
#else
    #include "VCLODay1Tests.hpp"
#endif

#pragma mark - Functions

int main(int argc, const char * argv[])
{
    VCL::testDay1();
}

