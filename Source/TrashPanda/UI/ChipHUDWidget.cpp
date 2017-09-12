// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "ChipHUDWidget.h"
#include "Player/Chip.h"

void UChipHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


float UChipHUDWidget::GetPlayerHealth() const
{
		AChip* OwningCharacter = Cast<AChip>(GetOwningPlayerPawn());

		float  porc = (OwningCharacter->Health) * 0.01f; 
		
		return porc;
	
	

}

float UChipHUDWidget::GetPlayerFury() const
{
	if (AChip* OwningCharacter = Cast<AChip>(GetOwningPlayerPawn()))
	{
	//	return OwningCharacter->GetFuryAsPercentage();
		return 0.0f;
	}
	else
	{
		return 0.0f;
	}
}

int32 UChipHUDWidget::GetPlayerHealthConsumableQ() const
{
	if (AChip* OwningCharacter = Cast<AChip>(GetOwningPlayerPawn()))
	{
	//	return OwningCharacter->GetHConsumablesQuantity();
		return 0;
	}
	else
	{
		return 0;
	}
}

int32 UChipHUDWidget::GetPlayerFuryConsumableQ() const
{
	if (AChip* OwningCharacter = Cast<AChip>(GetOwningPlayerPawn()))
	{
	//	return OwningCharacter->GetFConsumablesQuantity();
		return 0;
	}
	else
	{
		return 0;
	}
}


