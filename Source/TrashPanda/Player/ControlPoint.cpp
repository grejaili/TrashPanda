// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "AI/Enemy.h"
#include "ControlPoint.h"


// Sets default values
AControlPoint::AControlPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	//Collider->On

}

// Called when the game starts or when spawned
void AControlPoint::BeginPlay()
{
	Super::BeginPlay();
	SetGlobalCD();
	for (TObjectIterator<ASpawnPoint> Itr; Itr; ++Itr)
	{

		ASpawnPoint *Component = *Itr;
		SpawnPoint = Component->GetActorLocation();

	}

	for (TObjectIterator<ASpawnPoint2> Itr; Itr; ++Itr)
	{

		ASpawnPoint2 *Component = *Itr;
		SpawnPoint2 = Component->GetActorLocation();

	}


}

// Called every frame
void AControlPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetGlobalCD())
	{
		//AddScore();
	}

}

bool AControlPoint::GetGlobalCD()
{
	if (GetWorld()->GetTimerManager().GetTimerRemaining(TimeHandler) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void AControlPoint::SetGlobalCD()
{
	GetWorld()->GetTimerManager().ClearTimer(TimeHandler);
	GetWorld()->GetTimerManager().SetTimer(TimeHandler, 3, false);
}

void AControlPoint::AddScore()
{
	GetWorld()->SpawnActor<AEnemy>(EnemyClass, SpawnPoint, this->GetActorRotation());


}


void AControlPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		WaveMechanics(Cast<AChip>(OtherActor)->WaveNumber);
		Cast<AChip>(OtherActor)->WaveNumber++;
	}

}


void  AControlPoint::OnOverlapEnds(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{



}


void AControlPoint::WaveMechanics(int aux)
{

	if (PlayerPassed == false)
	{
		if (aux >= 1)
		{
			PlayerPassed = true;
			int32 aux = 0;
			while (aux < 30)
			{
				aux++;
				PlayerPassed = true;
				SpawnPoint.X = SpawnPoint.X + FMath::RandRange(-350, 350);
				SpawnPoint.Z = SpawnPoint.Z + FMath::RandRange(-350, 350);
				SpawnPoint.Y = SpawnPoint.Y + FMath::RandRange(-350, 350);

				AEnemy* enemy = GetWorld()->SpawnActor<AEnemy>(EnemyClass, SpawnPoint, this->GetActorRotation());

			}


		}

		if (aux == 0)
		{
			int32 aux = 0;
			while (aux < 20)
			{
				aux++;
				PlayerPassed = true;
				SpawnPoint.X = SpawnPoint.X + FMath::RandRange(-350, 350);
				SpawnPoint.Z = SpawnPoint.Z + FMath::RandRange(-350, 350);
				SpawnPoint.Y = SpawnPoint.Y + FMath::RandRange(-350, 350);

				AEnemy* enemy = GetWorld()->SpawnActor<AEnemy>(EnemyClass, SpawnPoint, this->GetActorRotation());

			}

		}
	}


}