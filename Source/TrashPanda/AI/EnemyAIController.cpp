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
<<<<<<< HEAD

	Pawn = Cast<AEnemy>(InPawn);
}



=======


}
>>>>>>> master
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
<<<<<<< HEAD


	return ETeamAttitude::Hostile;
}


void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//I have to change this but IDK how to make it better
	NextLocation = Pawn->NextPos();

	//NON COMBAT BEHAVIORS
	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == false)
	{
		GetBrainComponent()->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(TEXT("RandomPos"), NextLocation);
	}
}


//Rename to light attack
void AEnemyAIController::AttackCommand()
{
	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == true)
	{
		Pawn->AttackMelle(this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
	}
}

void AEnemyAIController::AttackHeavy()
{
	if (GetBrainComponent()->GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(TEXT("InCombat")) == true)
	{
		//Pawn->AttackMelle(this->GetBrainComponent()->GetBlackboardComponent()->GetValueAsObject(TEXT("Target")));
	}
}
=======
	
	return ETeamAttitude::Hostile;
}



void AEnemyAIController::CalculateRandomPos()
{
	FVector RandomPos;
	RandomPos.X = 100;
	RandomPos.Z = 150;
	RandomPos.Y = 0;
}



 void AEnemyAIController::AttackBasic()
{
	//GetBrainComponent()->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(TEXT("IsInAttackRange"), true);
	 print("im in AIContrller");
	//if in range attack
}

>>>>>>> master
