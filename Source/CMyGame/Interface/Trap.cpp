// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"

// Sets default values
ATrap::ATrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	StMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StMeshComponent"));
	//RootComponent = StMeshComponent;
	StMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
	
	ReactToTrigger(); // 调用纯C++接口
	//SteppedToTrigger();
	//BumpTntoToTrigger();
	//Test_2(99);
	this->Execute_TouchedToTrigger(this); // 调用接口，这个接口时纯蓝图接口，在蓝图中实现
	this->Execute_SteppedToTrigger(this); // 调用接口，这个接口可以在蓝图中重写
	this->Execute_BumpTntoToTrigger(this); // 调用接口，这个接口可以在蓝图中重写
	this->Execute_Test_2(this,99); // 调用接口，这个接口可以在蓝图中重写
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATrap::ReactToTrigger()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ATrap::ReactToTrigger()");
	UE_LOG(LogTemp, Log, TEXT("ATrap::ReactToTrigger()"));
	return true;
}

bool ATrap::SteppedToTrigger_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ATrap::SteppedToTrigger_Implementation()");

	UE_LOG(LogTemp, Log, TEXT("ATrap::SteppedToTrigger_Implementation()"));
	return true;
}

void ATrap::BumpTntoToTrigger_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ATrap::BumpTntoToTrigger_Implementation()");
	UE_LOG(LogTemp, Log, TEXT("ATrap::BumpTntoToTrigger_Implementation()"));
}

// void ATrap::Test_2_Implementation(int32 gold)
// {
// 	UE_LOG(LogTemp, Log, TEXT("ATrap::Test_2_Implementation()"));
// }

