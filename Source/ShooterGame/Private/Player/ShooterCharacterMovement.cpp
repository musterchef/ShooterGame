// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShooterGame.h"
#include "Player/ShooterCharacterMovement.h"

//----------------------------------------------------------------------//
// UPawnMovementComponent
//----------------------------------------------------------------------//
UShooterCharacterMovement::UShooterCharacterMovement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


float UShooterCharacterMovement::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();

	const AShooterCharacter* ShooterCharacterOwner = Cast<AShooterCharacter>(PawnOwner);
	if (ShooterCharacterOwner)
	{
		if (ShooterCharacterOwner->IsTargeting())
		{
			MaxSpeed *= ShooterCharacterOwner->GetTargetingSpeedModifier();
		}
		if (ShooterCharacterOwner->IsRunning())
		{
			MaxSpeed *= ShooterCharacterOwner->GetRunningSpeedModifier();
		}
	}

	return MaxSpeed;
}

void UShooterCharacterMovement::PerformMovement(float DeltaTime)
{
	AShooterCharacter* ShooterCharacterOwner = Cast<AShooterCharacter>(PawnOwner);
	if (ShooterCharacterOwner)
	{
		if (ShooterCharacterOwner->bIsUsingJetpack)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("IS USING JETPACK"));
			ShooterCharacterOwner->Fuel -= DeltaTime;
			if (ShooterCharacterOwner->Fuel < 0)
			{
				ShooterCharacterOwner->StopJetpack();
			}
			Velocity.Z += ShooterCharacterOwner->GetJetpackSpeedModifier() * DeltaTime;
		}

		else if (ShooterCharacterOwner->IsJetpackEnabled() == true)
		{
			ShooterCharacterOwner->Fuel += DeltaTime * ShooterCharacterOwner->GetJetpackRefreshRate();
			if (ShooterCharacterOwner->Fuel >= ShooterCharacterOwner->GetMaxFuel())
			{
				ShooterCharacterOwner->Fuel = ShooterCharacterOwner->GetMaxFuel();
			}
		}
	}

	Super::PerformMovement(DeltaTime);
}
