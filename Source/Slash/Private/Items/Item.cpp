// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt)

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(runningTime * timeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(runningTime * timeConstant);
}

float AItem::ConstantRotation(float DeltaTime, float rate)
{
	return DeltaTime * rate;
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	runningTime += DeltaTime;

}

