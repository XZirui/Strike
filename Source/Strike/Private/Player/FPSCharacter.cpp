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

	// 先建立按键映射
	BindCustomKeySettings();

	// 绑定基本移动
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AFPSCharacter::MoveForwardOrBackward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AFPSCharacter::MoveRightOrLeft);

	// 绑定视角移动
	PlayerInputComponent->BindAxis("Turn Right / Left", this, &AFPSCharacter::TurnRightOrLeft);
	PlayerInputComponent->BindAxis("Look Up / Down", this, &AFPSCharacter::LookUpOrDown);
}

void AFPSCharacter::BindCustomKeySettings()
{
	//Todo
	// 如果不存在自定义键位映射，加载默认的设置

	// 建立基本移动键位映射
	// 前后移动
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Forward / Backward", EKeys::W, 1.0f));
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Forward / Backward", EKeys::S, -1.0f));

	// 前后移动（手柄）
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Forward / Backward", EKeys::Gamepad_LeftY, 1.0f));

	// 左右移动
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Right / Left", EKeys::D, 1.0f));
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Right / Left", EKeys::A, -1.0f));

	// 左右移动（手柄）
	UInputSettings::GetInputSettings()->AddAxisMapping(FInputAxisKeyMapping("Move Right / Left", EKeys::Gamepad_LeftX, 1.0f));
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
