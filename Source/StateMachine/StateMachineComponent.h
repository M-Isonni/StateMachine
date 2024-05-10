// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateComponent.h"
#include "StateMachineComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class STATEMACHINE_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	EState InitialState = EState::Patrol;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	EState CurrentState;
	TMap<EState, UStateComponent*> StateComponents;
	void RegisterState(EState StateType, UStateComponent* State);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void ChangeState(EState NextState);

	virtual void OnRegister() override;


};
