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
		const FVector SpawnLocation = Direction * SpawnDistance + Location;
		SpawnLocations.Add(SpawnLocation);

		UKismetSystemLibrary::DrawDebugArrow(GetAvatarActorFromActorInfo(),Location,Location + Direction * MaxSpawnDistance,5.f,FLinearColor::Green,1.f);
		UKismetSystemLibrary::DrawDebugSphere(GetAvatarActorFromActorInfo(), SpawnLocation, 30.f, 12, FLinearColor::Red, 1.f);
		UKismetSystemLibrary::DrawDebugSphere(GetAvatarActorFromActorInfo(),Location + Direction * MinSpawnDistance, 8.f, 12, FLinearColor::Yellow, 1.f);
		UKismetSystemLibrary::DrawDebugSphere(GetAvatarActorFromActorInfo(),Location + Direction * MaxSpawnDistance, 8.f, 12, FLinearColor::Yellow, 1.f);


	}
	
	
	return SpawnLocations;
}
