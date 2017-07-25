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

#include "TrashPandaGameModeBase.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 

// Sets default values
AChip::AChip()
{

	//CAMERA SETTINGS IS SUPOSSE TO BE IN THE PAWN
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//INITILIZING
	static ConstructorHelpers::FObjectFinder<UBlueprint> BulletBP(TEXT("Blueprint'/Game/MyProjectile.MyProjectile'"));
	ProjectileClass = (UClass*)BulletBP.Object->GeneratedClass;
	
	// Help find anim locations
	static ConstructorHelpers::FObjectFinder<UAnimSequence> runanim(TEXT("AnimSequence'/Game/Player/ANIM/RunCycle2.RunCycle2'"));
	RunAnim = runanim.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> idleanim(TEXT("AnimSequence'/Game/Player/ANIM/IdleAnim.IdleAnim'"));
	IdleAnim = idleanim.Object;

	//static ConstructorHelpers::FObjectFinder<UAnimSequence> attackanim(TEXT("AnimSequence'/Game/Player/ANIM/AttackComboAnim1.AttackComboAnim1'"));
	//AttackAnim = attackanim.Object;

	static ConstructorHelpers::FObjectFinder<UAnimSequence> dodgeanim(TEXT("AnimSequence'/Game/Player/ANIM/DodgeAnim2.DodgeAnim2'"));
	DodgeAnim = dodgeanim.Object;

	// Set loop default
	bLoop = false;
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

void AChip::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, "Attack");
	//printf("I ATTACKED");
	
	// Get reference to custom anim class
	UChipAnimInstance* AnimInstanceRef = Cast<UChipAnimInstance>(GetMesh()->GetAnimInstance());

	if (AnimInstanceRef)
	{
		AnimInstanceRef->Attack();
	}
}

void AChip::Shoot()
{

	//UWorld* wp = GetWorld();
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, "Shoot");
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass,FVector( GetActorLocation().X+30, GetActorLocation().X + 30, GetActorLocation().X + 30), FRotator::ZeroRotator);


}
#pragma endregion Combat Region

void AChip::DodgeLeft()
{
	UE_LOG(LogTemp, Warning, TEXT("THEREFORE I DODGE"));

	//Play dodge animation, loop = false
	GetMesh()->PlayAnimation(DodgeAnim, false);

}

void AChip::PlayRunAnim()
{
	//Play Run animation, loop = true until player stops moving
	if (bLoop == false)		// Set bLoop to true if false
	{
		bLoop = true;
	}

	GetMesh()->PlayAnimation(RunAnim, bLoop);
}

void AChip::PlayStrafeAnim()
{
	//Play Run animation, loop = true until player stops moving to left or right
	if (bLoop == false)		// Set bLoop to true if false
	{
		bLoop = true;
	}
	GetMesh()->PlayAnimation(StrafeAnim, bLoop);
}

void AChip::PlayIdleAnim()
{
	//Play Idle animation, loop = true until player stops moving to left or right
	if (bLoop == false)		// Set bLoop to true if false
	{
		bLoop = true;
	}
	GetMesh()->PlayAnimation(IdleAnim, bLoop);
}

bool AChip::SetbLoop(bool SetbLoop)
{
	return SetbLoop;
}

bool AChip::GetbLoop()
{
	return bLoop;
}
