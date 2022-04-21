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
#include <string>
#include <vector>
#include <functional>
#include "../Global_Vars/Variables.h"

#define MAX_RGB 255.0
#define HELPMARKERDESC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ ? ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#define HELPMARKERDISC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ * ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#pragma warning(disable: 26812 26815)

namespace ImGui
{
	void Line(int newId)
	{
		std::string id = ("ImGui_Sauce_line_" + std::to_string(newId));
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		{
			ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::PopStyleColor();
	}

	void Linevertical()
	{
		ImGui::SameLine();
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::SameLine();
	}

	void CenterText(const char* text, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}

	float GetX()
	{
		return ImGui::GetContentRegionAvail().x;
	}

	float GetY()
	{
		return ImGui::GetContentRegionAvail().y;
	}

	void GUITheme()
	{
		ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_PickerHueWheel);
		ImGuiStyle* Style = &ImGui::GetStyle();
		Style->WindowBorderSize = 0;
		Style->FrameBorderSize = 0;
		Style->ChildBorderSize = 0;
		Style->WindowRounding = 0;
		Style->ChildRounding = 0;
		Style->FrameRounding = 0;
		Style->ScrollbarSize = 0;
		Style->WindowPadding = ImVec2(0, 0);
		Style->FramePadding = ImVec2(0, 0);
		Style->ItemSpacing = ImVec2(0, 0);
		Style->ItemInnerSpacing = ImVec2(0, 0);
		Style->IndentSpacing = 0;
		Style->DisplayWindowPadding = ImVec2(0, 0);
		Style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
		Style->Colors[ImGuiCol_Border] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
		Style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
		//Style->Colors[ImGuiCol_WindowBg] = ImColor(255, 255, 255);
		Style->Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
		Style->Colors[ImGuiCol_FrameBg] = ImColor(40, 40, 40, 155); // 40, 40, 40, 155
		Style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_FrameBgActive] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 255);
		Style->Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 255);
	}

