// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameUserSettings.h"
#include "UAVSimulationGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class UAVSIMULATION_API AUAVSimulationGameModeBase : public AGameModeBase
{
public:
	GENERATED_BODY() // 这是 Unreal Engine 的元编程特性之一，用于在类声明中生成一些自动化的 C++ 代码

	AUAVSimulationGameModeBase();
};
