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
	// C++ ʵ�ֽӿں���
	virtual bool ReactToTrigger() override;
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// ʵ�ֽӿں���
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool SteppedToTrigger();
	virtual bool SteppedToTrigger_Implementation() override;
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// ʵ�ֽӿں���,ͬʱ���������Ĭ�ϵ�ʵ�֣�������ﲻ����ʵ�֣������ʱ����Ĭ�ϵ�ʵ��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BumpTntoToTrigger();
	virtual void BumpTntoToTrigger_Implementation() override; // ʵ�ֽӿں���
	/* ---------------------------------------- */

	/* ---------------------------------------- */
	// ʵ�ֽӿں���,ͬʱ���������Ĭ�ϵ�ʵ�֣�������ﲻ����ʵ�֣������ʱ����Ĭ�ϵ�ʵ��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Test_2(int32 gold);
	//virtual void Test_2_Implementation(int32 gold) override; //ʵ�ֽӿں��� ����ע�͵���
	/* ---------------------------------------- */

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StMeshComponent;
};
