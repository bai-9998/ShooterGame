// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"

AGun::AGun()
{
	
	MaxAmmo = 1024;
	CurrentAmmo = MaxAmmo;
	AmmoPerShot = 1;

	TraceDistance = 100000;
}

void AGun::StartFire()
{
	FireBase();

	ConsumeAmmo();

	SpawnProjectile();
}

void AGun::StopFire()
{

}


bool AGun::CalcFireInfo(FVector& Location, FVector& Dir)
{
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	if (CameraManager)
	{
		Location = Mesh->GetSocketLocation(MuzzleSocket);
		FVector CamLoc = CameraManager->GetCameraLocation();
		FVector CamDir = CameraManager->GetCameraRotation().Vector();
		CamDir += FVector(0, 0.033, 0);
		Dir = ((CamLoc + CamDir * TraceDistance) - Location).GetSafeNormal();
		return true;
	}
	else
		return false;
}

void AGun::ConsumeAmmo()
{
	CurrentAmmo = FMath::Max(0, CurrentAmmo - AmmoPerShot);
}
