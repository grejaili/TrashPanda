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

	UAIPerceptionComponent* Perception = OwnerComp.GetAIOwner()->GetPerceptionComponent();
	AChip* FoundTarget; //= FindTarget(Perception, OwningCharacter, OwnerComp);

	for (TObjectIterator<AChip> Itr; Itr; ++Itr)
	{
		// Access the subclass instance with the * or -> operators.
		AChip *Component = *Itr;
		FoundTarget = Component;
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(TEXT("InCombat"), true);	
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), FoundTarget);
		AEnemyAIController* Controller = Cast <AEnemyAIController>(OwnerComp.GetAIOwner());
		Controller->Att = true;
		Controller->SetFocus(FoundTarget);
	}

	AbortTask(OwnerComp, NodeMemory);
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

		return Hostiles[0];
	}
	return NULL;
}


