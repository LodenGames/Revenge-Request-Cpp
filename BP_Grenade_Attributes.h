// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BP_Throwable_Attributes.h"
#include "BP_Grenade_Attributes.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPSRL_API UBP_Grenade_Attributes : public UBP_Throwable_Attributes
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void MultiplyGrenadeDamage (float MultiplyBy);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float InnerDamageOntopOfOuterDamage = 50;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float OuterDamage = 50;
	
};
