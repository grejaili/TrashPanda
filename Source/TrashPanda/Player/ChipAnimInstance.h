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
protected:



	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool  ClickingW;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bisLightAttackingAnim;

protected:
	UFUNCTION()
		void AnimNotify_DamageON();

	UFUNCTION()
		void AnimNotify_DamageOFF();



};
