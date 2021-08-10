// Fill out your copyright notice in the Description page of Project Settings.


#include "TrggerActor_Test.h"
#include <Components/BoxComponent.h>
#include <GameFramework/GameMode.h>
#include <Kismet/GameplayStatics.h>
#include "DelegateTest_GameMode.h"

// Sets default values
ATrggerActor_Test::ATrggerActor_Test()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	BoxTrigger->SetupAttachment(RootComponent);
	BoxTrigger->SetWorldScale3D(FVector::FVector(5.f, 5.f, 5.f));
}

// Called when the game starts or when spawned
void ATrggerActor_Test::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATrggerActor_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrggerActor_Test::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("-- NotifyActorBeginOverlap"));

	UWorld* curWorld = GetWorld();
	if (curWorld != nullptr)
	{
		//AGameMode* GameMode = curWorld->GetAuthGameMode();
		AGameModeBase* GameMode = Cast<AGameModeBase>(UGameplayStatics::GetGameMode(curWorld));
		ADelegateTest_GameMode* myGameMode = Cast<ADelegateTest_GameMode>(GameMode);
		if (myGameMode == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("-- myGameMode == nullptr"));
			return;
		}
		if (myGameMode->onEnterTrigger_00.IsBound())
		{
			myGameMode->onEnterTrigger_00.Execute();
		}
		myGameMode->onEnterTrigger_01.ExecuteIfBound(true);
		myGameMode->onEnterTrigger_02.ExecuteIfBound(true, 11);
		myGameMode->onEnterTrigger_03.ExecuteIfBound(true, 11, 11.f);
		if (myGameMode->onEnterTrigger_10.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_10.Execute();
		}
		if (myGameMode->onEnterTrigger_11.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_11.Execute(TEXT("test - 11"));
		}
		if (myGameMode->onEnterTrigger_15.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_15.Execute(true, 11, 11.f, TEXT("test - 11"), TEXT("test - 11"));
		}
	}
}

void ATrggerActor_Test::NotifyActorEndOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, TEXT("-- NotifyActorEndOverlap"));

	UWorld* curWorld = GetWorld();
	if (curWorld != nullptr)
	{
		AGameModeBase* gameMode = Cast<AGameModeBase>(UGameplayStatics::GetGameMode(curWorld));
		ADelegateTest_GameMode* myGameMode = Cast<ADelegateTest_GameMode>(gameMode);
		if (myGameMode == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("-- myGameMode == nullptr"));
			return;
		}
		myGameMode->onEnterTrigger_00.ExecuteIfBound();
		myGameMode->onEnterTrigger_01.ExecuteIfBound(false);
		myGameMode->onEnterTrigger_02.ExecuteIfBound(false, 22);
		myGameMode->onEnterTrigger_03.ExecuteIfBound(false, 22,22.f);
		if (myGameMode->onEnterTrigger_10.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_10.Execute();
		}
		if (myGameMode->onEnterTrigger_11.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_11.Execute(TEXT("Test - 22"));
		}
		if (myGameMode->onEnterTrigger_15.IsBound())
		{
			bool bValue = myGameMode->onEnterTrigger_15.Execute(false,22,22.f,TEXT("Test - 22"), TEXT("Test - 22"));
		}
	}
}

