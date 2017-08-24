// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPlayer.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API UBTTask_FindPlayer : public UBTTaskNode
{
	GENERATED_BODY()

public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


	virtual AActor*  FindTarget(class UAIPerceptionComponent* PerceptionComponent, class AChip* OwningCharacter, UBehaviorTreeComponent& OwnerComp);

	friend class AAIController;



};

