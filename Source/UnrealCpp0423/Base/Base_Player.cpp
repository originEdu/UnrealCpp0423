// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABase_Player::ABase_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//스켈레톤 메쉬 높이 및 회전 디폴트 설정
	float HalfHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight(); //88
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -HalfHeight));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	JumpMaxCount = 2;
	JumpMaxHoldTime = 0.5f;
}

// Called when the game starts or when spawned
void ABase_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABase_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABase_Player::Move);
		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABase_Player::Look);
		EIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &ABase_Player::Jump);
		EIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}

}

void ABase_Player::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	FRotator ControlRotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);
	FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(YawRotation);
	FVector RightDirection = UKismetMathLibrary::GetRightVector(YawRotation);

	AddMovementInput(ForwardDirection, Direction.X);
	AddMovementInput(RightDirection, Direction.Y);
}

void ABase_Player::Look(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();
	AddControllerPitchInput(-Direction.Y);
	AddControllerYawInput(Direction.X);
}

