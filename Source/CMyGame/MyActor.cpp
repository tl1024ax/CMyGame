// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitLocation = FVector(0.0f);
	PlaceLocation = FVector(0.0f);
	bGotoInitLocation = false;

	TickLocationOffset = FVector(0.0f);
	bTickLocationOffset = false;
	bSweep = false;

	InitForce = FVector(0.0f);
	InitTorque = FVector(0.0f);
	bAccelChange = false;
	bAddForce = false;

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	PlaceLocation = GetActorLocation();

	if (bGotoInitLocation)
	{
		SetActorLocation(InitLocation);
	}

	if (bAddForce)
	{
		MyStaticMesh->AddForce(InitForce, "", bAccelChange);
		MyStaticMesh->AddTorque(InitTorque, "", bAccelChange);
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTickLocationOffset)
	{
		FHitResult HitResult; 
		AddActorLocalOffset(TickLocationOffset, bSweep,&HitResult);
		if (HitResult.bBlockingHit)
		{
			//UE_LOG(LogTemp,Error,TEXT("X:%f,Y:%f,Z:%f"),HitResult.Location.X,HitResult.Location.Y,HitResult.Location.Z);
		}
		// UE_LOG(LogTemp,Warning,TEXT("X:%f,Y:%f,Z:%f"),HitResult.Location.X,HitResult.Location.Y,HitResult.Location.Z);
	}
}
