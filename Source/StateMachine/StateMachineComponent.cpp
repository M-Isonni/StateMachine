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
	TSet<UActorComponent*> OwnerComponents;
	OwnerComponents = GetOwner()->GetComponents();
	for (UActorComponent* component : OwnerComponents) 
	{
		UStateComponent* StateComponent = Cast<UStateComponent>(component);
		if (StateComponent) 
		{
			RegisterState(StateComponent->StateType, StateComponent);
		}
	}
	CurrentState = InitialState;
	if (StateComponents.Contains(CurrentState))
	{
		UStateComponent* CurrentStateComponent = StateComponents[CurrentState];
		CurrentStateComponent->EnterState();
	}

}


void UStateMachineComponent::RegisterState(EState StateType, UStateComponent* State)
{
	StateComponents.Add(StateType, State);
}

// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (StateComponents.Contains(CurrentState)) 
	{
		UStateComponent* CurrentStateComponent = StateComponents[CurrentState];
		CurrentStateComponent->PlayState();
	}
	// ...
}

void UStateMachineComponent::ChangeState(EState NextState) 
{
	if (StateComponents.Contains(CurrentState)&&StateComponents.Contains(NextState)) 
	{
		UStateComponent* CurrentStateComponent = StateComponents[CurrentState];
		CurrentStateComponent->ExitState();
		CurrentState = NextState;
		CurrentStateComponent = StateComponents[CurrentState];
		CurrentStateComponent->EnterState();
	}
}

void UStateMachineComponent::OnRegister()
{
	Super::OnRegister();
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (!PawnOwner) 
	{
		UE_LOG(LogTemp, Warning, TEXT("State Machine can only be Attached to a PawnActor"));
		UnregisterComponent();
	}
}

