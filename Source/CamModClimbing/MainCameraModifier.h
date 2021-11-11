// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "MainCameraModifier.generated.h"

UCLASS(BlueprintType, Blueprintable)
class CAMMODCLIMBING_API UMainCameraModifier : public UCameraModifier
{
	GENERATED_BODY()

public:
	UMainCameraModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
};
