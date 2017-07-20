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
<<<<<<< HEAD
<<<<<<< HEAD

	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;
	void AttackBasic();

protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;



	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;
=======
=======
>>>>>>> AI-Master
=======
>>>>>>> origin/AI-Master


	GENERATED_BODY()

public:
	virtual void Possess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;
<<<<<<< HEAD
<<<<<<< HEAD
	
	
=======
	
	
>>>>>>> AI-Master
=======
	
	
>>>>>>> origin/AI-Master
	// ATTACK FUNCTIONS----------
	void AttackCommand();



public:
	FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);
<<<<<<< HEAD
<<<<<<< HEAD




protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;
	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;

	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
	AEnemy* Pawn;

	UPROPERTY(VisibleAnywhere)
	FVector NextLocation;
>>>>>>> AI-Master

public:
	FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	static ETeamAttitude::Type GetAttitudeTowards(FGenericTeamId TeamA, FGenericTeamId TeamB);

<<<<<<< HEAD


protected:
	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;


	void CalculateRandomPos();
=======
>>>>>>> AI-Master
=======
=======
>>>>>>> origin/AI-Master




protected:
	UPROPERTY(EditDefaultsOnly)
		class UBehaviorTree* BehaviorTreeAsset;
	UPROPERTY(EditDefaultsOnly)
		FGenericTeamId TeamId;

	virtual ETeamAttitude::Type GetAttitudeTowardsPlayer(const AActor& Other) const;
	AEnemy* Pawn;

	UPROPERTY(VisibleAnywhere)
	FVector NextLocation;


<<<<<<< HEAD
>>>>>>> AI-Master
=======
>>>>>>> origin/AI-Master

};
