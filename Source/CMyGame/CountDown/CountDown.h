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
	//Ϊ���÷ǳ���Ա����C++���������� ��ͼ ������и���
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

	// ��֪ʲôԭ�򣬴˹���ûŪ����
	UFUNCTION(BlueprintSetter)
	void Settest_IntVal_T(int32 val);


};
