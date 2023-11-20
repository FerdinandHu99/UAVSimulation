#include "JsonConfigManager.h"
#include "Json.h"

UJsonConfigManager* UJsonConfigManager::Instance = nullptr;
UJsonConfigManager::UJsonConfigManager()
{
    // ��ʼ��JSON����
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
    // ����JSON���������
    ConfigJson->SetStringField(Key, Value);
}
FString UJsonConfigManager::GetConfigValue(const FString& Key) const
{
    // ��ȡJSON���������ֵ
    FString Value;
    ConfigJson->TryGetStringField(Key, Value);
    return Value;
}
void UJsonConfigManager::SaveConfigToFile(const FString& FilePath)
{
    // ��JSON���󱣴浽�ļ���
    FString JsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(ConfigJson.ToSharedRef(), Writer);
    FFileHelper::SaveStringToFile(JsonString, *FilePath);
}
void UJsonConfigManager::LoadConfigFromFile(const FString& FilePath)
{
    // ���ļ��м���JSON����
    FString JsonString;
    FFileHelper::LoadFileToString(JsonString, *FilePath);
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    FJsonSerializer::Deserialize(Reader, ConfigJson);
}

