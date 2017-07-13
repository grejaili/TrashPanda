// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Chip.h"
#include "ControllerChip.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 


void AControllerChip::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	print("I posses the player");

	Pawn = Cast<AChip>(InPawn);
}

void AControllerChip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AControllerChip::SetupInputComponent()
{
	/*
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ThisClass::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ThisClass::LookUpAtRate);

	InputComponent->BindAction("LAttack", IE_Pressed, this, &ThisClass::LightAttackPressed);
	InputComponent->BindAction("LAttack", IE_Released, this, &ThisClass::LightAttackReleased);
	InputComponent->BindAction("HAttack", IE_Pressed, this, &ThisClass::HeavyAttackPressed);
	InputComponent->BindAction("HAttack", IE_Released, this, &ThisClass::LightAttackReleased);
	InputComponent->BindAction("Dodge", IE_Pressed, this, &ThisClass::Dodge);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ThisClass::Interact);
	InputComponent->BindAction("ReadInv", IE_Pressed, this, &ThisClass::ReadInv);
	InputComponent->BindAction("OpenCharPanel", IE_Pressed, this, &ThisClass::OpenCharPanel);


	//Allow player to toggle pause
	FInputActionBinding& pauseToggle = InputComponent->BindAction("PauseGame", IE_Pressed, this, &ThisClass::PauseGame);
	pauseToggle.bExecuteWhenPaused = true;

	//Allow player to toggle pause when opening inventory
	FInputActionBinding& invToggle = InputComponent->BindAction("OpenInv", IE_Pressed, this, &ThisClass::OpenInv);
	invToggle.bExecuteWhenPaused = true;
	*/

}

/*
void AControllerChip::Interact()
{

	print("Interacting...");
	for (int32 i = 0; i < itemsInRange.Num(); i++)
	{
		if (itemsInRange[i])
		{
			if (ABaseItem* thing = Cast<ABaseItem>(itemsInRange[i]))
			{
				Inventory->AddItem(thing->GetClass());
				UE_LOG(LogTemp, Warning, TEXT("ItemType %s"), *GetNameSafe(thing->GetClass()));

				const int32* count = Inventory->GetItems().Find(thing->GetClass());
				UE_LOG(LogTemp, Warning, TEXT("Items in TMap %d"), *count);

				thing->Destroy();
			}
		}
	}
}
*/
void AControllerChip::LightAttackPressed()
{
	bisLightAttacking = true;
}

void AControllerChip::LightAttackReleased()
{
	bisLightAttacking = false;
}

void AControllerChip::HeavyAttackPressed()
{
	AGameMode* aux = Cast <AGameMode>(GetWorld()->GetAuthGameMode());
	aux->RestartGame();

	bisHeavyAttacking = true;
	print("Heavy Attack");
}

void AControllerChip::HeavyAttackReleased()
{
	bisHeavyAttacking = false;
}

void AControllerChip::Dodge()
{
	print("Dodge");
}

void AControllerChip::Rabid()
{
	print("Rabid");
}

void AControllerChip::OpenInv()
{
	if (InvWidget->Visibility == ESlateVisibility::Hidden)
	{
		InvWidget->SetVisibility(ESlateVisibility::Visible);
		PauseGame();
	}
	else if (InvWidget->Visibility == ESlateVisibility::Visible)
	{
		InvWidget->SetVisibility(ESlateVisibility::Hidden);
		PauseGame();
	}

}


void AControllerChip::PauseGame()
{
	print("ok");

	if (bGamePaused == false) //Is the game Paused? If not, pause it.
	{
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		print("Paused Game");
		bGamePaused = true;
		FInputModeGameAndUI Mode;
		Mode.SetWidgetToFocus(PauseGameWidget->GetCachedWidget());
		GetWorld()->GetFirstPlayerController()->SetInputMode(Mode);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

		//Trying to get the mouse to return to center screen when you pause the game.
		//FViewport* v = Cast<FViewport>(GetWorld()->GetGameViewport()->Viewport->SetMouse(0.5, 0.5));


		//Is the inventory open? Then don't open the pause menu.
		if (InvWidget->Visibility == ESlateVisibility::Hidden)
		{
			PauseGameWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
	else //Is the game paused? If so, un-pause it.
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		print("Un-Paused Game");
		bGamePaused = false;
		FInputModeGameOnly GameOnly;
		GetWorld()->GetFirstPlayerController()->SetInputMode(GameOnly);
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;

		if (InvWidget->Visibility == ESlateVisibility::Hidden)
		{
			PauseGameWidget->SetVisibility(ESlateVisibility::Hidden);
		}
		if (InvWidget->Visibility == ESlateVisibility::Visible)
		{
			InvWidget->SetVisibility(ESlateVisibility::Hidden);
		}
		if (PauseGameWidget->Visibility == ESlateVisibility::Visible)
		{
			PauseGameWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}

}

bool AControllerChip::GetIsLightAttacking()
{
	return bisLightAttacking;
}

bool AControllerChip::GetIsHeavyAttacking()
{

	return bisHeavyAttacking;
}


void AControllerChip::OpenCharPanel()
{
	/*
	if (SwitchWidget)
	{
		if (SwitchWidget->Visibility == ESlateVisibility::Hidden)
		{
			SwitchWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else if (SwitchWidget->Visibility == ESlateVisibility::Visible)
		{
			SwitchWidget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	*/
}

void AControllerChip::ReadInv()
{
	/*
	print("Read Inv Pressed");
	if (int32 num = Inventory->GetItems().Num())
	{
		//const int32* count = Inventory->GetItems().Find(AIConsumable::StaticClass());
		//UE_LOG(LogTemp, Warning, TEXT("Items in TMap %d"), count);
		//count = Inventory->GetItems().Find(AIMaterial::StaticClass());
		//UE_LOG(LogTemp, Warning, TEXT("Items in TMap %d"), count);
		//count = Inventory->GetItems().Find(ABaseItem::StaticClass());
		//UE_LOG(LogTemp, Warning, TEXT("Items in TMap %d"), count);
		UE_LOG(LogTemp, Warning, TEXT("Items in TMap %d"), num);
	}
	*/
}

void AControllerChip::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AControllerChip::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


void AControllerChip::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// it should be on player contrller
void AControllerChip::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}



}

