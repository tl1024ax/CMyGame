// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

// siki 学院 AMyActor
UCLASS()
class CMYGAME_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(VisibleAnywhere, Category = "My Actor Components")
	UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Property | Vector")
	FVector InitLocation;

	UPROPERTY(VisibleAnywhere, Category = "My Actor Property | Vector")
	FVector PlaceLocation;

	UPROPERTY(EditDefaultsOnly, Category = "My Actor Property | Vector")
	bool bGotoInitLocation;

	UPROPERTY(EditInstanceOnly,Category="My Actor Property | Vector")
	FVector TickLocationOffset;
	
	UPROPERTY(EditInstanceOnly, Category = "My Actor Property | Vector")
	bool bSweep;
	UPROPERTY(EditInstanceOnly, Category = "My Actor Property | Vector")
	bool bTickLocationOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "My Actor Property | Float")
	float InitVal;

	UPROPERTY(EditAnywhere, Category = "My Actor Property | Float",
		meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -5.0f, UIMax = 5.0f))
	float InitVal2;

	UPROPERTY(EditInstanceOnly, Category="My Actor Property | Physics")
	FVector InitForce;
	UPROPERTY(EditInstanceOnly, Category="My Actor Property | Physics")
	FVector InitTorque;
	UPROPERTY(EditInstanceOnly,Category="My Actor Property | Physics")
	bool bAddForce;
	UPROPERTY(EditInstanceOnly, Category="My Actor Property | Physics")
	bool bAccelChange;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
