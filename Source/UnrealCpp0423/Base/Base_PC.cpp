// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_PC.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

ABase_PC::ABase_PC()
{
}

void ABase_PC::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// 1. 로컬 플레이어 서브시스템 가져오기
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
		{
			// 2. 매핑 컨텍스트가 유효한지 확인 후 등록
			if (IMC_Base)
			{
				// 우선순위 0으로 등록 (숫자가 높을수록 우선순위가 높음)
				Subsystem->AddMappingContext(IMC_Base, 0);
			}
		}
	}
}

void ABase_PC::OnUnPossess()
{
	Super::OnUnPossess();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
		{
			if (IMC_Base)
			{
				Subsystem->ClearAllMappings();
			}
		}
	}
}
