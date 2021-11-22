// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "Animation/AnimInstance.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(FName("WeaponMesh"));

	MaxAmmo = 1024;
	CurrentAmmo = MaxAmmo;
	AmmoPerShot = 1;

	TraceDistance = 100000;
	MuzzleSocket = "Muzzle";
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AWeapon::StartFire()
{
	ConsumeAmmo();

	SpawnProjectile();

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = MS->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void AWeapon::StopFire()
{

}

bool AWeapon::CalcFireInfo(FVector& Location, FVector& Dir)
{
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	if (CameraManager)
	{
		Location = Mesh->GetSocketLocation(MuzzleSocket);
		FVector CamLoc = CameraManager->GetCameraLocation();
		FVector CamDir = CameraManager->GetCameraRotation().Vector();
		Dir = ((CamLoc + CamDir * TraceDistance) - Location).GetSafeNormal();
		return true;
	}
	else
		return false;
}

void AWeapon::ConsumeAmmo()
{
	CurrentAmmo = FMath::Max(0, CurrentAmmo - AmmoPerShot);
}
