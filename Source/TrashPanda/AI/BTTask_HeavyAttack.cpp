// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyAIController.h"
#include "Engine.h"
#include "BTTask_HeavyAttack.h"






EBTNodeResult::Type UBTTask_HeavyAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* BehaviorTree = &OwnerComp;


	if (AEnemyAIController* Controller = Cast<AEnemyAIController>(BehaviorTree->GetAIOwner()))
	{
		Controller->AttackHeavy();
		//Use the function from the AI Class
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UBTTask_HeavyAttack::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}


