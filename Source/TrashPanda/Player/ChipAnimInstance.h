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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  Direction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  ClickingW;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bisLightAttackingAnim;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  IsDodgding;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  IsBackDodgding;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  IsAttacking;
protected:
	UFUNCTION()
		void AnimNotify_AttackFinish();
	UFUNCTION()
		void AnimNotify_Dodge_OFF();
	UFUNCTION()
		void AnimNotify_BackDodged_OFF();
};