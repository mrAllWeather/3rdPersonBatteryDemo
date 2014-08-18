

#include "thirdPersonGame.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//Base power level of battery
	PowerLevel = 150.f;
}

void ABatteryPickup::OnPickedUp_Implementation()
{
	// Call the parent implementation of OnPickedUp first
	Super::OnPickedUp_Implementation();

	// Destroy the battery
	Destroy();


}
