// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "AIController.h"

UPatrolComponent::UPatrolComponent()
{
	StateType = EState::Patrol;
}

void UPatrolComponent::EnterState()
{
	GenerateTargetPoints(PatrolRange);
}

void UPatrolComponent::ExitState()
{
	Super::ExitState();
}

void UPatrolComponent::PlayState()
{

	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (PawnOwner)
	{
		AAIController* AIController = Cast<AAIController>(PawnOwner->GetController());
		if (AIController)
		{
			AActor* NextTarget = GetNextActorToPatrol();
			//move to the next actor
			//AIController->MoveToActor()
		}
	}
}

void UPatrolComponent::GenerateTargetPoints(float Range)
{
	TargetPoints.Empty();

	TArray<AActor*> AllTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), AllTargets);

	for (AActor* Target : AllTargets)
	{
		FVector OwnerLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = Target->GetActorLocation();
		if (FVector::Distance(OwnerLocation, TargetLocation) < Range)
		{
			TargetPoints.Add(Cast<ATargetPoint>(Target));
		}
	}
	if (TargetPoints.Num() < MinimumPatrolTargets)
	{
		GenerateTargetPoints(Range * 2);
	}
}

AActor* UPatrolComponent::GetNextActorToPatrol()
{
	//Get either randomly or in sequence the next actor to move to
	//return the next actor (not nullptr)
	return nullptr;
}
