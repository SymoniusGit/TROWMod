//-------------------------------------------------------------------------------------------------
// Scenario Name:		Historical
// Scenario Description:	Fight the War of the Ring from the historical start positions
// Game Type:			Elimination
// Win Conditions:		Player must conquer all the territories of each opposing team member
// Unavailable Territories:	None
// # of Players:		6
//-------------------------------------------------------------------------------------------------

LivingWorldCampaign WOTRScenario044

	IsEvilCampaign = No

	;////////////// RTS Settings /////////////
	#include "..\Common\LivingWorldDefaultRTSSettings.inc"

	Scenario
		DisplayName 		= LWScenario:WOTRScenario044
		DisplayDescription 	= LWScenario:WOTRScenario044Description
		DisplayGameType		= LWScenario:WOTRGameType002
		DisplayObjectives 	= LWScenario:WOTRObjectives002
		DisplayFiction 		= LWScenario:WOTRScenarioFiction003  
		DisplayVictoriousText	= LWScenario:WOTREliminationWin001
		DisplayDefeatedText	= LWScenario:WOTREliminationLose001

		RegionCampaign = DefaultCampaign
		
		; UseMpRulesVictoryCondition = No ; force the game to use the victory conditions here
		MinPlayers = 6
		MaxPlayers = 6

		;DisableRegions = Arnor Buckland Ettenmoors Forlindon Grey_Havens Harlindon Minhiriath The_Shire Tower_Hills Angmar Fornost Amon_Sul Barrow_Downs Lostriand Cardolan CarnDum Forodwaith MountGundabad
		DisabledFactions = FactionAngmar FactionArnor
		DefaultStartSpots = Rohan Rivendell Isengard Mordor Erebor High_Pass

		//HistoricalScenario marks this scenario as following several rules:
		// *Each player must play a unique faction (the list of selectable factions is dicated by the
		//  "DisabledFactions" flag above)
		// *Each faction has a predetermined starting location and team (outlined in the starting
		//  restrictions below)
		// Please read the information below on Starting Restrictions for more information.
		HistoricalScenario = Yes

           	PlayerDefeatCondition
                    Teams = 1 2
                    LoseIfCapitalLost = No
                    NumControlledRegionsLessOrEqualTo = 0
           	End
             
           	TeamDefeatCondition
                    Teams = 1 2
                    NumControlledRegionsLessOrEqualTo = 0
           	End

		//A HistoricalScenario MUST include a Starting Restriction for each faction allowed in the 
		//scenario.  This restriction dictates the starting region and team of each faction.  This is
		//important because users will NOT be able to choose a team or starting location if the 
		//"HistoricalScenario" flag is set.
		//
		//Also note, in this case Starting Restrictions are being used in a different context than what
		//they are used for when the HistoricalScenario flag is not set.  Without the HistoricalScenario
		//flag, starting restrictions restrict selection to starting position only, and the starting
		//position dictates the faction and/or team
		StartingRestriction
		    Factions = FactionMen
		    Regions = Rohan
		    Teams = 1
		End

		StartingRestriction
		    Factions = FactionElves
		    Regions = Rivendell
		    Teams = 1
		End

		StartingRestriction
		    Factions = FactionDwarves
		    Regions = Erebor
		    Teams = 1
		End

		StartingRestriction
		    Factions = FactionIsengard
		    Regions = Isengard
		    Teams = 2
		End

		StartingRestriction
		    Factions = FactionMordor
		    Regions = Mordor
		    Teams = 2
		End

		StartingRestriction
		    Factions = FactionWild
		    Regions = High_Pass
		    Teams = 2
		End
		//-----------End Historical starting restrictions
            
           	//----------------------------------------------------------
           	// OwnershipSets
           	//----------------------------------------------------------

           	// OwnershipSets are how you decide who owns which region at the start of the game (and what armies are owned also)
 
           	OwnershipSet 
                    Regions = Cair_Andros Anfalas Belfalas Helms_Deep Minas_Tirith Osgiliath Rohan Fornost
                    StartRegion = Rohan
                    
                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Rohan
                    End

                    SpawnBuildings
                        Buildings = LW_FORT
                        Region = Osgiliath
                    End

                    SpawnArmies //Theoden //Eomer
                        Armies = HeroArmy2 HeroArmy4
                        Region = Rohan
                    End

                     SpawnArmies //Boromir
                        Armies = HeroArmy3
                        Region = Minas_Tirith
                    End
					
					SpawnArmies //Aragorn
                        Armies = HeroArmy1
                        Region = Fornost
                    End

                    SpawnArmies
                        Armies = GarrisonArmy1
                        Region = Helms_Deep
                    End

           	End
 
                OwnershipSet
                    Regions = Rivendell Lothlorien Mirkwood Forlindon Grey_Havens Harlindon Fangorn
                    StartRegion = Rivendell

                    SpawnBuildings
                        Buildings = LW_ARMORY
                        Region = Rivendell
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS LW_FARM
                        Region = Lothlorien 
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS LW_FARM
                        Region = Mirkwood
                    End

                    SpawnArmies
                        Armies = HeroArmy3
                        Region = Lothlorien
                    End

                    SpawnArmies
                        Armies = HeroArmy2
                        Region = Rivendell
                    End

                    SpawnArmies
                        Armies = HeroArmy1
                        Region = Mirkwood
                    End
					
					SpawnArmies
                        Armies = GarrisonArmy1 HeroArmy4
                        Region = Grey_Havens
                    End
					
					SpawnArmies
                        Armies = GarrisonArmyFangorn
                        Region = Fangorn
                    End
                End

                OwnershipSet
                    Regions = Isengard Dunland Gap_Of_Rohan
                    StartRegion = Isengard   
             
                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Isengard
                    End

                    SpawnBuildings
                        Buildings = LW_FARM
                        Region = Dunland
                    End

                    SpawnArmies
                        Armies = HeroArmy1 HeroArmy2 
                        Region = Isengard
                    End

                    SpawnArmies
                        Armies = HeroArmy3
                        Region = Gap_Of_Rohan
                    End
					SpawnArmies
                        Armies = GarrisonArmy1
                        Region = Isengard
                    End
                    SpawnArmies  //Faolan
                        Armies = GarrisonArmyDunland HeroArmy4
                        Region = Dunland
                    End
                End
            
                OwnershipSet
                    Regions = Harad Rhun Minas_Morgul Mordor Mount_Doom The_Black_Gate Dol_Guldur Umbar
                    StartRegion = Mount_Doom
                
                    SpawnBuildings
                        Buildings = LW_BARRACKS LW_BARRACKS
                        Region = Mordor
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS LW_ARMORY
                        Region = Mount_Doom
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Minas_Morgul
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Rhun
                    End
                    SpawnArmies 
						Armies = HeroArmy3
                        Region = Rhun
                    End
                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Harad
                    End

                    SpawnArmies
                        Armies = HeroArmy1
                        Region = Minas_Morgul
                    End
                    SpawnArmies
                        Armies = HeroArmy4
                        Region = Harad
                    End
                    SpawnArmies
                        Armies = GarrisonArmy1
                        Region = The_Black_Gate
                    End
                    SpawnArmies
                        Armies = HeroArmy2
                        Region = Dol_Guldur
                    End
                    SpawnArmies
                        Armies = GarrisonArmy2
                        Region = Rhun
                    End
					SpawnArmies
                        Armies = GarrisonArmyHarad
                        Region = Harad
                    End
                End

                OwnershipSet
                    Regions = High_Pass Redhorn_Pass MountGundabad CarnDum Ettenmoors The_Dead_Marshes
                    StartRegion = High_Pass
                
                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = High_Pass 
                    End

                    SpawnBuildings
                        Buildings = LW_BARRACKS 
                        Region = Redhorn_Pass
                    End

					SpawnArmies // Agandaur
                        Armies = HeroArmy1
                        Region = CarnDum ;High_Pass 
                    End

                    SpawnArmies //Gorkill
                        Armies = HeroArmy3
                        Region = Ettenmoors ;Redhorn_Pass
                    End

                    SpawnArmies  // Shelob
                        Armies = HeroArmy2 
                        Region = The_Dead_Marshes
                    End
					
					SpawnArmies  // Lugbol
                        Armies = HeroArmy4
                        Region = Redhorn_Pass ;MountGundabad
                    End
					
					SpawnArmies
                        Armies = GarrisonArmy1
                        Region = High_Pass ;Ettenmoors
                    End
					
					SpawnArmies
                        Armies = GarrisonArmy2
                        Region = MountGundabad 
                    End
                End

                OwnershipSet
                    Regions = Iron_Hills Erebor Celduin
                    StartRegion = Erebor            

                    SpawnBuildings
                        Buildings = LW_BARRACKS
                        Region = Erebor
                    End
                    SpawnBuildings
                        Buildings = LW_FARM
                        Region = Iron_Hills 
                    End

                    //SpawnArmies
                    //    Armies = GarrisonArmy1
                    //    Region = Iron_Hills
                    //End
                    ;SpawnArmies //
                    ;  	Armies = 
                    ;   	Region = Iron_Hills
                    ;End
                    SpawnArmies //Gloin //Brand
                        Armies = HeroArmy3 HeroArmy4	
                        Region = Celduin
                    End
					SpawnArmies //Dain
						Armies = HeroArmy2 GarrisonArmy2 
						Region = Erebor
					End
					SpawnArmies //Thorin
						Armies = HeroArmy1 GarrisonArmyIronHills //Thorin
						Region = Iron_Hills
					End
                End
            End

	
	;//////////////////////////////////////////////////
	Act One
	;//////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
