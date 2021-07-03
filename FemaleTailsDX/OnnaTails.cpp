#include "pch.h"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		ReplacePVM("Miles", "OnnaTails")
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}