

#include "thirdPersonGame.h"
#include "TutorialCodeHUD.h"
#include "thirdPersonGameGameMode.h"
#include "thirdPersonGameCharacter.h"
#include "Kismet/GamePlayStatics.h"


ATutorialCodeHUD::ATutorialCodeHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//Use the RobotoDistanceField font from the engine
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void ATutorialCodeHUD::DrawHUD()
{
	// Get the screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	// Call to the parent versions of DrawHUD
	Super::DrawHUD();
	
	// Get the player and print its power level
	AthirdPersonGameCharacter* MyCharacter = Cast<AthirdPersonGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	FString PowerLevelString = FString::Printf(TEXT("%.1f"), FMath::Abs(MyCharacter->PowerLevel));
	DrawText(PowerLevelString, FColor::White, 50, 50, HUDFont);

	AthirdPersonGameGameMode* MyGameMode = Cast<AthirdPersonGameGameMode>(UGameplayStatics::GetGameMode(this));
	// If the game is over
	if(MyGameMode->GetCurrentState() == EthirdPersonGamePlayState::EGameOver)
	{
		// create a variable for storing the size of printing Game Over
		FVector2D GameOverSize;
		GetTextSize(TEXT("GAME OVER"), GameOverSize.X, GameOverSize.Y, HUDFont);
		DrawText(TEXT("GAME OVER"), FColor::White, (ScreenDimensions.X - GameOverSize.X) / 2.0f, (ScreenDimensions.Y - GameOverSize.Y) / 2.0f, HUDFont);

	}
}

