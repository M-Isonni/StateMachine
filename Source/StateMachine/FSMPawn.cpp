// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMPawn.h"
//The following includes
#include "StateMachineComponent.h"
#include "AttackComponent.h"
#include "ChaseComponent.h"
#include "PatrolComponent.h"

// Sets default values
AFSMPawn::AFSMPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PatrolComponent = CreateDefaultSubobject<UPatrolComponent>(TEXT("PatrolComponent"));
	ChaseComponent = CreateDefaultSubobject<UChaseComponent>(TEXT("ChaseComponent"));
	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComponent"));
	StateMachineComponent = CreateDefaultSubobject<UStateMachineComponent>(TEXT("StateMachineComponent"));
}

// Called when the game starts or when spawned
void AFSMPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSMPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFSMPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

