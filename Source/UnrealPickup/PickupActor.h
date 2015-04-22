// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class UNREALPICKUP_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
    // True when the pickup is able to be picked up, false is something deactivate the pickup
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickupActor)
    bool bIsActive;
    
    // Simpulate collision primitive to use as the root component
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = PickupActor);
    TSubobjectPtr<USphereComponent> BaseCollisionComponent;;
    
    
    // StaticMeshComponent to represent the pickup in the level
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = PickupActor)
    TSubobjectPtr<UStaticMeshComponent> PickupMesh;
    
    // Function to call when the pickup is collected
    UFUNCTION(BlueprintNativeEvent)
    void OnPickedUp();

	
	
};
