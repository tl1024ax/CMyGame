// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestInterfaceActor.generated.h"

UCLASS()
class CMYGAME_API ATestInterfaceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestInterfaceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ���� UE4 ���������ӿڣ���ȡ�ؿ��ڶ���
	UFUNCTION()
	void CallInterface();
};
