// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CountDown.generated.h"

UCLASS()
class CMYGAME_API ACountDown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void UpdateTimerDisplay();
	UFUNCTION()
	void AdvaceTimer();
	//为了让非程序员调用C++函数，并用 蓝图 对其进行覆盖
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	
	UPROPERTY()
	FTimerHandle CountdownTimerHandle;

	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	UPROPERTY()
	class UTextRenderComponent* CountdownText;



	UPROPERTY(BlueprintReadWrite, BlueprintSetter = "Settest_IntVal_T")
	int32 test_IntVal;

	// 不知什么原因，此功能没弄明白
	UFUNCTION(BlueprintSetter)
	void Settest_IntVal_T(int32 val);


};
