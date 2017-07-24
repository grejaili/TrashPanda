// All Rights Reserved for Students Graduating TFS Summer 2017

#pragma once

#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "Test1Controller.generated.h"

/**
 *
 */
UCLASS()
class TRASHPANDA_API ATest1Controller : public APlayerController
{
	GENERATED_BODY()

public:
	ATest1Controller();

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

protected:


#pragma region 
	// PLAYER CONTROLL FUNCTIONS
	void MoveForward(float Value);
	void MoveSides(float Value);
	FTimerHandle DodgeTimerHandler;
#pragma endregion Controll Functions ---------------------------------------------------------

#pragma
	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	void CameraYControll(float Rate);
	void CameraXControll(float Rate);

	class AChip *ChipRef = nullptr;

#pragma endregion Camera Controlls--------------------------------------------------------------------------




#pragma 

	void LightAttackPressed();
	void ShootPressed();
#pragma endregion Combat Functions -----------------------------------------------------
	void DoubleClick();

	FTimerHandle DodgeLeftTimeHandler;
	bool bIsPossibleDodgeLeft;





};
