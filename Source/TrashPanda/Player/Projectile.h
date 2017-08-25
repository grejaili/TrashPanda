// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TRASHPANDA_API AProjectile : public AActor
{
	GENERATED_BODY()
public:

	// Sets default values for this actor's properties
	AProjectile(const class FObjectInitializer& ObjectInitializer);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	void Direction(const FVector& ShootDirection);



	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditDefaultsOnly)
		class UCapsuleComponent* Collider;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly)
		float Speed;

	FVector direcao;

	USphereComponent* CollisionComp;


};
