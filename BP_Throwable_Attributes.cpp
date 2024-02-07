// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Throwable_Attributes.h"

#include "UObject/GarbageCollectionSchema.h"

// Sets default values for this component's properties
UBP_Throwable_Attributes::UBP_Throwable_Attributes()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBP_Throwable_Attributes::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBP_Throwable_Attributes::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBP_Throwable_Attributes::MultiplyGrenadeRadius(float MultiplyBy)
{
	InnerRadius *= MultiplyBy;
	OuterRadius *= MultiplyBy;
}

