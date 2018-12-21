class DefaultPlayerSetup
{
	private PlayerBase player;
	
	void DefaultPlayerSetup(PlayerBase m_player)
	{
		TStringArray tops = {"Shirt_BlueCheck","Shirt_RedCheck","Shirt_GreenCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","HikingJacket_Blue","HikingJacket_Green","HikingJacket_Red","Sweater_Blue","Sweater_Gray","Sweater_Green","Sweater_Red","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White"};
		TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		TStringArray bags = {"courierbag"};
		TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Grey","HikingBoots_Black","HikingBoots_Brown","HikingJacket_Black"};
		TStringArray tool = {"OrienteeringCompass","PurificationTablets","RoadFlare"};
		TStringArray medic = {"Rags","BandageDressing"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
		TStringArray food = {"PeachesCan","Apple","PowderedMilk","PeachesCan","Pear"};
		
		this.player = m_player;
		     
		player.RemoveAllItems();
		
		EntityAI itemEnt;
		EntityAI itemIn;
		ItemBase itemBs;
		
		EntityAI item = player.GetInventory().CreateInInventory(tops.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item2 = player.GetInventory().CreateInInventory(pants.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item3 = player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item4 = player.GetInventory().CreateInInventory(bags.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
				
		itemEnt = player.GetInventory().CreateInInventory(tool.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(medic.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(food.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("StoneKnife");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Flashlight");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("SardinesCan");
		itemBs = ItemBase.Cast(itemEnt);
	}

};

class AdminPlayerSetup
{
	private PlayerBase player;
	
	void AdminPlayerSetup(PlayerBase m_player)
	{
		TStringArray tool = {"OrienteeringCompass","PurificationTablets","RoadFlare"};
		TStringArray medic = {"Rags","BandageDressing"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
		TStringArray food = {"PeachesCan","Apple","PowderedMilk","PeachesCan","Pear"};
		
		this.player = m_player;
		
		player.RemoveAllItems(); 
		
		EntityAI itemEnt;
		EntityAI itemIn;
		ItemBase itemBs;
				
		EntityAI item = player.GetInventory().CreateInInventory("HuntingJacket_Summer");
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item2 = player.GetInventory().CreateInInventory("HunterPants_Summer");
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item3 = player.GetInventory().CreateInInventory("HikingBootsLow_Black");
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item4 = player.GetInventory().CreateInInventory("AssaultBag_Green");
		itemBs = ItemBase.Cast(itemEnt);
				
		itemEnt = player.GetInventory().CreateInInventory(tool.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(medic.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(food.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(food.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("CombatKnife");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Flashlight");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("PeachesCan");
		itemBs = ItemBase.Cast(itemEnt);
	}
}
	
//VIP Loadout
class VIPPlayerSetup
{
	private PlayerBase player;
	
	void VIPPlayerSetup(PlayerBase m_player)
	{
		TStringArray tops = {"Shirt_BlueCheck","Shirt_RedCheck","Shirt_GreenCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","HikingJacket_Blue","HikingJacket_Green","HikingJacket_Red","Sweater_Blue","Sweater_Gray","Sweater_Green","Sweater_Red","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White"};
		TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		TStringArray bags = {"courierbag"};
		TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Grey","HikingBoots_Black","HikingBoots_Brown","HikingJacket_Black"};
		TStringArray tool = {"OrienteeringCompass","PurificationTablets","RoadFlare"};
		TStringArray medic = {"Rags","BandageDressing"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
		TStringArray food = {"PeachesCan","Apple","PowderedMilk","PeachesCan","Pear"};
		
		this.player = m_player;
		
		player.RemoveAllItems(); 
		
		EntityAI itemEnt;
		EntityAI itemIn;
		ItemBase itemBs;
				
		EntityAI item = player.GetInventory().CreateInInventory(tops.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item2 = player.GetInventory().CreateInInventory(pants.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item3 = player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item4 = player.GetInventory().CreateInInventory(bags.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
				
		itemEnt = player.GetInventory().CreateInInventory(tool.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(medic.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(food.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("StoneKnife");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Flashlight");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("SardinesCan");
		itemBs = ItemBase.Cast(itemEnt);
		
	}
}
//Member Loadout

class MemberPlayerSetup
{
	private PlayerBase player;
	
	void MemberPlayerSetup(PlayerBase m_player)
	{
		TStringArray tops = {"Shirt_BlueCheck","Shirt_RedCheck","Shirt_GreenCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","HikingJacket_Blue","HikingJacket_Green","HikingJacket_Red","Sweater_Blue","Sweater_Gray","Sweater_Green","Sweater_Red","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White"};
		TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		TStringArray bags = {"courierbag"};
		TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Grey","HikingBoots_Black","HikingBoots_Brown","HikingJacket_Black"};
		TStringArray tool = {"OrienteeringCompass","PurificationTablets","RoadFlare"};
		TStringArray medic = {"Rags","BandageDressing"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
		TStringArray food = {"PeachesCan","Apple","PowderedMilk","PeachesCan","Pear"};
		
		this.player = m_player;
		
		player.RemoveAllItems(); 
		
		EntityAI itemEnt;
		EntityAI itemIn;
		ItemBase itemBs;
				
		EntityAI item = player.GetInventory().CreateInInventory(tops.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item2 = player.GetInventory().CreateInInventory(pants.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item3 = player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		EntityAI item4 = player.GetInventory().CreateInInventory(bags.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
				
		itemEnt = player.GetInventory().CreateInInventory(tool.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(medic.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(drink.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory(food.GetRandomElement());
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("StoneKnife");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Flashlight");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("SardinesCan");
		itemBs = ItemBase.Cast(itemEnt);
		
	}
}