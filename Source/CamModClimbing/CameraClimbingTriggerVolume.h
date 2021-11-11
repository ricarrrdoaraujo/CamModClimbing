// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "FCameraModifierInfo.h"
#include "CameraClimbingTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class CAMMODCLIMBING_API ACameraClimbingTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

//public:
	//ACameraClimbingTriggerVolume();

public:
	virtual void NotifyActorBeginOverlap(AActor* Other) override;

	//virtual void NotifyActorEndOverlap(AActor* Other) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = CameraModifiers)
	FCameraModifierInfo Modifiers;
	
};
