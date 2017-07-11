
#pragma once

#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class TRASHPANDA_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

	//UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	//class Inventory* Inventory;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = Behavior)
		class UBehaviorTree* EnemyBehavior;

	FVector NextPos();

	void AttackMechanics(UObject* Player);




protected:

	UPROPERTY(EditAnyWhere, Category = Stats)
		uint32 Health;

	UPROPERTY(EditAnyWhere, Category = Stats)
		uint32 DamageReduction;

	UPROPERTY(EditAnyWhere, Category = Stats)
		uint32 Damage;

	UPROPERTY(EditAnywhere, Category = AIBehavior)
		uint32 MoveRadius;
	// ATTACK OPTIONS
	UPROPERTY(EditAnyWhere, Category = AIBehavior)
		uint32 MelleAttackRange;
	UPROPERTY(EditAnywhere, Category = AIBehavior)
		uint32 ChargeRange;

	FTimerHandle AttackTimerHandler;
	bool bIsPossibletoAttack = true;

	UPROPERTY(EditAnywhere, Category = AIBehavior)
		float GlobalCD;


	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser);
	

	bool AttackHappening;

};