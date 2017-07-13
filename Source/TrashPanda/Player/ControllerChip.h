// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "GameFramework/PlayerController.h"
#include "Chip.h"
#include "ControllerChip.generated.h"

/**
 * 
 */
UCLASS()
class TRASHPANDA_API AControllerChip : public APlayerController
{
	GENERATED_BODY()

public :

		virtual void Possess(APawn* InPawn) override;

		virtual void Tick(float DeltaSconds) override;

		virtual void SetupInputComponent() override;

	

	AChip* Pawn;

		
	//void Interact();
	void LightAttackPressed();
	void LightAttackReleased();
	void HeavyAttackPressed();
	void HeavyAttackReleased();
	void Dodge();
	void Rabid();

	void OpenInv();
	void OpenCharPanel();

	void ReadInv();

	void PauseGame();

protected:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);
	

protected:
	bool bisRabid;
	bool bisLightAttacking;
	bool bisHeavyAttacking;
	int32 Damage;
	int32 DamageReduction;
	int32 Speed;
	int32 DodgeDistance;

	int32 CritChance;
	int32 CritModifier;
};
