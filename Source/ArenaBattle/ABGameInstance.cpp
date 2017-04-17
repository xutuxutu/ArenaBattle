// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

//������Ÿ�ӿ� �� �� �� ����. -> ������ ������ �Ϸ�Ǳ� ���� ����.
UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("Constructor Call Start"));
	//�ؽ�Ʈ�� ���������Ʈ�� �����ϱ� ���� �ؽ������� ����.
	//�����ڿ��� ȣ�������ν� Static�ϰ� ����. (������ Ÿ�ӿ� ����)
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));
	AB_LOG(Warning, TEXT("Constructor Call End"));
}

//��Ÿ�ӿ� ����.
void UABGameInstance::Init()
{
	Super::Init();
	AB_LOG_CALLONLY(Warning);

	TArray<UObject *> DefaultSubobjects;
	GetDefaultSubobjects(DefaultSubobjects);
	for (const auto& Entry : DefaultSubobjects)
	{
		AB_LOG(Warning, TEXT("DefaultSubobject : %s"), *Entry->GetClass()->GetName());
		AB_LOG(Warning, TEXT("Outer of DefaultSubobject : %s"), *Entry->GetOuter()->GetClass()->GetName());
	}

	//outerClass ������ �Ű������� ����.
	//��Ÿ�ӿ� �������� ����.
	WebConnectionNew = NewObject<UWebConnection>(this);
	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());
}