// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "BehaviorTree/BTService.h"
#include "Enemy.h"
#include "Player/Chip.h"
#include "BTService_DistanceCheck.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API UBTService_DistanceCheck : public UBTService
{
	GENERATED_BODY()


public :
	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	float CheckDistance(FVector Enemy, FVector Self);

protected:
	AEnemy* Pawn;


};
