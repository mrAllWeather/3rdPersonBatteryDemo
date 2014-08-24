// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "SpawnVolume.h"
#include "thirdPersonGameGameMode.generated.h"


// enum to store the current state of gameplay
enum class EthirdPersonGamePlayState : uint8
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AthirdPersonGameGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	virtual void Tick(float DeltaSeconds);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;

	EthirdPersonGamePlayState GetCurrentState() const;
	
	void SetCurrentState(EthirdPersonGamePlayState NewState);

	virtual void BeginPlay();

private:
	TArray<ASpawnVolume*> SpawnVolumeActors;

	EthirdPersonGamePlayState CurrentState;

	void HandleNewState(EthirdPersonGamePlayState NewState);
};

FORCEINLINE EthirdPersonGamePlayState AthirdPersonGameGameMode::GetCurrentState() const
{
	return CurrentState;
}

