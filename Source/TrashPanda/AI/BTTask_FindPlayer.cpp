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
#include "BTTask_FindPlayer.h"




EBTNodeResult::Type UBTTask_FindPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBehaviorTreeComponent* BehaviorTree = &OwnerComp;

	AChip* OwningCharacter = Cast<AChip>(OwnerComp.GetAIOwner()->GetPawn());
	UAIPerceptionComponent* Perception = OwnerComp.GetAIOwner()->GetPerceptionComponent();
	AActor* FoundTarget = FindTarget(Perception, OwningCharacter,OwnerComp);


	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(TEXT("Target"), FoundTarget);

	if (FoundTarget != NULL)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(TEXT("InCombat"), true);
	
		AbortTask(OwnerComp, NodeMemory);
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UBTTask_FindPlayer::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::AbortTask(OwnerComp, NodeMemory);
}

AActor* UBTTask_FindPlayer::FindTarget(class UAIPerceptionComponent* PerceptionComponent, class AChip* OwningCharacter, UBehaviorTreeComponent& OwnerComp)
{
	TArray<AActor*> Hostiles;
	PerceptionComponent->GetHostileActors(Hostiles);
	if (Hostiles.Num() > 0)
	{
		OwnerComp.GetAIOwner()->MoveToActor(Hostiles[0]);
		return Hostiles[0];
	}
	return NULL;
}


