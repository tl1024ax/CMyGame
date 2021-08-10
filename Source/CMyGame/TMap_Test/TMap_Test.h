// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Containers/Set.h>
#include <../Private/Fonts/FontCacheUtils.h>
#include "TMap_Test.generated.h"


struct FMyStruct
{
	FString UniqueID;
	float SomeFloat;

	explicit FMyStruct(float infloat) :UniqueID(FGuid::NewGuid().ToString()), SomeFloat(infloat) {

	}
};

template<typename ValueTye>
struct TMyStructMapKeyFuncs :BaseKeyFuncs<TPair<FMyStruct, ValueType>, FString>
{
private:
	typedef BaseKeyFuncs<TPair<FMyStruct, ValueType>, FString> Supper;
public:
	typedef typename Supper::ElementInitType ElementInitType;
	typedef typename Supper::KeyInitType KeyInitType;

	static KeyInitType GetSetKey(ElementInitType Element)
	{
		return Element.Key.UniqueID;
	}

	static bool Matches(KeyInitType A, KeyInitType B)
	{
		return A.Compare(B, ESearchCase::CaseSensitive) == 0;
	}

	static uint32 GetKeyHash(KeyInitType Key)
	{
		return FCrc::StrCrc32(*Key);
	}
};

//https://docs.unrealengine.com/4.26/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/TMap/
UCLASS()
class CMYGAME_API ATMap_Test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATMap_Test();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TMap<FMyStruct, int32, FDefaultSetAllocator, TMyStructMapKeyFuncs<int32>> MyMapToInt32;
};

