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
	if (GetGlobalCD() == true)
	{
		SetGlobalCD();
		UE_LOG(LogTemp, Warning, TEXT("SPAWN LITTLE BITCH"));
	}

}


bool ASpawnPoint::GetGlobalCD()
{
	
	if (GetWorld()->GetTimerManager().GetTimerRemaining(RespawnTimeHandler) <= 0)
	{
		return true;
	}

	else
	{
	return false;
	}

}


void ASpawnPoint::SetGlobalCD()
{
	GetWorld()->GetTimerManager().ClearTimer(RespawnTimeHandler);
	GetWorld()->GetTimerManager().SetTimer(RespawnTimeHandler, BaseGlobalCD, false);
}
