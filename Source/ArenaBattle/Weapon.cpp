// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponHashValue"));
	RootComponent = Weapon;

	//������(Constructor)������ ��밡��. -> CDO���ۿ��� ����.

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> 
		weaponObject(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Silly_Weapons/Blade_Driver/SK_Blade_Driver.SK_Blade_Driver'"));

	Weapon->SetSkeletalMesh(weaponObject.Object);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

