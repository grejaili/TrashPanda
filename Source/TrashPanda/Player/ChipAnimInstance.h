// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "Animation/AnimInstance.h"
#include "ChipAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TRASHPANDA_API UChipAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION()
	void isAttacking(bool onOff);

	UFUNCTION()
		bool getbIsLightAttacking();

	UFUNCTION()
		bool getbIsHeavyAttacking();

	UFUNCTION()
		bool GetCanDamage();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsLightAttackingAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsHeavyAttackingAnim;

	//Variable thats needed in BaseWeapon class to determine whether or not collision will apply damage
	bool bCanDamage;

protected:
	UFUNCTION()
		void AnimNotify_DamageON();
	
	UFUNCTION()
		void AnimNotify_DamageOFF();


};
