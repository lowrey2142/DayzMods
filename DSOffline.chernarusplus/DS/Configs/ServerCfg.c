/*
	DayZ SA Survival Mod
	
	FileName: DSPreInit.c
	
	Usage:
	Main Mod Configuration.
	
	//name
		init variables, arrays and any other needed
		#include config file
		#include function

	Authors: DayZ SA Dayz Survival Team(see credits.md)
	FNR:ModTeamInfo
	
	This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/

class ServerCfg
{
	protected bool DS_StaminaStatus     = true;  //set to true to disable Stamina	
	
	void ServerCfg( CustomMission missionServer )
		{
			
		}
		
		void ~ServerCfg()
		{
			
		}

}