// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "AuraSummoningAbility.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraSummoningAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()

public:


protected:


	UPROPERTY(EditAnywhere, Category="Combat")
	uint32 NumMinions = 0;

	UPROPERTY(EditAnywhere, Category="Combat")
	float MaxSpawnDistance = 400.f;
	
	UPROPERTY(EditAnywhere, Category="Combat")
	float MinSpawnDistance = 150.f;
	
	UPROPERTY(EditAnywhere, Category="Combat")
	float SpawnSpread = 90.f;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TArray<TSubclassOf<APawn>> MinionsToSpaw;

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GetRandomSpawnLocations();
};
