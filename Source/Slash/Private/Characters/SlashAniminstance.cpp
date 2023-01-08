// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashAniminstance.h"
#include "Characters/SlashCharacter.h"

void USlashAniminstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	
	SlashCharacter = Cast<ASlashCharacter>(TryGetPawnOwner());
	if (SlashCharacter)
	{
		SlashCharacterMovement = SlashCharacter->GetCharacterMovement();
	}
	
}

void USlashAniminstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (SlashCharacterMovement)
	{
		SlashCharacterMovement->Velocity
	}
}
