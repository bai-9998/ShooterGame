// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameGameMode.generated.h"

UCLASS(minimalapi)
class AShooterGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShooterGameGameMode();

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent)
	void OnVictory();

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int ScoreOnVictory = 40;
};



