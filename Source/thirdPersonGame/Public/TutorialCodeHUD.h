

#pragma once

#include "GameFramework/HUD.h"
#include "TutorialCodeHUD.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API ATutorialCodeHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	/** Variable for storing the font */
	UPROPERTY()
	UFont * HUDFont;
	
	/** Primary draw call for the HUD */
	virtual void DrawHUD();

};
