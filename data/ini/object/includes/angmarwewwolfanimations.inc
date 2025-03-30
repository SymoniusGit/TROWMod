;;================== ANIMATIONS =================================================================
		; -------------- STUNNED ANIMS ----------------

		;;; EAT ;;;

		AnimationState = EATING
			FrameForPristineBonePositions = 99
			Animation
				AnimationName = KUWWolf_SPCA
				AnimationMode = ONCE
			End
	      End

		;;; HOWL ;;;

		AnimationState = USER_3
			FrameForPristineBonePositions = 99
			Animation
				AnimationName = KUWWolf_RORA
				AnimationMode = ONCE
			End
	      End

		;;; CALL THE PACK ;;;

		AnimationState				= SPECIAL_WEAPON_ONE
			Animation			= Grabbed
				AnimationName		= KUWWolf_SPCB
				AnimationMode		= ONCE
			End
		End
		AnimationState				= PASSENGER
			Animation			= Grabbed
				AnimationName		= KUWWolf_GBDA
				AnimationMode		= LOOP
			End
		End
	
		AnimationState				= FREEFALL
			Animation			= freefall
				AnimationName		= KUWWolf_FLYA
				AnimationMode		= LOOP
				AnimationBlendTime	= 10
			End
		End
		
		AnimationState				=	DYING BURNINGDEATH
			Animation
				AnimationName		=	KUWWolf_DIEA
				AnimationMode		=	ONCE
				AnimationBlendTime	=	10
			End
		End

		AnimationState				=	DYING SPLATTED
			Animation			=	splatted
				AnimationName		=	KUWWolf_LNDA
				AnimationMode		=	ONCE
			End
		End
		
		AnimationState				=	STUNNED_FLAILING 
			Animation			=	JustDie
				AnimationName       	=	KUWWolf_FLYA
				AnimationMode       	=	LOOP
			End
		End

		AnimationState				=	DYING
			Animation			
				AnimationName		=	KUWWolf_DIEA
				AnimationMode		=	ONCE
			End
			Animation			
				AnimationName		=	KUWWolf_DIEB
				AnimationMode		=	ONCE
			End
		End		

		AnimationState				=	BURNINGDEATH
			Animation
				AnimationName       	=	KUWWolf_MFDA
				AnimationMode       	=	LOOP
				Distance		=	50
			End
		End

	AnimationState			= STUNNED_FLAILING
		Animation
			AnimationName   = KUWWolf_FLYA
			AnimationMode   = LOOP
			AnimationSpeedFactorRange	= 0.4 0.6
		End
	End


		AnimationState				=	STUNNED 
			Animation			=	Land
				AnimationName       	=	KUWWolf_LNDA
				AnimationMode       	=	ONCE
			End
		End

		AnimationState				=	STUNNED_STANDING_UP
			Animation			=	StandUp
				AnimationName       	=	KUWWolf_GTPA
				AnimationMode       	=	ONCE
			End
		End

		AnimationState = PACKING
			StateName				= STATE_Land
			Animation
				AnimationName		= KUWWolf_SKL.KUWWolf_RORA
				AnimationMode		= ONCE
			End
		End

		AnimationState = UNPACKING
			StateName				= STATE_TakeOff
			Animation
				AnimationName		= KUWWolf_SKL.KUWWolf_RORA
				AnimationMode		= ONCE
			End
		End
		
		; -------------- MOVING ANIMS ---------------
		AnimationState				=	TURN_LEFT_HIGH_SPEED
			Animation			=	MTurnLeft
				AnimationName		=	KUWWolf_TNL
				AnimationMode		=	LOOP
			End
		End

		AnimationState				=	TURN_RIGHT_HIGH_SPEED
			Animation			=	MTurnRight
				AnimationName		=	KUWWolf_TNR
				AnimationMode		=	LOOP
			End
		End
		
		AnimationState				=	TURN_LEFT  
			Animation			=	TurnRight
				AnimationName		=	KUWWolf_TRNL
				AnimationMode		=	LOOP
				AnimationSpeedFactorRange = 	2.0 2.0
			End
		End

		AnimationState				=	TURN_RIGHT 
			Animation			=	TurnRight
				AnimationName		=	KUWWolf_TRNR
				AnimationMode		=	LOOP
				AnimationSpeedFactorRange = 	2.0 2.0
			End
		End

		AnimationState				=	MOVING ACCELERATE 
			Animation				=	Accelerate
				AnimationName		=	KUWWolf_RUNA
				AnimationMode		=	ONCE
			End
