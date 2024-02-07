// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Global_Attributes.h"

// Sets default values for this component's properties
UBP_Global_Attributes::UBP_Global_Attributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBP_Global_Attributes::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBP_Global_Attributes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBP_Global_Attributes::SetExplosivesDamageMultiplier(float MultiplyBy)
{
	ExplosivesDamageMultiplier *= MultiplyBy;
}

void UBP_Global_Attributes::SetExplosivesRangeMultiplier(float MultiplyBy)
{
	ExplosivesRangeMultiplier *= MultiplyBy;
}



