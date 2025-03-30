		IdleAnimationState
			StateName					=   STATE_Idle
			Animation = IdleA
				AnimationName       = CUBear_SKL.CUBear_IDLA
				AnimationPriority	= 10
				AnimationMode       = ONCE
				AnimationBlendTime	=	10
			End
			Animation = IdleB
				AnimationName       = CUBear_SKL.CUBear_IDLB
				AnimationPriority	= 10
				AnimationMode       = ONCE
				AnimationBlendTime	=	10
			End
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Alert" then CurDrawableSetTransitionAnimState("TRANS_AlertToIdle") end
			EndScript
		End

		AnimationState				= MOVING PANICKING
			Animation				= RUNA
				AnimationName		= CUBear_SKL.CUBear_RUNA
				AnimationMode		= LOOP
			End
			Flags					= RANDOMSTART
		End
		
		AnimationState				= FIRING_OR_PREATTACK_A
			StateName				= STATE_ready
			Animation				= ATKD
				AnimationName		= CUBear_SKL.CUBear_ATKA
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationPriority	= 2
			End
			Animation				= ATKE
				AnimationName		= CUBear_SKL.CUBear_ATKB
				AnimationMode		= ONCE
				UseWeaponTiming		= Yes
				AnimationPriority	= 3
			End
			Flags					=	RESTART_ANIM_WHEN_COMPLETE
		End
				
		AnimationState			=	MOVING
			StateName			=	STATE_moving
			Animation			=	Moving
				AnimationName	=	CUBear_SKL.CUBear_RUNA
				AnimationBlendTime	=	10
				AnimationMustCompleteBlend = yes
			End
			
			BeginScript
				Prev = CurDrawablePrevAnimationState()
				if Prev == "STATE_Alert" then CurDrawableSetTransitionAnimState("TRANS_AlertToIdle") end
			EndScript
			
		End
		
;;======== ALERT
		
		AnimationState					= EMOTION_ALERT
			Animation					= Ready
				AnimationName			= CUBear_SKL.CUBear_IDLB
				AnimationPriority	= 10
				AnimationMode       = ONCE
				AnimationBlendTime	=	10
			End
			Animation					= Ready
				AnimationName			= CUBear_SKL.CUBear_IDLF
				AnimationPriority	= 10
				AnimationMode       = ONCE
				AnimationBlendTime	=	10
			End
		End	
		
		AnimationState        = DYING
			Animation           = CUBear_DIEA
				AnimationName     = CUBear_SKL.CUBear_DIEA
				AnimationMode     = ONCE
			End
		End