// Men of the West
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerMen		
	HeroTemplateName = GondorAragornMP
	PlayerArmy = MenAragornArmy_Historical
	Icon = HeroAragornIcon
	Banner = BannerMen
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerMen
	HeroTemplateName = RohanTheoden
	PlayerArmy = MenTheodenArmy_Historical
	Icon = HeroTheodenIcon
	Banner = BannerMen
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerMen
	HeroTemplateName = GondorBoromir
	PlayerArmy = MenBoromirArmy_Historical
	Icon = HeroBoromirIcon
	Banner = BannerMen
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerMen
	HeroTemplateName = RohanEomer
	PlayerArmy = EomerPlayerArmy
	Icon = HeroEomerIcon
	Banner = BannerMen
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerMen
	PlayerArmy = MenGarrisonArmy1_Historical
	Icon = MoWArmyIcon
End


//-------------------------------------------------------------------------------------------------
// Elves
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerElves
	HeroTemplateName = ElvenThranduil
	PlayerArmy = ElvenThranduilArmy_Historical
	Icon = HeroThranduilIcon
	Banner = BannerElves
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerElves
	HeroTemplateName = ElvenElrond
	PlayerArmy = ElvenElrondArmy_Historical
	Icon = HeroElrondIcon
	Banner = BannerElves
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerElves
	HeroTemplateName = ElvenCeleborn
	PlayerArmy = ElvenCelebornArmy_Historical
	Icon = HeroHaldirIcon
	Banner = BannerElves
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerElves
	HeroTemplateName = ElvenCirdan	;Before was Glorfindel
	PlayerArmy = CirdanPlayerArmy
	Icon = HeroGlorfindelIcon
	Banner = BannerElves
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerElves
	PlayerArmy = ElvesGarrisonArmy1_Historical
	Icon = BannerElves
