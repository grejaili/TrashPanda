// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "AI/Enemy.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile(const class FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);


	CollisionComp = ObjectInitializer.CreateOptionalDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->SetCollisionProfileName("Projectile");


	if (CollisionComp != NULL)
	{
		//CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	//	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
		//CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);

	}

	//Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	//Collider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//Collider->SetCollisionProfileName("Projectile");


	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;

}



// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Display, TEXT("WE ARE moving"));
	//
	ProjectileMovement->Velocity = direcao * 1000.f;


}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Display, TEXT("WE ARE moving"));
	ProjectileMovement->Velocity = direcao * 1000.f;
}

void AProjectile::Direction(const FVector& ShootDirection)
{
	direcao = ShootDirection;
}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Enemy"))
	{
		UE_LOG(LogTemp, Display, TEXT("WE ARE IN THE BEAM"));
		APlayerController* PlayerController = NULL;
		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);
		const float DamageAmount = 1.0f;
		OtherActor->TakeDamage(DamageAmount, DamageEvent, PlayerController, this);
	}
}
