#include <stdio.h>
#include "Windows.h"
#include "Dbghelp.h"

#pragma comment(lib, "Dbghelp.lib")

BOOL CALLBACK EnumSymProc(
	PSYMBOL_INFO pSymInfo,
	ULONG SymbolSize,
	PVOID UserContext)
{
	UNREFERENCED_PARAMETER(UserContext);

	printf("%08X %4u %s\n",
		pSymInfo->Address, SymbolSize, pSymInfo->Name);
	return TRUE;
}



int main(int argc, char** argv)
{
	SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
	HANDLE hProcess = GetCurrentProcess();
	DWORD64 BaseOfDll;
	char *Mask = "*";
	BOOL status;

	status = SymInitialize(hProcess, NULL, FALSE);
	if (status == FALSE)
	{
		printf("SymInitialize returned false\r\n");
		return 0;
	}

	BaseOfDll = SymLoadModuleEx(hProcess,
		NULL,
		"CCDManage.dll",
		NULL,
		0,
		0,
		NULL,
		4);

	if (BaseOfDll == 0)
	{
		printf("BaseOfDll == 0\r\n");
		SymCleanup(hProcess);
		return 0;
	}

	printf("BaseOfDll = %llx\r\n", BaseOfDll);

	if (SymEnumSymbols(hProcess,     // Process handle from SymInitialize.
		BaseOfDll,   // Base address of module.
		NULL,        // Name of symbols to match.
		EnumSymProc, // Symbol handler procedure.
		NULL))       // User context.
	{
		// SymEnumSymbols succeeded
		printf("SymEnumSymbols succeeded\r\n");
	}
	else
	{
		// SymEnumSymbols failed
		
		printf("SymEnumSymbols failed: %lx\n", GetLastError());
	}

	SymCleanup(hProcess);
	return 0;
}