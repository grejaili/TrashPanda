#pragma once

#include "GameFramework/Character.h"
#include "Ai/Enemy.h"
#include "Projectile.h"
#include "Chip.generated.h"

UCLASS()
class TRASHPANDA_API AChip : public ACharacter
{
	GENERATED_BODY()

public:
	AChip();
	virtual void Tick(float DeltaSeconds) override;


#pragma
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, Category = Camera)
		float TurnRate;

	void CameraYAxisMovement(float Rate);
	void CameraXAxisMovement(float Rate);

#pragma endregion Camera CONTROLLING FUNCTIONS AND VARIABLES


	
#pragma
	
	// Idle
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Anims")
		UAnimSequence * IdleAnim;

	// Run
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Anims")
		UAnimSequence * RunAnim;

	// Dodge
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Anims")
		UAnimSequence * DodgeAnim;

	// Attack 1
	//UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Anims")
	//	UAnimSequence * AttackAnim;

	// Strafe
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Anims")
		UAnimSequence * StrafeAnim;

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


#pragma endregion Animations


#pragma 
	//apply the animation funtion here o

	void Attack();
	void Shoot();
	void DodgeLeft();

	// Apply in PlayerController class

	void PlayRunAnim();
	void PlayStrafeAnim();
	void PlayIdleAnim();

	// Loop variable for anim
	bool bLoop;

	// Setter for PlayerController class
	bool SetbLoop(bool);

	// Getter for PlayerController class
	bool GetbLoop();

	//shooting mechanics
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileClass;
		


#pragma endregion Combat REGION




};