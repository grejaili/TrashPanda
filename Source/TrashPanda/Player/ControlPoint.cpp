// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
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


}

// Called when the game starts or when spawned
void AControlPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool AControlPoint::GetGlobalCD()
{
	if (GetWorld()->GetTimerManager().GetTimerRemaining(TimeHandler) <= 0)
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
	GetWorld()->GetTimerManager().SetTimer(TimeHandler, 1, false);
}


void AControlPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorGetDistanceToCollision("Player"))
	{
		if (GetGlobalCD())
		{

		}

	}

}
