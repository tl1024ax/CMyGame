// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReactToTriggerInterface.h"
#include "Trap.generated.h"

UCLASS()
class CMYGAME_API ATrap : public AActor,public IReactToTriggerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* ---------------------------------------- */
	// C++ 实现接口函数
	virtual bool ReactToTrigger() override;
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// 实现接口函数
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool SteppedToTrigger();
	virtual bool SteppedToTrigger_Implementation() override;
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// 实现接口函数,同时这个函数有默认的实现，如果这里不重新实现，则调用时调用默认的实现
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BumpTntoToTrigger();
	virtual void BumpTntoToTrigger_Implementation() override; // 实现接口函数
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// 实现接口函数,同时这个函数有默认的实现，如果这里不重新实现，则调用时调用默认的实现
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Test_2(int32 gold);
	//virtual void Test_2_Implementation(int32 gold) override; //实现接口函数 这里注释掉了
	/* ---------------------------------------- */

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StMeshComponent;
};
