// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"

#include "GameFramework/ProjectileMovementComponent.h"

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
	
	//ProjectileMovement->UpdatedComponent = Mesh;
	GrenadeMovement->InitialSpeed = 500.f;
	GrenadeMovement->MaxSpeed = 500.f;
	GrenadeMovement->bRotationFollowsVelocity = true;
	GrenadeMovement->bShouldBounce = true;
}

void AGrenade::StopFire()
{

}

void AGrenade::OnExplode()
{

}