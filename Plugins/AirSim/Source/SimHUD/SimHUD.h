#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SimHUDWidget.h"
#include "SimMode/SimModeBase.h"
#include "PIPCamera.h"
#include "api/ApiServerBase.hpp"
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <memory>
#include "SimHUD.generated.h"

UENUM(BlueprintType) // ��������ڽ�ö�����ͱ��Ϊ��ͼ���õģ�����ζ�����������ͼ��ʹ�ø�ö������
enum class ESimulatorMode : uint8
{
    SIM_MODE_HIL UMETA(DisplayName = "Hardware-in-loop")
};

UCLASS()
class AIRSIM_API ASimHUD : public AHUD
{
    GENERATED_BODY()

public:
    using ImageType = msr::airlib::ImageCaptureBase::ImageType;
    using AirSimSettings = msr::airlib::AirSimSettings;
    using MultirotorRpcLibClient = msr::airlib::MultirotorRpcLibClient;

public:
    void inputEventToggleRecording();
    void inputEventToggleReport();
    void inputEventToggleHelp();
    void inputEventToggleTrace();
    void inputEventToggleSubwindow0();
    void inputEventToggleSubwindow1();
    void inputEventToggleSubwindow2();
    void inputEventToggleAll();
    void commandTakeoff();

    ASimHUD();
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaSeconds) override;

protected:
    virtual void setupInputBindings();
    void toggleRecordHandler();
    void updateWidgetSubwindowVisibility();
    bool isWidgetSubwindowVisible(int window_index);
    void toggleSubwindowVisibility(int window_index);

private:
    void initializeSubWindows();
    void createSimMode();
    void initializeSettings();
    void setUnrealEngineSettings();
    void loadLevel();
    void createMainWidget();
    const std::vector<AirSimSettings::SubwindowSetting>& getSubWindowSettings() const;
    std::vector<AirSimSettings::SubwindowSetting>& getSubWindowSettings();

    bool getSettingsText(std::string& settingsText);
    bool getSettingsTextFromCommandLine(std::string& settingsText);
    bool readSettingsTextFromFile(const FString& fileName, std::string& settingsText);
    std::string getSimModeFromUser();

    static FString getLaunchPath(const std::string& filename);

private:
    typedef common_utils::Utils Utils;
    UClass* widget_class_; // Ѱ��BP_SimHUDWidget��

    UPROPERTY()
    USimHUDWidget* widget_; // ����BP_SimHUDWidget��
    UPROPERTY()
    ASimModeBase* simmode_;

    APIPCamera* subwindow_cameras_[AirSimSettings::kSubwindowCount];
    bool map_changed_;
    MultirotorRpcLibClient client;
};
