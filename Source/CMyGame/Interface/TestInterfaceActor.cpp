// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInterfaceActor.h"
#include "Trap.h"
#include <EngineUtils.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ATestInterfaceActor::ATestInterfaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestInterfaceActor::BeginPlay()
{
	Super::BeginPlay();

	// ���Խӿ�
	CallInterface();
}

// Called every frame
void ATestInterfaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ���� UE4 ���������ӿڣ���ȡ�ؿ��ڶ���
void ATestInterfaceActor::CallInterface()
{
	// UE4 ������TActorIterator
	//TActorIterator<T> actorIt = TActorIterator<T>(GetWorld());
	// ��ȡ�ؿ��������е� ATrap ����
	TActorIterator<ATrap> actorIt = TActorIterator<ATrap>(GetWorld(),ATrap::StaticClass());
	for (actorIt; actorIt; ++actorIt)
	{
		if (!actorIt)
		{
			continue;
		}
		ATrap* trap = *actorIt;
		//�ж�ATrap���Ƿ�ʵ���� UReactToTriggerInterface �ӿڣ����ﴫ�� UReactToTriggerInterface ���� IReactToTriggerInterface
		bool isImplement = trap->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass());
		if (isImplement)
		{
			// ת��Ϊ IReactToTriggerInterface �ӿ�
			IReactToTriggerInterface* inter = Cast<IReactToTriggerInterface>(trap); 
			inter->Execute_TouchedToTrigger(trap); // ���ýӿڣ�����ӿ�ʱ����ͼ�ӿڣ�ֻ������ͼ��ʵ��
			inter->Execute_SteppedToTrigger(trap); //���ýӿڣ���ͼ�ɸ��ǽӿ�
			inter->Execute_BumpTntoToTrigger(trap); //���ýӿڣ���ͼ�ɸ��ǽӿ�
			inter->Execute_Test_2(trap, 99);//���ýӿڣ���ͼ�ɸ��ǽӿ�
			inter->ReactToTrigger();//���ýӿڣ���C++�ӿ�
		}
	}

	// -- GetAllActorsOfClass
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("------------------ GetAllActorsOfClass"));
	//TArray<AActor*> ArryActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrap::StaticClass(), ArryActors);
	//for (int32 i = 0; i < ArryActors.Num(); i++)
	//{
	//	Cast<ATrap>(ArryActors[i])->Execute_TouchedToTrigger(ArryActors[i]); // ���ýӿڣ�����ӿ�ʱ����ͼ�ӿڣ�ֻ������ͼ��ʵ��
	//	Cast<ATrap>(ArryActors[i])->Execute_SteppedToTrigger(ArryActors[i]); //���ýӿڣ���ͼ�ɸ��ǽӿ�
	//	Cast<ATrap>(ArryActors[i])->Execute_BumpTntoToTrigger(ArryActors[i]); //���ýӿڣ���ͼ�ɸ��ǽӿ�
	//	Cast<ATrap>(ArryActors[i])->Execute_Test_2(ArryActors[i], 99);//���ýӿڣ���ͼ�ɸ��ǽӿ�
	//	Cast<ATrap>(ArryActors[i])->ReactToTrigger();//���ýӿڣ���C++�ӿ�
	//}
}

