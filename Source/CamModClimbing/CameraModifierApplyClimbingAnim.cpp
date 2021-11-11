// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraModifierApplyClimbingAnim.h"
#include "Camera/CameraComponent.h"
#include "FPSCharacter.h"


UCameraModifierApplyClimbingAnim::UCameraModifierApplyClimbingAnim(
    const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
    : Super(ObjectInitializer)
{
}

bool UCameraModifierApplyClimbingAnim::ModifyCamera(float DeltaTime, struct FMinimalViewInfo& InOutPOV) 
{
    Super::ModifyCamera(DeltaTime, InOutPOV);
    
	return false;
}
