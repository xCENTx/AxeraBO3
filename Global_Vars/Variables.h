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
#include "../imgui/imgui.h"

struct Global_Variables
{
	uintptr_t moduleBase = NULL;
	int iScreenWidth = 0;
	int iScreenHeight = 0;
	float fontSize = 16.f;
	int iTab = 1;
} GlobalVars;

struct Feature_Booleans
{
#pragma region Player_1_Bools
	bool bP1InfiniteHealth = false;
	bool bP1InfiniteClipAmmo = false;
	bool bP1InfiniteStockAmmo = false;
	bool bP1RapidFire = false;
	bool bP1InfinitePoints = false;
	bool bP1AlwaysInstaKill = false;
	bool bP1JumpHeight = false;
	bool bP1RunSpeed = false;
	bool bP1Speed = false;
	bool bZombieTP = false;
	bool bExtraZombiesTP = false;
	bool bTPAllZombies = false;
	bool bNewZombieLocation = false;
	bool bP1WCycle = false;
	bool bP1Name = false;
#pragma endregion	
#pragma region Player_2_Bools
	bool bP2InfiniteHealth = false;
	bool bP2InfiniteAmmo = false;
	bool bP2InfiniteClipAmmo = false;
	bool bP2InfiniteStockAmmo = false;
	bool bP2InfinitePoints = false;
	bool bP2RapidFire = false;
	bool bP2JumpHeight = false;
	bool bP2RunSpeed = false;
	float p2RunSpeedvalue = 1.f;
	bool bP2WCycle = false;
#pragma endregion
#pragma region Player_3_Bools
	bool bP3InfiniteHealth = false;
	bool bP3InfiniteAmmo = false;
	bool bP3InfiniteClipAmmo = false;
	bool bP3InfiniteStockAmmo = false;
	bool bP3InfinitePoints = false;
	bool bP3RapidFire = false;
	bool bP3JumpHeight = false;
	bool bP3RunSpeed = false;
	float p3RunSpeedvalue = 1.f;
	bool bP3WCycle = false;
#pragma endregion
#pragma region Player_4_Bools
	bool bP4InfiniteHealth = false;
	bool bP4InfiniteAmmo = false;
	bool bP4InfiniteClipAmmo = false;
	bool bP4InfiniteStockAmmo = false;
	bool bP4InfinitePoints = false;
	bool bP4RapidFire = false;
	bool bP4JumpHeight = false;
	bool bP4RunSpeed = false;
	float p4RunSpeedvalue = 1.f;
	bool bP4WCycle = false;
#pragma endregion
#pragma region Extra_Goodies_Bools
	bool bJetPack = false;
	bool bAimbot = false;
	bool bZombieCount = false;
	bool bNoRecoilOn = false;
	bool bNoRecoilOff = false;
	bool bNoGunJitter = false;
#pragma endregion
} FeatureBools;