End

SpawnArmy
	ScriptingName = GarrisonArmyFangorn
	SpawnForTemplates = PlayerElves
	PlayerArmy = ElvesGarrisonArmyFangorn_Historical
	Icon = BannerElves
End

//-------------------------------------------------------------------------------------------------
// Dwarves
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerDwarves
	HeroTemplateName = DwarvenThorinStonehelm ;Gimli
	PlayerArmy = ThorinPlayerArmy
	Icon = HeroGimliIcon
	Banner = BannerDwarves
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerDwarves
	HeroTemplateName = DwarvenDain
	PlayerArmy = DainPlayerArmy
	Icon = HeroDainIcon
	Banner = BannerDwarves
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerDwarves
	HeroTemplateName = DwarvenGloin
	PlayerArmy = GloinPlayerArmy
	Icon = HeroGloinIcon
	Banner = BannerDwarves
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerDwarves
	HeroTemplateName = DwarvenCaptainofDale
	PlayerArmy = CaptainofDalePlayerArmy
	Icon = HeroCaptainofDaleIcon
	Banner = BannerDwarves
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerDwarves
	PlayerArmy = Dwarven_StartingArmy
	Icon = DwarfArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmy2
	SpawnForTemplates = PlayerDwarves
	PlayerArmy = DwarvesGarrisonArmy1_Historical
	Icon = DwarfArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmyIronHills
	SpawnForTemplates = PlayerDwarves
	PlayerArmy = DwarvesGarrisonArmyIronHills_Historical
	Icon = DwarfArmyIcon
