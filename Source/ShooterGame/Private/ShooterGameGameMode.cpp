// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterGameGameMode.h"
#include "ShooterGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyGameStateBase.h"

AShooterGameGameMode::AShooterGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AShooterGameGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AMyGameStateBase* GS = GetGameState<AMyGameStateBase>();
	if (GS)
	{
		if (GS->Score==ScoreOnVictory)
		{
			OnVictory();
		}
	}
}

void AShooterGameGameMode::OnVictory_Implementation()
{
}

