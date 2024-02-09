// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Throwable_Attributes.h"

#include "UObject/GarbageCollectionSchema.h"

// Sets default values for this component's properties
UBP_Throwable_Attributes::UBP_Throwable_Attributes()
{

}


// Called when the game starts
void UBP_Throwable_Attributes::BeginPlay()
{
	Super::BeginPlay();
	
}

void UBP_Throwable_Attributes::MultiplyGrenadeRadius(float MultiplyBy)
{
	InnerRadius *= MultiplyBy;
	OuterRadius *= MultiplyBy;
}

