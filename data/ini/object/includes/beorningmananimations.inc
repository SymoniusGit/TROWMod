;;================== ANIMATIONS =================================================================

		; --- Idle Anims
		IdleAnimationState
			StateName = Idle			
			Animation           = IDLB
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_IDLB 0 15
				AnimationMode     = ONCE
				AnimationPriority   = 20
			End			
			Animation           = IDLC
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_IDLC
				AnimationMode     = ONCE
				AnimationPriority   = 5
			End			
			Animation           = IDLD
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_IDLD
				AnimationMode     = ONCE
				AnimationPriority   = 5
			End			
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Selected" then CurDrawableSetTransitionAnimState("TRANS_Selected_To_Idle") end
			EndScript			
		End

		
		AnimationState        = STUNNED_FLAILING 
			Flags               = RANDOMSTART
			Animation           = GUBoromir_FLYA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_FLYA
				AnimationMode     = LOOP
			End
		End


		; --- Dying anims
		
		AnimationState        = DYING SPLATTED
			Animation           = GUBoromir_LNDA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_LNDA
				AnimationMode     = ONCE
			End
		End
		AnimationState        = DYING AFLAME
			Animation = DieAflame
				AnimationName       = Kuhwaldar_SKL.Kuhwaldar_MFDA
				AnimationMode       = LOOP
			End
		End
		AnimationState        = DYING
			Animation           = GUBoromir_DTHA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_DTHA
				AnimationMode     = ONCE
			End
		End
		
		; --- Stunned anims
		AnimationState        = STUNNED_STANDING_UP
			Animation           = GUBoromir_GTPA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_GTPA
				AnimationMode     = ONCE
				AnimationSpeedFactorRange = 1.3 1.3
			End
		End
		AnimationState        = STUNNED 
			Animation           = GUBoromir_LNDA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_LNDA
				AnimationMode     = ONCE
			End
		End
		
		AnimationState        = PACKING_TYPE_2 
			StateName		  =	CaptainPower
			Animation           = GUBoromir_CHRA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_CHRA
				AnimationMode     = LOOP
				AnimationSpeedFactorRange = 1.2 1.2
			End
		End

		AnimationState        = SPECIAL_POWER_1
			Animation           
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_SPCC
				AnimationMode     = LOOP
			End
		End
		
		
		; --- Moving Anims
		AnimationState        = MOVING WANDER WEAPONSTATE_CLOSE_RANGE
			StateName           = WithSword
			;ParticleSysBone     = None InfantryDustTrails
			Animation           = GUBoromir_WLKA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_WLKA
				AnimationMode     = LOOP
			End
		End
		; non mo cap
		AnimationState        = MOVING WANDER
			;ParticleSysBone     = None InfantryDustTrails
			Animation           = GUBoromir_WLKA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_WLKA
				AnimationMode     = LOOP
			End
		End
		
		
		AnimationState        = MOVING FIRING_OR_PREATTACK_A
			ShareAnimation		= Yes
			Animation           = RunAndFire
				AnimationName       = Kuhwaldar_SKL.Kuhwaldar_RUNB
				AnimationMode       = LOOP
			End
			Flags               = RANDOMSTART  
		End
		
		
		AnimationState        = MOVING
			;ParticleSysBone     = None InfantryDustTrails
			Flags               = RANDOMSTART
			Animation           = MOVE
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_RUNA
				AnimationMode     = LOOP
			End
		End
		
		

		; Attacking Anims [Weapon_A]
		AnimationState        = FIRING_OR_PREATTACK_A 
			StateName           = Attack
			Animation           = ATKA
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_ATKA
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
			Animation           = ATKB
				AnimationName    = Kuhwaldar_SKL.Kuhwaldar_ATKB
				AnimationMode     = ONCE
				UseWeaponTiming		= Yes
			End
		End

		;SHAPESHIFT
		AnimationState        = PACKING_TYPE_3
			Animation           = SPCB
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_CHRA
				AnimationMode     = ONCE
			End
		End
		
		; --------- Selected Anims and Transitions
		TransitionState					=	TRANS_Idle_to_Selected
			Animation					=	ATNA
				AnimationName			=	Kuhwaldar_SKL.Kuhwaldar_ATNA
				AnimationMode			=	ONCE
			End
		End
		
		TransitionState					=	TRANS_Selected_To_Idle
			Animation					=	ATNC
				AnimationName			=	Kuhwaldar_SKL.Kuhwaldar_ATNC
				AnimationMode			=	ONCE
			End
		End
		
		AnimationState				= LEVELED 						; This state clears itself in 3 seconds
			Animation				= LevelUp
				AnimationName		= Kuhwaldar_SKL.Kuhwaldar_LVLA
				AnimationMode		= ONCE
			End
		End

		AnimationState				= RAISING_FLAG
			StateName				= STATE_ready
			Animation				= CHRA
				AnimationName		= Kuhwaldar_SKL.Kuhwaldar_CHRA
				AnimationMode		= LOOP
			End
		End

		AnimationState				=	SELECTED
			StateName				=	Selected
			SimilarRestart			=   Yes			
			Animation				=	ATNB
				AnimationName		=	Kuhwaldar_SKL.Kuhwaldar_ATNB
				AnimationMode		=	LOOP
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Idle" then CurDrawableSetTransitionAnimState("TRANS_Idle_to_Selected") end
			EndScript
		End
		
		;------------emotions---------------
		AnimationState			= EMOTION_CELEBRATING
			Animation           = CHRA
				AnimationName   = Kuhwaldar_SKL.Kuhwaldar_CHRA
				AnimationMode   = LOOP
			End
		End
		
		AnimationState					= EMOTION_ALERT EMOTION_MORALE_HIGH
			Animation					= Taunting
				AnimationName			=  Kuhwaldar_SKL.Kuhwaldar_TNTA
				AnimationMode			= ONCE
			End
			Animation					= Taunting
				AnimationName			=  Kuhwaldar_SKL.Kuhwaldar_TNTB
				AnimationMode			= ONCE
			End
			Flags						= RANDOMSTART RESTART_ANIM_WHEN_COMPLETE
		End
		
		; READY IDLE
		AnimationState        = EMOTION_ALERT
			Animation           = ALERT_1
				AnimationName     = Kuhwaldar_SKL.Kuhwaldar_IDLA
				AnimationMode     = LOOP ;ONCE
			End
;			Flags               = RESTART_ANIM_WHEN_COMPLETE ; acts like an idle animation & keeps running the animations.
		End
		
		
		; --------- Click and Hit Reactions ------------
		AnimationState = HIT_REACTION HIT_LEVEL_1
			Animation = Hit_Level_1_a
				AnimationName = Kuhwaldar_SKL.Kuhwaldar_HITA
				AnimationMode = ONCE
			End
		End