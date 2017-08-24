// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "MoveWithAbort.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API UMoveWithAbort : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;




};
