// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Chip.h"
#include "ChipAnimInstance.h"




void UChipAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		Speed = OwningPawn->GetVelocity().Size();
		Direction = OwningPawn->AnimDirectionRight;
		ClickingW = OwningPawn->movingFront;
		IsDodgding = OwningPawn->Dodgding;
		IsBackDodgding = OwningPawn->BackDodge;
	}
}

void UChipAnimInstance::isAttacking(bool onOff)
{

}

bool UChipAnimInstance::getbIsAttacking()
{
	//return bisLightAttackingAnim;
	return true;
}

void UChipAnimInstance::AnimNotify_DamageON()
{
	
}

void UChipAnimInstance::AnimNotify_DamageOFF()
{

}




void UChipAnimInstance::AnimNotify_Dodge_OFF()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("DODGE Variable"));
		OwningPawn->Dodgding = false;
	}
}


void UChipAnimInstance::AnimNotify_BackDodged_OFF()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningPawn->BackDodge = false;
	}
}



