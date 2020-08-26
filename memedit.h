#pragma once
#include "pch.h"

namespace memedit {
	struct PatchInfo {
		unsigned int addr, size;
		const char* content;
		std::unique_ptr<char[]> backup;
	};

	inline void Patch(void* dwBaseAddress, const char* szData, size_t iSize);
	void applyPatch();
}