struct Player_Offsets
{
	uintptr_t playerBasePtr = 0x0A54BDE0;
	uintptr_t playerPedPtr = 0x0A54BDE8;
	uintptr_t playerNoRecoilPtr = 0x11BD901; // \x84\xc0\x74\x00\x32\xc0\xe9\x00\x00\x00\x00\x48\x83\xc4 xxx?xxx????xxx // 84 c0 74 ? 32 c0 e9 ? ? ? ? 48 83 c4
	uintptr_t playerNoRecoilBase;
	uintptr_t playerBase;
	uintptr_t playerBaseAddr;
	uintptr_t playerPedBase;
	uintptr_t playerPedBaseAddr;
	uintptr_t playerPedHealthAddr;
	uintptr_t playerXCoordAddr;
	uintptr_t playerYCoordAddr;
	uintptr_t playerZCoordAddr;
	uintptr_t playerArraySizeOffset = { 0x171F0 }; // New
	uintptr_t playerWeaponArraySizeOffset = { 0x40 };
	uintptr_t playerArray = { 0x4 };
	uintptr_t playerWeaponArray = { 0x8 };
	std::vector <unsigned int> playerNameOffset = { 0x6060 };
	std::vector <unsigned int> playerGodModeOffset = { 0x2A8 }; // New
	std::vector <unsigned int> playerNormalHealthOffset = { 0x16F28 }; // New
	std::vector <unsigned int> playerClipAmmoOffset = { 0x684 }; // New
	std::vector <unsigned int> playerStockAmmoOffset = { 0x648 }; // New
	std::vector <unsigned int> playerRapidFireOffset = { 0x54 }; // New
	std::vector <unsigned int> playerRapidFireOffset2 = { 0xE80 };
	std::vector <unsigned int> playerNoRecoilOffset = { 0x12F8 }; // 66 41 89 80 ? ? ? ? f3 c3 90 84 0f
	std::vector <unsigned int> playerPointsOffset = { 0x16E84 }; // New
	std::vector <unsigned int> playerRunSpeedOffset = { 0x5C70 };
	std::vector <unsigned int> playerLocationOffset = { 0xDE8 };
	std::vector <unsigned int> playerSetWeaponOffset = { 0x378 };
	std::vector <unsigned int> gameSkipRounds = { 0x333D8 };
	std::vector <unsigned int> playerKillsOffset = { 0x5D28 };
	std::vector <unsigned int> playerXCoord = { 0x30 };
	std::vector <unsigned int> playerYCoord = { 0x34 };
	std::vector <unsigned int> playerZCoord = { 0x38 };
	std::vector <unsigned int> playerXView = { 0xD0 };
	std::vector <unsigned int> playerYView = { 0xD4 };
	std::vector <unsigned int> playerZView = { 0xD8 };
	// Player Feature Values
	const int iPlayerGodModeOn = 0x9;
	const int iPlayerGodModeOff = 0x8;
	const int iPlayerNoRecoilOn = 0x75; // 3224506229
	const int iPlayerNoRecoilOff = 0x74; // 3224506228
	std::byte noRecoilValue;
	int iPlayerHealthValue;
	int iPlayerNewAmmoValue = 255;
	int iPlayerNewPointsValue = 100000;
	int iPlayerNewCustomPointsValue = 0;
	int iPlayerNewRecoilValue = 0;
	int iPlayerNewRapidFireValue = 0;
	int iPlayer1NewWeaponValue;
	int iPlayer2NewWeaponValue;
	int iPlayer3NewWeaponValue;
	int iPlayer4NewWeaponValue;
	float player1NewRunSpeedValue = 1.f;
	float player2NewRunSpeedValue = 1.f;
	float player3NewRunSpeedValue = 1.f;
	float player4NewRunSpeedValue = 1.f;
	float playerDefaultRunSpeedValue = 1.f;
	float currentPlayerCoordsX;
	float currentPlayerCoordsY;
	float currentPlayerCoordsZ;
	float currentPlayerCoordsTeleportX;
	float currentPlayerCoordsTeleportY;
	float currentPlayerCoordsTeleportZ;
	float currentPlayerViewAngleX;
	float currentPlayerViewAngleY;
	float currentPlayerViewAngleZ;
	float playerDistance;
	int iPlayer1Index = 0;
	int iPlayer2Index = 1;
	int iPlayer3Index = 2;
	int iPlayer4Index = 3;
	//Vec3 currentPlayerViewAngleXYZ;
} PlayerOffsets;

