

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class ABatteryPickup : public APickup
{
	GENERATED_UCLASS_BODY()

	/* Sets the amount of power that the battery will give to the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	float PowerLevel;
	
	/* Override the OnPickedUp function (use Implementation because this is a BlueprintNativeEvent) */
	void OnPickedUp_Implementation();
	
};
