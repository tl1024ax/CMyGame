// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegate_Test.generated.h"

// https://docs.unrealengine.com/4.26/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/
// https://docs.unrealengine.com/4.26/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/Dynamic/

UCLASS()
class CMYGAME_API ADelegate_Test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegate_Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
