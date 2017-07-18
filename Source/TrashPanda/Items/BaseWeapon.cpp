// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "AI/Enemy.h"
#include "Player/ChipAnimInstance.h"
#include "Player/Chip.h"
#include "BaseWeapon.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->CanCharacterStepUp(false);
	Collider->SetCapsuleSize(9.f, 60.f);
	RootComponent = Collider;
	
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	Collider->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);

	//Set default light attack damage number
	LightDamage = 5;

}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
}

void ABaseWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UWorld* WorldRef = GetWorld();
	AEnemy* EnemyRef = Cast<AEnemy>(OtherActor);
	AChip* PlayerRef = Cast<AChip>(WorldRef->GetFirstPlayerController()->GetCharacter());
	
	//Access Chips Anim instance to get bCanDamage variable **CRASHES GAME**
	//UChipAnimInstance* AnimInstance = Cast<UChipAnimInstance>(PlayerRef->GetMesh()->GetAnimInstance);

	////Will only apply damage if bCanDamage is set to true which is set in DamageON in Chips Anim Instance
	//if (AnimInstance->GetCanDamage() == true)
	//{
	//	//Checks to make sure it does not run if collides with self or player
	//	if (OtherActor && (OtherActor != this && OtherActor != PlayerRef) && OtherComp)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("Sword Has has collided with %s"), *OtherActor->GetName());

	//		//TODO Apply Damage
	//		EnemyRef->Health -= LightDamage;
	//	}
	//}
	
}

void ABaseWeapon::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->Tags.Contains("Enemy"))
	{

	}
}



