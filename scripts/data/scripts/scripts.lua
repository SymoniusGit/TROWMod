-- define lua functions 
function NoOp(self, source)
end

function kill(self) -- Kill unit self.
	ExecuteAction("NAMED_KILL", self);
end

function OnMoving(self)
    ObjectRemoveUpgrade( self, "Upgrade_NotMovingBow" )
    ObjectGrantUpgrade( self, "Upgrade_MovingBow" )
end

function OnNotMoving(self)
    ObjectRemoveUpgrade( self, "Upgrade_MovingBow" )
    ObjectGrantUpgrade( self, "Upgrade_NotMovingBow" )
end

function OnSwitchToBow(self)
    ObjectRemoveUpgrade( self, "Upgrade_SwitchToSword" )
    ObjectGrantUpgrade( self, "Upgrade_SwitchToBow" )
end

function OnSwitchToSword(self)
    ObjectRemoveUpgrade( self, "Upgrade_SwitchToBow" )
    ObjectGrantUpgrade( self, "Upgrade_SwitchToSword" )
end

function UpgradeFireArrows(self)
    ObjectGrantUpgrade( self, "Upgrade_MordorFireArrows" )
    ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
    return
end

function RadiatePhialFear( self )
	ObjectBroadcastEventToEnemies( self, "BeAfraidOfPhial", 75 )
end

function RadiateUncontrollableFear( self )
	ObjectBroadcastEventToEnemies( self, "BeUncontrollablyAfraid", 350 )
end

function RadiateGateDamageFear(self)
	ObjectBroadcastEventToAllies(self, "BeAfraidOfGateDamaged", 200)
end

function RadiateBalrogFear(self)
	ObjectBroadcastEventToEnemies(self, "BeAfraidOfBalrog", 180)
end

function OnMumakilCreated(self)
	ObjectHideSubObjectPermanently( self, "Houda", true )
	ObjectHideSubObjectPermanently( self, "Houda01", true )
end

function OnTrollCreated(self)
	ObjectHideSubObjectPermanently( self, "Trunk01", true )
	ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" )
end

function OnHobbitCreated(self)
	ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" )
end

function OnCreepTrollCreated(self)
	ObjectHideSubObjectPermanently( self, "Trunk01", true )
	ObjectHideSubObjectPermanently( self, "ROCK", true )
end

function OnMounting(self)
    ObjectRemoveUpgrade( self, "Upgrade_Dismount" )
    ObjectGrantUpgrade( self, "Upgrade_Mount" )
end

function OnDismounting(self)
    ObjectRemoveUpgrade( self, "Upgrade_Mount" )
    ObjectGrantUpgrade( self, "Upgrade_Dismount" )
end

function OnCaptureFlagGenericEvent(self,data)
	local str = ObjectCapturingObjectPlayerSide(self)
	if str == nil then
		str = ObjectPlayerSide(self)
	end


	ObjectHideSubObjectPermanently( self, "FLAG_ISENGARD", true)
	ObjectHideSubObjectPermanently( self, "FLAG_MORDOR", true)
	ObjectHideSubObjectPermanently( self, "FLAG_WILD", true)
	ObjectHideSubObjectPermanently( self, "FLAG_MEN", true)
	ObjectHideSubObjectPermanently( self, "FLAG_ELVES", true)
	ObjectHideSubObjectPermanently( self, "FLAG_DWARVES", true)
	ObjectHideSubObjectPermanently( self, "FLAG_ANGMAR", true)

	if str == "Isengard" then
		ObjectHideSubObjectPermanently( self, "FLAG_ISENGARD", false)
	elseif str == "Mordor" then
		ObjectHideSubObjectPermanently( self, "FLAG_MORDOR", false)
	elseif str == "Men" then
		ObjectHideSubObjectPermanently( self, "FLAG_MEN", false)
	elseif str == "Dwarves" then
		ObjectHideSubObjectPermanently( self, "FLAG_DWARVES", false)
	elseif str == "Elves" then
		ObjectHideSubObjectPermanently( self, "FLAG_ELVES", false)
	elseif str == "Wild" then
		ObjectHideSubObjectPermanently( self, "FLAG_WILD", false)
	elseif str == "Angmar" then
		ObjectHideSubObjectPermanently( self, "FLAG_ANGMAR", false)
	else
		ObjectHideSubObjectPermanently( self, "FLAG_NEUTRAL", false)
	end
end

function OnTrollGenericEvent(self,data)

	local str = tostring( data )

	if str == "show_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", false )
	elseif str == "hide_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", true )
	end
end

function OnEntCreated(self)
	--ObjectShowSubObjectPermanently( self, "ROCK", true )
	ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" )
end

function ShowTorch(self)
	ObjectHideSubObjectPermanently( self, "TORCH", false )
end

function OnMountainGiantCreated(self)
	--ObjectHideSubObjectPermanently( self, "ROCK", true )
	ObjectGrantUpgrade( self, "Upgrade_SwitchToRockThrowing" )
