#include "TrashPanda.h"
#include "Items/BaseItem.h"
#include "Player/InventoryComponent.h"
#include "Items/IMaterial.h"
#include "Player/InventoryWidget.h"
#include "Items/IConsumable.h"
#include "Player/ChipAnimInstance.h"
#include "UI/CharacterWidgetSwitcher.h"
#include "Player/Chip.h"
#include "UI/ChipHUDWidget.h"
#include "UI/PauseWidget.h"
#include "EngineUtils.h"
#include "Projectile.h"
#include "Items/BaseWeapon.h"
#include "TrashPandaGameModeBase.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 

// Sets default values
AChip::AChip()
{


	PlayerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	PlayerSphere->SetupAttachment(RootComponent);
	PlayerSphere->InitSphereRadius(40.0f);
	PlayerSphere->SetCollisionProfileName(TEXT("PAWN"));


	AnimInstance = GetMesh()->GetAnimInstance();

	///CAMERA SETTINGS IS SUPOSSE TO BE IN THE PAWN
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

												   //INITILIZING
	//static ConstructorHelpers::FObjectFinder<UBlueprint> BulletBP(TEXT("Blueprint'/Game/Player/Projectile.Projectile'"));

	//ProjectileClass = (UClass*)BulletBP.Object->GeneratedClass;

	//hand_rSocket



}


// Called every frame
void AChip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//I might need to implement


}

#pragma region 

void AChip::CameraYAxisMovement(float Rate)
{

	AddControllerPitchInput(Rate*TurnRate  * GetWorld()->GetDeltaSeconds());
}

void AChip::CameraXAxisMovement(float Rate)
{
	AddControllerYawInput(Rate *TurnRate * GetWorld()->GetDeltaSeconds());
}


#pragma endregion Camera controlling region

#pragma


//		ATTACKKKKKKKKKKK------------------------------
void AChip::LightAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, "Attack");
	MeleeWeapon->SetCollision(true);
	IsAttacking = true;

	// combo timing will be placed here


}

void AChip::TurnOffCollider()
{
	MeleeWeapon->SetCollision(false);

}


void AChip::Shoot()
{
	
	FVector PlayerPos = this->GetActorLocation();
	UWorld* const World = GetWorld();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		
	if (World)
	{
		if (ProjectileClass != NULL)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, PlayerPos, YawRotation);
			if (Projectile)
			{
				// find launch direction
//				FVector const Direction = MuzzleRotation.Vector();
				Projectile->Direction(Direction);
				Projectile->Speed = 1000 ;

			}
		}

	}


}
#pragma endregion Combat Region

void AChip::DodgeLeft()
{
	DodgdingLeft = true;
	//PlayerSphere->AddForce(FVector(100, 0, 0));
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//this->AddMovementInput(Direction, );
	this->LaunchCharacter(Direction * -DodgeDistance, true, true);


}

void AChip::DodgeRight()
{

	bool DodgingRight = true;
	//PlayerSphere->AddForce(FVector(100, 0, 0));
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//this->AddMovementInput(Direction, );
	this->LaunchCharacter(Direction * DodgeDistance, true, true);
}

void AChip::DodgeBack()
{
	BackDodge = true;
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//this->AddMovementInput(Direction, );
	this->LaunchCharacter(Direction * -DodgeDistance, true, true);
	//	UE_LOG(LogTemp, Warning, TEXT("Dodge Back"));
}



void  AChip::RightStrafe(float Value)
{
	if (Value == 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Left Strafe"));
		AnimDirectionRight = false;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Right Strafe"));
		AnimDirectionRight = true;
	}
}

void AChip::IsW(float Value)
{

	if (Value > 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Left Strafe"));
		movingFront = true;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Right Strafe"));
		movingFront = false;
	}
}



void AChip::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	// instantiate the melee weapon if a bp was selected
	if (Weapon)
	{
		MeleeWeapon = GetWorld()->SpawnActor<ABaseWeapon>(Weapon, FVector(0), FRotator(0));
		if (MeleeWeapon)
		{
			//MeleeWeapon->WeaponHolder = this;
			const USkeletalMeshSocket *socket = GetMesh()->GetSocketByName("hand_rSocket");
			socket->AttachActor(MeleeWeapon, GetMesh());  // <-- attempt to put a sword in the right hand
		}

	}
}

void AChip::KnockItBack
()
{
	MeleeWeapon->KnockIt = true;

}