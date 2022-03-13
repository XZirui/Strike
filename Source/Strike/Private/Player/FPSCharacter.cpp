// Copyright (c) XuZirui 2022


#include "Player/FPSCharacter.h"

#include "GameFramework/InputSettings.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 绑定基本移动
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AFPSCharacter::MoveForwardOrBackward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AFPSCharacter::MoveRightOrLeft);

	// 绑定视角移动
	PlayerInputComponent->BindAxis("Turn Right / Left", this, &AFPSCharacter::TurnRightOrLeft);
	PlayerInputComponent->BindAxis("Look Up / Down", this, &AFPSCharacter::LookUpOrDown);

	// 绑定跳跃操作
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJumping);
}

void AFPSCharacter::MoveForwardOrBackward(const float Val)
{
	AddMovementInput(GetActorForwardVector(), Val);
}

void AFPSCharacter::MoveRightOrLeft(const float Val)
{
	AddMovementInput(GetActorRightVector(), Val);
}

void AFPSCharacter::TurnRightOrLeft(const float Val)
{
	AddControllerYawInput(Val * MouseSense);
}

void AFPSCharacter::LookUpOrDown(const float Val)
{
	AddControllerPitchInput(Val * MouseSense);
}

void AFPSCharacter::Jump()
{
	bPressedJump = true;
}

void AFPSCharacter::StopJumping()
{
	bPressedJump = false;
}

