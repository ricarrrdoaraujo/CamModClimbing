// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCameraModifier.h"
#include "CameraModifierApplyClimbingAnim.generated.h"

/**
 * 
 */
UCLASS()
class CAMMODCLIMBING_API UCameraModifierApplyClimbingAnim : public UMainCameraModifier
{
	GENERATED_BODY()

public:
	UCameraModifierApplyClimbingAnim(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual bool ModifyCamera(float DeltaTime, struct FMinimalViewInfo& InOutPOV) override;
	
};
