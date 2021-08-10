// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class CMYGAME_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	UPROPERTY(VisibleAnywhere,Category = "My pawn Components")
	class UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(VisibleAnywhere, Category = "My pawn Components")
	class USpringArmComponent* MySpringArm;

	UPROPERTY(VisibleAnywhere, Category = "My pawn Components")
	class UCameraComponent* MyCamera;

	UPROPERTY(VisibleAnywhere,Category = "My pawn Components")
	FVector CameraLocation;

	UPROPERTY(VisibleAnywhere, Category = "My pawn Components")
	FRotator CameraRotator;


	UPROPERTY(EditAnywhere, Category = "My pawn Components")
	float MaxSpeed;

	//UPROPERTY(VisibleAnywhere, Category = "My pawn Components")
	FVector Velocity;
	FVector2D MouseInput;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void MoveForward(float value);
	void MoveRight(float value);

	void LookUp(float value);
	void LookRight(float value);

};
