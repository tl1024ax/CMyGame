// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DelegateTest_GameMode.generated.h"

// ���� �޲� �޷���ֵ �ĵ���ί��
DECLARE_DELEGATE(OnEnterTrigger_00);
// ���� 1������ �޷���ֵ �ĵ���ί��
DECLARE_DELEGATE_OneParam(OnEnterTrigger_01, bool);
// ���� 2������ �޷���ֵ �ĵ���ί��
DECLARE_DELEGATE_TwoParams(OnEnterTrigger_02, bool, int32);
// ���� 3������ �޷���ֵ �ĵ���ί��
DECLARE_DELEGATE_ThreeParams(OnEnterTrigger_03, bool, int32, float);
// ���� �޲� �з���ֵ �ĵ���ί��
DECLARE_DELEGATE_RetVal(bool, OnEnterTrigger_10);
// ���� 1������ �з���ֵ �ĵ���ί��
DECLARE_DELEGATE_RetVal_OneParam(bool, OnEnterTrigger_11, FString);
// ���� 5������ �з���ֵ �ĵ���ί��
DECLARE_DELEGATE_RetVal_FiveParams(bool, OnEnterTrigger_15, bool, int32, float, FString, FString);

// ���� �޲� �Ķಥ��ί��
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
