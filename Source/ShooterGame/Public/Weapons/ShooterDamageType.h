// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ShooterDamageType.generated.h"

UENUM()
enum class EShooterDamageType : uint8
{
	WEP_Gun	UMETA(DisplayName = "Gun"),
	WEP_Freezer UMETA(DisplayName = "Freezer")
};

// DamageType class that specifies an icon to display
UCLASS(const, Blueprintable, BlueprintType)
class UShooterDamageType : public UDamageType
{
	GENERATED_UCLASS_BODY()

	/** icon displayed in death messages log when killed with this weapon */
	UPROPERTY(EditDefaultsOnly, Category=HUD)
	FCanvasIcon KillIcon;

	/** force feedback effect to play on a player hit by this damage type */
	UPROPERTY(EditDefaultsOnly, Category=Effects)
	UForceFeedbackEffect *HitForceFeedback;

	/** force feedback effect to play on a player killed by this damage type */
	UPROPERTY(EditDefaultsOnly, Category=Effects)
	UForceFeedbackEffect *KilledForceFeedback; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
		EShooterDamageType DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
		bool IsFreezingGun;
};



