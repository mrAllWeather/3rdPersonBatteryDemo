

#include "thirdPersonGame.h"
#include "Pickup.h"


APickup::APickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// The pickup is valid when it is created
	bIsActive = true;

	// Create the root SphereComponent to handle the pickup's collision
	BaseCollisionComponent = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	// Set the sphere component as the root component
	RootComponent = BaseCollisionComponent;

	// Create the static mesh component
	PickupMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	// Turn physics on for the static mesh
	PickupMesh->SetSimulatePhysics(true);

	// Attach static mesh component to the root component
	PickupMesh->AttachTo(RootComponent);

}

void APickup::OnPickedUp_Implementation()
{
	//There is no default behaviour for a Pickup when it is picked up.
}
