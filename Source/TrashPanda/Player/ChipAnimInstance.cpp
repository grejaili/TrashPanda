// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Chip.h"
#include "ChipAnimInstance.h"




void UChipAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	/*
	Super::NativeUpdateAnimation(DeltaSeconds);

	AChip* OwningPawn = Cast<AChip>(TryGetPawnOwner());
	if (OwningPawn)
	{
		Speed = OwningPawn->GetVelocity().Size();
		bisLightAttackingAnim = OwningPawn->GetIsLightAttacking();

	}
	*/
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

void UChipAnimInstance::Attack()
{
	if (MeleeAttackMontage)
	{
		FName CurrentSection = Montage_GetCurrentSection(MeleeAttackMontage);

		
		if (CurrentSection.IsNone())													// If no current section of the montage is playing, start the montage
		{
			Montage_Play(MeleeAttackMontage);											// Play first attack
		}
		else if (CurrentSection.IsEqual("FirstAttack") && bAcceptsSecondAttackInput)	// If First Attack section of montage is playing AND is bAcceptsSecondAttackInput == true
		{
			Montage_JumpToSection(FName("SecondAttack"), MeleeAttackMontage);			// Play Second combo attack
		}
		else if (CurrentSection.IsEqual("SecondAttack") && bAcceptsThirdAttackInput)	// If Second attack section of montage AND bAcceptsThirdAttackInput == true
		{
			Montage_JumpToSection(FName("ThirdAttack"), MeleeAttackMontage);			// Play third combo attack
		}
		else if (CurrentSection.IsEqual("ThirdAttack") && bAcceptsFourthAttackInput)	// If third attack section of montage AND bAcceptsfourthAttackInput == true
		{
			Montage_JumpToSection(FName("FourthAttack"), MeleeAttackMontage);			// Play fourth attack anim
		}

	}
}

void UChipAnimInstance::AnimNotify_DamageON()
{
	
}

void UChipAnimInstance::AnimNotify_DamageOFF()
{

}

bool UChipAnimInstance::getbIsAttacking()
{
	//return bisLightAttackingAnim;
	return true;
}