end

function OnMountainGiantGenericEvent(self)
	
	local str = tostring( data )

	if str == "show_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", false )
	elseif str == "hide_rock" then
		ObjectHideSubObjectPermanently( self, "ROCK", true )
	end
end

function GoIntoRampage(self)
	ObjectEnterRampageState(self)
		
	--Broadcast fear to surrounding unit(if we actually rampaged)
	if ObjectTestModelCondition(self, "WEAPONSET_RAMPAGE") then
		ObjectBroadcastEventToUnits(self, "BeAfraidOfRampage", 250)
	end
end

function MakeMeAlert(self)
	ObjectEnterAlertState(self)
end

function BeEnraged(self)
	--Broadcast enraged to surrounding units.
	ObjectBroadcastEventToAllies(self, "BeingEnraged", 500)
end

function BecomeEnraged(self)
	ObjectSetEnragedState(self, true)
end

function StopEnraged(self)
	ObjectSetEnragedState(self, false)
end

function BecomeUncontrollablyAfraid(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterUncontrollableCowerState(self, other)
end

function BecomeAfraidOfRampage(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self, other)
end

function BecomeAfraidOfBalrog(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self, other)
end

function RadiateTerror(self, other)
	ObjectBroadcastEventToEnemies(self, "BeTerrified", 180)
end
	
function RadiateTerrorEx(self, other, terrorRange)
	ObjectBroadcastEventToEnemies(self, "BeTerrified", terrorRange)
end
	

function BecomeTerrified(self, other)
	ObjectEnterRunAwayPanicState(self, other)
end

function BecomeAfraidOfGateDamaged(self, other)
	if not ObjectTestCanSufferFear(self) then
		return
	end

	ObjectEnterCowerState(self,other)
end


function ChantForUnit(self) -- Used by units to broadcast the chant event to their own side.
	ObjectBroadcastEventToAllies(self, "BeginChanting", 9999)
end

function StopChantForUnit(self) -- Used by units to stop the chant event to their own side.
	ObjectBroadcastEventToAllies(self, "StopChanting", 9999)
end

function BeginCheeringForGrond(self)
	ObjectSetChanting(self, true)
end

function StopCheeringForGrond(self)
	ObjectSetChanting(self, false)
end

function OnMordorArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "ARROWFIRE", true )
end

function OnGundabadOrcArcherCreated(self)
	shldrList = {"", "PELTSHLDR", "PELTSHLDL"}

	HideAllSubObjects(self, shldrList)
	RandomizeSubobjects(self, shldrList)
	ObjectHideSubObjectPermanently( self, "ARROWFIRE", true )
end

function OnGundabadOrcPikemanCreated(self)
	shldrList = {"", "PELTSHLDR", "PELTSHLDL"}

	HideAllSubObjects(self, shldrList)
	RandomizeSubobjects(self, shldrList)
end

function OnGundabadOrcRiderCreated(self)
    local weaponListR = {"AXER","SWORDR"}
    local shldrList = {"", "PELTSHLDR", "PELTSHLDL"}


    HideAllSubObjects(self,weaponListR)
    HideAllSubObjects(self,shldrList)

    RandomizeSubobjects(self,weaponListR)
    RandomizeSubobjects(self,shldrList)
end

function OnMordorFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADES", true )
end

-- This function hides a set of subobjects
-- --------------------------------------------------
-- # Inputs: self: an instance of the object
-- # subObjectTable: a table containing strings naming all the subobjects to be hidden
function HideAllSubObjects(self,subObjectTable)
    -- For all objects in the subObjectTable
    local length = getn(subObjectTable)
    for i=1,length do
        -- hide the subobject.
        ObjectHideSubObjectPermanently( self, subObjectTable[i], true )
    end
end

