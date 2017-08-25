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
#include "MoveWithAbort.h"




EBTNodeResult::Type UMoveWithAbort::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AChip* Player = Cast<AChip>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	AEnemy* Self = Cast <AEnemy>(OwnerComp.GetAIOwner()->GetPawn());


	Self->Shoot(Player->GetActorLocation());

	OwnerComp.GetAIOwner()->MoveToActor(Player, 500);

	return Super::ExecuteTask(OwnerComp, NodeMemory);
}


EBTNodeResult::Type UMoveWithAbort::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}
