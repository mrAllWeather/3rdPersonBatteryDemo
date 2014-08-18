

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class APickup : public AActor
{
	GENERATED_UCLASS_BODY()
	
	/* True when pickup is able to be picked up, false if something deactivates the pickup. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	bool bIsActive;

	/* Simple collision primative to use as the root component */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<USphereComponent> BaseCollisionComponent;

	/* StaticMeshComponent to represent the pickup in the level */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pickup)
	TSubobjectPtr<UStaticMeshComponent> PickupMesh;

	/* Function to call when pickup is collected */
	UFUNCTION(BlueprintNativeEvent)
	void OnPickedUp();
};
