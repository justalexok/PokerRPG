// Copyright Alex Goulder


#include "Character/Hero/Hero.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/PokerPlayerState.h"
#include "AbilitySystemComponent.h"
#include "Player/HeroPlayerController.h"
#include "UI/HUD/PokerHUD.h"


AHero::AHero()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = TargetArmLength;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->SetRelativeRotation(FRotator(SpringArmAngle, 0.0f, 0.0f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	if (APokerPlayerState* PS = Cast<APokerPlayerState>(GetPlayerState()))
	{
		AbilitySystemComponent = PS->GetAbilitySystemComponent();
		AttributeSet = PS->GetAttributeSet();
	}
}

void AHero::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AHero::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AHero::InitAbilityActorInfo()
{
	APokerPlayerState* PokerPlayerState = GetPlayerState<APokerPlayerState>();
	check(PokerPlayerState);
	PokerPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(PokerPlayerState, this);
	AbilitySystemComponent = PokerPlayerState->GetAbilitySystemComponent();
	AttributeSet = PokerPlayerState->GetAttributeSet();

	if (AHeroPlayerController* HeroPC = Cast<AHeroPlayerController>(GetController()))
	{
		if (APokerHUD* PokerHUD = Cast<APokerHUD>(HeroPC->GetHUD()))
		{
			PokerHUD->InitOverlay(HeroPC, PokerPlayerState, AbilitySystemComponent, AttributeSet);
		}
		
	}
	
}
