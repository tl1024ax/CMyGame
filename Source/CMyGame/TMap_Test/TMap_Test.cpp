// Fill out your copyright notice in the Description page of Project Settings.


#include "TMap_Test.h"

// Sets default values
ATMap_Test::ATMap_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATMap_Test::BeginPlay()
{
	Super::BeginPlay();
	
	MyMapToInt32.Add(FMyStruct(3.14f), 5);
	MyMapToInt32.Add(FMyStruct(1.2f), 2);

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("--------------------------------------------"));
	for (auto& elem : MyMapToInt32)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Value = %d, Key = \"%s\""),  elem.Value, *elem.Key.UniqueID) );
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("--------------------------------------------"));

	for (auto It = MyMapToInt32.CreateConstIterator();It;++It)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Value = %d,Key = %s"), It->Value, *(It->Key.UniqueID)));
	}
}

// Called every frame
void ATMap_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

