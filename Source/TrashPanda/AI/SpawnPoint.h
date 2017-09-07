// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "EnemyAIController.h"
#include "SpawnPoint.generated.h"

UCLASS()
class TRASHPANDA_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

void SetGlobalCD();
 bool GetGlobalCD();
 FTimerHandle RespawnTimeHandler;

 UPROPERTY(EditAnywhere, Category = SpawnParams)
	 float BaseGlobalCD;




 UPROPERTY(EditDefaultsOnly, Category = SpawnParams)
	 TSubclassOf<AEnemy> EnemyClass;

 UPROPERTY(EditDefaultsOnly, Category = SpawnParams)
	 TSubclassOf<AEnemyAIController> AIController;

 void SpawnEnemy();

};
