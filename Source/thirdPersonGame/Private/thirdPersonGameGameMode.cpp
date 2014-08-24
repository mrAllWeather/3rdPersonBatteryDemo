// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "thirdPersonGame.h"
#include "thirdPersonGameGameMode.h"
#include "thirdpersonGameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TutorialCodeHUD.h"

AthirdPersonGameGameMode::AthirdPersonGameGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UClass> PlayerPawnBPClass(TEXT("Class'/Game/Blueprints/MyCharacter.MyCharacter_C'"));
	if (PlayerPawnBPClass.Object != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Object;

	}

	// set the default HUD class
	HUDClass = ATutorialCodeHUD::StaticClass();

	// Base decay rate
	DecayRate = 0.25f;

}

void AthirdPersonGameGameMode::Tick(float DeltaSeconds)
{
	AthirdPersonGameCharacter* MyCharacter = Cast<AthirdPersonGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// if the character still has power
	if (MyCharacter->PowerLevel > 0.05)
	{
		// decrease the characters power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.f, DeltaSeconds, DecayRate);
	}
	else
	{
		SetCurrentState(EthirdPersonGamePlayState::EGameOver);
	}

}

void AthirdPersonGameGameMode::SetCurrentState(EthirdPersonGamePlayState NewState)
{
	CurrentState = NewState;
	
	HandleNewState(NewState);
	
}

void AthirdPersonGameGameMode::HandleNewState(EthirdPersonGamePlayState NewState)
{
	switch (NewState)
	{
	// When we are playing the Spawn Volumes Can Spawn
	case EthirdPersonGamePlayState::EPlaying:
		for (ASpawnVolume* Volume : SpawnVolumeActors)
		{
			Volume->EnableSpawning();
		}
		break;
	// When the game is over the Spawn Volumes should deactivate
	case EthirdPersonGamePlayState::EGameOver:
	{
		for (ASpawnVolume* Volume : SpawnVolumeActors)
		{
			Volume->DisableSpawning();
		}
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		PlayerController->SetCinematicMode(true, true, true);
	}
		break;
	case EthirdPersonGamePlayState::EUnknown:
	default:
		// Do nothing
		break;
	}
}

void AthirdPersonGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	//find all spawn volume actors
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundActors);

	for (auto Actor : FoundActors)
	{
		ASpawnVolume* SpawnVolumeActor = Cast<ASpawnVolume>(Actor);
		if (SpawnVolumeActor)
		{
			SpawnVolumeActors.Add(SpawnVolumeActor);
		}
	}

	SetCurrentState(EthirdPersonGamePlayState::EPlaying);

}