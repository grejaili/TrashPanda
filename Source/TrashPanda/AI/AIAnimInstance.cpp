// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Enemy.h"
#include "Player/Chip.h"
#include "AIAnimInstance.h"



void UAIAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AEnemy* OwningPawn = Cast<AEnemy>(TryGetPawnOwner());
	if (OwningPawn)
	{
		Speed = OwningPawn->GetVelocity().Size();
		bIsAttacking = OwningPawn->bIsAttacking;
	}



}



void UAIAnimInstance::AnimNotify_AttackFinish()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningPawn->IsAttacking = false;
	}
}