#pragma region MainGUISetup
	void SetupDoubleButtonFeature(int pos1Value, int pos2Value, const char* button1Name, bool* feature1, const char* button2Name, bool* feature2)
	{
		ImGui::SetCursorPosX(pos1Value);
		if (ImGui::Button(button1Name, ImVec2(75, 20)))
		{
			*feature1 = true;
		}
		ImGui:SameLine();
		ImGui::SetCursorPosX(pos2Value);
		if (ImGui::Button(button2Name, ImVec2(75, 20)))
		{
			*feature2 = true;
		}
		ImGui::NewLine();
	}

	void SetupIntSliderFeature(int posValue, int sliderWidth, const char* sliderName, bool* feature, int* sliderInt)
	{
		ImGui::SetCursorPosX(posValue);
		ImGui::PushItemWidth(sliderWidth);
		if (ImGui::InputInt(sliderName, sliderInt, 1))
		{
			*feature = true;
		}
		ImGui::PopItemWidth();
		ImGui::NewLine();
	}

	void SetupFloatSliderFeature(int posValue, int sliderWidth, const char* sliderName, bool* feature, float* sliderfloat, float sliderMin, float sliderMax)
	{
		ImGui::SetCursorPosX(posValue);
		ImGui::PushItemWidth(sliderWidth);
		if (ImGui::SliderFloat(sliderName, sliderfloat, sliderMin, sliderMax))
		{
			*feature = true;
		}
		ImGui::PopItemWidth();
		ImGui::NewLine();
	}

	void SetupColorEditFeature(int posValue, const char* colorEditName, float* colorEditFloatValue)
	{
		ImGui::SetCursorPosX(posValue);
		ImGui::ColorEdit3(colorEditName, colorEditFloatValue, ImGuiColorEditFlags_NoInputs);
		ImGui::NewLine();
	}

	void SetupCheckboxFeatures(int posValue, const char* featureName, bool* feature)
	{
		ImGui::SetCursorPosX(posValue);
		ImGui::Checkbox(featureName, feature);
		ImGui::NewLine();
	}

	void SetupButtonTabs()
	{
		ImGui::SetCursorPosX(35);
		if (ImGui::Button("[ Player 1 ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 1;
		}
		ImGui::SameLine();
		ImGui::SetCursorPosX(145);
		if (ImGui::Button("[ Player 2 ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 2;
		}
		ImGui::SameLine();
		ImGui::SetCursorPosX(255);
		if (ImGui::Button("[ Player 3 ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 3;
		}
		ImGui::SameLine();
		ImGui::SetCursorPosX(365);
		if (ImGui::Button("[ Player 4 ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 4;
		}
		ImGui::NewLine();
		ImGui::SetCursorPosX(145);
		if (ImGui::Button("[ Goodies ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 5;
		}
		ImGui::SameLine();
		ImGui::SetCursorPosX(255);
		if (ImGui::Button("[ Settings ]", ImVec2(100, 20)))
		{
			GlobalVars.iTab = 6;
		}
	}

	void SetupPlayer1Features()
	{
		SetupCheckboxFeatures(15, "  Godmode", &FeatureBools.bP1InfiniteHealth);
		SetupCheckboxFeatures(15, "  Unlimited Clip", &FeatureBools.bP1InfiniteClipAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Stock", &FeatureBools.bP1InfiniteStockAmmo);
		SetupIntSliderFeature(15, 90, "  Custom Points", &FeatureBools.bP1InfinitePoints, &PlayerOffsets.iPlayerNewCustomPointsValue);
		//SetupCheckboxFeatures(15, "  Unlimited Points", &FeatureBools.bP1InfinitePoints); ( This Hard Sets Points )
		SetupDoubleButtonFeature(15, 100, "Recoil Off", &FeatureBools.bNoRecoilOn, "Recoil On", &FeatureBools.bNoRecoilOff);
		SetupCheckboxFeatures(15, "  Rapid Fire", &FeatureBools.bP1RapidFire);
		SetupIntSliderFeature(15, 75, "  Weapon Cycle", &FeatureBools.bP1WCycle, &PlayerOffsets.iPlayer1NewWeaponValue);
		SetupFloatSliderFeature(15, 150, "  Jump Height", &FeatureBools.bP1JumpHeight, &GlobalOffsets.globalNewJumpHeightValue, 39.f, 1000.f);
		SetupFloatSliderFeature(15, 150, "  Jet Pack", &FeatureBools.bJetPack, &GlobalOffsets.globalJetPackAddValue, 8.f, 200.f);
	}

	void SetupPlayer2Features()
	{
		SetupCheckboxFeatures(15, "  Godmode", &FeatureBools.bP2InfiniteHealth);
		SetupCheckboxFeatures(15, "  Unlimited Clip", &FeatureBools.bP2InfiniteClipAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Stock", &FeatureBools.bP2InfiniteStockAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Points", &FeatureBools.bP2InfinitePoints);
		SetupCheckboxFeatures(15, "  Rapid Fire", &FeatureBools.bP2RapidFire);
		SetupIntSliderFeature(15, 75, "  Weapon Cycle", &FeatureBools.bP2WCycle, &PlayerOffsets.iPlayer2NewWeaponValue);
	}

	void SetupPlayer3Features()
	{
		SetupCheckboxFeatures(15, "  Godmode", &FeatureBools.bP3InfiniteHealth);
		SetupCheckboxFeatures(15, "  Unlimited Clip", &FeatureBools.bP3InfiniteClipAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Stock", &FeatureBools.bP3InfiniteStockAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Points", &FeatureBools.bP3InfinitePoints);
		SetupCheckboxFeatures(15, "  Rapid Fire", &FeatureBools.bP3RapidFire);
		SetupIntSliderFeature(15, 75, "  Weapon Cycle", &FeatureBools.bP3WCycle, &PlayerOffsets.iPlayer3NewWeaponValue);
	}

	void SetupPlayer4Features()
	{
		SetupCheckboxFeatures(15, "  Godmode", &FeatureBools.bP4InfiniteHealth);
		SetupCheckboxFeatures(15, "  Unlimited Clip", &FeatureBools.bP4InfiniteClipAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Stock", &FeatureBools.bP4InfiniteStockAmmo);
		SetupCheckboxFeatures(15, "  Unlimited Points", &FeatureBools.bP4InfinitePoints);
		SetupCheckboxFeatures(15, "  Rapid Fire", &FeatureBools.bP4RapidFire);
		SetupIntSliderFeature(15, 75, "  Weapon Cycle", &FeatureBools.bP4WCycle, &PlayerOffsets.iPlayer4NewWeaponValue);
	}

	void SetupExtraGoodies()
	{
		SetupCheckboxFeatures(15, "  Zombie Insta Kill", &FeatureBools.bP1AlwaysInstaKill);
		SetupCheckboxFeatures(15, "  Zombie Teleport", &FeatureBools.bZombieTP);
		SetupCheckboxFeatures(15, "  2D Box ESP", &VisualSettings.bZombie2DBox);
		SetupCheckboxFeatures(15, "  2D Bracket ESP", &VisualSettings.bZombie2DBrackets);
		SetupCheckboxFeatures(15, "  Snapline ESP", &VisualSettings.bZombieSnaplines);
		SetupCheckboxFeatures(15, "  Crosshair +", &MiscSettings.bCrosshairFeature);
		SetupCheckboxFeatures(15, "  FOV Circle", &MiscSettings.bPlayerFov);
		SetupCheckboxFeatures(15, "  Zombie Counter", &FeatureBools.bZombieCount);
		SetupCheckboxFeatures(15, "  Aimbot ( Beta )", &FeatureBools.bAimbot);
	}

	void SetupSettings()
	{
		SetupColorEditFeature(15, "  2D Box Color", (float*)&VisualSettings.boxImColor);
		SetupColorEditFeature(15, "  2D Bracket Color", (float*)&VisualSettings.bracketBoxImColor);
		SetupColorEditFeature(15, "  Snapline Color", (float*)&VisualSettings.snaplineImColor);
		SetupColorEditFeature(15, "  Crosshair Color", (float*)&VisualSettings.crosshairImColor);
		SetupColorEditFeature(15, "  FOV Color", (float*)&VisualSettings.fovImColor);
	}

	void SetupMainGUIInterface()
	{
		ImGui::NewLine();
		ImGui::CenterText("Axera Dev Squad | Open Source BO3 ZM Tool", 0, false);
		ImGui::NewLine();
		ImGui::NewLine();
		SetupButtonTabs();
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::NewLine();
		if (GlobalVars.iTab == 1)
		{
			CenterText("-- Player 1 Features --", 0, false);
			ImGui::NewLine();
			SetupPlayer1Features();
		}
		if (GlobalVars.iTab == 2)
		{
			CenterText("-- Player 2 Features --", 0, false);
			ImGui::NewLine();
			SetupPlayer2Features();
		}
		if (GlobalVars.iTab == 3)
		{
			CenterText("-- Player 3 Features --", 0, false);
			ImGui::NewLine();
			SetupPlayer3Features();
		}
		if (GlobalVars.iTab == 4)
		{
			CenterText("-- Player 4 Features --", 0, false);
			ImGui::NewLine();
			SetupPlayer4Features();
		}
		if (GlobalVars.iTab == 5)
		{
			CenterText("-- Goodies Features --", 0, false);
			ImGui::NewLine();
			SetupExtraGoodies();
		}
		if (GlobalVars.iTab == 6)
		{
			CenterText("-- Settings --", 0, false);
			ImGui::NewLine();
			SetupSettings();
		}
	}
#pragma endregion
}