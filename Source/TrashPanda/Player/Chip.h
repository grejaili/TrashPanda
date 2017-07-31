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

	UPROPERTY(EditDefaultsOnly)
		USphereComponent* PlayerSphere;

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
	//apply the animation funtion here o
	
	void LightAttack();
	void Shoot();
	void DodgeLeft();
	void DodgeRight();
	void DodgeBack();


	void IsW(float Value);
	bool movingFront;

	bool Dodgding = false;
	bool BackDodge = false;
	
	class UAnimInstance* AnimInstance;

	UPROPERTY( EditAnywhere, Category = Dodge)
		float DodgeDistance;


	void  RightStrafe(float Value);
	bool AnimDirectionRight = false;
	//shooting mechanics
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileClass;



#pragma endregion Combat REGION




};