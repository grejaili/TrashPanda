// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

UENUM(BlueprintType, Category = "WeaponType")
enum WeaponType
{
	Slashing, Bludgeoning
};

#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class TRASHPANDA_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeapon(const class FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

protected:

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditDefaultsOnly)
		class UCapsuleComponent* Collider;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Weapon)
		float overlapRadius;

	USphereComponent* CollisionComp;

	
protected:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SetCollision();

};