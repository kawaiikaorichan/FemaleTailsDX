#include "pch.h"

#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
NJS_MATERIAL* TemporaryMaterialArray[] = { nullptr };

static Trampoline* LoadRegObjTextures_t = nullptr;
static Trampoline* FreeRegObjTexlists_t = nullptr;

static NJS_TEXNAME GUI_TEXNAME[2] = {};
static NJS_TEXLIST GUI_TEXLIST = { arrayptrandlengthT(GUI_TEXNAME, int) };

static void __cdecl LoadRegObjTextures_r(int a1)
{
	LoadPVM("GUI", &GUI_TEXLIST);
	((decltype(LoadRegObjTextures_r)*)LoadRegObjTextures_t->Target())(a1);
}

static void __cdecl FreeRegObjTexlists_r()
{
	njReleaseTexture(&GUI_TEXLIST);
	((decltype(FreeRegObjTexlists_r)*)FreeRegObjTexlists_t->Target())();
}

void Icons_Init()
{
	LoadRegObjTextures_t = new Trampoline(0x4212E0, 0x4212E5, LoadRegObjTextures_r, false);
	FreeRegObjTexlists_t = new Trampoline(0x420F40, 0x420F45, FreeRegObjTexlists_r, false);
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		Icons_Init();
		ReplacePVM("Miles", "OnnaTails")
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}