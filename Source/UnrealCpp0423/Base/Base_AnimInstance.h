// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Base_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP0423_API UBase_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UBase_AnimInstance();

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Direction;

	FVector SmoothVelocity;
};
