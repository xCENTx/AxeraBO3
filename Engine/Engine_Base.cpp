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
		PlayerOffsets.playerXCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerXCoord);

		PlayerOffsets.playerYCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerYCoord);

		PlayerOffsets.playerZCoordAddr = Utils::PointerChain(hProc, Player->GetPlayerEntity(), PlayerOffsets.playerZCoord);
	}
	// Get Zombie Coords.
	void GetZombieCoords()
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
	// Features for Player 1.
	void Player1Features()
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
			Player->SetPlayerPoints(PlayerOffsets.iPlayer1Index);
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
	// Features for Player 2.
	void Player2Features()
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
	// Features for Player 3.
	void Player3Features()
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
	// Features for Player 4.
	void Player4Features()
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
	// Features for Zombies.
	void ExtraGoodieFeatures()
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
	// Disbale All Features.
	void DisableAllFeatures()
	{
		procID = Utils::GetProcId("BlackOps3.exe");
		if (procID < 1)
		{
			///*
			//*	Player 1 booleans
			//*/
			//infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player1Index);
			//infiniteClipAmmo = false;
			//infiniteStockAmmo = false;
			//infinitePoints = false;
			//alwaysInstaKill = false;
			//noRecoil_On = false;
			//Player->Disable_No_Recoil();
			//rapidFire = false;
			//jumpHeight = false;
			//zombieTP = false;
			//extraZombiesTP = false;
			//tpAllZombies = false;
			//p1WCycle = false;
			///*
			//*	Player 2 booleans
			//*/
			//p2infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_2_Index);
			//p2infiniteClipAmmo = false;
			//p2infiniteStockAmmo = false;
			//p2infinitePoints = false;
			//p2RapidFire = false;
			//p2WCycle = false;
			///*
			//*	Player 3 booleans
			//*/
			//p3infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_3_Index);
			//p3infiniteClipAmmo = false;
			//p3infiniteStockAmmo = false;
			//p3infinitePoints = false;
			//p3RapidFire = false;
			//p3WCycle = false;
			///*
			//*	Player 4 booleans
			//*/
			//p4infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_4_Index);
			//p4infiniteAmmo = false;
			//p4infiniteClipAmmo = false;
			//p4infiniteStockAmmo = false;
			//p4infinitePoints = false;
			//p4RapidFire = false;
			//p4WCycle = false;
			exit(0);
		}
		if (GetAsyncKeyState(VK_DELETE))
		{
			///*
			//*	Player 1 booleans
			//*/
			//infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player1Index);
			//infiniteClipAmmo = false;
			//infiniteStockAmmo = false;
			//infinitePoints = false;
			//alwaysInstaKill = false;
			//noRecoil_On = false;
			//Player->Disable_No_Recoil();
			//rapidFire = false;
			//jumpHeight = false;
			//zombieTP = false;
			//extraZombiesTP = false;
			//tpAllZombies = false;
			//p1WCycle = false;
			///*
			//*	Player 2 booleans
			//*/
			//p2infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_2_Index);
			//p2infiniteClipAmmo = false;
			//p2infiniteStockAmmo = false;
			//p2infinitePoints = false;
			//p2RapidFire = false;
			//p2WCycle = false;
			///*
			//*	Player 3 booleans
			//*/
			//p3infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_3_Index);
			//p3infiniteClipAmmo = false;
			//p3infiniteStockAmmo = false;
			//p3infinitePoints = false;
			//p3RapidFire = false;
			//p3WCycle = false;
			///*
			//*	Player 4 booleans
			//*/
			//p4infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_4_Index);
			//p4infiniteAmmo = false;
			//p4infiniteClipAmmo = false;
			//p4infiniteStockAmmo = false;
			//p4infinitePoints = false;
			//p4RapidFire = false;
			//p4WCycle = false;
		}
		if (GetAsyncKeyState(VK_HOME))
		{
			///*
			//*	Player 1 booleans
			//*/
			//infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player1Index);
			//infiniteClipAmmo = false;
			//infiniteStockAmmo = false;
			//infinitePoints = false;
			//alwaysInstaKill = false;
			//noRecoil_On = false;
			//noRecoil_Off = false;
			//Player->Disable_No_Recoil();
			//rapidFire = false;
			//jumpHeight = false;
			//zombieTP = false;
			//extraZombiesTP = false;
			//tpAllZombies = false;
			//p1WCycle = false;
			///*
			//*	Player 2 booleans
			//*/
			//p2infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_2_Index);
			//p2infiniteClipAmmo = false;
			//p2infiniteStockAmmo = false;
			//p2infinitePoints = false;
			//p2RapidFire = false;
			//p2WCycle = false;
			///*
			//*	Player 3 booleans
			//*/
			//p3infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_3_Index);
			//p3infiniteClipAmmo = false;
			//p3infiniteStockAmmo = false;
			//p3infinitePoints = false;
			//p3RapidFire = false;
			//p3WCycle = false;
			///*
			//*	Player 4 booleans
			//*/
			//p4infiniteHealth = false;
			//Player->Disable_GodMode(PlayerOffsets.player_4_Index);
			//p4infiniteAmmo = false;
			//p4infiniteClipAmmo = false;
			//p4infiniteStockAmmo = false;
			//p4infinitePoints = false;
			//p4RapidFire = false;
			//p4WCycle = false;
			exit(0);
		}
	}
};
