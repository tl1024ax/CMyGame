// Fill out your copyright notice in the Description page of Project Settings.


#include "LightActor_Test.h"
#include <Components/PointLightComponent.h>
#include <Kismet/GameplayStatics.h>
#include "DelegateTest_GameMode.h"

// Sets default values
ALightActor_Test::ALightActor_Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	PointLigth = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point"));
	PointLigth->SetupAttachment(RootComponent);
	PointLigth->SetVisibility(false);
}

// Called when the game starts or when spawned
void ALightActor_Test::BeginPlay()
{
	Super::BeginPlay();
	
	TestBindDelegate();
}

void ALightActor_Test::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	TestUnBindDelegate();
}

// Called every frame
void ALightActor_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALightActor_Test::TestBindDelegate()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, TEXT("-- TestDelegate"));

	UWorld* curWorld = GetWorld();
	if (curWorld)
	{
		AGameModeBase* curGameMode = UGameplayStatics::GetGameMode(curWorld);
		ADelegateTest_GameMode* myGameMode = Cast<ADelegateTest_GameMode>(curGameMode);

		myGameMode->onEnterTrigger_01.BindUObject(this, &ALightActor_Test::EnablePointLight);

		myGameMode->onEnterTrigger_00.BindUObject(this, &ALightActor_Test::TestFuncNoParam);
		myGameMode->onEnterTrigger_03.BindUObject(this, &ALightActor_Test::TestFuncThreeParams);
		myGameMode->onEnterTrigger_10.BindUObject(this, &ALightActor_Test::TestFuncRetValNoParam);
		myGameMode->onEnterTrigger_15.BindUObject(this, &ALightActor_Test::TestFuncRetValFiveParams);
	}
}

void ALightActor_Test::TestUnBindDelegate()
{
	UWorld* curWorld = GetWorld();
	if (curWorld)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(curWorld);
		ADelegateTest_GameMode* myGameMode = Cast<ADelegateTest_GameMode>(gameMode);
		if (myGameMode)
		{
			myGameMode->onEnterTrigger_00.Unbind();
			myGameMode->onEnterTrigger_01.Unbind();
			myGameMode->onEnterTrigger_03.Unbind();
			myGameMode->onEnterTrigger_10.Unbind();
			myGameMode->onEnterTrigger_15.Unbind();
		}
	}
}

void ALightActor_Test::TestFuncNoParam()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, TEXT("-- TestFuncNoParam"));
}

void ALightActor_Test::TestFuncThreeParams(bool bVal, int32 iVal, float fVal)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, FString::Printf(TEXT("-- TestFuncThreeParams,%d, %d,%f"), bVal ? 1:0, iVal, fVal));
}

bool ALightActor_Test::TestFuncRetValNoParam()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, TEXT("-- TestFuncRetValNoParam"));
	return false;
}

bool ALightActor_Test::TestFuncRetValFiveParams(bool bVal, int32 iVal, float fVal, FString fStr1, FString fStr2)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::White, FString::Printf(TEXT("-- TestFuncRetValFiveParams,%d, %d, %f,%s,%s"), bVal?1:0, iVal, fVal, *fStr1, *fStr2));
	return false;
}

void ALightActor_Test::EnablePointLight(bool bEnable)
{
	PointLigth->SetVisibility(bEnable);
}

