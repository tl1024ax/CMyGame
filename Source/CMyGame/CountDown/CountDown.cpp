// Fill out your copyright notice in the Description page of Project Settings.


#include "CountDown.h"
#include <Components/TextRenderComponent.h>

// Sets default values
ACountDown::ACountDown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownText"));
	RootComponent = CountdownText;
	CountdownText->SetWorldSize(150.0f);
	CountdownText->SetHorizontalAlignment(EHTA_Left);

	CountdownTime = 3;

}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountDown::AdvaceTimer, 1.0f, true);
}

// Called every frame
void ACountDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACountDown::UpdateTimerDisplay()
{
	if (CountdownText)
	{
		CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
	}
}

void ACountDown::AdvaceTimer()
{
	CountdownTime--;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		//倒数完成，停止运行定时器。
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//定时器结束时，执行要执行的特殊操作。
		CountdownHasFinished();
	}
}

void ACountDown::CountdownHasFinished_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("C++ : CountdownHasFinished_Implementation"));
	if (CountdownText)
	{
		CountdownText->SetText("GO");
	}
}



void ACountDown::Settest_IntVal_T(int32 val)
{
	// 如果蓝图复写了 CountdownHasFinished 函数，那么这里就掉用到 蓝图 的 复写函数 CountdownHasFinished 。
	// 当然 蓝图的函数还可以调用其父类 的 CountdownHasFinished 函数,也就是C++中 CountdownHasFinished_Implementation 函数
	CountdownHasFinished();
	// 不要这样调用，如果CountdownHasFinished 函数被蓝图 复写，这里就无法 执行蓝图的函数了。
	//CountdownHasFinished_Implementation();

	UE_LOG(LogTemp, Log, TEXT("调用了 C++ Settest_IntVal_T 函数"));
	test_IntVal = val;
}

//int32 ACountDown::Gettest_IntVal_T(int32 val)
//{
//	return test_IntVal;
//}

