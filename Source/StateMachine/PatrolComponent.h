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

	UPROPERTY()
	TArray<class ATargetPoint*> TargetPoints;

	void EnterState()override;
	void ExitState()override;
	void PlayState()override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PatrolRange = 1000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MinimumPatrolTargets = 3;

	void GenerateTargetPoints(float Range);
	AActor* GetNextActorToPatrol();
	AActor* CurrentTarget;
};
