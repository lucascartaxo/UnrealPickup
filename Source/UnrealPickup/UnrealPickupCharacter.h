// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "UnrealPickupCharacter.generated.h"

UCLASS(config=Game)
class AUnrealPickupCharacter : public ACharacter
{
    GENERATED_BODY()
    
    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;
    
    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FollowCamera;
    
public:
    AUnrealPickupCharacter(const FObjectInitializer& ObjectInitializer);

    /** Collection Volume */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
    TSubobjectPtr<class USphereComponent> CollectionSphere;
    
    /** Power Level of Our Character */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Power)
    float PowerLevel;
    
    /** Power multiplier for the speed of the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
    float SpeedFactor;
    
    /** Baseline speed of the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Power)
    float BaseSpeed;
    
    /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseTurnRate;
    
    /** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseLookUpRate;
    
    UFUNCTION(BlueprintCallable, Category = Character)
    virtual void Tick(float DeltaSeconds) OVERRIDE;
    
protected:
    
    /** Called for forwards/backward input */
    void MoveForward(float Value);
    
    /** Called for side to side input */
    void MoveRight(float Value);
    
    /**
     * Called via input to turn at a given rate.
     * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void TurnAtRate(float Rate);
    
    /**
     * Called via input to turn look up/down at a given rate.
     * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void LookUpAtRate(float Rate);
    
    /** Handler for when a touch input begins. */
    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
    
    /** Handler for when a touch input stops. */
    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
    
    /** Called when we press the key  to collect any batteries inside the SphereComponent */
    UFUNCTION(BlueprintCallable, Category = Power)
    void CollectBatteries();
    
    /** Called by CollectBatteries() to use Blueprinted PowerUp() feature */
    UFUNCTION(BlueprintImplementableEvent, Category = Power)
    void PowerUp(float BatteryPower);

protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    // End of APawn interface
    
public:
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

