// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

//컴파일타임에 딱 한 번 실행. -> 에디터 실행이 완료되기 전에 실행.
UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("Constructor Call Start"));
	//텍스트는 서브오브젝트를 관리하기 위한 해쉬값으로 사용됨.
	//생성자에서 호출함으로써 Static하게 생성. (컴파일 타임에 생성)
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));
	AB_LOG(Warning, TEXT("Constructor Call End"));
}

//런타임에 실행.
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

	//outerClass 정보를 매개변수로 받음.
	//런타임에 동적으로 생성.
	WebConnectionNew = NewObject<UWebConnection>(this);
	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());
}