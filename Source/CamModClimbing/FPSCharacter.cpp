// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(GetMesh());
	FollowCamera->AttachToComponent(GetMesh(), AttachmentRules, FName(TEXT("headSocket")));
	FollowCamera-> bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::LookUp);

	PlayerInputComponent->BindAction("Climb",IE_Pressed, this, &AFPSCharacter::Climb);
}

void AFPSCharacter::Climb()
{
	PlayClimbingMontage();
}

void AFPSCharacter::LerpCameraToArm()
{
	FVector ArmLocation = GetMesh()->GetSocketLocation("HumanRUpperarmSocket");
	FollowCamera->SetWorldLocation(FMath::Lerp(
     FollowCamera->GetComponentLocation(),
     ArmLocation,
     0.5f));
}

void AFPSCharacter::DettachCamFromArm()
{
	FVector ArmLocation = GetMesh()->GetSocketLocation("HumanRUpperarmSocket");
	FVector CameraLocation = GetMesh()->GetSocketLocation("headSocket");
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
