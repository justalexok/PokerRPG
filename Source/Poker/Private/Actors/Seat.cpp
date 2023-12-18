// Copyright Alex Goulder


#include "Actors/Seat.h"

#include "Poker/Poker.h"

ASeat::ASeat()
{
	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	RootMesh->SetupAttachment(RootComponent);
	RootMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

}

void ASeat::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASeat::HighlightActor()
{
	RootMesh->SetRenderCustomDepth(true);
	RootMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_BLUE);
}

void ASeat::UnHighlightActor()
{
	RootMesh->SetRenderCustomDepth(false);

}



