// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EnemyAIController.h"
#include "Player/Chip.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"

void AEnemyAIController::Possess(APawn* InPawn)
{

	Super::Possess(InPawn);

	if (BehaviorTreeAsset)
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}

	Pawn = Cast<AEnemy>(InPawn);

}



ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (const APawn* OtherCharacter = Cast<APawn>(&Other))
	{
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherCharacter->GetController()))
		{
			return Super::GetTeamAttitudeTowards(*OtherCharacter->GetController());
		}

		return GetAttitudeTowardsPlayer(Other);
	}



	return ETeamAttitude::Neutral;
}

ETeamAttitude::Type AEnemyAIController::GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB)
{
	return TeamA == TeamB ? ETeamAttitude::Friendly : ETeamAttitude::Hostile;
}

ETeamAttitude::Type AEnemyAIController::GetAttitudeTowardsPlayer(const AActor& Other) const
{


	return ETeamAttitude::Hostile;
}


void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//I have to change this but IDK how to make it better
	RandomMove();
	//NON COMBAS
	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == false)
	{
		GetBrainComponent()->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(TEXT("RandomPos"), NextLocation);
	}
}

void AEnemyAIController::RangedAttack()
{
		
		if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == true)
		{
			Pawn->Shoot(this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsVector(TEXT("PlayerPos")));
		}
		
}

void AEnemyAIController::RandomMove()
{

	FVector Position = Pawn->GetActorLocation();
	if (this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsBool(TEXT("InCombat")) == false)
	{

		Goal.X = Position.X + FMath::RandRange(-2000, 2000);
		Goal.Y = Position.Y + FMath::RandRange(-2000, 2000);
		Goal.Z = Position.Z + FMath::RandRange(-2000, 2000);
		this->GetBrainComponent()->GetBlackboardComponent()->SetValueAsVector(TEXT("Goal"), Goal);
	}
}
