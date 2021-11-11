// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "DrawDebugHelpers.h"

AFPSCharacter::AFPSCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh());
	FollowCamera->AttachToComponent(GetMesh(), AttachmentRules, FName(TEXT("headSocket")));
	FollowCamera-> bUsePawnControlRotation = true;

}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

}

void AFPSCharacter::Climb(FCameraModifierInfo Modifiers)
{
	CameraModifiers = Modifiers;
	if (CurrentDirection > 0.0f)
	{
		PlayClimbingMontage();
	}
}

void AFPSCharacter::LerpCameraToArm()
{
	//"HumanRUpperarmSocket"
	FVector ArmLocation = GetMesh()->GetSocketLocation(FName(CameraModifiers.InitialSocketLocationName));
	FollowCamera->SetWorldLocation(FMath::Lerp(
     FollowCamera->GetComponentLocation(),
     ArmLocation,
     0.5f));
}

void AFPSCharacter::DettachCamFromArm()
{
	//"HumanRUpperarmSocket"
	//headSocket
	FVector ArmLocation = GetMesh()->GetSocketLocation(FName(CameraModifiers.InitialSocketLocationName));
	FVector CameraLocation = GetMesh()->GetSocketLocation(FName(CameraModifiers.EndSocketLocationName));
	FollowCamera->SetWorldLocation(FMath::Lerp(
     ArmLocation,
     CameraLocation,
     0.5f));
}

void AFPSCharacter::PlayClimbingMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && ClimbingMontage)
	{
		AnimInstance->Montage_Play(ClimbingMontage);
		AnimInstance->Montage_JumpToSection(FName("Climbing"));
	}
}

void AFPSCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AFPSCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}


void AFPSCharacter::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
	CurrentDirection = Value;
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}