-- This function randomly (or not so randomly) unhides a set of subobjects
-- --------------------------------------------------
-- # Inputs: self: an instance of the object
-- #     subObjectTable: a table containing strings naming all the subobjects to be randomized
-- #         probTable:     a table containing probabilties from 0 to 1.0.
-- #                If shorter than subObjectTable, the script will assume all remaining objects have zero probability
-- #                Each probability corresponds to the subobject with the same index.
-- #                If the probabilities add to more than 1.0, the script will use equal probabilties
-- #                 Is not required, function will assume equal probability if left empty
function RandomizeSubobjects(self,subObjectTable,probTable)

    -- Error checking
    local redFlag = false
    if probTable then
        -- See if probabilities add to more than 1.0
            local sum = 0
            -- Loop through table, sum probabilites
            for i=1,getn(probTable) do
                sum = sum + probTable[i]
            end
            -- If the sum is greater than 0 or less than 1, set the red flag
            if (sum > 1.0) or (sum < 1.0) then
                redFlag = true
            end
        -- See if there are too few probabilities
            -- If there are, set the remainder to zero
            if getn(probTable) < getn(subObjectTable) then
                while getn(probTable) < getn(subObjectTable) do
                    probTable[getn(probTable)+1] = 0
                end
            end
    end

    -- If we don't have a probability table, or redFlag was true, use equal probabilities
    if (not probTable) or (redFlag) then
        -- Generate a random number
        local number = GetRandomNumber()
        -- Get the probability of getting each object
        local increment = 1/getn(subObjectTable)
        local curProb = increment
        
        -- For each subobject...
        local length = getn(subObjectTable)
        for i=1,length do
            if number <= curProb then
                -- If our random # is less than the target probability, unhide the object and
                -- break the loop
                ObjectHideSubObjectPermanently( self, subObjectTable[i], false )
                break
            end
            -- Increment the probability
            curProb = curProb + increment
        end
    else
        -- Generate a random number
        local number = GetRandomNumber()
        -- Our starting probability is the first item in the table
        local curProb = probTable[1]
        
        -- For each subobject...
        local length = getn(subObjectTable)
        for i=1,length do
            if number <= curProb then
                -- If our random # is less than the target probability, unhide the object and
                -- break the loop
                ObjectHideSubObjectPermanently( self, subObjectTable[i], false )
                break
            end
            -- Probability increases to the second probability
            curProb = curProb + probTable[i+1]
        end
        
    end
end

function OnEreborArkenguardCreated(self)

    local weaponList = {"AXE_01","AXE_03","HMR","HMRAXE"}

    HideAllSubObjects(self,weaponList)

    RandomizeSubobjects(self,weaponList)

end

function OnGundabadOrcFighterCreated(self)

    local weaponListL = {"AXEL","SWORDL", "SHLD"}
    local weaponListR = {"AXER","SWORDR"}
    local shldrList = {"", "PELTSHLDR", "PELTSHLDL"}


    HideAllSubObjects(self,weaponListL)
    HideAllSubObjects(self,weaponListR)
    HideAllSubObjects(self,shldrList)

    RandomizeSubobjects(self,weaponListL)
    RandomizeSubobjects(self,weaponListR)
    RandomizeSubobjects(self,shldrList)

end

function OnSnowTrollCreated(self)

    local weaponList = {"TRUNK01","WARBONE","TROLLHAMMER","CLUB_01"}
    local boneList = {"BONES01","BONES02","BONES03","BONES04","BONES05","BONES11","BONES12", "skull01", "skull02", "skull03", "skull04", "RIBS"}
    ;local brac1 = {"BONES06","BONES07","BONES08","BONES09","BONES10"}
    ;local brac2 = {"BONES13","BONES14","BONES15","BONES16","BONES17"}
    ;local braclist = {brac1, brac2, "ribs"};

    HideAllSubObjects(self,weaponList)
    HideAllSubObjects(self,boneList)

    RandomizeSubobjects(self,weaponList)
    RandomizeSubobjects(self,boneList)
    RandomizeSubobjects(self,boneList)
    RandomizeSubobjects(self,boneList)

end

function SpyEnemies(self)
	if tonumber(ObjectCountNearbyEnemies(self, 150)) >= 10 then
		ObjectDoSpecialPower(self, "SpecialAbilityGainExperience")
		return
	end
end

function OnBeorningCreated(self)

    local weaponList = {"AXE00","AXE01","CLUB00","HAMMER00"}

    HideAllSubObjects(self,weaponList)

    RandomizeSubobjects(self,weaponList)

end

function OnAngmarUndeadFighterCreated(self)
    ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
    local weaponList = {"SWORD00", "SWORD01"}
    local armorList = {"", "ARMOR00", "ARMOR01", "ARMOR02", "ARMOR03"}
    local skirtList = {"", "SKIRT00", "SKIRT01", "SKIRT02"}
    local helmList = {"", "HELM00", "HELM01", "HELM02"}
    local shieldList = {"", "", "NUM_SHIELD", "NUM_SHIELD", "NUM_SHIELD"}

    HideAllSubObjects(self,weaponList)
    HideAllSubObjects(self,armorList)
    HideAllSubObjects(self,skirtList)
    HideAllSubObjects(self,helmList)
    HideAllSubObjects(self,shieldList)

    RandomizeSubobjects(self,weaponList)
    RandomizeSubobjects(self,armorList)
    RandomizeSubobjects(self,skirtList)
    RandomizeSubobjects(self,helmList)
    RandomizeSubobjects(self,shieldList)

end

function OnDunlandFighterCreated(self)
    ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
    local weaponList = {"IRONAXE", "IRONSWORD"}
    ;local weaponhideList = {"AXE", "HMR_03"}

    HideAllSubObjects(self,weaponList)

    RandomizeSubobjects(self,weaponList)

end

function OnDunland2HFighterCreated(self)

    local weaponList = {"AXE00","AXE01"}
    local weaponhideList = {"AXE00","AXE01", "HAMMER_00"}

    HideAllSubObjects(self,weaponhideList )

    RandomizeSubobjects(self,weaponList)

end

