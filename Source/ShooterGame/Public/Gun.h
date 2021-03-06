// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AGun : public AWeapon
{
	GENERATED_BODY()
	
public:
	AGun();
public:
	virtual void StartFire() override;

	virtual void StopFire() override;

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnProjectile();
	
	UFUNCTION(BlueprintCallable)
	bool CalcFireInfo(FVector& Location, FVector& Dir);

	UPROPERTY(EditAnywhere)
	float TraceDistance;

};
