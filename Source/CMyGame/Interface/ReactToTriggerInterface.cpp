// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactToTriggerInterface.h"

// Add default functionality here for any IReactToTriggerInterface functions that are not pure virtual.

bool IReactToTriggerInterface::ReactToTrigger()
{
	UE_LOG(LogTemp, Log, TEXT("IReactToTriggerInterface::ReactToTrigger()"));
	return true;
}

void IReactToTriggerInterface::BumpTntoToTrigger_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("IReactToTriggerInterface::BumpTntoToTrigger_Implementation()"));
	
}

void IReactToTriggerInterface::Test_2_Implementation(int32 gold)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("IReactToTriggerInterface::Test_2_Implementation() %d"));
	UE_LOG(LogTemp, Log, TEXT("IReactToTriggerInterface::Test_2_Implementation()"));
	
}

