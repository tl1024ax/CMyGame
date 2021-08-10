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

	// 测试接口
	CallInterface();
}

// Called every frame
void ATestInterfaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 测试 UE4 迭代器，接口，获取关卡内对象
void ATestInterfaceActor::CallInterface()
{
	// UE4 迭代器TActorIterator
	//TActorIterator<T> actorIt = TActorIterator<T>(GetWorld());
	// 获取关卡里面所有的 ATrap 对象
	TActorIterator<ATrap> actorIt = TActorIterator<ATrap>(GetWorld(),ATrap::StaticClass());
	for (actorIt; actorIt; ++actorIt)
	{
		if (!actorIt)
		{
			continue;
		}
		ATrap* trap = *actorIt;
		//判断ATrap类是否实现了 UReactToTriggerInterface 接口，这里传入 UReactToTriggerInterface 而非 IReactToTriggerInterface
		bool isImplement = trap->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass());
		if (isImplement)
		{
			// 转换为 IReactToTriggerInterface 接口
			IReactToTriggerInterface* inter = Cast<IReactToTriggerInterface>(trap); 
			inter->Execute_TouchedToTrigger(trap); // 调用接口，这个接口时纯蓝图接口，只能在蓝图中实现
			inter->Execute_SteppedToTrigger(trap); //调用接口，蓝图可覆盖接口
			inter->Execute_BumpTntoToTrigger(trap); //调用接口，蓝图可覆盖接口
			inter->Execute_Test_2(trap, 99);//调用接口，蓝图可覆盖接口
			inter->ReactToTrigger();//调用接口，纯C++接口
		}
	}

	// -- GetAllActorsOfClass
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("------------------ GetAllActorsOfClass"));
	//TArray<AActor*> ArryActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrap::StaticClass(), ArryActors);
	//for (int32 i = 0; i < ArryActors.Num(); i++)
	//{
	//	Cast<ATrap>(ArryActors[i])->Execute_TouchedToTrigger(ArryActors[i]); // 调用接口，这个接口时纯蓝图接口，只能在蓝图中实现
	//	Cast<ATrap>(ArryActors[i])->Execute_SteppedToTrigger(ArryActors[i]); //调用接口，蓝图可覆盖接口
	//	Cast<ATrap>(ArryActors[i])->Execute_BumpTntoToTrigger(ArryActors[i]); //调用接口，蓝图可覆盖接口
	//	Cast<ATrap>(ArryActors[i])->Execute_Test_2(ArryActors[i], 99);//调用接口，蓝图可覆盖接口
	//	Cast<ATrap>(ArryActors[i])->ReactToTrigger();//调用接口，纯C++接口
	//}
}

