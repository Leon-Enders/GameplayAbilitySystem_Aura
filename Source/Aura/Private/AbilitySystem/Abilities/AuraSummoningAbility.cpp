// Copyright Druid Mechanics


#include "AbilitySystem/Abilities/AuraSummoningAbility.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

TArray<FVector> UAuraSummoningAbility::GetRandomSpawnLocations()
{

	
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector ForwardVector =  GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const float DeltaSpread = SpawnSpread/NumMinions;

	TArray<FVector> SpawnLocations;
	
	const FVector LeftSpreadDirection =	ForwardVector.RotateAngleAxis(-SpawnSpread/2.f,FVector::UpVector);
	for(uint32 i = 0; i < NumMinions; i++)
	{
		const FVector Direction = LeftSpreadDirection.RotateAngleAxis(DeltaSpread*i, FVector::UpVector);
		const float SpawnDistance = FMath::RandRange(MinSpawnDistance, MaxSpawnDistance);
		FVector SpawnLocation = Direction * SpawnDistance + Location;
		

		FHitResult Hit;

		if(GetWorld()->LineTraceSingleByChannel(Hit, SpawnLocation + FVector(0.f,0.f,500.f),SpawnLocation - FVector(0.f,0.f,400.f), ECollisionChannel::ECC_Visibility))
		{
			SpawnLocation = Hit.ImpactPoint;
		}
		SpawnLocations.Add(SpawnLocation);
	}
	return SpawnLocations;
}

TSubclassOf<APawn> UAuraSummoningAbility::GetRandomMinionClass()
{
	
	const uint32 Selection = FMath::RandRange(0,MinionsToSpaw.Num()-1);
	return MinionsToSpaw[Selection];
}
