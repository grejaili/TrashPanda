#pragma once

#include "GameFramework/Character.h"
#include "Ai/Enemy.h"
<<<<<<< HEAD
=======
#include "Projectile.h"
>>>>>>> origin/AI-Master
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
	//apply the animation funtion here o

<<<<<<< HEAD
	void AttackInput();
=======
	void LightAttack();
	void Shoot();


	//shooting mechanics
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileClass;
		

>>>>>>> origin/AI-Master

#pragma endregion Combat REGION




};