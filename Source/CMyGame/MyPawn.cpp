// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MouseInput = FVector2D::ZeroVector;
	Velocity = FVector::ZeroVector;
	MaxSpeed = 100.0f;
	
	// ����һ�����������ֵ Mesh,Material
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// ����һ�����
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	RootComponent = MyStaticMesh;
	// ���������� ������
	MyStaticMesh->SetupAttachment(GetRootComponent());
	MyStaticMesh->SetCollisionProfileName(TEXT("Pawn"));

	// ������Ŀ�� UStaticMesh Mesh��Դ
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	// ������Ŀ�� UMaterialInterface ������Դ
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_ColorGrid_LowSpec.M_ColorGrid_LowSpec'"));
	if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded())
	{
		MyStaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		MyStaticMesh->SetMaterial(0, MaterialAsset.Object);
		MyStaticMesh->SetWorldScale3D(FVector(0.5f));
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("Hello World!"));
		UE_LOG(LogTemp, Error, TEXT("XXXXXXXXXXXXXXXXX"));
	}

	// ��� SpringArm ���
	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArm"));
	MySpringArm->SetupAttachment(MyStaticMesh);
	MySpringArm->SetRelativeRotation(FRotator(-45.0f, .0f, 0.0f));
	MySpringArm->TargetArmLength = 500.0f;
	MySpringArm->bEnableCameraLag = true;
	MySpringArm->CameraLagSpeed = 3.0f;

	// �����������
	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	MyCamera->SetupAttachment(MySpringArm);
	//CameraRotator = FRotator(-45.0f, 0.0f, 0.0f);
	CameraLocation = FVector(-300.0f, 0.0f, 300.0f);
	//MyCamera->SetRelativeLocation(CameraLocation);
	MyCamera->SetRelativeRotation(CameraRotator);

	// ���ÿ��������ƵĽ�ɫ ��
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// λ��
	AddActorLocalOffset(Velocity * MaxSpeed * DeltaTime, true);

	// ������ת
	FRotator NewSpringRotation = MySpringArm->GetComponentRotation();
	NewSpringRotation.Pitch = FMath::Clamp(NewSpringRotation.Pitch += MouseInput.Y, -80.0f, 1.0f);
	MySpringArm->SetWorldRotation(NewSpringRotation);

	// ������ת
	AddControllerYawInput(MouseInput.X);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMyPawn::LookRight);

}

void AMyPawn::MoveForward(float value)
{
	Velocity.X = FMath::Clamp(value, -1.0f, 1.0f);
}

void AMyPawn::MoveRight(float value)
{
	Velocity.Y = FMath::Clamp(value, -1.0f, 1.0f);
}

void AMyPawn::LookUp(float value)
{
	MouseInput.Y = value;
}

void AMyPawn::LookRight(float value)
{
	MouseInput.X = value;
}

