// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestTArray.generated.h"

UCLASS()
class CMYGAME_API ATestTArray : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestTArray();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TestTheTArray();

	void TestTArrayFor(TArray<FString> strArr);

	void TestTArrayFor(TArray<int32> strArr);

	void GetSizeInfo(TArray<int32>& strArr);

};
