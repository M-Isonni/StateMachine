// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FSMPawn.generated.h"

UCLASS()
class STATEMACHINE_API AFSMPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFSMPawn();
	
	
	UPROPERTY()
	class UAttackComponent* AttackComponent; //forward declaration
	UPROPERTY()
	class UChaseComponent* ChaseComponent;//forward declaration
	UPROPERTY()
	class UPatrolComponent* PatrolComponent;//forward declaration
	UPROPERTY()
	class UStateMachineComponent* StateMachineComponent;//forward declaration

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
