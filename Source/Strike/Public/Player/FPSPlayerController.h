// Copyright (c) XuZirui 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPSPlayerController.generated.h"

/**
 * @brief 玩家控制器类，用于处理玩家控制
 */
UCLASS()
class STRIKE_API AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFPSPlayerController();

	/**
	* @brief 加载玩家自定义的键位映射，若存在则自动加载
	*        若不存在则绑定为默认设置
	*        一般在@see AFPSCharacter::SetupPlayerInputComponent中调用
	*/
	virtual void SetupInputComponent() override;
};
