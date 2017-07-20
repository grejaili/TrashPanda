// All Rights Reserved for Students Graduating TFS Summer 2017

#include "TrashPanda.h"
#include "EnemyAIController.h"
#include "BTService_AIAttack.h"



#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red,text) 


void UBTService_AIAttack::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{


	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AEnemyAIController*  controller = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	
//	AChip* OwningCharacter = Cast<AChip>(OwnerComp.GetAIOwner()->GetPawn());


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	if (controller != NULL)
		controller->AttackBasic();
	if (controller == NULL)
		print("NUll");
=======
>>>>>>> AI-Master
=======
>>>>>>> AI-Master
=======
>>>>>>> origin/AI-Master




		// set the calculation to distance here


}
