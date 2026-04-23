// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Base_PC.generated.h"


class UInputMappingContext;
/**
 * 
 */
UCLASS()
class UNREALCPP0423_API ABase_PC : public APlayerController
{
	GENERATED_BODY()
public:
	ABase_PC();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> IMC_Base;
	//소프트 및 배열을 패스

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
};
