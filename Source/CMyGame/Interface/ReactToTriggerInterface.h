// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ReactToTriggerInterface.generated.h"

// This class does not need to be modified.
// Blueprintable:将该类公开为可用于蓝图中的变量的类型。
UINTERFACE(MinimalAPI, Blueprintable)
class UReactToTriggerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class CMYGAME_API IReactToTriggerInterface
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// 此接口可以在接口的.cpp中定义一个默认的实现，并且只能在C++中重写
	virtual bool ReactToTrigger();

	// 只能在蓝图中重写
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void TouchedToTrigger();

	// 能在 蓝图 与 C++ 中重写。可以在接口的.cpp文件中实现一个默认的 接口函数。但是这里没有实现
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool SteppedToTrigger();

	// 能在 蓝图 与 C++ 中重写。可以在接口的.cpp文件中实现一个默认的 接口函数。
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BumpTntoToTrigger();
	virtual void BumpTntoToTrigger_Implementation(); // 在接口中实现一个默认的 接口函数

	// 能在 蓝图 与 C++ 中重写。可以在接口的.cpp文件中实现一个默认的 接口函数。
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Test_2(int32 gold);
	virtual void Test_2_Implementation(int32 gold); // 在接口中实现一个默认的 接口函数
};
