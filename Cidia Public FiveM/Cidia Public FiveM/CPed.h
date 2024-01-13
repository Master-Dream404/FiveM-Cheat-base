#pragma once
#include <string>
#include <vector>

//247FAC8

class CPed
{
public:
	void SetHP(int value) {
		*(float*)(this + 0x280) = value;
	}
	float GetHP()
	{
		return *(float*)(this + 0x280);
	}
};

class CWorld
{
public:
	CPed* LocalPlayer()
	{
		if (!this) return 0;
		return (CPed*)(*(uint64_t*)(this + 0x8));
	}
};
