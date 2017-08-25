// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "IConsumable.h"



void AIConsumable::BeginPlay()
{
	Super::BeginPlay();
	ConsumableList.Add(TEXT("Health"));
	ConsumableList.Add(TEXT("Whisky"));
	
	itemName = ConsumableList[ConsType.GetValue()];
}