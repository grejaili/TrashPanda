// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Chip.h"
#include "Items/BaseWeapon.h"
#include "ChipAnimInstance.h"

void UChipAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		// Update movement speed
		Speed = OwningPawn->GetVelocity().Size();

		//Update if player is light attacking
		bIsLightAttackingAnim = OwningPawn->GetIsLightAttacking();

		//Update if player is Heavy attacking
		bIsHeavyAttackingAnim = OwningPawn->GetIsHeavyAttacking();
	}
}

void UChipAnimInstance::isAttacking(bool onOff)
{
	//if (onOff == true)
	//{
	//	bisAttackingAnim = true;
	//}
	//else if (onOff == false)
	//{
	//	bisAttackingAnim = false;
	//}
}

void UChipAnimInstance::AnimNotify_DamageON()
{
	bCanDamage = true;
}

void UChipAnimInstance::AnimNotify_DamageOFF()
{
	bCanDamage = false;
}

bool UChipAnimInstance::GetCanDamage()
{
	return bCanDamage;
}

bool UChipAnimInstance::getbIsLightAttacking()
{
	return bIsLightAttackingAnim;
}

bool UChipAnimInstance::getbIsHeavyAttacking()
{
	return bIsHeavyAttackingAnim;
}
