// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealPickup.h"
#include "BatteryPickupActor.h"

ABatteryPickupActor::ABatteryPickupActor(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    // The base power level of the battery
    PowerLevel = 150.f;
    
}

void ABatteryPickupActor:: OnPickedUp_Implementation()
{
    // Called the parent implementation first
    Super::OnPickedUp_Implementation();
    
    // Destroy the battery
    Destroy();
}