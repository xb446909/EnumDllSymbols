// DllDemo1.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DllDemo1.h"
#include <stdio.h>

// ���ǵ���������һ��ʾ����
DLLDEMO1_API int fnDllDemo1(void)
{
	printf("This is print from DllDemo1");
    return 1;
}

