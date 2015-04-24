// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealPickup.h"
#include "PickupActor.h"

// Sets default values
APickupActor::APickupActor(const class FObjectInitializer& ObjectInitializer) {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    // The pickup is valid when it iscreated
    bIsActive = true;
    
    // Create the root SphereComponent to handle the pickup's collision
    BaseCollisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));
    
    // Set the SphereComponent as the root component
    RootComponent = BaseCollisionComponent;
    
    // Create the static MeshComponent
    PickupMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));
    
    // Turn Physics on for the static mesh
    PickupMesh->SetSimulatePhysics(true);
    
    // Attach StaticMeshComponent to the root component
    PickupMesh->AttachTo(RootComponent);
    
    
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void APickupActor::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    
}

void APickupActor::OnPickedUp_Implementation()
{
    // There is no default behavior for a pickup is picked up
}