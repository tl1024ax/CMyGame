// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnWithCamera.generated.h"

//https://docs.unrealengine.com/4.26/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/PlayerCamera/
UCLASS()
class CMYGAME_API APawnWithCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnWithCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float AxisValue);
	UFUNCTION()
	void MoveRight(float AxisValue);
	UFUNCTION()
	void PitchCamera(float AxisValue);
	UFUNCTION()
	void YawCamera(float AxisValue);
	UFUNCTION()
	void ZoomIn();
	UFUNCTION()
	void ZoomOut();
protected:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere)
	class UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComp;


	FVector2D MovmentInput;
	FVector2D CameraInput;
	float ZoomFactor;
	bool bZoomingIn;

};
