/*
	DayZ SA Survival Mod
	
	FileName: ServerCfg.c
	
	Usage:
	Main Mod Configuration.
	
	//name
		init variables, arrays and any other needed
		#include config file
		#include function

	Authors: DayZ SA Dayz Survival Team(see credits.md)
	
	
	This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/

#include "$CurrentDir:\\mpmissions\\DSOffline.chernarusplus\\DS\\Community\\loadouts.c"

class DSCommunity : MissionServer
{		
	
	protected ref map<string, string> m_CommAdminList;
	protected ref map<string, string> m_CommVIPList;
	protected ref map<string, string> m_CommMemberList;
	
	protected PlayerBase Admin;
	protected PlayerIdentity identityT;
	protected string PlayerUID;
	protected string GUID;
	
	protected string m_MemberListPath = "$CurrentDir:\\mpmissions\\DSOffline.chernarusplus\\DS\\Community\\";
		
	void DSCommunity()
	{
		Print("VANILLA PLUS PLUS IS ALIVE!!");
	}
	
	void ~DSCommunity()
	{
		
	}

	override void OnInit()
	{
		super.OnInit();
		
		Print("Loading DSCommunity Mods...");
		
		m_CommAdminList    = new map<string, string>; //UID, name
		m_CommVIPList    = new map<string, string>; //UID, name
		m_CommMemberList    = new map<string, string>; //UID, name

		//-----Add Admins from txt-----
		FileHandle CommAdminUIDSFile = OpenFile(m_MemberListPath + "CommAdmins.txt",FileMode.READ);
		if (CommAdminUIDSFile != 0)
		{
			string adminline_content = "";
			while ( FGets(CommAdminUIDSFile,adminline_content) > 0 )
			{
				m_CommAdminList.Insert(adminline_content,"null"); //UID , NAME
				Print("Adding Admins: "+ adminline_content + " To the Community Admin List!");
			}
			CloseFile(CommAdminUIDSFile);
		}

		//-----Add VIPs from txt-----
		FileHandle CommVIPUIDSFile = OpenFile(m_MemberListPath + "CommVIPs.txt",FileMode.READ);
		if (CommVIPUIDSFile != 0)
		{
			string VIPline_content = "";
			while ( FGets(CommVIPUIDSFile,VIPline_content) > 0 )
			{
				m_CommVIPList.Insert(VIPline_content,"null"); //UID , NAME
				Print("Adding VIPs: "+ VIPline_content + " To the Community VIP List!");
			}
			CloseFile(CommVIPUIDSFile);
		}

		//-----Add Members from txt-----
		FileHandle CommMemberUIDSFile = OpenFile(m_MemberListPath + "CommMembers.txt",FileMode.READ);
		if (CommMemberUIDSFile != 0)
		{
			string Memline_content = "";
			while ( FGets(CommMemberUIDSFile,Memline_content) > 0 )
			{
				m_CommMemberList.Insert(Memline_content,"null"); //UID , NAME
				Print("Adding Members: "+ Memline_content + " To the Community Member List!");
			}
			CloseFile(CommMemberUIDSFile);
		}
		
		//-----Setup Server Messaging system-----
		Print("[DS]: Setting up msg system...");
		
	
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(NumPlayersOnServer, 120 * 1000, true);  // 60 seconds
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(MainServerMessages, 1200 * 1000, true);  // 30 Min = 1800
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(rMessages1, 9900 * 1000, true);  // 30 Min = 1800
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(rMessages2, 10200 * 1000, true);  // 30 Min = 1800
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(rMessages3, 10500 * 1000, true);  // 30 Min = 1800
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(rMessages4, 10740 * 1000, true);  // 30 Min = 1800
		
		Print("[DS]: msg setup completed...");
		//-----End Setup Server Messaging system-----
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
		
	}
	
	void GlobalMessage(int Channel, string Message)
	{
		if (Message != "")
		{
			GetGame().ChatPlayer(Channel,Message);
		}
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
		
		//Geting plaer ID
		PlayerUID = player.GetIdentity().GetPlainId();
		
		
		//Community Admin Starting Equip
		if (m_CommAdminList.Contains( PlayerUID ))
		{
			Print("Player: "+ PlayerUID + " is a Community admin, granting admin Starting Equip.");
			AdminPlayerSetup adminobj = new AdminPlayerSetup(player);
		}
		
		//Community VIP Starting Equip
		else if (m_CommVIPList.Contains( PlayerUID ))
		{
			Print("Player: "+ PlayerUID + " is a Community VIP, granting VIP Starting Equip.");
			VIPPlayerSetup vipobj = new VIPPlayerSetup(player);
		}
		
		//Community Member Starting Equip
		else if (m_CommMemberList.Contains( PlayerUID ))
		{
			Print("Player: "+ PlayerUID + " is a Community member, granting member Starting Equip.");
			MemberPlayerSetup memberobj = new MemberPlayerSetup(player);
		}
		
		//Default player Starting Equip
		else 
		{
			DefaultPlayerSetup defaultobj = new DefaultPlayerSetup(player);
		}
		
	}
}	