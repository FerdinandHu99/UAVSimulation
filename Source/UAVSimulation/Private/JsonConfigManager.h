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
    // ��ȡ��������
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        static UJsonConfigManager* GetInstance();
    // ����JSON����ֵ
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void SetConfigValue(const FString& Key, const FString& Value);
    // ��ȡJSON����ֵ
    UFUNCTION(BlueprintPure, Category = "Json Config")
        FString GetConfigValue(const FString& Key) const;
    // ����JSON���ļ�
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void SaveConfigToFile(const FString& FilePath);
    // ���ļ�����JSON
    UFUNCTION(BlueprintCallable, Category = "Json Config")
        void LoadConfigFromFile(const FString& FilePath);
private:
    static UJsonConfigManager* Instance;
    TSharedPtr<FJsonObject> ConfigJson;
};