;            ParticleSysBone				= None GenericSiegeTrailDust
		End
	
		AnimationState				=	MOVING DECELERATE
			Animation				=	Decelerate
				AnimationName		=	KUWWolf_RUNA
				AnimationMode		=	ONCE
			End
		End
		
		AnimationState				=	MOVING BACKING_UP
			Animation			=	BackingUp
				AnimationName		=	KUWWolf_BAKA
				AnimationMode		=	LOOP
			End
		End
		
		AnimationState				=	MOVING
			ShareAnimation			=	Yes
			Animation			=	RunA
				AnimationName		=	KUWWolf_RUNB
				AnimationMode		=	LOOP
			End
			;ParticleSysBone		=	None CalvaryDustTrails  
			Flags               = RANDOMSTART
		End
		
		; ----------- ATTACKING ANIMS --------------		
		AnimationState				=	BETWEEN_FIRING_SHOTS_A
			Animation			=	BetweenFiringShots
				AnimationName		=	KUWWolf_IDLA
				AnimationMode		=	ONCE
				AnimationBlendTime	=   	10
			End
		End

		AnimationState				=	FIRING_OR_PREATTACK_A
			Animation			
				AnimationName		=	KUWWolf_ATKA
				AnimationMode		=	LOOP
				UseWeaponTiming		=	Yes
				AnimationBlendTime	=   	10
			End
			Animation			
				AnimationName		=	KUWWolf_ATKB
				AnimationMode		=	LOOP
				UseWeaponTiming		=	Yes
				AnimationBlendTime  	=	10
			End
		End
		
		AnimationState				=	ATTACKING
			Animation			
				AnimationName		=	KUWWolf_IDLA
				AnimationMode		=	LOOP
				UseWeaponTiming		=	Yes
				;AnimationBlendTime	=   	10
			End
		End

		; ----------- EMOTION ANIMS ---------------
		AnimationState				= EMOTION_TAUNTING
			Animation			= TNTA
				AnimationName		= KUWWolf_CHRA
				AnimationMode		= LOOP
			End
		End
		
		AnimationState				= EMOTION_CELEBRATING
			Animation                   	= CHRA
				AnimationName		= KUWWolf_CHRA
				AnimationMode		= LOOP
			End
		End
		
		; ----------- IDLE ANIMS ---------------
		AnimationState				= EMOTION_ALERT
			StateName			= STATE_Ready 
			Animation			= ALERT
				AnimationName		= KUWWolf_IDLC
				AnimationMode		= ONCE
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Selected" then CurDrawableSetTransitionAnimState("Selected_to_Ready") end
			EndScript	
		End
		
		; ----------- SELECTED ANIMS --------------
		AnimationState				= SELECTED
			SimilarRestart			= Yes
			Animation			= AtAttention
				AnimationName		= KUWWolf_IDLA
				AnimationMode		= LOOP
			End
			StateName			= Selected
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Idle" then CurDrawableSetTransitionAnimState("Idle_to_Selected") end
				if Prev == "STATE_Ready" then CurDrawableSetTransitionAnimState("Ready_to_Selected") end
			EndScript
		End

		IdleAnimationState
			StateName				= STATE_Idle
			Animation				= IDLA
				AnimationName       = KUWWolf_IDLA
				AnimationMode       = ONCE
				AnimationPriority   = 20
				AnimationSpeedFactorRange = 0.9 1.1
				AnimationBlendTime	= 15
			End
			Animation				= IDLC
				AnimationName       = KUWWolf_IDLB
				AnimationMode       = ONCE
				AnimationPriority   = 5
				AnimationSpeedFactorRange = 0.9 1.1
				AnimationBlendTime	= 15
			End
			Animation				= IDLD
				AnimationName       = KUWWolf_IDLC
				AnimationMode       = ONCE
				AnimationPriority   = 5
				AnimationSpeedFactorRange = 0.9 1.1
				AnimationBlendTime	= 15
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "Selected" then CurDrawableSetTransitionAnimState("Selected_to_Idle") end
			EndScript
		End

		AnimationState        = PACKING_TYPE_1
			Animation           = SPCA
				AnimationName     = KUWWolf_SPCA
				AnimationMode     = ONCE
			End
		End
		;------------ TRANSITION ANIMS ----------------
		TransitionState       = Selected_to_Idle
			Animation           		= ATNE
				AnimationName		=	KUWWolf_IDLA
				AnimationMode		=	ONCE
				AnimationSpeedFactorRange = 0.7 1.3
			End
		End
		
		TransitionState       = Idle_to_Selected
			Animation           		= ATND
				AnimationName     	= KUWWolf_IDLA
				AnimationMode   	=	ONCE
				AnimationSpeedFactorRange = 0.7 1.3
			End
		End

	    TransitionState 	   = TRANS_JustBuilt_To_Idle
			Animation = BeingSummoned
				AnimationName = KUWWolf_SKL.KUWWolf_RORA 
				AnimationMode = ONCE
			End
		End

		AnimationState			= USER_2
			StateName = State_JustBuilt
			Animation
				AnimationName = KUWWolf_SKL.KUWWolf_RORA 
				AnimationMode = ONCE
				AnimationBlendTime = 0
				AnimationSpeedFactorRange	=	0.5 0.5
			End
		End

		AnimationState			= USER_3
			StateName = State_JustBuilt
			Animation
				AnimationName = KUWWolf_SKL.KUWWolf_SPCB 
				AnimationMode = ONCE
				AnimationBlendTime = 0
				AnimationSpeedFactorRange	=	0.5 0.5
			End
		End

	End
	
	Draw = W3DScriptedModelDraw DustEffects
	    DefaultModelConditionState
	      Model = None
	    End
	    IdleAnimationState
	    End
	    AnimationState = MOVING WADING
			ParticleSysBone = None FootstepSlash
	    End
	    AnimationState = MOVING ACCELERATE
			ParticleSysBone = None GenericSiegeTrailDust
	    End
	    ;AnimationState = MOVING DECELERATE
		;	ParticleSysBone = None GenericSiegeTrailDust
	    ;End
	    AnimationState = MOVING
	    End
	End