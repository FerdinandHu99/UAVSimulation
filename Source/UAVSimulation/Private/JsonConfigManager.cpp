#include "JsonConfigManager.h"
#include "Json.h"

UJsonConfigManager* UJsonConfigManager::Instance = nullptr;
UJsonConfigManager::UJsonConfigManager()
{
    // 初始化JSON对象
    ConfigJson = MakeShared<FJsonObject>();
}
UJsonConfigManager* UJsonConfigManager::GetInstance()
{
    if (Instance == nullptr) 
    {
        Instance = NewObject<UJsonConfigManager>();
    }
    return Instance;
}
void UJsonConfigManager::SetConfigValue(const FString& Key, const FString& Value)
{
    // 设置JSON对象的属性
    ConfigJson->SetStringField(Key, Value);
}
FString UJsonConfigManager::GetConfigValue(const FString& Key) const
{
    // 获取JSON对象的属性值
    FString Value;
    ConfigJson->TryGetStringField(Key, Value);
    return Value;
}
void UJsonConfigManager::SaveConfigToFile(const FString& FilePath)
{
    // 将JSON对象保存到文件中
    FString JsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(ConfigJson.ToSharedRef(), Writer);
    FFileHelper::SaveStringToFile(JsonString, *FilePath);
}
void UJsonConfigManager::LoadConfigFromFile(const FString& FilePath)
{
    // 从文件中加载JSON对象
    FString JsonString;
    FFileHelper::LoadFileToString(JsonString, *FilePath);
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    FJsonSerializer::Deserialize(Reader, ConfigJson);
}

