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
#include "TrashPandaGameModeBase.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 

// Sets default values
AChip::AChip()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate

	RootComponent->ComponentTags.Add("Player");

	PickupRadius = CreateDefaultSubobject<USphereComponent>(TEXT("PickupRadius"));
	PickupRadius->SetupAttachment(RootComponent);
	PickupRadius->bGenerateOverlapEvents = true;
	PickupRadius->SetSphereRadius(150.0f, true);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	//tags
	RootComponent->ComponentTags.Add("Player");
	Tags.Add("Player");
	this->Tags.Add("Player");
	PickupRadius->ComponentTags.Add("Player");

}

// Called when the game starts or when spawned
void AChip::BeginPlay()
{
	Super::BeginPlay();
	PickupRadius->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	PickupRadius->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);

	AnimInstance = GetMesh()->GetAnimInstance();
	SetPlayerStats(1);

	if (InvWidgetClass)
	{
		InvWidget = CreateWidget<UInventoryWidget>(GetWorld()->GetFirstPlayerController(), InvWidgetClass);
		InvWidget->AddToPlayerScreen();
		InvWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (WidgetSwitcherClass)
	{
		SwitchWidget = CreateWidget<UCharacterWidgetSwitcher>(GetWorld()->GetFirstPlayerController(), WidgetSwitcherClass);
		SwitchWidget->AddToPlayerScreen();
		SwitchWidget->SetVisibility(ESlateVisibility::Hidden);
	}

	if (PauseWidgetClass)
	{
		PauseGameWidget = CreateWidget<UPauseWidget>(GetWorld()->GetFirstPlayerController(), PauseWidgetClass);
		PauseGameWidget->AddToPlayerScreen();
		PauseGameWidget->SetVisibility(ESlateVisibility::Hidden);
	}

}

// Called every frame
void AChip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

/*
void AChip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);


}
*/


void AChip::SetPlayerStats(int32 level)
{
	/*
	MaxHealth = 100;
	MaxFury = 100;
	CurrentHealth = MaxHealth;
	CurrentFury = MaxFury;
	Damage = 0;
	Speed = 10;

	CritChance = .10f;
	CritModifier = 1.2f;

	DodgeDistance = 4;
	*/
}





void AChip::AddFury(int32 fury)
{
	CurrentFury += fury;
}




//Experience bar needs to update a bar on the HUD eventually. ------TO DO----------------
void AChip::GainExperience(int32 amount)
{
	//Increase Experience
	PlayerExperience += amount;

	//If the player has earned enough exp to level up
	if (PlayerExperience >= ExperienceToLevel(PlayerLevel))
	{
		//Calculate the overflow of experience gained (Eg; 1200 PlayerExperience - 900)
		int32 overflowExperience = PlayerExperience - ExperienceToLevel(PlayerLevel);
		//Call LevelUp and pass it the overflow of exp. (Alternatively, I could just do that in here, but why not.
		LevelUp(overflowExperience);
	}
}

void AChip::LevelUp(int32 overflowExperience)
{
	//Increase PlayerLevel 
	PlayerLevel += 1;

	//Make sure they didn't level up twice, somehow. If so, gain that experience again and calculate if they player needs to level up.
	if (overflowExperience >= ExperienceToLevel(PlayerLevel))
	{
		GainExperience(overflowExperience);
	}
	else
	{
		PlayerExperience = overflowExperience;
	}
	//Also call any function necessary to change base stats like damage or anything that increases as we level.
	//I believe the function to do that is SetPlayerStats(); but we need the "int level" we pass it to actually do something
}


void AChip::ReSpawn()
{
	print("Hello World");
	//Needs to reset the player position, player stats, enemies, and everything in the whole level, basically. 
	//We need the reset function to accurately reset everything in level 1.
}

void AChip::Death()
{
	print("You died...");//Dark souls style lol

						 //Need to instantiate a menu that asks whether the player wants to retry (ReSpawn();) or return to the main menu? (Maybe just respawn and quit.)

						 //ReSpawn(); //?
}


