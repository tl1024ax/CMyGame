// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTArray.h"

// Sets default values
ATestTArray::ATestTArray()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestTArray::BeginPlay()
{
	Super::BeginPlay();
	
	TestTheTArray();
}

// Called every frame
void ATestTArray::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestTArray::TestTheTArray()
{


	TArray<FString> strArr;
	strArr.Add("Hello");
	//������ԣ�Emplace ���� Add�����ݾ��飬�ɽ� Add ����ǳ�����ͣ��� Emplace �����������͡�Emplace ��Ч��ʼ�ո��� Add���� Add �Ŀɶ��Կ��ܸ��á�
	strArr.Emplace("World");

	strArr.Insert("?", 1);

	FString tempArr[] = { TEXT("of"),TEXT("Tomorrow"),TEXT("?") ,TEXT("XGame")};
	strArr.Append(tempArr, ARRAY_COUNT(tempArr));

	strArr.AddUnique("!");
	strArr.AddUnique("!");
	strArr.AddUnique("()");

	TestTArrayFor(strArr);
	strArr.Pop();
	//strArr.Remove("Hello");
	strArr.RemoveAll([](const FString& Str) {
		return Str.Len() == 5;
	});
	TestTArrayFor(strArr);
	

	bool bidx_1 = strArr.ContainsByPredicate([](const FString& Str) {
		//return Str == "Hello";
		return Str.Len() == 5;
	});

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, bidx_1?TEXT("True"):TEXT("False"));

	int32 idx_2 = 0;
	strArr.Find(TEXT("World"), idx_2);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::FromInt(idx_2));

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("-------------------------------"));

	TArray<int32> intArr;
	//intArr.Init(91, 5);// [91,91,91,91,91]
	intArr.Emplace(1);
	intArr.Emplace(22);
	intArr.Emplace(33);
	TArray<int32> intArr_2;
	intArr_2 = intArr;
	TestTArrayFor(intArr_2);
	intArr_2[0] = 12;
	TestTArrayFor(intArr_2);
	intArr_2 += intArr;
	TestTArrayFor(intArr_2);
	intArr = MoveTemp(intArr_2);
	TestTArrayFor(intArr_2);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("-------------------------------"));
	TestTArrayFor(intArr);

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("-------------------------------"));

	TArray<int32> intArr_3;
	intArr_3.Add(13);
	intArr_3.Add(23);
	intArr_3.Add(23);
	intArr_3.Add(23);
	intArr_3.Add(23);
	//intArr_3.Empty();
	intArr_3.Reset();
	FString SizeInof = TEXT("Slack = ") + FString::FromInt(intArr_3.GetSlack())
		+ TEXT(",Num = ") + FString::FromInt(intArr_3.Num())
		+ TEXT(",Max = ") + FString::FromInt(intArr_3.Max());
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, SizeInof);
	GetSizeInfo(intArr_3);
}

// �������Ԫ��
void ATestTArray::TestTArrayFor(TArray<FString> strArr)
{
	FString joinedStr;

	//�ж��ַ����ɵ��������Ԫ�أ�����ʹ��C++�ķ�Χ��ranged-for�����ܣ�
	for (auto& str : strArr)
	{
		joinedStr += str;
		joinedStr += TEXT(" ");
	}

	//ͬʱҲ��ʹ�û��������ĳ��������
	//for (int32 idx = 0;idx < strArr.Num();++idx)
	//{
	//	joinedStr += strArr[idx];
	//	joinedStr += " ";
	//}

	//��󣬻���ͨ��������������Ϳ��Ƶ��������� CreateIterator �� CreateConstIterator �ɷֱ�����Ԫ�صĶ�д��ֻ�����ʣ�
	//for (auto It = strArr.CreateConstIterator();It;++It)
	//{
	//	joinedStr += *It;
	//	joinedStr += " ";
	//}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, joinedStr);
}

// �������Ԫ��
void ATestTArray::TestTArrayFor(TArray<int32> strArr)
{
	FString joinStr;
	for (auto& Str:strArr)
	{
		joinStr += FString::FromInt(Str);
		joinStr += " ";
	}

	//for (int idx = 0;idx < strArr.Num();++idx)
	//{
	//	joinStr += FString::FromInt(strArr[idx]);
	//	joinStr += " ";
	//}

	//for (auto It = strArr.CreateConstIterator();It;++It)
	//{
	//	joinStr += FString::FromInt(*It);
	//	joinStr += " ";
	//}
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, joinStr);
}

// �������ߴ���Ϣ
void ATestTArray::GetSizeInfo(TArray<int32>& strArr)
{
	FString SizeInof = TEXT("GetSizeInfo() Slack = ") + FString::FromInt( strArr.GetSlack()) 
		+ TEXT(",Num = ") + FString::FromInt(strArr.Num()) + TEXT(",Max = ") + FString::FromInt(strArr.Max());
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, SizeInof);
}


