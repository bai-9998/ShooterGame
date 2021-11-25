// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"

AGrenade::AGrenade()
{
	MaxAmmo = 1024;
	CurrentAmmo = MaxAmmo;
	AmmoPerShot = 1;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	GrenadeMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
}

void AGrenade::StartFire()
{
	FireBase();

	ConsumeAmmo();

	SpawnProjectile();

	
}

void AGrenade::StopFire()
{

}

void AGrenade::OnExplode()
{

}

bool AGrenade::CalcFireInfo(FVector& Location, FVector& Dir)
{
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	if (CameraManager)
	{
		Location = Mesh->GetSocketLocation(MuzzleSocket);
		FVector CamLoc = CameraManager->GetCameraLocation();
		FVector CamDir = CameraManager->GetCameraRotation().Vector();
		CamDir += FVector(1, 1, 0);
		Dir = ((CamLoc + CamDir * TraceDistance) - Location).GetSafeNormal();
		return true;
	}
	else
		return false;
}