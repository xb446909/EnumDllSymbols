// DllDemo2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DllDemo2.h"
#include <stdio.h>

// ���ǵ���������һ��ʾ����
DLLDEMO2_API int fnDllDemo2(void)
{
	printf("This is print from DllDemo2");
    return 2;
}

