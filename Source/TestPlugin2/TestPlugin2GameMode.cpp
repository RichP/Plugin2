// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPlugin2GameMode.h"
#include "TestPlugin2PlayerController.h"
#include "TestPlugin2Character.h"
#include "UObject/ConstructorHelpers.h"

ATestPlugin2GameMode::ATestPlugin2GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATestPlugin2PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}