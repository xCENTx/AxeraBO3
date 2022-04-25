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

#include "Engine_Base.h"

namespace Engine_Base
{
	// Get Player Coords.
	void GetPlayerCoords()
	{
		while (true)
		{
			if (Zombie->GetZombieCount() > 1)
			{
				PlayerOffsets.playerXCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerXCoord);
				//
				PlayerOffsets.playerYCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerYCoord);
				//
				PlayerOffsets.playerZCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerZCoord);
			}
			Sleep(1);
		}
	}
	// Get Zombie Coords.
	void GetZombieCoords()
	{
		while (true)
		{
			if (Zombie->GetZombieCount() > 1)
			{
				ZombieOffsets.zombiesXCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieXCoord);
				//
				ZombieOffsets.zombiesYCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieYCoord);
				//																
				ZombieOffsets.zombiesZCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieZCoord);
				//
				ZombieOffsets.zombiesHeadXCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieHeadXCoord);
				//
				ZombieOffsets.zombiesHeadYCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieHeadYCoord);
				//
				ZombieOffsets.zombiesHeadZCoordAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieHeadZCoord);
				//
				PlayerOffsets.playerPedHealthAddr = Utils::PointerChain(hProc, Zombie->GetZombieEntity(), ZombieOffsets.zombieHealthOffset);
			}
			Sleep(1);
		}
	}
	// Features for Player 1.
	void Player1Features()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			if (FeatureBools.bP1InfiniteHealth)
			{
				Player->EnableGodMode(PlayerOffsets.iPlayer1Index);
			}
			if (!FeatureBools.bP1InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer1Index);
			}
			if (FeatureBools.bP1InfiniteClipAmmo)
			{
				Player->SetPlayerClipAmmo(PlayerOffsets.iPlayer1Index);
			}
			if (FeatureBools.bP1InfiniteStockAmmo)
			{
				Player->SetPlayerStockAmmo(PlayerOffsets.iPlayer1Index);
			}
			if (FeatureBools.bP1InfinitePoints)
			{
				Player->SetCustomPlayerPoints(PlayerOffsets.iPlayer1Index);
			}
			if (FeatureBools.bP1AlwaysInstaKill)
			{
				Player->EnableInstaKill();
			}
			if (FeatureBools.bP1JumpHeight)
			{
				Player->SetPlayerJumpHeight();
			}
			if (FeatureBools.bNoRecoilOn)
			{
				Player->EnableNoRecoil();
				FeatureBools.bNoRecoilOn = false;
			}
			if (FeatureBools.bNoRecoilOff)
			{
				Player->DisableNoRecoil();
				FeatureBools.bNoRecoilOff = false;
			}
			if (FeatureBools.bP1RapidFire)
			{
				Player->EnableRapidFire(PlayerOffsets.iPlayer1Index);
			}
			if (FeatureBools.bJetPack)
			{
				Player->EnablePlayerJetPck();
			}
			if (FeatureBools.bP1WCycle)
			{
				Player->SetPlayerWeapon(PlayerOffsets.iPlayer1Index, PlayerOffsets.iPlayer1NewWeaponValue);
			}
		}
	}
	// Features for Player 2.
	void Player2Features()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			if (FeatureBools.bP2InfiniteHealth)
			{
				Player->EnableGodMode(PlayerOffsets.iPlayer2Index);
			}
			if (!FeatureBools.bP2InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer2Index);
			}
			if (FeatureBools.bP2InfiniteClipAmmo)
			{
				Player->SetPlayerClipAmmo(PlayerOffsets.iPlayer2Index);
			}
			if (FeatureBools.bP2InfiniteStockAmmo)
			{
				Player->SetPlayerStockAmmo(PlayerOffsets.iPlayer2Index);
			}
			if (FeatureBools.bP2InfinitePoints)
			{
				Player->SetPlayerPoints(PlayerOffsets.iPlayer2Index);
			}
			if (FeatureBools.bP2RunSpeed)
			{
				// Needs Added.
			}
			if (FeatureBools.bP2RapidFire)
			{
				Player->EnableRapidFire(PlayerOffsets.iPlayer2Index);
			}
			if (FeatureBools.bP2WCycle)
			{
				Player->SetPlayerWeapon(PlayerOffsets.iPlayer2Index, PlayerOffsets.iPlayer2NewWeaponValue);
			}
		}
	}
	// Features for Player 3.
	void Player3Features()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			if (FeatureBools.bP3InfiniteHealth)
			{
				Player->EnableGodMode(PlayerOffsets.iPlayer3Index);
			}
			if (!FeatureBools.bP3InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer3Index);
			}
			if (FeatureBools.bP3InfiniteClipAmmo)
			{
				Player->SetPlayerClipAmmo(PlayerOffsets.iPlayer3Index);
			}
			if (FeatureBools.bP3InfiniteStockAmmo)
			{
				Player->SetPlayerStockAmmo(PlayerOffsets.iPlayer3Index);
			}
			if (FeatureBools.bP3InfinitePoints)
			{
				Player->SetPlayerPoints(PlayerOffsets.iPlayer3Index);
			}
			if (FeatureBools.bP3RunSpeed)
			{
				// Needs Added.
			}
			if (FeatureBools.bP3RapidFire)
			{
				Player->EnableRapidFire(PlayerOffsets.iPlayer3Index);
			}
			if (FeatureBools.bP3WCycle)
			{
				Player->SetPlayerWeapon(PlayerOffsets.iPlayer3Index, PlayerOffsets.iPlayer3NewWeaponValue);
			}
		}
	}
	// Features for Player 4.
	void Player4Features()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			if (FeatureBools.bP4InfiniteHealth)
			{
				Player->EnableGodMode(PlayerOffsets.iPlayer4Index);
			}
			if (!FeatureBools.bP4InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer4Index);
			}
			if (FeatureBools.bP4InfiniteClipAmmo)
			{
				Player->SetPlayerClipAmmo(PlayerOffsets.iPlayer4Index);
			}
			if (FeatureBools.bP4InfiniteStockAmmo)
			{
				Player->SetPlayerStockAmmo(PlayerOffsets.iPlayer4Index);
			}
			if (FeatureBools.bP4InfinitePoints)
			{
				Player->SetPlayerPoints(PlayerOffsets.iPlayer4Index);
			}
			if (FeatureBools.bP4RunSpeed)
			{
				// Needs Added.
			}
			if (FeatureBools.bP4RapidFire)
			{
				Player->EnableRapidFire(PlayerOffsets.iPlayer4Index);
			}
			if (FeatureBools.bP4WCycle)
			{
				Player->SetPlayerWeapon(PlayerOffsets.iPlayer4Index, PlayerOffsets.iPlayer4NewWeaponValue);
			}
		}
	}
	// Features for Zombies.
	void ExtraGoodieFeatures()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			if (FeatureBools.bZombieTP)
			{
				Zombie->EnableZombieTP();
			}
			if (FeatureBools.bZombieCount)
			{
				Zombie->GetZombieCount();
			}
		}
	}
	// Disbale All Features.
	void DisableAllFeatures()
	{
		procID = Utils::GetProcId("BlackOps3.exe");
		if (procID < 1)
		{
			exit(0);
		}
		if (GetAsyncKeyState(VK_DELETE))
		{
			/*
			*	Player 1 booleans
			*/
			FeatureBools.bP1InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer1Index);
			FeatureBools.bP1InfiniteClipAmmo = false;
			FeatureBools.bP1InfiniteStockAmmo = false;
			FeatureBools.bP1InfinitePoints = false;
			FeatureBools.bP1AlwaysInstaKill = false;
			FeatureBools.bNoRecoilOn = false;
			Player->DisableNoRecoil();
			FeatureBools.bP1RapidFire = false;
			FeatureBools.bP1JumpHeight = false;
			FeatureBools.bZombieTP = false;
			FeatureBools.bExtraZombiesTP = false;
			FeatureBools.bTPAllZombies = false;
			FeatureBools.bP1WCycle = false;
			/*
			*	Player 2 booleans
			*/
			FeatureBools.bP2InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer2Index);
			FeatureBools.bP2InfiniteClipAmmo = false;
			FeatureBools.bP2InfiniteStockAmmo = false;
			FeatureBools.bP2InfinitePoints = false;
			FeatureBools.bP2RapidFire = false;
			FeatureBools.bP2WCycle = false;
			/*
			*	Player 3 booleans
			*/
			FeatureBools.bP3InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer3Index);
			FeatureBools.bP3InfiniteClipAmmo = false;
			FeatureBools.bP3InfiniteStockAmmo = false;
			FeatureBools.bP3InfinitePoints = false;
			FeatureBools.bP3RapidFire = false;
			FeatureBools.bP3WCycle = false;
			/*
			*	Player 4 booleans
			*/
			FeatureBools.bP4InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer4Index);
			FeatureBools.bP4InfiniteClipAmmo = false;
			FeatureBools.bP4InfiniteStockAmmo = false;
			FeatureBools.bP4InfinitePoints = false;
			FeatureBools.bP4RapidFire = false;
			FeatureBools.bP4WCycle = false;
			/*
			*	Extra Goodies booleans
			*/
			VisualSettings.bZombie2DBox = false;
			VisualSettings.bZombie2DBrackets = false;
			VisualSettings.bZombieSnaplines = false;
			MiscSettings.bCrosshairFeature = false;
			MiscSettings.bPlayerFov = false;
			FeatureBools.bZombieCount = false;
		}
		if (GetAsyncKeyState(VK_HOME))
		{
			/*
			*	Player 1 booleans
			*/
			FeatureBools.bP1InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer1Index);
			FeatureBools.bP1InfiniteClipAmmo = false;
			FeatureBools.bP1InfiniteStockAmmo = false;
			FeatureBools.bP1InfinitePoints = false;
			FeatureBools.bP1AlwaysInstaKill = false;
			FeatureBools.bNoRecoilOn = false;
			Player->DisableNoRecoil();
			FeatureBools.bP1RapidFire = false;
			FeatureBools.bP1JumpHeight = false;
			FeatureBools.bZombieTP = false;
			FeatureBools.bExtraZombiesTP = false;
			FeatureBools.bTPAllZombies = false;
			FeatureBools.bP1WCycle = false;
			/*
			*	Player 2 booleans
			*/
			FeatureBools.bP2InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer2Index);
			FeatureBools.bP2InfiniteClipAmmo = false;
			FeatureBools.bP2InfiniteStockAmmo = false;
			FeatureBools.bP2InfinitePoints = false;
			FeatureBools.bP2RapidFire = false;
			FeatureBools.bP2WCycle = false;
			/*
			*	Player 3 booleans
			*/
			FeatureBools.bP3InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer3Index);
			FeatureBools.bP3InfiniteClipAmmo = false;
			FeatureBools.bP3InfiniteStockAmmo = false;
			FeatureBools.bP3InfinitePoints = false;
			FeatureBools.bP3RapidFire = false;
			FeatureBools.bP3WCycle = false;
			/*
			*	Player 4 booleans
			*/
			FeatureBools.bP4InfiniteHealth = false;
			Player->DisableGodMode(PlayerOffsets.iPlayer4Index);
			FeatureBools.bP4InfiniteClipAmmo = false;
			FeatureBools.bP4InfiniteStockAmmo = false;
			FeatureBools.bP4InfinitePoints = false;
			FeatureBools.bP4RapidFire = false;
			FeatureBools.bP4WCycle = false;
			exit(0);
		}
		if (Zombie->GetZombieCount() < 1)
		{
			if (FeatureBools.bP1InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer1Index);
				FeatureBools.bP1InfiniteHealth = false;
			}
			if (FeatureBools.bP2InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer2Index);
				FeatureBools.bP2InfiniteHealth = false;
			}
			if (FeatureBools.bP3InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer3Index);
				FeatureBools.bP3InfiniteHealth = false;
			}
			if (FeatureBools.bP4InfiniteHealth)
			{
				Player->DisableGodMode(PlayerOffsets.iPlayer4Index);
				FeatureBools.bP4InfiniteHealth = false;
			}
			Player->DisableNoRecoil();
			FeatureBools.bJetPack = false;
			GlobalOffsets.globalJetPackValue = 0.f;
			GlobalOffsets.globalJetPackAddValue = 8.f;
		}
	}
};
