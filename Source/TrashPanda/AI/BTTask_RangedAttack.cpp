// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Player/Chip.h"
#include "EnemyAIController.h"
#include "AI/Enemy.h"
#include "BTTask_RangedAttack.h"





EBTNodeResult::Type UBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
//	AChip* Player = Cast<AChip>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	//AEnemy* Self = Cast <AEnemy>( OwnerComp.GetAIOwner()->GetPawn());


	AEnemyAIController*  controller = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	AChip* Player = Cast<AChip>( OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));

	controller->RangedAttack();
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}


EBTNodeResult::Type UBTTask_RangedAttack::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}
