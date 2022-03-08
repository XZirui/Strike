// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

/**
 * @brief 游戏中玩家的人物类，主要实现射击、瞄准，以及各种操作的结合
 */
UCLASS()
class STRIKE_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief 玩家在不开镜时的灵敏度
	 */
	UPROPERTY(BlueprintReadWrite, Category="Mouse")
	float MouseSense = 1.0f;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * @brief 处理前后移动请求，此函数用于处理玩家输入
	 */
	void MoveForwardOrBackward(const float Val);

	/**
	 * @brief 处理左右移动请求，此函数用于处理玩家输入
	 */
	void MoveRightOrLeft(const float Val);

	/**
	 * @brief 处理视角左右移动请求，此函数用于处理玩家输入
	 */
	void TurnRightOrLeft(const float Val);

	/**
	 * @brief 处理视角上下移动请求，此函数用于处理玩家输入
	 */
	void LookUpOrDown(const float Val);
};
