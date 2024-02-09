// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Grenade_Throwable_Object.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABP_Grenade_Throwable_Object::ABP_Grenade_Throwable_Object()
{
	// sphere to replace root... test to see it is working in blueprint?

	ObjectCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	RootComponent = ObjectCollider;

	InnerRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InnerRadius"));
	InnerRadius->SetupAttachment(ObjectCollider);
	InnerRadius->SetSphereRadius(InnerSphereRadius);
	InnerRadius->OnComponentBeginOverlap.AddDynamic(this, &ABP_Grenade_Throwable_Object::OnInnerRadiusOverlap);

	
	OuterRadius = CreateDefaultSubobject<USphereComponent>(TEXT("OuterRadius"));
	OuterRadius->SetupAttachment(ObjectCollider);
	InnerRadius->SetSphereRadius(OuterSphereRadius);
	OuterRadius->OnComponentBeginOverlap.AddDynamic(this, &ABP_Grenade_Throwable_Object::OnOuterRadiusOverlap);


	ThrowingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ThrowingMesh"));
	ThrowingMesh->SetupAttachment(ObjectCollider);
	
}	

// Called when the game starts or when spawned
void ABP_Grenade_Throwable_Object::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABP_Grenade_Throwable_Object::OnInnerRadiusOverlap(UPrimitiveComponent* thisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->ActorHasTag("Person")) return;

	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) 
	{
		Destroy();	
		return;
	}
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();
	
	UGameplayStatics::ApplyDamage(OtherActor, InnerDamageCombinedWithOuter + OuterDamage, MyOwnerInstigator, this, DamageTypeClass);
}

void ABP_Grenade_Throwable_Object::OnOuterRadiusOverlap(UPrimitiveComponent* thisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->ActorHasTag("Person")) return;

	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) 
	{
		Destroy();	
		return;
	}
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();
	
	UGameplayStatics::ApplyDamage(OtherActor, OuterDamage, MyOwnerInstigator, this, DamageTypeClass);
}


