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

#include "ESP_Base.h"
#include "../Tool_Utilities/Utils.h"

inline float Distance_Cursor(Vec2 vec)
{
	POINT p;
	if (GetCursorPos(&p))
	{
		float ydist = (vec.y - p.y);
		float xdist = (vec.x - p.x);
		float ret = sqrt(pow(ydist, 2) + pow(xdist, 2));
		return ret;
	}
}

Vec2 Smooth(Vec2 pos)
{
	Vec2 center{ (float)(GlobalVars.iScreenWidth / 2), (float)(GlobalVars.iScreenHeight / 2) };
	Vec2 target{ 0, 0 };
	if (pos.x != 0) {
		if (pos.x > center.x) {
			target.x = -(center.x - pos.x);
			target.x /= 1;
			if (target.x + center.x > center.x * 2)
				target.x = 0;
		}

		if (pos.x < center.x) {
			target.x = pos.x - center.x;
			target.x /= 1;
			if (target.x + center.x < 0)
				target.x = 0;
		}
	}

	if (pos.y != 0) {
		if (pos.y > center.y) {
			target.y = -(center.y - pos.y);
			target.y /= 1;
			if (target.y + center.y > center.y * 2)
				target.y = 0;
		}

		if (pos.y < center.y) {
			target.y = pos.y - center.y;
			target.y /= 1;
			if (target.y + center.y < 0)
				target.y = 0;
		}
	}

	target.x /= AimSettings.aimSmooth;
	target.y /= AimSettings.aimSmooth;

	if (abs(target.x) < 1) {
		if (target.x > 0) {
			target.x = 1;
		}
		if (target.x < 0) {
			target.x = -1;
		}
	}
	if (abs(target.y) < 1) {
		if (target.y > 0) {
			target.y = 1;
		}
		if (target.y < 0) {
			target.y = -1;
		}
	}

	return target;
}

void Mouse_Aim(Vec2 target)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = target.x;
	input.mi.dy = target.y;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
}

bool WorldToScreen(Vec3 pos, Vec2& screen, float matrix[16], int windowWidth, int windowHeight)
{
	Vec4 clipCoords;
	clipCoords.x = pos.x * matrix[0] + pos.y * matrix[1] + pos.z * matrix[2] + matrix[3];
	clipCoords.y = pos.x * matrix[4] + pos.y * matrix[5] + pos.z * matrix[6] + matrix[7];
	clipCoords.z = pos.x * matrix[8] + pos.y * matrix[9] + pos.z * matrix[10] + matrix[11];
	clipCoords.w = pos.x * matrix[12] + pos.y * matrix[13] + pos.z * matrix[14] + matrix[15];

	if (clipCoords.w < 0.1f)
		return false;


	Vec3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;

	screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
	return true;
}

