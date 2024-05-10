// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateComponent.h"
#include "PatrolComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class STATEMACHINE_API UPatrolComponent : public UStateComponent
{
	GENERATED_BODY()
public:
	UPatrolComponent();
};
