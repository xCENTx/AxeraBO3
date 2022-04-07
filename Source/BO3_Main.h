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
#include "../Includes/Includes.h"
#include "../Engine/Engine_Base.h"
#include "../Engine/ESP_Base.h"
#include "../Tool_Utilities/Utils.h"
#include "../Extra_Headers/Display_Messages.h"
#include "../Global_Vars/Variables.h"
#include "../Overlay/Overlay.h"

namespace GeneralPurpose
{
	// Simple Random String Generator Function.
	std::string chars{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?" };
	std::random_device rd;
	std::mt19937 generator(rd());
	std::string RandStr(size_t length)
	{
		const size_t char_size = chars.size();
		std::uniform_int_distribution<> random_int(0, char_size - 1);
		std::string output;
		for (size_t i = 0; i < length; ++i)
			output.push_back(chars[random_int(generator)]);
		return output;
	}

	// Set Console App Title and Window Foreground Setting.
	void SetConsoleAppInfo()
	{
		SetConsoleTitle(RandStr(12).c_str());
		HWND console = GetConsoleWindow();
		ShowWindow(console, FALSE);
	}

	// Grab Pid and Module Base.
	void GrabGameInfo()
	{
		procID = Utils::GetProcId("BlackOps3.exe");
		hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		if (procID < 1)
		{
			Message::Load_Game();
			//exit(0);
		}
		else if (procID > 1)
		{
			GlobalVars.moduleBase = Utils::GetModuleBaseAddress(procID, "BlackOps3.exe");
		}
	}

	// Create our Separate Threads so ESP is as smooth as possible.
	void CreateThreads()
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Overlay::Loop, nullptr, 0, nullptr);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Engine_Base::GetPlayerCoords, nullptr, 0, nullptr);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Engine_Base::GetZombieCoords, nullptr, 0, nullptr);
	}
};