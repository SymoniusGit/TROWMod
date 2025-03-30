		AnimationState = STUNNED_STANDING_UP WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			StateName			  = STATE_StandingUpWithRock
			Animation
				AnimationName     = WUMntGnt_RGRBA
				AnimationMode     = ONCE
				AnimationSpeedFactorRange	= 1.67 1.67
			End
			LuaEvent = Frame:20 Data: show_rock
			FXEvent	= Frame:22	Name: FX_GiantRockGrab
			FXEvent	= Frame:38	Name: FX_GiantRockYank
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev ~= "STATE_StandingUpWithRock" and Prev ~= "TRANS_GetUpWithRock"
					then CurDrawableSetTransitionAnimState("TRANS_GetUpWithRock") end
			EndScript
			
		End
		
		AnimationState = STUNNED_STANDING_UP CREATE_A_HERO_35
			Animation
				AnimationName     = WUMntGnt_GTPA 
				AnimationMode     = ONCE
			End
		End

		AnimationState			= USER_4				; This is a special for being tied up.
			StateName			= STATE_Tied
			Animation
				AnimationName   = WUMntGnt_SPCA
				AnimationMode   = LOOP
			End
;			BeginScript
;				CurDrawableHideSubObjectPermanently("ROCK")
;			EndScript
		End

		AnimationState			= STUNNED_FLAILING CREATE_A_HERO_35
			Animation           = StunFlail 
				AnimationName   = WUMntGnt_FLYA
				AnimationMode   = LOOP
			End
			Flags = MAINTAIN_FRAME_ACROSS_STATES2
		End

		AnimationState = STUNNED CREATE_A_HERO_35
			Animation
				AnimationName     = WUMntGnt_LNDA
				AnimationMode     = ONCE
			End
		End
		
		AnimationState = DYING DEATH_3 CREATE_A_HERO_35
			Animation
				AnimationName = WUMntGnt_IDLA
				AnimationMode = LOOP
			End
		End


		ModelConditionState = DYING SPLATTED DECAY DEATH_1 CREATE_A_HERO_35
			Model				= WUMntGnt_DISA
			RetainSubObjects	= Yes
		End

		AnimationState = DYING SPLATTED DECAY DEATH_1 CREATE_A_HERO_35
			Animation
				AnimationName	  = WUMntGnt_DISA.WUMntGnt_DISA
				AnimationMode	  = ONCE
			End
			BeginScript
				CurDrawableHideSubObjectPermanently("ROCK")
			EndScript
		End
		
		AnimationState = DYING SPLATTED DEATH_1 CREATE_A_HERO_35
			Animation
				AnimationName	  = WuMntGnt_LNDA
				AnimationMode	  = ONCE
			End
			BeginScript
				CurDrawableHideSubObjectPermanently("ROCK")
			EndScript
		End

		ModelConditionState = DYING DECAY DEATH_1 CREATE_A_HERO_35
			Model				= WUMntGnt_DISA
			RetainSubObjects	= Yes
		End

		AnimationState = DYING DECAY DEATH_1 WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation = dead1
				AnimationName	= WUMntGnt_DISA.WUMntGnt_DISA
				AnimationMode	= ONCE
			End
		End

		AnimationState = DYING DECAY DEATH_1 CREATE_A_HERO_35
			Animation = dead1
				AnimationName	= WUMntGnt_DISA.WUMntGnt_DISA
				AnimationMode	= ONCE
			End
			BeginScript
				CurDrawableHideSubObjectPermanently("ROCK")
			EndScript
		End

		AnimationState = DYING WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName     = WUMntGnt_RDIEA
				AnimationMode     = ONCE
			End
		End

		AnimationState = DYING CREATE_A_HERO_35
			Animation
				AnimationName     = WUMntGnt_DIEA
				AnimationMode     = ONCE
			End
			
			// DIEB falls forward and cannot be used until there is an equivalent RDIEB so that the DeathWeapon can match properly
			//Animation
			//	AnimationName     = WUMntGnt_DIEB
			//	AnimationMode     = ONCE
			//End
		End		
		
		AnimationState						= PARALYZED CREATE_A_HERO_35
			Animation
				AnimationName				= WUMntGnt_IDLB
				AnimationMode				= LOOP
			End
		End

		AnimationState = SPECIAL_WEAPON_ONE CREATE_A_HERO_35
			FrameForPristineBonePositions = 64
			Animation
				AnimationName = WUMntGnt_UGRBB
				AnimationMode = ONCE
			End
		End

		AnimationState = SPECIAL_WEAPON_TWO CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_ATKF
				AnimationMode		= ONCE
			End
		End

		AnimationState = RELOADING_A WEAPONSET_TOGGLE_1	CREATE_A_HERO_35		; Pull rock out of the ground.
			Animation
				AnimationName		= WUMntGnt_RGRBA
				AnimationMode		= ONCE
			End

			FXEvent	= Frame:22	Name: FX_GiantRockGrab
			FXEvent	= Frame:38	Name: FX_GiantRockYank
			
		End

		// Throw rock close range
		AnimationState = FIRING_OR_PREATTACK_B WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_RTHRC
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationBlendTime	= 10
			End
			FrameForPristineBonePositions = 37							; Just as the rock leaves his hands.
		End

		// Throw rock
		AnimationState = FIRING_OR_PREATTACK_A WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_RTHRA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationBlendTime	= 10
			End
			FrameForPristineBonePositions = 37							; Just as the rock leaves his hands.
		End

		// ATKA - Left arm swat 
		AnimationState = FIRING_OR_PREATTACK_A CREATE_A_HERO_35
			Animation 
				AnimationName		= WUMntGnt_ATKA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
		End
		AnimationState = FIRING_OR_PREATTACK_B CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_ATKB
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
		End
		AnimationState = FIRING_OR_PREATTACK_C CREATE_A_HERO_35	
			Animation
				AnimationName		= WUMntGnt_ATKD
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
			End
		End


		// ATKE - Left forward kick		
		AnimationState = FIRING_OR_PREATTACK_D CREATE_A_HERO_35						; The anti-structure weapon
			Animation
				AnimationName		= WUMntGnt_ATKE
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationBlendTime	= 10
			End
		End

		// ATRA - Right backhand while moving
		AnimationState = FIRING_OR_PREATTACK_E CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_ATRA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationBlendTime	= 10
			End
			FXEvent	= Frame:3 FireWhenSkipped Name:FX_GiantRightFootStep
			FXEvent	= Frame:20 FireWhenSkipped Name:FX_GiantLeftFootStep
		End


		AnimationState = TURN_LEFT WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_RTRNL
				AnimationMode		= LOOP
				AnimationBlendTime	= 10 ;20
			End
		End
		
		AnimationState = TURN_RIGHT WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_RTRNR
				AnimationMode		= LOOP
				AnimationBlendTime	= 10 ;20
			End
		End

		AnimationState = MOVING WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_RWLKA
				AnimationMode		= LOOP
				Distance			= 175
			End
			FXEvent	= Frame:21 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:43 FireWhenSkipped Name:FX_GiantRightFootStep
			FXEvent	= Frame:63 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:85 FireWhenSkipped Name:FX_GiantRightFootStep
			FXEvent	= Frame:103 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:127 FireWhenSkipped Name:FX_GiantRightFootStep
		End

		AnimationState = ENGAGED WEAPONSET_TOGGLE_1 CREATE_A_HERO_35			; 'Ready' pose with rock. This is to smooth out the reload/attacking anims.
			Animation
				AnimationName	= WUMntGnt_RIDLA
				AnimationMode	= LOOP
				AnimationBlendTime	= 10
			End
			Flags = RANDOMSTART
		End

		AnimationState = ATTACKING WEAPONSET_TOGGLE_1 CREATE_A_HERO_35			; 'Ready' pose with rock. This is to smooth out the reload/attacking anims.
			Animation
				AnimationName	= WUMntGnt_RIDLA
				AnimationMode	= LOOP
				AnimationBlendTime	= 10
			End
			Flags = RANDOMSTART
		End

		;AnimationState = MOVING ATTACKING CREATE_A_HERO_35
		;	Animation
		;		AnimationName		= WUMntGnt_RUNA
		;		AnimationMode		= LOOP
		;		UseWeaponTiming		= Yes
		;	End
		;End

		AnimationState = TURN_LEFT CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_TRNL
				AnimationMode		= LOOP
				AnimationBlendTime	= 10
			End
		End

		AnimationState = TURN_RIGHT CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_TRNR 
				AnimationMode		= LOOP
				AnimationBlendTime	= 10
			End
		End
					
		AnimationState				= MOVING PANICKING CREATE_A_HERO_35
			Animation
				AnimationName				= WUMntGnt_MFDA
				AnimationMode				= LOOP
				AnimationSpeedFactorRange	= 0.55 0.55						; Feet slide a lot, so slow the anim down.
			End
			Flags					= RANDOMSTART
		End

		AnimationState = MOVING CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_WLKA
				AnimationMode		= LOOP
				AnimationBlendTime	= 10
				Distance			= 175
			End
			Flags = RANDOMSTART
			FXEvent	= Frame:21 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:43 FireWhenSkipped Name:FX_GiantRightFootStep
			FXEvent	= Frame:63 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:85 FireWhenSkipped Name:FX_GiantRightFootStep
			FXEvent	= Frame:103 FireWhenSkipped Name:FX_GiantLeftFootStep
			FXEvent	= Frame:127 FireWhenSkipped Name:FX_GiantRightFootStep
		End

		AnimationState = SWAPPING_TO_WEAPONSET_1 CREATE_A_HERO_35		; This is required so we get a nice pose to blend from when reloading the rock.
			Animation									; must be before SELECTED
				AnimationName	= WUMntGnt_ATNB
			End
		End



