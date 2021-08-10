// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightActor_Test.generated.h"

UCLASS()
class CMYGAME_API ALightActor_Test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightActor_Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	class UPointLightComponent* PointLigth;


	UFUNCTION(BlueprintCallable)
	void TestBindDelegate();
	UFUNCTION(BlueprintCallable)
	void TestUnBindDelegate();

	UFUNCTION(BlueprintCallable)
	void TestFuncNoParam();

	UFUNCTION(BlueprintCallable)
	void TestFuncThreeParams(bool bVal,int32 iVal,float fVal);

	UFUNCTION(BlueprintCallable)
	bool TestFuncRetValNoParam();

	UFUNCTION(BlueprintCallable)
		bool TestFuncRetValFiveParams(bool bVal, int32 iVal, float fVal, FString fStr1, FString fStr2);

	UFUNCTION(BlueprintCallable)
	void EnablePointLight(bool bEnable);
};
