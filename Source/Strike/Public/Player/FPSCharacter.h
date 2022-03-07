// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

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
	 * @brief 加载玩家自定义的键位映射，若存在则自动加载
	 *        若不存在则绑定为默认设置
	 *        一般在@see AFPSCharacter::SetupPlayerInputComponent中调用
	 */
	void BindCustomKeySettings();

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