;;------------------ Selected with Rock

		AnimationState = SELECTED WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			StateName			= STATE_SelectedRock
			Animation
				AnimationName	= WUMntGnt_RATNB
				AnimationMode	= LOOP
			End
			Flags = RANDOMSTART
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev ~= "STATE_SelectedRock" and Prev ~= "TRANS_IdleToSelectedRock"
					then CurDrawableSetTransitionAnimState("TRANS_IdleToSelectedRock") end
			EndScript
		End
					
;;------------------ Idle with Rock

		AnimationState = WEAPONSET_TOGGLE_1 CREATE_A_HERO_35
			StateName = STATE_RockIdle
			Animation
				AnimationName	= WUMntGnt_RIDLB
				AnimationMode	= LOOP
			End
			Flags = RANDOMSTART
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Tied" then
					CurDrawableSetTransitionAnimState("TRANS_SelectedFromTied")
				elseif Prev ~= "STATE_RockIdle" and Prev ~= "TRANS_SelectedRockToIdle" then
					CurDrawableSetTransitionAnimState("TRANS_SelectedRockToIdle")
				end
			EndScript
		End


		
;;------------------ Attacking

		AnimationState = ATTACKING CREATE_A_HERO_35								; Between attacks we need to go to this idle since it's the base for the attack animations (needs to be before SELECTED)
			Animation
				AnimationName	= WUMntGnt_IDLA
				AnimationMode	= LOOP
				AnimationBlendTime	= 10
			End
		End

