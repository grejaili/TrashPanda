 // All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy.h"
#include "BTTask_HeavyAttack.generated.h"

/**
 * 
 */
UCLASS()
class TRASHPANDA_API UBTTask_HeavyAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	

public :
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	friend class AAIController;
	
	
	
};
