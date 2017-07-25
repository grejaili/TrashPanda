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
		bool getbIsAttacking();

	// Attack montage (Combo) 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimMontage")
		UAnimMontage* MeleeAttackMontage;

	// True if Chip can preform attack 2
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AnimMontage")
		bool bAcceptsSecondAttackInput;

	// True if Chip can preform attack 3
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AnimMontage")
		bool bAcceptsThirdAttackInput;

	// True if Chip can preform attack 4
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AnimMontage")
		bool bAcceptsFourthAttackInput;

	void Attack();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bisLightAttackingAnim;

protected:
	UFUNCTION()
		void AnimNotify_DamageON();
	
	UFUNCTION()
		void AnimNotify_DamageOFF();




};
