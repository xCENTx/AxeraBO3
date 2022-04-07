/*
	░█████╗░██╗░░██╗███████╗██████╗░░█████╗░░░░██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░
	██╔══██╗╚██╗██╔╝██╔════╝██╔══██╗██╔══██╗░░░██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░
	███████║░╚███╔╝░█████╗░░██████╔╝███████║░░░██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░
	██╔══██║░██╔██╗░██╔══╝░░██╔══██╗██╔══██║░░░██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░
	██║░░██║██╔╝╚██╗███████╗██║░░██║██║░░██║██╗██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗
	╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝
	
	-- Axera.Digital BO3 Zombie Tool ( Open Source )

	-- Coded by noodle@axera.digital && sonic@axera.digital

	-- Visit Us @https://axera.digital
*/

#include "BO3_Main.h"

int main()
{
	GeneralPurpose::SetConsoleAppInfo();
	GeneralPurpose::GrabGameInfo();
	GeneralPurpose::CreateThreads();
	while (true)
	{
		Engine_Base::Player1Features();
		Engine_Base::Player2Features();
		Engine_Base::Player3Features();
		Engine_Base::Player4Features();
		Engine_Base::ExtraGoodieFeatures();
		Engine_Base::DisableAllFeatures();
		Sleep(5);
	}
}