End
//-------------------------------------------------------------------------------------------------
// Mordor
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerMordor
	HeroTemplateName = MordorWitchKingOnFellBeast
	PlayerArmy = MordorWitchKingArmy_Historical
	Icon = HeroWitchKingIcon
	Banner = BannerMordor
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerMordor
	HeroTemplateName = KhamulFellBeast
	PlayerArmy = MordorFellBeast1Army_Historical
	Icon = HeroFellBeast1Icon
	Banner = BannerMordor
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerMordor
	HeroTemplateName = MordorMouthOfSauron
	PlayerArmy = MouthOfSauronArmy
	Icon = HeroMouthOfSauronIcon
	Banner = BannerMordor
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerMordor
	HeroTemplateName = MordorGothmog
	PlayerArmy = GothmogPlayerArmy
	Icon = HeroGothmogIcon
	Banner = BannerMordor
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerMordor
	PlayerArmy = Mordor_StartingArmy
	Icon = MordorArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmy2
	SpawnForTemplates = PlayerMordor
	PlayerArmy = MordorGarrisonArmy_Historical
	Icon = MordorArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmyHarad
	SpawnForTemplates = PlayerMordor
	PlayerArmy = MordorGarrisonArmyHarad_Historical
	Icon = MordorArmyIcon
End

//-------------------------------------------------------------------------------------------------
// Isengard
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerIsengard
	HeroTemplateName = IsengardHurak ;Saruman
	PlayerArmy = IsengardHurakArmy_Historical
	Icon = HeroSarumanIcon
	Banner = BannerIsengard
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerIsengard
	HeroTemplateName = IsengardLurtz
	PlayerArmy = IsengardLurtzArmy_Historical
	Icon = HeroLurtzIcon
	Banner = BannerIsengard
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerIsengard
	HeroTemplateName = IsengardSharku
	PlayerArmy = IsengardSharkuArmy_Historical
	Icon = HeroSharkuIcon
	Banner = BannerIsengard
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerIsengard
	HeroTemplateName = IsengardDunlandFaolan
	PlayerArmy = FaolanPlayerArmy
	Icon = HeroWormTongueIcon
	Banner = BannerIsengard
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerIsengard
	PlayerArmy = IsengardGarrisonArmy_Historical
	Icon = IsengardArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmyDunland
	SpawnForTemplates = PlayerIsengard
	PlayerArmy = IsengardGarrisonArmyDunland_Historical
	Icon = IsengardArmyIcon
End
//-------------------------------------------------------------------------------------------------
// Goblins
//-------------------------------------------------------------------------------------------------

SpawnArmy
	ScriptingName = HeroArmy1
	SpawnForTemplates = PlayerWild
	HeroTemplateName = WildAgandaur
	PlayerArmy = WildAgandaurArmy_Historical
	Icon = HeroDrogothIcon
	Banner = BannerWild
End

SpawnArmy
	ScriptingName = HeroArmy2
	SpawnForTemplates = PlayerWild
	HeroTemplateName = WildShelob
	PlayerArmy = ShelobPlayerArmy
	Icon = HeroShelobIcon
	Banner = BannerWild
End

SpawnArmy
	ScriptingName = HeroArmy3
	SpawnForTemplates = PlayerWild
	HeroTemplateName = WildGoblinKing
	PlayerArmy = WildGorkilArmy_Historical
	Icon = HeroGorkilIcon
	Banner = BannerWild
End

SpawnArmy
	ScriptingName = HeroArmy4
	SpawnForTemplates = PlayerWild
	HeroTemplateName = WildLugbol
	PlayerArmy = WildLugbolArmy_Historical
	Icon = HeroAzogIcon
	Banner = BannerWild
End

SpawnArmy
	ScriptingName = GarrisonArmy1
	SpawnForTemplates = PlayerWild
	PlayerArmy = WildGarrisonArmy1_Historical
	Icon = WildArmyIcon
End

SpawnArmy
	ScriptingName = GarrisonArmy2
	SpawnForTemplates = PlayerWild
	PlayerArmy = WildGarrisonArmy2_Historical
	Icon = WildArmyIcon
End

		;//////////////// Cities (Yes, this is a hack for mouse over movies.) ////////////////
		//#include "..\Common\LivingWorldCities.inc"


		;//////////////// VISUAL FLUFF ////////////////
		EyeTowerPoints
			LookPoint = X:436 Y:687 ; Rohan
			LookPoint = X:481 Y:287
			LookPoint = X:1179 Y:461
			LookPoint = X:947 Y:917
			LookPoint = X:172 Y:573 ; Isengard
			LookPoint = X:160 Y:560 ; Isengard
			LookPoint = X:175 Y:557 ; Isengard
			LookPoint = X:171 Y:348 ; Helm's Deep
			LookPoint = X:257 Y:535 ; Helm's Deep
			LookPoint = X:120 Y:350 ; Helm's Deep
			LookPoint = X:157 Y:420 ; Helm's Deep
		End		
	End
End
