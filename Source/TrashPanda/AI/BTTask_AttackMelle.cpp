// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyAICOntroller.h"
#include "Engine.h"
#include "BTTask_AttackMelle.h"
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 




EBTNodeResult::Type UBTTask_AttackMelle::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* BehaviorTree = &OwnerComp;


	if (AEnemyAIController* Controller = Cast<AEnemyAIController>(BehaviorTree->GetAIOwner()))
	{
		Controller->AttackCommand();

		//Use the function from the AI Class
	
	}

	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UBTTask_AttackMelle::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}
