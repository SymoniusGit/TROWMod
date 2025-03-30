//---------------------------------------------------------------------------------------------
// Giant class
//---------------------------------------------------------------------------------------------
CreateAHeroClass	
	NameTag			= CreateAHero:ClassName_Giant
	DescriptionTag		= CreateAHero:ClassDesc_Giant
	PowersDescTag		= CreateAHero:ClassPowersDesc_Giant
	UpgradeName			= Upgrade_CreateAHero_ClassGiant
	IconImage	   = BWFissure_Giant ;Archetype_Giant
																						
	SubClass
		NameTag			  =	CreateAHero:SubClassName_Giant
		DescriptionTag	  =	CreateAHero:SubClassDesc_Giant
		IconImage         = BWFissure_Giant
		ButtonImage       = BWFissure_Giant
		//DefaultFaction              = Mordor 
		UsableFactions              = Isengard Mordor Wild Angmar
		SpendableAttributePoints        = 15
		// In UI it should be  		=  HICAHTroll_wotr

		UpgradeName			  =	Upgrade_CreateAHero_SubClass_0
		//-------------------------------
		// Awards common to all heros.
		#include "CreateAHeroSystemCommonStatsAndAwards.inc"
		// Class specific awards
		Awards = ScourgeOfMiddleEarth


		//-------------------------------
		// Weapons
		BlingUpgrades =	Upgrade_GiantWeapon
		//-------------------------------
		// Head	Gear
		BlingUpgrades = None
		//-------------------------------
		// Shoulder	Plates
		BlingUpgrades = None
		//-------------------------------
		// Gauntlets
		BlingUpgrades = None
		//-------------------------------
		// Shield
		BlingUpgrades = None
		//-------------------------------
		// Boots
		BlingUpgrades = None
		//-------------------------------
		// Body
		BlingUpgrades = None
		DefaultPrimaryColor	  =	R:160 G:160 B:160
		DefaultSecondaryColor =	R:160 G:160 B:160
		DefaultTertiaryColor  =	R:160 G:160 B:160

		Attribute
			GroupName			= CreateAHero_ArmorAttribute
			MinValueUpgrade		= Upgrade_ArmorAttribute01
			MaxValueUpgrade		= Upgrade_ArmorAttribute17
			DefaultValueUpgrade	= Upgrade_ArmorAttribute09
		End
		
		Attribute
			GroupName			= CreateAHero_DamageMultAttribute
			MinValueUpgrade		= Upgrade_DamageMultAttribute20
			MaxValueUpgrade		= Upgrade_DamageMultAttribute20
			DefaultValueUpgrade	= Upgrade_DamageMultAttribute18
		End

		Attribute
			GroupName			= CreateAHero_HealthMultAttribute
			MinValueUpgrade		= Upgrade_HealthMultAttribute08
			MaxValueUpgrade		= Upgrade_HealthMultAttribute13
			DefaultValueUpgrade	= Upgrade_HealthMultAttribute09
		End

		Attribute
			GroupName			= CreateAHero_AutoHealAttribute
			MinValueUpgrade		= Upgrade_AutoHealAttribute01
			MaxValueUpgrade		= Upgrade_AutoHealAttribute20
			DefaultValueUpgrade	= Upgrade_AutoHealAttribute09
		End

		Attribute
			GroupName			= CreateAHero_VisionAttribute
			MinValueUpgrade		= Upgrade_VisionAttribute01
			MaxValueUpgrade		= Upgrade_VisionAttribute15
			DefaultValueUpgrade	= Upgrade_VisionAttribute02
		End
        

		// Camera used to view object with in create a hero
		ViewInfo
				FarPitch  = -0.106
		        FarZoom   = 0.192
		        FarFloor  = 15.760
		        FarDist   = 56.500
		        FarShift  = 13.000
		        NearPitch = -0.046
		        NearZoom  = 0.262
		        NearFloor = 78.260
		        NearDist  = 56.000
		        NearShift = 6.300
		        CloseUpPitch = -0.330
		        CloseUpZoom  = 0.200
		        CloseUpFloor = 50.000
		        CloseUpDist  = 96.000
		        CloseUpShift = -1.700
		        PortraitPitch = -0.090
		        PortraitZoom  = 0.100
		        PortraitFloor = 50.000
		        PortraitDist  = 152.00
		        PortraitShift = -1.20
		        //NormalCam = 1.00

			
			CameraAngle	= -0.1
			MapLocation	= 0	   
		End
	End
End
