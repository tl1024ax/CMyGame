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
	
	ReactToTrigger(); // ���ô�C++�ӿ�
	//SteppedToTrigger();
	//BumpTntoToTrigger();
	//Test_2(99);
	this->Execute_TouchedToTrigger(this); // ���ýӿڣ�����ӿ�ʱ����ͼ�ӿڣ�����ͼ��ʵ��
	this->Execute_SteppedToTrigger(this); // ���ýӿڣ�����ӿڿ�������ͼ����д
	this->Execute_BumpTntoToTrigger(this); // ���ýӿڣ�����ӿڿ�������ͼ����д
	this->Execute_Test_2(this,99); // ���ýӿڣ�����ӿڿ�������ͼ����д
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

