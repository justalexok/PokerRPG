// Copyright Alex Goulder


#include "Actors/PokerEffectActor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/PokerAttributeSet.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemComponent.h"

APokerEffectActor::APokerEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void APokerEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UPokerAttributeSet* PokerAttributeSet = Cast<UPokerAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UPokerAttributeSet::StaticClass()));

		UPokerAttributeSet* MutablePokerAttributeSet = const_cast<UPokerAttributeSet*>(PokerAttributeSet);
		MutablePokerAttributeSet->SetBankroll(PokerAttributeSet->GetBankroll() + 25.f);
		Destroy();
	}
}

void APokerEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void APokerEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &APokerEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &APokerEffectActor::EndOverlap);
}

