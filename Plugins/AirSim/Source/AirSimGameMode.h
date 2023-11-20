// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameUserSettings.h"
#include "AirSimGameMode.generated.h"

/**
 * 
 */
UCLASS() // 这个宏告诉 Unreal Engine 编译器和编辑器，这是一个 Unreal 类，可以在蓝图编辑器中使用
class AIRSIM_API AAirSimGameMode : public AGameModeBase
{
public:
    GENERATED_BODY() // 这是 Unreal Engine 的元编程特性之一，用于在类声明中生成一些自动化的 C++ 代码

    virtual void StartPlay() override;

    AAirSimGameMode(const FObjectInitializer& ObjectInitializer);

    //private:
    //UGameUserSettings* GetGameUserSettings();
};
