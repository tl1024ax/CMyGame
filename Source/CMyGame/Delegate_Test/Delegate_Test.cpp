// Fill out your copyright notice in the Description page of Project Settings.


#include "Delegate_Test.h"

// Sets default values
ADelegate_Test::ADelegate_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADelegate_Test::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADelegate_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

