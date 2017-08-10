// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "AI/Enemy.h"
#include "BaseWeapon.h"


// Sets default values
ABaseWeapon::ABaseWeapon(const class FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CollisionComp = ObjectInitializer.CreateOptionalDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));

	if (CollisionComp != NULL)
	{
		CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
		CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);

	}
	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);





}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Tags.Contains("Enemy"))
	{
		AEnemy* DamagedActor = Cast<AEnemy>(OtherActor);

		UE_LOG(LogTemp, Display, TEXT("WE HIT IT"))

			APlayerController* PlayerController = NULL;
		TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());
		FDamageEvent DamageEvent(ValidDamageTypeClass);
		const float DamageAmount = 1.0f;
		OtherActor->TakeDamage(DamageAmount, DamageEvent, PlayerController, this);
		if (Particle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, Particle, GetActorLocation(), GetActorRotation());

		}

		//OtherComp->AddForce (  FVector (0.0f, 0.0f, 2000));

		//this->AddMovementInput(Direction, );
		

		if (KnockIt == true)
		{
			const FRotator Rotation = DamagedActor->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			DamagedActor->LaunchCharacter(Direction * -5000, true, true);
			KnockIt = false;
		}
		


	}
}

void ABaseWeapon::SetCollision(bool OnOff)
{

	UE_LOG(LogTemp, Display, TEXT("collision off"));
	this->SetActorEnableCollision(OnOff);
}