namespace Feature_Base
{
	void DoESP()
	{
		if (Zombie->GetZombieCount() > 1)
		{
			for (uintptr_t i = 0; i < 80; i++)
			{
				Utils::Read((BYTE*)PlayerOffsets.playerPedHealthAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.iZombieCurrentHealthValue, sizeof(ZombieOffsets.iZombieCurrentHealthValue), hProc);

				if (ZombieOffsets.iZombieCurrentHealthValue < 1)
					continue;

				Utils::Read((BYTE*)PlayerOffsets.playerXCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsX, sizeof(PlayerOffsets.currentPlayerCoordsX), hProc);
				Utils::Read((BYTE*)PlayerOffsets.playerYCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsY, sizeof(PlayerOffsets.currentPlayerCoordsY), hProc);
				Utils::Read((BYTE*)PlayerOffsets.playerZCoordAddr, (BYTE*)&PlayerOffsets.currentPlayerCoordsZ, sizeof(PlayerOffsets.currentPlayerCoordsZ), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesXCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsX, sizeof(ZombieOffsets.currentZombiesCoordsX), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesYCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsY, sizeof(ZombieOffsets.currentZombiesCoordsY), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesZCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsZ, sizeof(ZombieOffsets.currentZombiesCoordsZ), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesHeadXCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsHeadX, sizeof(ZombieOffsets.currentZombiesCoordsHeadX), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesHeadYCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsHeadY, sizeof(ZombieOffsets.currentZombiesCoordsHeadY), hProc);
				Utils::Read((BYTE*)ZombieOffsets.zombiesHeadZCoordAddr + (ZombieOffsets.zombieArraySize * i), (BYTE*)&ZombieOffsets.currentZombiesCoordsHeadZ, sizeof(ZombieOffsets.currentZombiesCoordsHeadZ), hProc);

				float Matrix[16];
				Vec2 vScreen;
				Vec2 vHead;
				DWORD viewMatrix = 0x36772A0;
				Utils::Read((BYTE*)GlobalVars.moduleBase + viewMatrix, (BYTE*)&Matrix, sizeof(Matrix), hProc);

				Vec3 zombie_Pos = { ZombieOffsets.currentZombiesCoordsX, ZombieOffsets.currentZombiesCoordsY, ZombieOffsets.currentZombiesCoordsZ };
				Vec3 zombie_Head_Pos = { ZombieOffsets.currentZombiesCoordsHeadX - 10.f, ZombieOffsets.currentZombiesCoordsHeadY - 20.f, ZombieOffsets.currentZombiesCoordsHeadZ - 10.f };
				Vec3 player_Pos = { PlayerOffsets.currentPlayerCoordsX, PlayerOffsets.currentPlayerCoordsY, PlayerOffsets.currentPlayerCoordsZ };
				AimSettings.fovLimit = FLT_MAX;
				ZombieOffsets.zombieTarget = 0;

				if (WorldToScreen(zombie_Pos, vScreen, Matrix, GlobalVars.iScreenWidth, GlobalVars.iScreenHeight))
				{
					if (WorldToScreen(zombie_Head_Pos, vHead, Matrix, GlobalVars.iScreenWidth, GlobalVars.iScreenHeight))
					{
						float headHeight = vHead.y - vScreen.y;
						float width = headHeight / 2;
						float center = width / -2;
						Vec3 zombie_Coords_Total = { headHeight , width , center };
						if (VisualSettings.bZombieSnaplines)
						{
							Render::Line(ImVec2(GlobalVars.iScreenWidth / 2, GlobalVars.iScreenHeight / 2), ImVec2(vScreen.x, vHead.y), VisualSettings.snaplineImColor, 1.f);
						}
						if (VisualSettings.bZombie2DBrackets)
						{
							Render::DrawBoxBrackets(ImGui::GetWindowDrawList(), vScreen.x + center, vScreen.y, width, headHeight, VisualSettings.bracketBoxImColor, 1.f);
						}
						if (VisualSettings.bZombie2DBox)
						{
							Render::DrawBox(VisualSettings.boxImColor, vScreen.x + center, vScreen.y, width, headHeight);
						}
						if (FeatureBools.bAimbot)
						{
							auto fov = Distance_Cursor(vHead);

							if (fov < MiscSettings.playerFovSize)
							{
								if (GetAsyncKeyState(VK_LMENU))
								{
									vHead.y = vHead.y + 15.f;
									vHead = { vHead.x, vHead.y };
									Mouse_Aim(Smooth(vHead));
								}
							}
						}
					}
				}
			}
		}
	}

	void MiscFeatures()
	{
		if (MiscSettings.bCrosshairFeature)
		{
			// Small Crosshair in the Center of the Screen.
			constexpr long crosshairSize = 10.0f;
			ImVec2 center = ImVec2(WND_SIZEX / 2, WND_SIZEY / 2);
			Render::Line(ImVec2((center.x), (center.y) - crosshairSize), ImVec2((center.x), (center.y) + crosshairSize), VisualSettings.crosshairImColor, 1.5f);
			Render::Line(ImVec2((center.x) - crosshairSize, (center.y)), ImVec2((center.x) + crosshairSize, (center.y)), VisualSettings.crosshairImColor, 1.5f);
		}
		if (MiscSettings.bPlayerFov)
		{
			// Center Screen.
			Render::Circle(VisualSettings.fovImColor, MiscSettings.playerFovSize);
		}
		if (FeatureBools.bZombieCount)
		{
			// Draw Zombie Counter in Bottom Left Screen.
			Render::EasyText(ImVec2(10, GlobalVars.iScreenHeight - 30), VisualSettings.zombieCounterImColor, "Zombie Count: ", 15.f);
			Render::EasyNumber(ImVec2(100, GlobalVars.iScreenHeight - 30), VisualSettings.zombieCounterValueImColor, ZombieOffsets.iZombieCountValue, 15.f);
		}
	}

	void FeatureLoop()
	{
		DoESP();
		MiscFeatures();
	}
};