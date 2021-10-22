// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterAnimInstance.h"
#include "FPSCharacter.h"

void UFPSCharacterAnimInstance::UpdateAnimationFunction(float DeltaTime)
{
    if (FPSCharacter == nullptr)
    {
        FPSCharacter = Cast<AFPSCharacter>(TryGetPawnOwner());
    }
}

void UFPSCharacterAnimInstance::NativeInitializeAnimation()
{
    FPSCharacter = Cast<AFPSCharacter>(TryGetPawnOwner());
}
