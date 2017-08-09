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
	InputComponent->BindAction("Attack_Light", IE_Repeat, this, &ThisClass::LightAttackPressed);
	InputComponent->BindAction("Attack_Light", IE_Released, this, &ThisClass::LightAttackPressed);
	InputComponent->BindAction("Attack_Shoot", IE_Pressed, this, &ThisClass::ShootPressed);

#pragma endregion Combat REGION


	InputComponent->BindAction("DodgeLEFT", IE_DoubleClick, this, &ThisClass::DodgeLeft);
	InputComponent->BindAction("DodgeRIGHT", IE_DoubleClick, this, &ThisClass::DodgeRight);
	InputComponent->BindAction("DodgeBACK", IE_DoubleClick, this, &ThisClass::DodgeBack);

}

void ATest1Controller::MoveForward(float Value)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		const FRotator Rotation = MyPawn->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		MyPawn->AddMovementInput(Direction, Value);

		Cast<AChip>(MyPawn)->IsW(Value);
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

		Cast<AChip>(MyPawn)->RightStrafe(Value);
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


void ATest1Controller::LightAttackReleased()
{
	APawn* const MyPawn = GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("STOP ATTACKING"));
	Cast<AChip>(MyPawn)->IsAttacking = false;

}




void ATest1Controller::ShootPressed()
{
	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->Shoot();


}




void ATest1Controller::DodgeLeft()
{

	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->DodgeLeft();


}

void ATest1Controller::DodgeRight()
{
	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->DodgeRight();
}



void ATest1Controller::DodgeBack()
{
	APawn* const MyPawn = GetPawn();
	Cast<AChip>(MyPawn)->DodgeBack();
}
