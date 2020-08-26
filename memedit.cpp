#include "pch.h"
#include "memedit.h"

memedit::PatchInfo p[] = {
	{0x3A49AC,2,"\x90\x90",nullptr},
	{0x1BFEE5,1,"\xEB",nullptr},
	{0x370AD3,1,"\xEB",nullptr},
	{0x3BDBED,1,"\xE7",nullptr},
	{0x3BD7E5,2,"\x33\xC0",nullptr},
	{0x6516A3,1,"\xEB",nullptr},
	{0x1C0144,1,"\xEB",nullptr},
	{0x1C0053,1,"\xEB",nullptr},
	{0x251274,1,"\xFC",nullptr},
	{0x251287,1,"\xFC",nullptr},
	{0x66E457,2,"\x40\xC3",nullptr}
};

void memedit::Patch(void* dwBaseAddress, const char* szData, size_t iSize)
{
	DWORD dwOldProtection = NULL;
	VirtualProtect((LPVOID)dwBaseAddress, iSize, PAGE_EXECUTE_READWRITE, &dwOldProtection);
	memcpy_s(dwBaseAddress, iSize, szData, iSize);
	VirtualProtect((LPVOID)dwBaseAddress, iSize, dwOldProtection, NULL);
}

const unsigned int numberOfPatch = sizeof(p) / sizeof(memedit::PatchInfo);
void memedit::applyPatch()
{
	for (unsigned int i = 0; i < numberOfPatch; i++) {
		//p[i].backup = std::make_unique<char[]>(p[i].size);
		//memcpy_s(p[i].backup.get(), p[i].size, (void*)(p[i].addr + gameDll), p[i].size);
		Patch((void*)(p[i].addr + gameDll), p[i].content, p[i].size);
	}
}