// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "Chip.h"
#include "Test1Controller.h"


#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 

ATest1Controller::ATest1Controller()
{


	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
}

void ATest1Controller::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}


void ATest1Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	//check(SetupInputComponent);


	//CAMERA INPUTS
#pragma
	InputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ThisClass::MoveSides);

	InputComponent->BindAxis("TurnRate", this, &ThisClass::TurnAtRate);
	InputComponent->BindAxis("LookUpRate", this, &ThisClass::LookUpAtRate);
	InputComponent->BindAxis("MouseCameraRotationY", this, &ThisClass::CameraYControll);
	InputComponent->BindAxis("MouseCameraRotationX", this, &ThisClass::CameraXControll);
#pragma endregion CAMERA REGION
	//COMBAT INPUTS

#pragma

	InputComponent->BindAction("Attack_Light", IE_Pressed, this, &ThisClass::LightAttackPressed);
	InputComponent->BindAction("Attack_Shoot", IE_Pressed, this, &ThisClass::ShootPressed);

#pragma endregion Combat REGION


	InputComponent->BindAction("Dodge", IE_Pressed, this, &ThisClass::DoubleClick);

}

void ATest1Controller::MoveForward(float Value)
{
	if (Value != 0) 
	{




		APawn* const MyPawn = GetPawn();
		if (MyPawn)
		{
			const FRotator Rotation = MyPawn->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			MyPawn->AddMovementInput(Direction, Value);
		}
	}

}

void ATest1Controller::MoveSides(float Value)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		const FRotator Rotation = MyPawn->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		MyPawn->AddMovementInput(Direction, Value);
	}

}


void ATest1Controller::TurnAtRate(float Rate)
{

	APawn* const MyPawn = GetPawn();
	// calculate delta for this frame from the rate information
	MyPawn->AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATest1Controller::LookUpAtRate(float Rate)
{
	APawn* const MyPawn = GetPawn();
	// calculate delta for this frame from the rate information
	MyPawn->AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATest1Controller::CameraYControll(float Rate)
{


	APawn* const MyPawn = GetPawn();

	Cast<AChip>(MyPawn)->CameraYAxisMovement(Rate);
}

void ATest1Controller::CameraXControll(float Rate)
{


	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->CameraXAxisMovement(Rate);

}

void ATest1Controller::LightAttackPressed()
{
	APawn* const MyPawn = GetPawn();
	//UE_LOG(LogTemp, Warning, TEXT("ATTACK"));
	Cast<AChip>(MyPawn)->LightAttack();

}


void ATest1Controller::ShootPressed()
{
	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->Shoot();


}

void ATest1Controller::DoubleClick()
{
//	GetWorld()->GetTimerManager().ClearTimer(DodgeTimerHandler);
	//GetWorld()->GetTimerManager().SetTimer(DodgeTimerHandler, 2, false);
	//GetWorldTimerManager().SetTimer(this, &ThisClass::FunctionToCall, TimeInFloat);

	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, "dodge");
	if (GetWorld()->GetTimerManager().GetTimerRemaining(DodgeTimerHandler) <= 0)
	{

	}
	
}






