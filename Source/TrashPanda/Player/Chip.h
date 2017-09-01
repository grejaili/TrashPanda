#pragma once

#include "GameFramework/Character.h"
#include "Ai/Enemy.h"
#include "Player/Projectile.h"
#include "Items/BaseWeapon.h"
#include "Chip.generated.h"

UCLASS()
class TRASHPANDA_API AChip : public ACharacter
{
	GENERATED_BODY()

public:
	AChip();
	virtual void Tick(float DeltaSeconds) override;
	virtual void PostInitializeComponents();

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

	bool DodgdingLeft = false;
	bool DodgingRight = false;
	bool Shooting = false;

	bool BackDodge = false;
	bool IsAttacking = false;
	class UAnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, Category = Dodge)
		float DodgeDistance;
	UPROPERTY(EditAnywhere, Category = Dodge)
		float BasicLaunch;

	void RightStrafe(float Value);
	bool GoingLeft = false;
	bool GoingRight = false;
	//shooting mechanics
	
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABaseWeapon> Weapon;

	ABaseWeapon* MeleeWeapon;

#pragma endregion Combat REGION

public:

	void TurnOffCollider();

	void KnockItBack();
	UPROPERTY(EditAnywhere, Category = Projectile)
	FVector MuzzleOffset;

	void Launch();
	void LaunchBasic();
};