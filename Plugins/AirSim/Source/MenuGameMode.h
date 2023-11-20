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
    GENERATED_BODY() // ���� Unreal Engine ��Ԫ�������֮һ��������������������һЩ�Զ����� C++ ����

    virtual void StartPlay() override;

    AMenuGameMode(const FObjectInitializer& ObjectInitializer);
	
};
