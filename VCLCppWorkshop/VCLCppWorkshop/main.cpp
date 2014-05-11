//
//  main.cpp
//  VCLCppWorkshop
//
//  Created by suisei on 2014/05/11.
//  Copyright (c) 2014年 Kazuki Kumagai. All rights reserved.
//

#include <iostream>

//#define VCL_ONLINE

#ifdef VCL_ONLINE

#else
    #include "VCLODay1Tests.hpp"
#endif

int main(int argc, const char * argv[])
{
#ifdef VCL_ONLINE
    
#else
    VCL::testDay1();
#endif
}

