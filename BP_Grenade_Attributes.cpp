// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Grenade_Attributes.h"

void UBP_Grenade_Attributes::MultiplyGrenadeDamage(float MultiplyBy)
{
	InnerDamageOntopOfOuterDamage *= MultiplyBy;
	OuterDamage *= MultiplyBy;
}
