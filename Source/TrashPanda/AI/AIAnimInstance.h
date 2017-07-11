// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TRASHPANDA_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public :
	virtual void NativeUpdateAnimation(float DeltaSceonds) override;

	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool	bIsAttacking;


	
};
