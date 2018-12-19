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
//#include "$CurrentDir:\\mpmissions\\DSOffline.chernarusplus\\DS\\Configs\\CommunityCfg.c"
#include "$CurrentDir:\\mpmissions\\DSOffline.chernarusplus\\DS\\Community\\loadouts.c"

class CustomMission: MissionServer
{		
	void CustomMission()
	{
		Print("VANILLA PLUS PLUS IS ALIVE!!");
	}
	
	void ~CustomMission()
	{
		
	}

	override void OnInit()
	{
		Hive ce = CreateHive();
		if ( ce )
		ce.InitOffline();
	}

		override void OnPreloadEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int queueTime)
	{
		if (GetHive())
		{
			useDB = true;
			queueTime = 3;
		}
		else
		{
			useDB = false;
			pos = "7500 0 7500";
			yaw = 0;
			queueTime = 3;
		}
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.PlayerCounter, 110000, true);  //Default 120000 2 mins Looped
	}
	
	void GlobalMessage(int Channel, string Message)
	{
		if (Message != "")
		{
			GetGame().ChatPlayer(Channel,Message);
		}
	}
	
	void PlayerCounter()
	{
		array<Man> players = new array<Man>;
	    GetGame().GetPlayers( players );
	    int numbOfplayers = players.Count();
	    GlobalMessage(1,"Online Players: "+ numbOfplayers.ToString());
	}

	override void TickScheduler(float timeslice)
	{
		GetGame().GetWorld().GetPlayerList(m_Players);
		if( m_Players.Count() == 0 ) return;
		for(int i = 0; i < SCHEDULER_PLAYERS_PER_TICK; i++)
		{
			if(m_currentPlayer >= m_Players.Count() )
			{
				m_currentPlayer = 0;
			}

			PlayerBase currentPlayer = PlayerBase.Cast(m_Players.Get(m_currentPlayer));
			currentPlayer.OnTick();

			currentPlayer.GetStaminaHandler().SyncStamina(1000,1000);
            currentPlayer.GetStatStamina().Set(currentPlayer.GetStaminaHandler().GetStaminaCap());
		}
	}
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
		
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		
		DefaultPlayerSetup pobj = new DefaultPlayerSetup(player);
	}
}	