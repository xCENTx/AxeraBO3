/*
	░█████╗░██╗░░██╗███████╗██████╗░░█████╗░░░░██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░
	██╔══██╗╚██╗██╔╝██╔════╝██╔══██╗██╔══██╗░░░██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░
	███████║░╚███╔╝░█████╗░░██████╔╝███████║░░░██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░
	██╔══██║░██╔██╗░██╔══╝░░██╔══██╗██╔══██║░░░██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░
	██║░░██║██╔╝╚██╗███████╗██║░░██║██║░░██║██╗██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗
	╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝

	-- Axera.Digital BO3 Zombie Tool ( Open Source )

	-- Coded by noodle@axera.digital & sonic@axera.digital

	-- Visit Us @https://axera.digital
*/

#pragma once
#include "../../Tool_Utilities/Utils.h"
#include "../../Global_Vars/Variables.h"

class ZombieEntity
{
private:

public:
	uintptr_t GetZombieEntity()
	{
		ZombieOffsets.zombieBase = GlobalVars.moduleBase + ZombieOffsets.zombieBasePtr;

		return ZombieOffsets.zombieBase;
	}

	uintptr_t GetZombieEntityCount()
	{
		ZombieOffsets.zombieCountBase = GlobalVars.moduleBase + ZombieOffsets.zombieCountPtr;

		return ZombieOffsets.zombieCountBase;
	}

	void EnableZombieTP()
	{
		if (GetAsyncKeyState(0x5A))
		{
			Utils::Read((BYTE*)PlayerOffsets.playerXCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportX, sizeof(PlayerOffsets.currentPlayerCoordsTeleportX), hProc);
			//
			Utils::Read((BYTE*)PlayerOffsets.playerYCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportY, sizeof(PlayerOffsets.currentPlayerCoordsTeleportY), hProc);
			//
			Utils::Read((BYTE*)PlayerOffsets.playerZCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportZ, sizeof(PlayerOffsets.currentPlayerCoordsTeleportZ), hProc);
		}
		for (uintptr_t i = 0; i < 80; i++)
		{
			// Zombie Coords
			Utils::Write((BYTE*)ZombieOffsets.zombiesXCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportX, sizeof(PlayerOffsets.currentPlayerCoordsTeleportX), hProc);
			//							 
			Utils::Write((BYTE*)ZombieOffsets.zombiesYCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportY, sizeof(PlayerOffsets.currentPlayerCoordsTeleportY), hProc);
			//							
			Utils::Write((BYTE*)ZombieOffsets.zombiesZCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&PlayerOffsets.currentPlayerCoordsTeleportZ, sizeof(PlayerOffsets.currentPlayerCoordsTeleportZ), hProc);
		}
	}

	int GetZombieCount()
	{
		ZombieOffsets.zombieCountBaseAddr = Utils::PointerChain(hProc, GetZombieEntityCount(), ZombieOffsets.zombieCountOffset);

		Utils::Read((BYTE*)ZombieOffsets.zombieCountBaseAddr, (BYTE*)&ZombieOffsets.iZombieCountValue, sizeof(ZombieOffsets.iZombieCountValue), hProc);

		return ZombieOffsets.iZombieCountValue;
	}
};