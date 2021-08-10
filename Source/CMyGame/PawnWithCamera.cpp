// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnWithCamera.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
APawnWithCamera::APawnWithCamera()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �������
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	// �����
	StaticMeshComp->SetupAttachment(RootComponent);
	SpringArmComp->SetupAttachment(StaticMeshComp);
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	// Ϊ SpringArm ��ֵ
	SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 400.0f;
	SpringArmComp->bEnableCameraLag = true; //�ƶ�ƽ���̶�
	SpringArmComp->CameraLagSpeed = 3.0f;

	//����Ĭ�����
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APawnWithCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APawnWithCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//��������˷Ŵ�ť��Ŵ󣬷������С
	if (bZoomingIn)
	{
		ZoomFactor += DeltaTime / 0.5f;
	}
	else
	{
		ZoomFactor -= DeltaTime / 0.5f;
	}
	ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);

	//����ZoomFactor��������������ӳ��͵��ɱ۵ĳ���
	CameraComp->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
	SpringArmComp->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);

	{
		// ��תActor��ƫת�Ƕȣ����������Actor����󶨣���������Ҳ����ת
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.Y;
		SetActorRotation(NewRotation);
	}

	{
		// ��ת������ĸ����ǣ�������������ƣ�ȷ������ʼ�ճ��¿�
		FRotator NewRotation = SpringArmComp->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp<float>(NewRotation.Pitch + CameraInput.X, -80.0f, -15.f);
		SpringArmComp->SetWorldRotation(NewRotation);
	}

	{
		// ����"MoveX"��"MoveY"�Ĵ����ƶ�
		if (!MovmentInput.IsZero())
		{
			MovmentInput = MovmentInput.GetSafeNormal() * 100.0f;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovmentInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovmentInput.Y * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}

}

// Called to bind functionality to input
void APawnWithCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ��"ZoomIn"�¼�
	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &APawnWithCamera::ZoomIn);
	InputComponent->BindAction("ZoomIn", IE_Released, this, &APawnWithCamera::ZoomOut);

	// �������¼�
	InputComponent->BindAxis("MoveForward", this, &APawnWithCamera::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APawnWithCamera::MoveRight);
	InputComponent->BindAxis("CameraPitch", this, &APawnWithCamera::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &APawnWithCamera::YawCamera);
}

void APawnWithCamera::MoveForward(float AxisValue)
{
	MovmentInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::MoveRight(float AxisValue)
{
	MovmentInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void APawnWithCamera::PitchCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void APawnWithCamera::YawCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void APawnWithCamera::ZoomIn()
{
	bZoomingIn = true;
}

void APawnWithCamera::ZoomOut()
{
	bZoomingIn = false;
}

