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
		//������ɣ�ֹͣ���ж�ʱ����
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//��ʱ������ʱ��ִ��Ҫִ�е����������
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
	// �����ͼ��д�� CountdownHasFinished ��������ô����͵��õ� ��ͼ �� ��д���� CountdownHasFinished ��
	// ��Ȼ ��ͼ�ĺ��������Ե����丸�� �� CountdownHasFinished ����,Ҳ����C++�� CountdownHasFinished_Implementation ����
	CountdownHasFinished();
	// ��Ҫ�������ã����CountdownHasFinished ��������ͼ ��д��������޷� ִ����ͼ�ĺ����ˡ�
	//CountdownHasFinished_Implementation();

	UE_LOG(LogTemp, Log, TEXT("������ C++ Settest_IntVal_T ����"));
	test_IntVal = val;
}

//int32 ACountDown::Gettest_IntVal_T(int32 val)
//{
//	return test_IntVal;
//}

