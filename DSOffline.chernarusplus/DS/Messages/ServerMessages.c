/*
	DayZ SA Survival Mod
	
	FileName: ServerMessages.c
	
	Usage:
	All server messages are in this file.
	
	//name
		init variables, arrays and any other needed
		#include config file
		#include function

	Authors: DayZ SA Dayz Survival Team(see credits.md)
	FNR:ModTeamInfo
	
	This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
	void ServerMessagingSystem(string ServerMsg)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		for ( int i = 0; i < players.Count(); ++i )
		{
			Man player = players.Get(i);
			if( player )
			{
				Param1<string> m_MessageParam = new Param1<string>(ServerMsg);
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
			}
		}
	}
	
	void rMessages1()
	{
		string rMsg1 =  "[DS]: WARNING SERVER RESTART IN 15 MINS";
		ServerMessagingSystem(rMsg1);
	}

	void rMessages2()
	{
		string rMsg2 =  "[DS]: WARNING SERVER RESTART IN 10 MINS";
		ServerMessagingSystem(rMsg2);
	}

	void rMessages3()
	{
		string rMsg3 =  "[DS]: WARNING SERVER RESTART IN 5 MINS";
		ServerMessagingSystem(rMsg3);
	}

	void rMessages4()
	{
		string rMsg4 =  "[DS]: WARNING SERVER RESTART IN 1 MIN";
		ServerMessagingSystem(rMsg4);
	}

	void MainServerMessages()
	{
		string messages[6] = {"[DS]: Welcome To Dayz Survival Server 3", "[DS]: Become a member for Customized Loadouts(limited time)", "[DS]: https://dayzsurvival.com","[DS]: Discord: https://discord.gg/E2zEtTx","",""};
		for ( int m = 0; m < 6; ++m )
		{
			ServerMessagingSystem(messages[m]);;
		}
	}
	
	void PlayerServerMessages()
	{
		string plyMsg[6] = {"[DS]: Welcome To Dayz Survival Server 3", "[DS]: Become a member for Customized Loadouts(limited time)", "[DS]: https://dayzsurvival.com","[DS]: Discord: https://discord.gg/E2zEtTx","",""};
		for ( int mPly = 0; mPly < 6; ++mPly )
		{
			ServerMessagingSystem(plyMsg[mPly]);;
		}
	}


	void ServerMessages4()
	{
		string messages4 =  "[DS]: Welcome To Dayz Survival Server 3";
		ServerMessagingSystem(messages4);
	}
	
	void NumPlayersOnServer()
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		string msg = "[DS]: Current player count is: " + players.Count().ToString();
		ServerMessagingSystem(msg);
	}
