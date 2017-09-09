
// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "GameFramework/Actor.h"
#include "ControlPoint.generated.h"

UCLASS()
class TRASHPANDA_API AControlPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlPoint();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly, Category = Timer)
		float  MaxScore;
		
	UPROPERTY(BlueprintReadOnly, Category = Timer)
		float Score;


	UPROPERTY(EditDefaultsOnly)
		class UCapsuleComponent* Collider;

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;


	void AddScore();

	FTimerHandle TimeHandler;
	void SetGlobalCD();
	bool GetGlobalCD();
	
	bool AddPoints = false;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UFUNCTION()
		void OnOverlapEnds(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
