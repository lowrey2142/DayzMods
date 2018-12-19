
class Community extends CustomMission
{
	protected ref map<string, string> m_CommAdminList;
	protected ref map<string, string> m_CommVIPList;
	protected ref map<string, string> m_CommMemberList;
	
	protected PlayerBase Admin;
	protected PlayerIdentity identityT;
	protected string PlayerUID;
	protected string GUID;
	
	protected string m_MemberListPath = "$CurrentDir:\\mpmissions\\DSOffline.chernarusplus\\DS\\Community\\";
	
	override void Init()
	{
		Print("Community:: Init():: Loading Community Mods...");
		
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
	}
	
	void Community( CustomMission missionServer )
	{

	}
	
	void ~Community()
	{
		
	}
}
