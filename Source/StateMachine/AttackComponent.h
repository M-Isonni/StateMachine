// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateComponent.h"
#include "AttackComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class STATEMACHINE_API UAttackComponent : public UStateComponent
{
	GENERATED_BODY()
public:
	UAttackComponent();
};
