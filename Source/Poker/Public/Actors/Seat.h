// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/HighlightInterface.h"
#include "Seat.generated.h"

UCLASS()
class POKER_API ASeat : public AActor, public IHighlightInterface
{
	GENERATED_BODY()
	
public:	
	ASeat();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RootMesh;

protected:
	virtual void BeginPlay() override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;


};
