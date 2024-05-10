// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineComponent.h"

// Sets default values for this component's properties
UStateMachineComponent::UStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	UStateComponent* CurrentStateComponent = StateComponents[CurrentState];
	CurrentStateComponent->PlayState();
	// ...
}

void UStateMachineComponent::ChangeState(EState NextState) 
{
	UStateComponent* CurrentStateComponent = StateComponents[CurrentState];
	CurrentStateComponent->ExitState();
	CurrentState = NextState;
	CurrentStateComponent = StateComponents[CurrentState];
	CurrentStateComponent->EnterState();
}
