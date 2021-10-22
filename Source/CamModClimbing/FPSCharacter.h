// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class CAMMODCLIMBING_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* ClimbingMontage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Climb();

	UFUNCTION(BlueprintCallable)
	void LerpCameraToArm();

	UFUNCTION(BlueprintCallable)
    void DettachCamFromArm();

	void PlayClimbingMontage();

	void Turn(float Value);

	void LookUp(float Value);
	
public:	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; };

};