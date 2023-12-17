// Copyright Alex Goulder


#include "Actors/Table.h"
#include "Poker/Poker.h"

ATable::ATable()
{
	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	RootMesh->SetupAttachment(RootComponent);
	RootMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void ATable::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATable::HighlightActor()
{
	RootMesh->SetRenderCustomDepth(true);
	RootMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

}

void ATable::UnHighlightActor()
{
	RootMesh->SetRenderCustomDepth(false);
}

