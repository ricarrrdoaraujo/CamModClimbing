#pragma once

#include "FCameraModifierInfo.generated.h"

USTRUCT(BlueprintType)
struct FCameraModifierInfo
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraModifiers)
    FString InitialSocketLocationName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraModifiers)
    FString EndSocketLocationName;
    
};
