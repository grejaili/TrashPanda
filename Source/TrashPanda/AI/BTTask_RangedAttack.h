// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class TRASHPANDA_API UBTTask_RangedAttack : public UBTTaskNode
{
	GENERATED_BODY()
	
public :
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;



	friend class AAIController;

	
	
	
};