/*
void AChip::TakeDamage(float damage)
{
	CurrentHealth -= damage;

	if (CurrentHealth <= 0)
	{
		Death();
	}
}*/

float AChip::GetHealthAsPercentage()
{
	return GetHealth() / GetMaxHealth();
}

float AChip::GetHealth()
{
	return CurrentHealth;
}

float AChip::GetMaxHealth()
{
	return MaxHealth;
}

float AChip::GetFuryAsPercentage()
{
	return GetFury() / GetMaxFury();
}

float AChip::GetFury()
{
	return CurrentFury;
}

float AChip::GetMaxFury()
{
	return MaxFury;
}

int AChip::GetHConsumablesQuantity()
{
	return 5; //Setting to test
}

int AChip::GetFConsumablesQuantity()
{
	return 4; //setting to test
}

void AChip::DebugHealth()
{
	//Debugging to the screen
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0F, FColor::Yellow, FString::Printf(TEXT("Health: %f"), this->CurrentHealth));

	UE_LOG(LogTemp, Warning, TEXT("Health %f"), this->GetHealthAsPercentage());
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth %f"), this->GetHealth());
	UE_LOG(LogTemp, Warning, TEXT("MaxHealth %f"), this->GetMaxHealth());
}

void AChip::DebugFury()
{
	UE_LOG(LogTemp, Warning, TEXT("Health %f"), this->GetFuryAsPercentage());
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth %f"), this->GetFury());
	UE_LOG(LogTemp, Warning, TEXT("MaxHealth %f"), this->GetMaxFury());
}


void AChip::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Tags.Contains("Pickup"))
	{
		if (!itemsInRange.Contains(OtherActor))
		{
			itemsInRange.Add(OtherActor);
			print("Item in Range");
		}

	}
}

void AChip::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->Tags.Contains("Pickup"))
	{
		if (itemsInRange.Contains(OtherActor))
		{
			itemsInRange.Remove(OtherActor);
			print("Item has left Range");
		}
	}
}




// the way ryan teached us is wrong
// do not open the project by visual studio



// TO DO - Nick:
/*
(Please do not remove this, I will get to that. This is just the easiest way to keep track of my progress, considering that I work in/with this class so often.)
- Inventory needs to create images of items, their stack size, and anything else needed in the inventory. (tooltips?)
- Make widget blueprint and class for pop-up window on death.
- Player needs to die (play death animation) and then create the window, asking them to "Retry?" or "Quit?". On selection, do either ReSpawn(); or just quit the game.
- Create main menu widget class to go with the blueprint I made and re-parent the blueprint to the class for it's functions.
- Work on displaying consumables on the HUD. Also, make the consumables simply grab the player's CurrentHealth and increase it by the consumable's HealthRegain function.
- Add a pop-up window when overlapping an item (using the OnOverlapStart and End we have already to instantiate it.) that displays the names of the items in range.
- (Crafting can be potentially put into the inventory class so it can share the add/remove functions and anything else it needs.)
- Crafting menu needs to have a "Craft" function that checks the crafting choice, checks inventory for required items, and calls the add/remove functions in inventory for the necessary items.
- To craft, the player will select 2 items to merge and pass their item IDs to the craft function to find, craft, add, and remove items.
- Create a crafting tutorial. (Pop-Up window that has 3 options; Next, Back, and Close.)
- The tutorial will provide worded tips and eventually pictures of what to do. (stretch goal is to have it move around or point to locations)(Alternative goal is to have gifs or videos show what to do.)
- Player Experience stat. Player LevelUp(); function. Levelling up needs to add to level and change new requirement to a new number (use an enum to store these values Eg. 0 = 1000exp, 1 = 3000exp, etc).
- Overlapping experience gained needs to be added to the new experience level. (basically, if i needed 1000exp and gained 1200, I should be at 200 exp towards the next level.)
- Many more things to add here, I'm sure. Will update this list as I complete things.

*/