;;------------------ Selected
			
		AnimationState = SELECTED CREATE_A_HERO_35
			StateName			= STATE_Selected
			Animation
				AnimationName	= WUMntGnt_ATNB
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Idle" then CurDrawableSetTransitionAnimState("TRANS_IdleToSelected") end
			EndScript
		End
	
		AnimationState = ENGAGED CREATE_A_HERO_35
			Animation
				AnimationName	= WUMntGnt_IDLB
				AnimationMode	= LOOP
			End
		End
		
;;------------------ Hit Reaction 

		AnimationState = HIT_REACTION CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_HITA
				AnimationMode		= ONCE
			End
		End
		
;;------------------ Emotions

		// Emotions must be beneath WEAPONSET_TOGGLE_1 default idle because there are no
		// emotions-with-rock animations

		AnimationState = EMOTION_TAUNTING CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_TNTA
				AnimationMode		= LOOP
			End
		End

		AnimationState = EMOTION_CELEBRATING CREATE_A_HERO_35
			Animation
				AnimationName		= WUMntGnt_CHRA
				AnimationMode		= ONCE
			End
		End

;;------------------ Transitions

		TransitionState = TRANS_GetUpWithRock CREATE_A_HERO_35
			Animation
				AnimationName = WUMntGnt_GTPA
				AnimationMode = ONCE
				AnimationSpeedFactorRange	=	1.5 1.5
			End		
		End

		TransitionState = TRANS_IdleToSelectedRock CREATE_A_HERO_35
			Animation
				AnimationName = WUMntGnt_RATNA
				AnimationMode = ONCE
			End
		End

		TransitionState = TRANS_SelectedRockToIdle CREATE_A_HERO_35
			Animation
				AnimationName = WUMntGnt_RATNC
				AnimationMode = ONCE
			End
		End

		TransitionState = TRANS_IdleToSelected CREATE_A_HERO_35
			Animation
				AnimationName = WUMntGnt_ATNA
				AnimationMode = ONCE
			End
		End

		TransitionState = TRANS_SelectedToBored CREATE_A_HERO_35
			Animation 
				AnimationName = WUMntGnt_ATNC
				AnimationMode = ONCE
			End
		End

		TransitionState = TRANS_SelectedFromTied CREATE_A_HERO_35
			Animation 
				AnimationName = WUMntGnt_GTPB
				AnimationMode = ONCE
			End
			ParticleSysBone = B_FOOTL GiantRopesBreak
			ParticleSysBone = B_FOOTR GiantRopesBreak
			ParticleSysBone = B_HANDL GiantRopesBreak
			ParticleSysBone = B_HANDR GiantRopesBreak
			ParticleSysBone = B_NECK01 GiantRopesBreak
			
			ParticleSysBone = B_FOOTL GiantRopesDust
			ParticleSysBone = B_FOOTR GiantRopesDust
			ParticleSysBone = B_HANDL GiantRopesDust
			ParticleSysBone = B_HANDR GiantRopesDust
			ParticleSysBone = B_NECK01 GiantRopesDust
		End
			
		
		AnimationState = CREATE_A_HERO_35
			StateName = Idle
			AllowRepeatInRandomPick = Yes
			Flags = RESTART_ANIM_WHEN_COMPLETE		

			Animation = stand
				AnimationName		= WUMntGnt_IDLB
				AnimationMode		= ONCE
				AnimationPriority	= 60
			End
			Animation = tugarmour
				AnimationName		= WUMntGnt_IDLD
				AnimationMode		= ONCE
				AnimationPriority	= 10
			End
			Animation = scratchbutt
				AnimationName		= WUMntGnt_IDLC
				AnimationMode		= ONCE
				AnimationPriority	= 5
			End
			Animation = bugstep
				AnimationName		= WUMntGnt_IDLE
				AnimationMode		= ONCE
				AnimationPriority	= 5
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Selected"
					then CurDrawableSetTransitionAnimState("TRANS_SelectedToBored")
				elseif Prev == "STATE_Tied"
					then CurDrawableSetTransitionAnimState("TRANS_SelectedFromTied")
				end
			EndScript			
		End