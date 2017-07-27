#include "TrashPanda.h"
#include "Enemy.h"
#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 


// Sets default values
AEnemy::AEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sphere component to react to physics.
	USphereComponent* EnemySphere = CreateDefaultSubobject<USphereComponent>(TEXT("ROOT COMPONENT"));
	EnemySphere->SetupAttachment(RootComponent);
	EnemySphere->InitSphereRadius(40.0f);
	EnemySphere->SetCollisionProfileName(TEXT("PAWN"));


}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//GetWorld()->GetTimerManager().SetTimer(AttackTimerHandler, GeneralAttackCD, false);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector AEnemy::NextPos()
{
	float TmpRandom = FMath::RandRange(0, 360);
	float t = FMath::DegreesToRadians(TmpRandom);


	float x = MoveRadius*cos(t) + this->GetActorLocation().X;
	float y = MoveRadius*sin(t) + this->GetActorLocation().X;


	FVector RandomPos;
	RandomPos.X = x;
	RandomPos.Z = 0;
	RandomPos.Y = y;
	return  RandomPos;
}

// COMBAT MECHANICS AND FUNCTIONS


//GLOBAL CD FOR HABILITES
bool AEnemy::GetGlobalCD()
{
	if (GetWorld()->GetTimerManager().GetTimerRemaining(AttackTimerHandler) <= 0)
	{
		bIsPossibletoAttack = true;
	}

	else
	{
		bIsPossibletoAttack = false;
	}


	return bIsPossibletoAttack;
}


void AEnemy::SetGlobalCD()
{
	GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandler);
	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandler, BaseGlobalCD, false);
}


void AEnemy::SetGlobalCD(float CD)
{
	check (CD < BaseGlobalCD)
	
		GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandler);
		GetWorld()->GetTimerManager().SetTimer(AttackTimerHandler, CD, false);
}



//Light attack here too
void AEnemy::AttackMelle(UObject* CPlayer)
{


	if (GetGlobalCD())
	{
	//	print("Attack  Melle");
		AttackHappening = true;
		//place the animations calls here

		SetGlobalCD();
	}



}

void AEnemy::AttackHeavy(UObject* CPlayer)
{
	GetGlobalCD();


	SetGlobalCD();
}








float AEnemy::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	// Call the base class - this will tell us how much damage to apply  
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (Health <= 0.f)
		{
			SetLifeSpan(0.001f);
		}
	}

	return ActualDamage;
}