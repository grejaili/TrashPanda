// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Perception/AISense_Sight.h"
#include "Player/Chip.h"
#include "EnemyAIController.h"
#include "AI/Enemy.h"
#include "Enemy.h"
#include "BTService_DistanceCheck.h"




void UBTService_DistanceCheck::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	//this is the pawn
	Pawn = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());


	AChip* Target = Cast<AChip>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TEXT("Player")));
	if (Target)
	{
		float aux = CheckDistance(Target->GetActorLocation(), Pawn->GetActorLocation());

		OwnerComp.GetBlackboardComponent()->SetValueAsFloat(TEXT("AttackDistance"), aux);

	}
	

}



float UBTService_DistanceCheck::CheckDistance(FVector Enemy, FVector Self)
{
	return  FVector::Dist(Enemy, Self);
}
