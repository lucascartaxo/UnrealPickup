// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PickupActor.h"
#include "BatteryPickupActor.generated.h"

UCLASS()
class UNREALPICKUP_API ABatteryPickupActor : public APickupActor
{
	GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABatteryPickupActor(const class FObjectInitializer& ObjectInitializer);
    
    // Set the amount of power the battery gives to the player
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
    float PowerLevel;
    
    // Override the OnPickedUp function (use Implementation because this is a BlueprintNativeEvent)
    void OnPickedUp_Implementation() OVERRIDE;
    
};