function OnDunlandBerserkerCreated(self)

    local weaponListR = {"R_AXE"}
    local weaponListL = {"L_AXE"}

    HideAllSubObjects(self,weaponListR)
    HideAllSubObjects(self,weaponListL)

    RandomizeSubobjects(self,weaponListR)
    RandomizeSubobjects(self,weaponListL)

end

function MordorFighterBecomeUncontrollablyAfraid(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "MordorFighterEntFear") 
	end
end

function MordorFighterBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)
	-- BecomeAfraidOfTroll(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
--		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
--			ObjectPlaySound(self, "MordorFighterEntFear") 
--		end
end

function OnMordorCorsairCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Forged_Blade01", true )
end

function WildInfantryBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")
	BecomeUncontrollablyAfraid(self,other)
end


function ShelobBecomeAfraidOfPhial(self,other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeUncontrollablyAfraid(self,other)
	-- BecomeAfraidOfTroll(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfTroll may fail, don't play sound if we didn't enter fear state
--		if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
--			ObjectPlaySound(self, "MordorFighterEntFear") 
--		end
end

function OnInfantryBannerCreated(self)
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnCavalryCreated(self)
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnRangerCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnGondorFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Hammer1", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
	ObjectHideSubObjectPermanently( self, "Glow1", true )
end

function OnAragornCreated(self)
	ObjectHideSubObjectPermanently( self, "PLANE02", true )
end

function OnGondorArcherCreated(self)
	-- ObjectHideSubObjectPermanently( self, "arrow", true )		-- This gets hidden pending the art being fixed.  it is the pre-new-archer-firing-pattern arrow
	ObjectHideSubObjectPermanently( self, "FireArowTip", true ) -- This gets hidden because the Fire Arrow upgrade turns it on.
end

function DragonStrikeDragonCreated(self)
	ObjectForbidPlayerCommands( self, true )
end

function OnLegolasCreated(self)
	-- ObjectHideSubObjectPermanently( self, "arrow02", true )		-- This gets hidden pending the art being fixed.  it is the pre-new-archer-firing-pattern arrow
	-- ObjectHideSubObjectPermanently( self, "arrow", true )		-- This gets hidden pending the art being fixed.  it is the pre-new-archer-firing-pattern arrow
end

function OnRohanArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FireArowTip", true ) -- yes, it's a typo in the art.
	-- ObjectHideSubObjectPermanently( self, "ArrowNock", true )
	-- ObjectHideSubObjectPermanently( self, "arrow", true )
end

function GondorFighterBecomeAfraid(self, other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	-- An object has a 100% chance to become afraid.
	-- An object has a 66% chance to be feared, 33% chance to run away.
	if GetRandomNumber() <= 0.67 then 
		ObjectEnterFearState(self, other, false) -- become afraid of other.
	else --if GetRandomNumber() > 0.67 then
		ObjectEnterRunAwayPanicState(self, other) -- run away.

	end
	
	if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "GondorSoldierScream")	
	end
	
end


function GondorFighterBecomeAfraidOfGateDamaged(self, other)
	local wasAfraid = ObjectTestModelCondition(self, "EMOTION_AFRAID")

	BecomeAfraidOfGateDamaged(self,other)                 -- Call base function appropriate to many unit types
	
	-- Play unit-specific sound, but only when first entering state (not every time troll sends out fear message!)
	-- BecomeAfraidOfGateDamaged may fail, don't play sound if we didn't enter fear state
	
	if ( not wasAfraid ) and ObjectTestModelCondition(self, "EMOTION_AFRAID") then
		ObjectPlaySound(self, "GondorSoldierScream")	
	end
end

function GondorFighterRecoverFromTerror(self)
	-- Add recovery sound
	ObjectPlaySound(self, "GondorSoldierRecoverFromTerror")
end

function SpyMoving(self, other)
	print(ObjectDescription(self).." spying movement of "..ObjectDescription(other));
end

function GandalfConsiderUsingDefensePower(self, other, delay, amount)
	-- Put up the shield if a big attack is coming and we have time to block it
	if tonumber(delay) > 1 then
		if tonumber(amount) >= 1 then
			ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
			return
		end
	end
	
	-- Or, if we are being hit and there are alot of guys arround, do our cool pushback power
	--if tonumber(ObjectCountNearbyEnemies(self, 50)) >= 4 then
	--	ObjectDoSpecialPower(self, "SpecialPowerTelekeneticPush")
	--	return
	--end
end

function RhunWarChariotToDoublePower(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityShapeshiftOne")
	return
end

function FireDrakeGrowUp(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityShapeshiftOne")
	return
end

function TransToHit(self)
	ObjectDoSpecialPower(self, "SpecialAbilityTransToHit")
end

function RevealSpiderWeb(self)
	ObjectDoSpecialPower(self, "SpecialAbilityElfCloak")
	return
end

function GandalfUseDefensePower(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
	return
end

function RadagastUseSurvivalInstinct(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityHeroMode")
	return
end

function BoromirUseLastChance(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityHeroMode")
	return
end

function  HighlanderHardness(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityLastChance")
	return
end

function  HighlanderLastChance(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityLastChance2")
	return
end

function MouthOfSauronUseDarkWave(self, other, delay, amount)
	ObjectDoSpecialPower(self, "SpecialAbilityWildMountainGiantStomp")
	return
end

function PallandoUseDefensePower(self) -- Used by units to broadcast the chant event to their own side.
	ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
	return
end

function GandalfTriggerWizardBlast(self)
	ObjectCreateAndFireTempWeapon(self, "GandalfWizardBlast")
end

--function SarumanConsiderUsingDefensePower(self, other, delay, amount)
--	-- Put up the shield if a big attack is coming and we have time to block it
--E4	if tonumber(delay) > 1 then
--E4		if tonumber(amount) >= 25 then
--E4			ObjectDoSpecialPower(self, "SpecialPowerShieldBubble")
--E4			return
--E4		end
--E4	end
--	
--	-- Or, if we are being hit and there are alot of guys arround, do our cool pushback power
--	if tonumber(ObjectCountNearbyEnemies(self, 50)) >= 4 then
--		ObjectDoSpecialPower(self, "SpecialPowerTelekeneticPush")
--		return
--	end
--end

function BalrogTriggerBreatheFire(self)
	ObjectCreateAndFireTempWeapon(self, "MordorBalrogBreath")
end

function OnRohirrimCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "SHIELD", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnNobleHaradrimCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "GNLT_01", true )
	ObjectHideSubObjectPermanently( self, "HLMT_01", true )
	ObjectHideSubObjectPermanently( self, "SLDR_01", true )
	ObjectHideSubObjectPermanently( self, "BOOT_01", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnDolAmrothCreated(self)
	ObjectGrantUpgrade( self, "Upgrade_Mount")
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnSummonedRohirrimCreated(self)
	ObjectGrantUpgrade( self, "Upgrade_RohanHeavyArmorForRohirrim" )
	ObjectGrantUpgrade( self, "Upgrade_RohanHorseShield" )
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
end

function OnGondorCavalryCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "sshield", true )
end

function OnDwarvenBattleWagonCreated(self)
	ObjectHideSubObjectPermanently( self, "dwarfHearth", true )
	ObjectHideSubObjectPermanently( self, "dwarfHearthFire", true )
	ObjectHideSubObjectPermanently( self, "Banner_L", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnRhunWarChariotCreated(self)
	ObjectHideSubObjectPermanently( self, "TRUNKPOLE01", true )
	ObjectHideSubObjectPermanently( self, "HORSECHEST01", true )
	ObjectHideSubObjectPermanently( self, "BLADEL02", true )
	ObjectHideSubObjectPermanently( self, "BLADER02", true )
	ObjectHideSubObjectPermanently( self, "BLADEF01", true )
end

function OnEvilMenBlackRiderCreated(self)
	-- @todo place appropriate functionality here
end

function OnBallistaCreated(self)
	ObjectHideSubObjectPermanently( self, "MinedArrow", true )
end

function OnCatapultCreated(self)
	ObjectHideSubObjectPermanently( self, "PROJECTILEROCK", true )
	ObjectHideSubObjectPermanently( self, "FIREPLANE", true )
end

function OnTrebuchetCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREPLANE", true )
end

function OnTrollSlingCreated(self)
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
end

function OnPorterCreated(self)
	ObjectHideSubObjectPermanently( self, "ARROWS", true )
	ObjectHideSubObjectPermanently( self, "BRAZIER", true )
	ObjectHideSubObjectPermanently( self, "BOWS", true )
	ObjectHideSubObjectPermanently( self, "TREBUCHET_FIRE", true )
	ObjectHideSubObjectPermanently( self, "SWORDS", true )
	ObjectHideSubObjectPermanently( self, "SHIELDS", true )
	ObjectHideSubObjectPermanently( self, "ARMOR", true )
	ObjectHideSubObjectPermanently( self, "BANNERS", true )
end

function OnEvilPorterCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "ARROW_UPGRADE", true )
	ObjectHideSubObjectPermanently( self, "ARMOR_UPGRADE", true )
	ObjectHideSubObjectPermanently( self, "GOLD", true )
	ObjectHideSubObjectPermanently( self, "SWORD_UPGRADES", true )
end

function OnPeasantCreated(self)
	ObjectHideSubObjectPermanently( self, "HELMET", true )
	ObjectHideSubObjectPermanently( self, "SWORD", true )
	ObjectHideSubObjectPermanently( self, "HAMMER", false )
	ObjectHideSubObjectPermanently( self, "FORGED_BLADE", true )
	ObjectHideSubObjectPermanently( self, "SHIELD", true )
	ObjectHideSubObjectPermanently( self, "Broom", true )
end

function OnMordorSauronCreated(self)
	ObjectHideSubObjectPermanently( self, "SHARD01", true )
	ObjectHideSubObjectPermanently( self, "SHARD02", true )
	ObjectHideSubObjectPermanently( self, "SHARD03", true )
	ObjectHideSubObjectPermanently( self, "SHARD04", true )
	ObjectHideSubObjectPermanently( self, "SHARD05", true )
	ObjectHideSubObjectPermanently( self, "SHARD06", true )
	ObjectHideSubObjectPermanently( self, "SHARD07", true )
	ObjectHideSubObjectPermanently( self, "SHARD08", true )
	ObjectHideSubObjectPermanently( self, "SHARD09", true )
	ObjectHideSubObjectPermanently( self, "SHARD10", true )
	ObjectHideSubObjectPermanently( self, "SHARD11", true )
	ObjectHideSubObjectPermanently( self, "SHARD12", true )
	ObjectHideSubObjectPermanently( self, "SHARD13", true )
	ObjectHideSubObjectPermanently( self, "SHARD14", true )
	ObjectHideSubObjectPermanently( self, "SHARD15", true )
	ObjectHideSubObjectPermanently( self, "SHARD16", true )
	ObjectHideSubObjectPermanently( self, "SHARD17", true )
	ObjectHideSubObjectPermanently( self, "SHARD18", true )
	ObjectHideSubObjectPermanently( self, "SHARD19", true )
	ObjectHideSubObjectPermanently( self, "SHARD20", true )
end

function OnElvenWarriorCreated(self)
	ObjectHideSubObject( self, "ARROW", true )
	ObjectHideSubObject( self, "ARROWNOCK", true )
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnIsengardFighterCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Glow", true )
end

function OnIsengardWildmanCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Torch", true )
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
end

function OnWildSpiderRiderCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
	ObjectHideSubObject( self, "ARROWNOCK", true )
end

function OnHaradrimArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FireArowTip", true )
	ObjectHideSubObject( self, "ArrowNock", true )
end

function OnIsengardArcherCreated(self)
	ObjectHideSubObject( self, "ARROWNOCK", true )
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnWildGoblinArcherCreated(self)
	ObjectHideSubObjectPermanently( self, "FIREAROWTIP", true )
end

function OnGarrisonableCreated(self)
	ObjectHideSubObjectPermanently( self, "GARRISON01", true )
	ObjectHideSubObjectPermanently( self, "GARRISON02", true )
end
function OnDwarvenGuardianCreated(self)
	ObjectHideSubObjectPermanently( self, "Forged_Blade", true )
	ObjectHideSubObjectPermanently( self, "Hammer1", true )
end

function CreateAHeroHideEverything(self)
	ObjectHideSubObjectPermanently( self, "SWORD", true )
	ObjectHideSubObjectPermanently( self, "BOW", true )
	ObjectHideSubObjectPermanently( self, "BOW_03", true )
	ObjectHideSubObjectPermanently( self, "BOW_04", true )
	ObjectHideSubObjectPermanently( self, "BOW_05", true )
	ObjectHideSubObjectPermanently( self, "TRUNK01", true )
	ObjectHideSubObjectPermanently( self, "STAFF_LIGHT", true )
	ObjectHideSubObjectPermanently( self, "OBJECT01", true )
	
	ObjectHideSubObjectPermanently( self, "SHIELD01", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_01", true )
	ObjectHideSubObjectPermanently( self, "SPEAR", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_B", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_C", true )
	ObjectHideSubObjectPermanently( self, "SHIELD_D", true )
	ObjectHideSubObjectPermanently( self, "B_SHIELD", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_A", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_B", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_C", true )
	ObjectHideSubObjectPermanently( self, "WEAPON_D", true )
	
	ObjectHideSubObjectPermanently( self, "AXE02", true )

	ObjectHideSubObjectPermanently( self, "AxeWeapon", true )
	ObjectHideSubObjectPermanently( self, "Belthronding", true )
	-- ObjectHideSubObjectPermanently( self, "Mithlondrecurve", true )
	ObjectHideSubObjectPermanently( self, "Dwarf_Axe01", true )
	ObjectHideSubObjectPermanently( self, "FireBrand", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_SM", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_FX01", true )
	ObjectHideSubObjectPermanently( self, "FireBrand_FX02", true )
	ObjectHideSubObjectPermanently( self, "Gurthang", true )
	ObjectHideSubObjectPermanently( self, "Gurthang_SM", true )
	ObjectHideSubObjectPermanently( self, "HeroOfTheWestShield", true )
	ObjectHideSubObjectPermanently( self, "HeroOfTheWestShield_SM", true )
	ObjectHideSubObjectPermanently( self, "MithlondBow", true )
	ObjectHideSubObjectPermanently( self, "TrollBane", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_SM", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_FX01", true )
	ObjectHideSubObjectPermanently( self, "TrollBane_FX02", true )
	ObjectHideSubObjectPermanently( self, "TrollMace", true )
	ObjectHideSubObjectPermanently( self, "TrollSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword", true )
	ObjectHideSubObjectPermanently( self, "WestronSword_SM", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX2", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX3", true )
	ObjectHideSubObjectPermanently( self, "WizStaff01_FX4", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff02", true )
	ObjectHideSubObjectPermanently( self, "WizStaff02_FX1", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff03", true )
	ObjectHideSubObjectPermanently( self, "WizStaff03_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff03_FX02", true )
	ObjectHideSubObjectPermanently( self, "WizardStaff04", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX01", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX02", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX03", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX04", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX05", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX06", true )
	ObjectHideSubObjectPermanently( self, "WizStaff04_FX07", true )
	ObjectHideSubObjectPermanently( self, "WizardSword", true )
	ObjectHideSubObjectPermanently( self, "CMSword01", true )
	ObjectHideSubObjectPermanently( self, "CMSword02", true )
	ObjectHideSubObjectPermanently( self, "CHEST_00", true )	
	ObjectHideSubObjectPermanently( self, "CHEST_01", true )	
	ObjectHideSubObjectPermanently( self, "CHEST_02", true )	
	ObjectHideSubObjectPermanently( self, "BOOT_00", true )
	ObjectHideSubObjectPermanently( self, "BOOT_01", true )
	ObjectHideSubObjectPermanently( self, "BOOT_02", true )
	ObjectHideSubObjectPermanently( self, "BOOT_03", true )
	ObjectHideSubObjectPermanently( self, "BOOT_04", true )
	ObjectHideSubObjectPermanently( self, "BOOT_05", true )
	ObjectHideSubObjectPermanently( self, "BOOT_06", true )
	ObjectHideSubObjectPermanently( self, "SHLD_00", true )
	ObjectHideSubObjectPermanently( self, "SHLD_01", true )
	ObjectHideSubObjectPermanently( self, "SHLD_02", true )
	ObjectHideSubObjectPermanently( self, "SHLD_03", true )
	ObjectHideSubObjectPermanently( self, "SHLD_04", true )
	ObjectHideSubObjectPermanently( self, "SLDR_00", true )
	ObjectHideSubObjectPermanently( self, "SLDR_01", true )
	ObjectHideSubObjectPermanently( self, "SLDR_02", true )
	ObjectHideSubObjectPermanently( self, "SLDR_03", true )
	ObjectHideSubObjectPermanently( self, "SLDR_04", true )
	ObjectHideSubObjectPermanently( self, "SLDR_05", true )
	ObjectHideSubObjectPermanently( self, "SLDR_06", true )
	ObjectHideSubObjectPermanently( self, "Shield_1OG", true )
	ObjectHideSubObjectPermanently( self, "Shield_2OG", true )
	ObjectHideSubObjectPermanently( self, "HAIR_00", true )
	ObjectHideSubObjectPermanently( self, "HAIR_01", true )
	ObjectHideSubObjectPermanently( self, "HLMT_00", true )
	ObjectHideSubObjectPermanently( self, "HLMT_01", true )
	ObjectHideSubObjectPermanently( self, "HLMT_02", true )
	ObjectHideSubObjectPermanently( self, "HLMT_03", true )
	ObjectHideSubObjectPermanently( self, "HLMT_04", true )
	ObjectHideSubObjectPermanently( self, "HLMT_05", true )
	ObjectHideSubObjectPermanently( self, "HLMT_06", true )
	ObjectHideSubObjectPermanently( self, "HLMT_07", true )
	ObjectHideSubObjectPermanently( self, "HLMT_07_LOD1", true )
	ObjectHideSubObjectPermanently( self, "HLMT_08", true )
	ObjectHideSubObjectPermanently( self, "HLMT_09", true )
	ObjectHideSubObjectPermanently( self, "GNLT_00", true )
	ObjectHideSubObjectPermanently( self, "GNLT_01", true )
	ObjectHideSubObjectPermanently( self, "GNLT_02", true )
	ObjectHideSubObjectPermanently( self, "GNLT_03", true )
	ObjectHideSubObjectPermanently( self, "GNLT_04", true )
	ObjectHideSubObjectPermanently( self, "GNLT_05", true )
	ObjectHideSubObjectPermanently( self, "GNLT_06", true )
	ObjectHideSubObjectPermanently( self, "GNLT_07", true )
	ObjectHideSubObjectPermanently( self, "GNLT_08", true )
	ObjectHideSubObjectPermanently( self, "GHLT_08", true )
	ObjectHideSubObjectPermanently( self, "GNLT_09", true )
	ObjectHideSubObjectPermanently( self, "GNLT_09_LOD1", true )
	ObjectHideSubObjectPermanently( self, "GNLT_10", true )
	ObjectHideSubObjectPermanently( self, "SPR_01", true )
	ObjectHideSubObjectPermanently( self, "PAXE_01", true )
	ObjectHideSubObjectPermanently( self, "PAXE_01_LOD1", true )
	ObjectHideSubObjectPermanently( self, "SWRD_01", true )
	ObjectHideSubObjectPermanently( self, "SWRD_02", true )
	ObjectHideSubObjectPermanently( self, "SWRD_03", true )
	ObjectHideSubObjectPermanently( self, "SWRD_04", true )
	ObjectHideSubObjectPermanently( self, "SWRD_05", true )
	ObjectHideSubObjectPermanently( self, "SWD_01", true )
	ObjectHideSubObjectPermanently( self, "SWD_02", true )
	ObjectHideSubObjectPermanently( self, "SWD_03", true )
	ObjectHideSubObjectPermanently( self, "SWD_04", true )
	ObjectHideSubObjectPermanently( self, "STFF_05", true )
	ObjectHideSubObjectPermanently( self, "STFF_06", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_01", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_02", true )
	ObjectHideSubObjectPermanently( self, "objSLDR_03", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_01", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_02", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_03", true )
	ObjectHideSubObjectPermanently( self, "objHLMT_04", true )	
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_01", true )
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_02", true )
	ObjectHideSubObjectPermanently( self, "Uruk_Sword_03", true )
	ObjectHideSubObjectPermanently( self, "TrollTree", true )
	ObjectHideSubObjectPermanently( self, "TrollHammer", true )
	ObjectHideSubObjectPermanently( self, "CLUB_01", true )
	ObjectHideSubObjectPermanently( self, "CLUB_02", true )
	ObjectHideSubObjectPermanently( self, "CLUB_03", true )
	ObjectHideSubObjectPermanently( self, "HMR_01", true )
	ObjectHideSubObjectPermanently( self, "HMR_02", true )
	ObjectHideSubObjectPermanently( self, "HMR_03", true )
	ObjectHideSubObjectPermanently( self, "HMR_04", true )
	ObjectHideSubObjectPermanently( self, "AXE_01", true )
	ObjectHideSubObjectPermanently( self, "AXE_02", true )
	ObjectHideSubObjectPermanently( self, "AXE_03", true )
	ObjectHideSubObjectPermanently( self, "BARREL", true )
	ObjectHideSubObjectPermanently( self, "OBJECT02", true )	-- Barrel on the Orc Raider
	ObjectHideSubObjectPermanently( self, "ARROW", true )
	ObjectHideSubObjectPermanently( self, "PLANE02", true )	
end

function OnCreateAHeroFunctions(self)
	CreateAHeroHideEverything(self)
end

function OnEvilShipCreated(self)
	ObjectHideSubObjectPermanently( self, "CAULDRON", true )
	ObjectHideSubObjectPermanently( self, "CAULDRON_FIRE", true )
	ObjectHideSubObjectPermanently( self, "CAULDRON_TOP", true )
	ObjectHideSubObjectPermanently( self, "CROWSNEST", true )
	ObjectHideSubObjectPermanently( self, "FLAG", true )
	ObjectHideSubObjectPermanently( self, "BANNER", true )
end

function OnGoodShipCreated(self)
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_01", true )
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_02", true )
	ObjectHideSubObjectPermanently( self, "UG_FLAMING_FIRE", true )
	ObjectHideSubObjectPermanently( self, "UG_ARMOR", true )
	ObjectHideSubObjectPermanently( self, "BANNER", true )
end

function OnShipWrightCreated(self)
	ObjectHideSubObjectPermanently( self, "GoodPart_A", true )
	ObjectHideSubObjectPermanently( self, "GoodPart_B", true )
	ObjectHideSubObjectPermanently( self, "EvilPart_A", true )
	ObjectHideSubObjectPermanently( self, "EvilPart_B", true )
end

function OnDormitoryBuildVariation(self,variation)

	local var = tonumber(variation)

	if var == 1 then
		ObjectSetGeometryActive( self, "VersionOne", true )
		ObjectSetGeometryActive( self, "VersionTwo", false )
	elseif var == 2 then
		ObjectSetGeometryActive( self, "VersionOne", false )
		ObjectSetGeometryActive( self, "VersionTwo", true )
	end

end

function OnFortressCreated(self)
	ObjectHideSubObjectPermanently( self, "DBFBANNER", true )	
	ObjectSetGeometryActive( self, "HighTowerGeom", false )
end

function OnGateWatcherBuilt(self)
	ObjectDoSpecialPower(self, "SpecialAbilityGateWatchersFear")
end	

function NeutralGollum_RingStealerDamaged(self,other)

	if ObjectHasUpgrade( other, "Upgrade_RingHero" ) == 0 then
		ObjectChangeAllegianceFromNonPlayablePlayer( self, other )
	end
	
end

function NeutralGollum_RingStealerSlaughtered(self,other)
	ObjectRemoveUpgrade( other, "Upgrade_RingHero" )
end

function OnNecromancerStatueCreated(self)
	ObjectDoSpecialPower(self, "SpecialAbilityGateWatchersFear")
end	