#pragma once

#include "CoreMinimal.h"
#include "JsonConfigManager.generated.h"
class FJsonObject;
UCLASS()
class UAVSIMULATION_API UJsonConfigManager : public UObject
{
    GENERATED_BODY()
public:
    UJsonConfigManager(); 
    // 获取单例对象
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        static UJsonConfigManager* GetInstance();
    // 设置JSON属性值
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void SetConfigValue(const FString& Key, const FString& Value);
    // 获取JSON属性值
    UFUNCTION(BlueprintPure, Category = "Json Config")
        FString GetConfigValue(const FString& Key) const;
    // 保存JSON到文件
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void SaveConfigToFile(const FString& FilePath);
    // 从文件加载JSON
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void LoadConfigFromFile(const FString& FilePath);
private:
    static UJsonConfigManager* Instance;
    TSharedPtr<FJsonObject> ConfigJson;
};