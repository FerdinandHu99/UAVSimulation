// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameUserSettings.h"
#include "MenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AIRSIM_API AMenuGameMode : public AGameModeBase
{
public:
    GENERATED_BODY() // 这是 Unreal Engine 的元编程特性之一，用于在类声明中生成一些自动化的 C++ 代码

    virtual void StartPlay() override;

    AMenuGameMode(const FObjectInitializer& ObjectInitializer);
	
};