struct Zombie_Offsets
{
	uintptr_t zombieBasePtr = 0x0A54BE48; // New
	uintptr_t zombieBase;
	uintptr_t zombieBaseAddr;
	uintptr_t zombieCountPtr = 0x0A54BE40;
	uintptr_t zombieCountBase;
	uintptr_t zombieCountBaseAddr;
	uintptr_t zombiesXCoordAddr;
	uintptr_t zombiesYCoordAddr;
	uintptr_t zombiesZCoordAddr;
	uintptr_t zombiesHeadXCoordAddr;
	uintptr_t zombiesHeadYCoordAddr;
	uintptr_t zombiesHeadZCoordAddr;
	uintptr_t zombieArraySize = 0x4F8; // New
	uintptr_t zombieNextEntitiyOffset = 0x8;
	std::vector <unsigned int> zombieHealthOffset = { 0x8, 0x2C8 }; // New
	std::vector <unsigned int> zombieXCoord = { 0x8, 0x230 }; // New
	std::vector <unsigned int> zombieYCoord = { 0x8, 0x234 }; // New
	std::vector <unsigned int> zombieZCoord = { 0x8, 0x238 }; // New
	std::vector <unsigned int> zombieHeadXCoord = { 0x8, 0x224 }; // New
	std::vector <unsigned int> zombieHeadYCoord = { 0x8, 0x228 }; // New
	std::vector <unsigned int> zombieHeadZCoord = { 0x8, 0x22C }; // New
	std::vector <unsigned int> zombieHeadXYZCoord = { 0x8, 0x224, 0x228, 0x22C }; // New
	std::vector <unsigned int> zombieCountOffset = { 0x3C };
	// Zombie Feature Values
	int iZombieCurrentHealthValue;
	int iZombieNewHealthValue = 1;
	int iZombieNewCriticalValue = -1;
	int iZombieCountValue;
	float currentZombiesCoordsX;
	float currentZombiesCoordsY;
	float currentZombiesCoordsZ;
	float currentZombiesCoordsHeadX;
	float currentZombiesCoordsHeadY;
	float currentZombiesCoordsHeadZ;
	//Vec3 currentZombiesCoordsHeadXYZ;
	float zombieDistance;
	float closestZombie;
	uintptr_t zombieTarget = 0;
} ZombieOffsets;

struct Global_Offsets
{
	uintptr_t inGamePtr = 0x19C7A0BC;
	uintptr_t inGameAddr;
	uintptr_t jumpHeightPtr = 0x03079A34;
	uintptr_t jumpHeightBase;
	// Global Game Feature Values
	int iInGameValue = 0;
	float globalNewJumpHeightValue = 39.f;
	float globalDefaultJumpHeightValue = 39.f;
	float globalJetPackValue;
	float globalJetPackAddValue = 8.f;
} GlobalOffsets;

struct Visuals
{
	bool bZombieSnaplines = false;
	bool bZombie2DBox = false;
	bool bZombie2DBrackets = false;
	bool bZombie2DBracketsRainbow = false;
	bool bZombie2DBoxesRainbow = false;
	bool bZombieSnaplinesRainbow = false;
	bool bZombieCrosshairRainbow = false;
	bool bZombieFovRainbow = false;
	float boxColor[4] = { 0, 0.872, 1, 1 };
	float bracketBoxColor[4] = { 0, 0.872, 1, 1 };
	float snaplineColor[4] = { 0, 0.872, 1, 1 };
	float crosshairColor[4] = { 1, 1, 1, 1 };
	float fovColor[4] = { 1, 1, 1, 1 };
	float zombieCounterColor[4] = {0, 0.872, 1, 1};
	float zombieCounterValueColor[4] = { 1, 1, 1, 1 };
	//
	ImVec4 whiteText = ImVec4(255.f / 255.f, 255.f / 255.f, 255.f / 255.f, 1.0f);
	ImVec4 blackText = ImVec4(0.f / 255.f, 0.f / 255.f, 0.f / 255.f, 1.0f);
	ImColor boxImColor = ImColor(boxColor[0], boxColor[1], boxColor[2]);
	ImColor bracketBoxImColor = ImColor(bracketBoxColor[0], bracketBoxColor[1], bracketBoxColor[2]);
	ImColor snaplineImColor = ImColor(snaplineColor[0], snaplineColor[1], snaplineColor[2]);
	ImColor crosshairImColor = ImColor(crosshairColor[0], crosshairColor[1], crosshairColor[2]);
	ImColor fovImColor = ImColor(fovColor[0], fovColor[1], fovColor[2]);
	ImColor zombieCounterImColor = ImColor(zombieCounterColor[0], zombieCounterColor[1], zombieCounterColor[2]);
	ImColor zombieCounterValueImColor = ImColor(zombieCounterValueColor[0], zombieCounterValueColor[1], zombieCounterValueColor[2]);
} VisualSettings;

struct Aim
{
	float fovLimit;
	float aimSmooth = 1.f;
	int aimkey = 0x5;
} AimSettings;

struct Misc
{
	bool bCrosshairFeature = false;
	bool bPlayerFov = false;
	float playerFovSize = 175;
} MiscSettings;