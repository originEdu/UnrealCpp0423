// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_AnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "Components/CapsuleComponent.h"

UBase_AnimInstance::UBase_AnimInstance()
{
}

void UBase_AnimInstance::NativeInitializeAnimation()
{
}

void UBase_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Player = Cast<ACharacter>(TryGetPawnOwner());
	if (Player)
	{
		FVector CurrentAccel = Player->GetCharacterMovement()->GetCurrentAcceleration();
		float InterpSpeed = 6.0f;
		SmoothVelocity = FMath::VInterpTo(SmoothVelocity, CurrentAccel, GetWorld()->GetDeltaSeconds(), InterpSpeed);
		Speed = SmoothVelocity.Size2D();
		if (!FMath::IsNearlyZero(Speed))
		{
			Direction = UKismetAnimationLibrary::CalculateDirection(SmoothVelocity, Player->GetActorRotation());
		}
	}
	
}

void UBase_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
}
