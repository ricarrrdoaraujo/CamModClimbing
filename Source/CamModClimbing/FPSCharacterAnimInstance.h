// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CAMMODCLIMBING_API UFPSCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void UpdateAnimationFunction(float DeltaTime);
	
	virtual void NativeInitializeAnimation() override;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class AFPSCharacter* FPSCharacter;
	
};
