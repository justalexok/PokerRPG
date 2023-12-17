// Copyright Alex Goulder

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/HighlightInterface.h"
#include "Table.generated.h"

UCLASS()
class POKER_API ATable : public AActor, public IHighlightInterface
{
	GENERATED_BODY()
	
public:	

	ATable();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RootMesh;

protected:
	virtual void BeginPlay() override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

	
	
};

