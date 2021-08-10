// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ReactToTriggerInterface.generated.h"

// This class does not need to be modified.
// Blueprintable:�����๫��Ϊ��������ͼ�еı��������͡�
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

	// �˽ӿڿ����ڽӿڵ�.cpp�ж���һ��Ĭ�ϵ�ʵ�֣�����ֻ����C++����д
	virtual bool ReactToTrigger();

	// ֻ������ͼ����д
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void TouchedToTrigger();

	// ���� ��ͼ �� C++ ����д�������ڽӿڵ�.cpp�ļ���ʵ��һ��Ĭ�ϵ� �ӿں�������������û��ʵ��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool SteppedToTrigger();

	// ���� ��ͼ �� C++ ����д�������ڽӿڵ�.cpp�ļ���ʵ��һ��Ĭ�ϵ� �ӿں�����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BumpTntoToTrigger();
	virtual void BumpTntoToTrigger_Implementation(); // �ڽӿ���ʵ��һ��Ĭ�ϵ� �ӿں���

	// ���� ��ͼ �� C++ ����д�������ڽӿڵ�.cpp�ļ���ʵ��һ��Ĭ�ϵ� �ӿں�����
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Test_2(int32 gold);
	virtual void Test_2_Implementation(int32 gold); // �ڽӿ���ʵ��һ��Ĭ�ϵ� �ӿں���
};
