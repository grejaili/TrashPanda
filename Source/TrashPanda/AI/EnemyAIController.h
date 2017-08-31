// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "AIController.h"
#include "Enemy.h"
#include "Player/Chip.h"
#include "EnemyAIController.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API AEnemyAIController : public AAIController
{


	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;
	
	
	// ATTACK FUNCTIONS----------
	void AttackCommand(AChip* Player);



public:
	FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);

	FVector Goal;


protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;
	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;

	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
	AEnemy* Pawn;

	UPROPERTY(VisibleAnywhere)
	FVector NextLocation;

	void RandomMove();

	

};
