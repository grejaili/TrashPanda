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
		
		Left = OwningPawn->GoingLeft;
		Right = OwningPawn->GoingRight;


	

		ClickingW = OwningPawn->movingFront;
		IsDodgdingLeft = OwningPawn->DodgdingLeft ;
		IsDodgdingRight = OwningPawn->DodgingRight;
		DodgeRight = OwningPawn->DodgingRight;
		IsShooting = OwningPawn->Shooting;

		IsBackDodgding = OwningPawn->BackDodge;
		IsAttacking = OwningPawn->IsAttacking;



		if (IsAttacking == false)
		{
			Combo = 0;
			isResetANim = false;
		}

	}


}


void UChipAnimInstance::AnimNotify_AttackFinish()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		Combo += 1;



		if (Combo == 3)
		{
			Combo = 0;
			
			isResetANim = true;
		}
		else
		{
			isResetANim = false;
		}
	
	}
}
void UChipAnimInstance::AnimNotify_ComboFinish()
{
	// dont use this
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		isResetANim = false;
		OwningPawn->KnockItBack();
	}
}


void UChipAnimInstance::AnimNotify_Dodge_OFF()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("DODGE Variable"));
		OwningPawn->DodgdingLeft = false;
		OwningPawn->DodgingRight = false;
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


void UChipAnimInstance::AnimNotify_ShootingOver()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningPawn->Shooting = false;
	}
}

void UChipAnimInstance::AnimNotify_Launch()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningPawn->Launch();
	}
}

void UChipAnimInstance::AnimNotify_LaunchBasicAttack()
{
	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		OwningPawn->LaunchBasic();
	}
}