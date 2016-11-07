// DllDemo1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "DllDemo1.h"
#include <stdio.h>

// 这是导出函数的一个示例。
DLLDEMO1_API int fnDllDemo1(void)
{
	printf("This is print from DllDemo1");
    return 1;
}

