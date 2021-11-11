// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraClimbingTriggerVolume.h"
#include "FPSCharacter.h"

void ACameraClimbingTriggerVolume::NotifyActorBeginOverlap(AActor* Other)
{
    Super::NotifyActorBeginOverlap(Other);

    AFPSCharacter* CameraActor = Cast<AFPSCharacter>(Other);
    
    if (CameraActor)
    {
        CameraActor->Climb(Modifiers);
    } 
    
}