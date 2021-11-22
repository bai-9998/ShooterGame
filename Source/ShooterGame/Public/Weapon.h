// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class USkeletalMeshComponent;
class UAnimMontage;
class USoundBase;

UCLASS()
class SHOOTERGAME_API AWeapon : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category=Mesh)
	USkeletalMeshComponent* MS;

public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartFire();

	UFUNCTION(BlueprintCallable)
	void StopFire();

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnProjectile();

	UFUNCTION(BlueprintCallable)
	bool CalcFireInfo(FVector& Location, FVector& Dir);

	void ConsumeAmmo();

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere)
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere)
	int32 AmmoPerShot;

	UPROPERTY(EditAnywhere)
	float TraceDistance;

	UPROPERTY(EditAnywhere)
	FName	MuzzleSocket;

};
