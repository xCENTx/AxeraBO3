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
#include "../Zombie/Zombie_Engine.h"

ZombieEntity* Zombie;

class PlayerEntity
{
private:

public:
	uintptr_t GetPlayerEntity()
	{
		PlayerOffsets.playerBase = GlobalVars.moduleBase + PlayerOffsets.playerBasePtr;

		return PlayerOffsets.playerBase;
	}

	uintptr_t GetPlayerEntityPed()
	{
		PlayerOffsets.playerPedBase = GlobalVars.moduleBase + PlayerOffsets.playerPedPtr;

		return PlayerOffsets.playerPedBase;
	}

	uintptr_t GetJumpHeightBase()
	{
		GlobalOffsets.jumpHeightBase = GlobalVars.moduleBase + GlobalOffsets.jumpHeightPtr;

		return GlobalOffsets.jumpHeightBase;
	}

	void EnableGodMode(int index)
	{
		PlayerOffsets.playerPedBaseAddr = Utils::PointerChain(hProc, GetPlayerEntityPed(), PlayerOffsets.playerGodModeOffset);

		Utils::Write((BYTE*)PlayerOffsets.playerPedBaseAddr + (ZombieOffsets.zombieArraySize * index), (BYTE*)&PlayerOffsets.iPlayerGodModeOn, sizeof(PlayerOffsets.iPlayerGodModeOn), hProc);
	}

	void DisableGodMode(int index)
	{
		PlayerOffsets.playerPedBaseAddr = Utils::PointerChain(hProc, GetPlayerEntityPed(), PlayerOffsets.playerGodModeOffset);

		Utils::Write((BYTE*)PlayerOffsets.playerPedBaseAddr + (ZombieOffsets.zombieArraySize * index), (BYTE*)&PlayerOffsets.iPlayerGodModeOff, sizeof(PlayerOffsets.iPlayerGodModeOff), hProc);
	}

	void SetPlayerClipAmmo(int index)
	{
		PlayerOffsets.playerBaseAddr = Utils::PointerChain(hProc, GetPlayerEntity(), PlayerOffsets.playerClipAmmoOffset);

		for (uintptr_t a = 0; a < 9; a++)
		{
			Utils::Write((BYTE*)PlayerOffsets.playerBaseAddr + (a * PlayerOffsets.playerArray) + (PlayerOffsets.playerArraySizeOffset * index), (BYTE*)&PlayerOffsets.iPlayerNewAmmoValue, sizeof(PlayerOffsets.iPlayerNewAmmoValue), hProc);
		}
	}

	void SetPlayerStockAmmo(int index)
	{
		PlayerOffsets.playerBaseAddr = Utils::PointerChain(hProc, GetPlayerEntity(), PlayerOffsets.playerStockAmmoOffset);

		for (uintptr_t a = 0; a < 9; a++)
		{
			Utils::Write((BYTE*)PlayerOffsets.playerBaseAddr + (a * PlayerOffsets.playerArray) + (PlayerOffsets.playerArraySizeOffset * index), (BYTE*)&PlayerOffsets.iPlayerNewAmmoValue, sizeof(PlayerOffsets.iPlayerNewAmmoValue), hProc);
		}
	}

	void SetPlayerPoints(int index)
	{
		PlayerOffsets.playerBaseAddr = Utils::PointerChain(hProc, GetPlayerEntity(), PlayerOffsets.playerPointsOffset);

		Utils::Write((BYTE*)PlayerOffsets.playerBaseAddr + (PlayerOffsets.playerArraySizeOffset * index), (BYTE*)&PlayerOffsets.iPlayerNewPointsValue, sizeof(PlayerOffsets.iPlayerNewPointsValue), hProc);
	}

	void EnableInstaKill()
	{
		for (uintptr_t i = 0; i < 80; i++)
		{
			Utils::Read((BYTE*)PlayerOffsets.playerPedHealthAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.iZombieCurrentHealthValue, sizeof(ZombieOffsets.iZombieCurrentHealthValue), hProc);

			if (ZombieOffsets.iZombieCurrentHealthValue < 1)
				continue;

			Utils::Write((BYTE*)PlayerOffsets.playerPedHealthAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.iZombieNewHealthValue, sizeof(ZombieOffsets.iZombieNewHealthValue), hProc);
		}
	}

	void SetPlayerJumpHeight()
	{
		Utils::Write((BYTE*)GetJumpHeightBase(), (BYTE*)&GlobalOffsets.globalNewJumpHeightValue, sizeof(GlobalOffsets.globalNewJumpHeightValue), hProc);
	}

	void SetPlayerRunSpeed()
	{
		// Need to Add.
	}

	void EnableRapidFire(int index)
	{
		PlayerOffsets.playerBaseAddr = Utils::PointerChain(hProc, GetPlayerEntity(), PlayerOffsets.playerRapidFireOffset);

		Utils::Write((BYTE*)PlayerOffsets.playerBaseAddr + (PlayerOffsets.playerArraySizeOffset * index), (BYTE*)&PlayerOffsets.iPlayerNewRapidFireValue, sizeof(PlayerOffsets.iPlayerNewRapidFireValue), hProc);
	}

	void EnableNoRecoil()
	{
		PlayerOffsets.playerNoRecoilBase = GlobalVars.moduleBase + PlayerOffsets.playerNoRecoilPtr;

		Utils::Nop((BYTE*)PlayerOffsets.playerNoRecoilBase, 2, hProc);
	}

	void DisableNoRecoil()
	{
		PlayerOffsets.playerNoRecoilBase = GlobalVars.moduleBase + PlayerOffsets.playerNoRecoilPtr;

		Utils::Patch((BYTE*)PlayerOffsets.playerNoRecoilBase, (BYTE*)"\x84\xc0\x74\x00\x32\xc0\xe9\x00\x00\x00\x00\x48\x83\xc4", 2, hProc);
	}

	void EnablePlayerJetPck()
	{
		if (GetAsyncKeyState(VK_SPACE) && 1)
		{
			Utils::Read((BYTE*)PlayerOffsets.playerZCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsZ, sizeof(PlayerOffsets.currentPlayerCoordsZ), hProc);

			GlobalOffsets.globalJetPackValue = PlayerOffsets.currentPlayerCoordsZ + GlobalOffsets.globalJetPackAddValue;

			Utils::Write((BYTE*)PlayerOffsets.playerZCoordAddr, (BYTE*)&GlobalOffsets.globalJetPackValue, sizeof(GlobalOffsets.globalJetPackValue), hProc);
		}
	}

	void SetPlayerWeapon(int index, int playerWeaponID)
	{
		PlayerOffsets.playerBaseAddr = Utils::PointerChain(hProc, GetPlayerEntity(), PlayerOffsets.playerSetWeaponOffset);

		Utils::Write((BYTE*)PlayerOffsets.playerBaseAddr + (PlayerOffsets.playerWeaponArray * 6) + (PlayerOffsets.playerArraySizeOffset * index), (BYTE*)&playerWeaponID, sizeof(playerWeaponID), hProc);
	}
};