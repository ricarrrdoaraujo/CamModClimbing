// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FCameraModifierInfo.h"
#include "FPSCharacter.generated.h"

UCLASS()
class CAMMODCLIMBING_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	void Climb(FCameraModifierInfo Modifiers);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* ClimbingMontage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void LerpCameraToArm();

	UFUNCTION(BlueprintCallable)
    void DettachCamFromArm();

	void PlayClimbingMontage();

	void Turn(float Value);

	void LookUp(float Value);

	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	FCameraModifierInfo CameraModifiers;

	float CurrentDirection;
	
public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; };
	//FORCEINLINE AFPSCharacter* GetFPSCharacter() const { return FollowCamera; };

};
