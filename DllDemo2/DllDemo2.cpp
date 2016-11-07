// DllDemo2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "DllDemo2.h"
#include <stdio.h>

// 这是导出函数的一个示例。
DLLDEMO2_API int fnDllDemo2(void)
{
	printf("This is print from DllDemo2");
    return 2;
}

