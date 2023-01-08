// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
Abird::Abird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void Abird::BeginPlay()
{
	Super::BeginPlay();
	
}

void Abird::MoveForward(float value)
{
	if (Controller && (value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, value);
	}
	UE_LOG(LogTemp, Warning, TEXT("Value %f"), value)
}

void Abird::Turn(float value)
{
	AddControllerYawInput(value);
}

void Abird::LookUp(float value)
{
	AddControllerPitchInput(value);
}

// Called every frame
void Abird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Abird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &Abird::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &Abird::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &Abird::LookUp);
}

