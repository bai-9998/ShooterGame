// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTarget.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"

#include "MyGameStateBase.h"

// Sets default values
AShootTarget::AShootTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	StaticMeshComponent->Mobility = EComponentMobility::Movable;
	StaticMeshComponent->bUseDefaultCollision = true;

	RootComponent = StaticMeshComponent;
	
}

// Called when the game starts or when spawned
void AShootTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShootTarget::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (StaticMeshComponent->BodyInstance.bSimulatePhysics)
	{
		if (OtherActor)
		{
			Cast<AMyGameStateBase>(GetWorld()->GetGameState())->Score++;
		}
	}
	else
	{
		Super::NotifyActorBeginOverlap(OtherActor);

		if (OtherActor)
		{
			Destroy();

			Cast<AMyGameStateBase>(GetWorld()->GetGameState())->Score+=5;
		}
	}
}

// Called every frame
void AShootTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

