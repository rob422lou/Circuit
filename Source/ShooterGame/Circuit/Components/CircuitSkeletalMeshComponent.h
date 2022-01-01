// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interfaces/SetValuesInterface.h"
#include "Components/SkeletalMeshComponent.h"
#include "Circuit/CircuitHelper.h"
#include "CircuitSkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Rendering, Common), hidecategories = Object, meta = (BlueprintSpawnableComponent))
class SHOOTERGAME_API UCircuitSkeletalMeshComponent : public USkeletalMeshComponent, public ISetValuesInterface
{
	GENERATED_BODY()
	
public:
/////////////////////////////////////////////////////////////////////////
// Property Replication

	virtual void SetCollisionEnabled(ECollisionEnabled::Type NewType) override;

	UFUNCTION(NetMulticast, Reliable)
	void Multi_SetCollisionEnabled(ECollisionEnabled::Type NewType);
	bool Multi_SetCollisionEnabled_Validate(ECollisionEnabled::Type NewType);
	void Multi_SetCollisionEnabled_Implementation(ECollisionEnabled::Type NewType);
};
