// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "SpawnPoint.h"


// Sets default values
ASpawnPoint::ASpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


bool ASpawnPoint::GetGlobalCD()
{
	if (GetWorld()->GetTimerManager().GetTimerRemaining(AttackTimerHandler) <= 5)
	{
		bIsPossibletoAttack = true;
	}

	else
	{
		bIsPossibletoAttack = false;
	}


	return bIsPossibletoAttack;
}


void ASpawnPoint::SetGlobalCD()
{
	GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandler);
	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandler, BaseGlobalCD, false);
}
