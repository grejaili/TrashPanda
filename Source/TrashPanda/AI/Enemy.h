
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

	FVector CalculateRandomPos();

	void AttackMechanics();


protected:

	UPROPERTY(VisibleAnywhere)
		uint32 Health;

	UPROPERTY(VisibleAnywhere)
		uint32 DamageReduction;

	UPROPERTY(VisibleAnywhere)
		uint32 Damage;

	UPROPERTY(EditAnywhere, Category = Randomization)
	uint32 MaxRandomization;



};