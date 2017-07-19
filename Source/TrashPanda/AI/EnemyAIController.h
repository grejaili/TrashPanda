// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "AIController.h"
#include "Enemy.h"
#include "EnemyAIController.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API AEnemyAIController : public AAIController
{
<<<<<<< HEAD

	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;
	
	
	// ATTACK FUNCTIONS----------
	void AttackCommand();
	void AttackHeavy();



public:
	FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);




protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;
	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;

	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
	AEnemy* Pawn;

	UPROPERTY(VisibleAnywhere)
	FVector NextLocation;
=======

	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;
	void AttackBasic();

protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;



	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;
>>>>>>> master

public:
	FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);

<<<<<<< HEAD
	friend class UBTTask_BlackboardBase;
=======


protected:
	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;


	void CalculateRandomPos();
>>>>>>> master

};
