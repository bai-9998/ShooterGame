// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameGameMode.h"
#include "MyShooterGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AMyShooterGameGameMode : public AShooterGameGameMode
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
};
