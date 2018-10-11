// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

/**
 * Movement component meant for use with Pawns.
 */

#pragma once
#include "ShooterCharacterMovement.generated.h"

UCLASS()
class UShooterCharacterMovement : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()

	virtual float GetMaxSpeed() const override;

	/* Faccio l'override del Perform Movement per imprimere una forza sulla componente Z del componente movement e così da poter volare con il jetpack*/
	virtual void PerformMovement(float DeltaTime) override;

public:

};

