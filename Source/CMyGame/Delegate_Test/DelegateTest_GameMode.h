// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DelegateTest_GameMode.generated.h"

// 声明 无参 无返回值 的单播委托
DECLARE_DELEGATE(OnEnterTrigger_00);
// 声明 1个参数 无返回值 的单播委托
DECLARE_DELEGATE_OneParam(OnEnterTrigger_01, bool);
// 声明 2个参数 无返回值 的单播委托
DECLARE_DELEGATE_TwoParams(OnEnterTrigger_02, bool, int32);
// 声明 3个参数 无返回值 的单播委托
DECLARE_DELEGATE_ThreeParams(OnEnterTrigger_03, bool, int32, float);
// 声明 无参 有返回值 的单播委托
DECLARE_DELEGATE_RetVal(bool, OnEnterTrigger_10);
// 声明 1个参数 有返回值 的单播委托
DECLARE_DELEGATE_RetVal_OneParam(bool, OnEnterTrigger_11, FString);
// 声明 5个参数 有返回值 的单播委托
DECLARE_DELEGATE_RetVal_FiveParams(bool, OnEnterTrigger_15, bool, int32, float, FString, FString);

// 声明 无参 的多播播委托
DECLARE_MULTICAST_DELEGATE(OnEnterTriggerMult_00);
DECLARE_MULTICAST_DELEGATE_OneParam(OnEnterTriggerMult_01, bool);
//UDELEGATE(BlueprintAuthorityOnly)
//DECLARE_MULTICAST_DELEGATE_TwoParams(OnEnterTriggerMult_02, bool, bVal, int32, iVal);
//UDELEGATE(BlueprintAuthorityOnly)
//DECLARE_MULTICAST_DELEGATE_FiveParams(OnEnterTriggerMult_05, bool, bVal, int32, iVal,FString,fStr1, FString, fStr2, FString, fStr3);
/**
 * 
 */
UCLASS()
class CMYGAME_API ADelegateTest_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	OnEnterTrigger_00 onEnterTrigger_00;
	OnEnterTrigger_01 onEnterTrigger_01;
	OnEnterTrigger_02 onEnterTrigger_02;
	OnEnterTrigger_03 onEnterTrigger_03;
	OnEnterTrigger_10 onEnterTrigger_10;
	OnEnterTrigger_11 onEnterTrigger_11;
	OnEnterTrigger_15 onEnterTrigger_15;

	OnEnterTriggerMult_00 onEnterTriggerMult_00;
};
