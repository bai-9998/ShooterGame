// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Grenade.generated.h"

class UProjectileMovementComponent;

UCLASS()
class SHOOTERGAME_API AGrenade : public AWeapon
{
	GENERATED_BODY()
	
public:
	AGrenade();

public:
	virtual void StartFire() override;
	virtual void StopFire() override;

	UFUNCTION()
	void OnExplode();

};
