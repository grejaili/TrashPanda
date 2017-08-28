// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 

void AEnemyAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (BehaviorTreeAsset)
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}

	Pawn = Cast<AEnemy>(InPawn);
	RandomMove();
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

	//NON COMBAS
	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == false)
	{
		GetBrainComponent()->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(TEXT("RandomPos"), NextLocation);
	}
	RandomMove();

	UE_LOG(LogTemp, Warning, TEXT("Your COMPILING WHY IS CRASHING THE ENGINE"));

}

void AEnemyAIController::AttackCommand()
{
	// COMBAT BEHAVIORS


	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == true)
	{
		Pawn->AttackMelle(this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
	}
}

void AEnemyAIController::RandomMove()
{


	float x = Pawn->GetActorLocation().X;
	float y = Pawn->GetActorLocation().Y;


	if (this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsBool(TEXT("InCombat")) == false)
	{


		Goal.X = x + FMath::RandRange(-10000, 10000);
		Goal.Y = y + FMath::RandRange(-10000, 10000);
		Goal.Z = 0 + FMath::RandRange(-10000, 10000);
		this->GetBrainComponent()->GetBlackboardComponent()->SetValueAsVector(TEXT("Goal"), Goal);
	}




	if (this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsBool(TEXT("InCombat")) == true)
	{

	}

}
