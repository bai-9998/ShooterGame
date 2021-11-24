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

public:	
	// Sets default values for this actor's properties
	AWeapon();
	
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void StartFire(){};

	UFUNCTION(BlueprintCallable)
	virtual void StopFire(){};

	void ConsumeAmmo();

	void FireBase();

	UPROPERTY(EditAnywhere)
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere)
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere)
	int32 AmmoPerShot;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	UFUNCTION(BlueprintCallable)
	USkeletalMeshComponent* GetWeaponMesh(){return Mesh;}

	UPROPERTY(EditAnywhere)
	FName	MuzzleSocket;

};
