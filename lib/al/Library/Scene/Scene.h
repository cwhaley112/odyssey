#pragma once

#include <al/Library/Audio/AudioKeeper.h>
#include <al/Library/Camera/CameraDirector.h>
#include <al/Library/Nerve/NerveExecutor.h>
#include <al/Library/Nerve/NerveKeeper.h>
#include <al/Library/Scene/SceneObjHolder.h>
#include <prim/seadSafeString.h>

namespace al {
class StageResourceKeeper;
class LiveActorKit;
class LayoutKit;
class SceneStopCtrl;
class SceneMsgCtrl;
class ScreenCoverCtrl;
class SceneInitInfo;
class GraphicsInitArg;
struct DrawSystemInfo;
class Scene : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseCamera, public al::IUseSceneObjHolder {
private:
    bool mIsAlive;
    sead::FixedSafeString<64> mName;
    al::StageResourceKeeper* mStageResourceKeeper;
    al::LiveActorKit* mLiveActorKit;
    al::LayoutKit* mLayoutKit;
    al::SceneObjHolder* mSceneObjHolder;
    al::SceneStopCtrl* mSceneStopCtrl;
    al::SceneMsgCtrl* mSceneMsgCtrl;
    al::ScreenCoverCtrl* mScreenCoverCtrl;
    al::AudioDirector* mAudioDirector;
    al::AudioKeeper* mAudioKeeper;
    al::DrawSystemInfo* mDrawSystemInfo;

public:
    Scene(const char* name);
    virtual ~Scene();
    virtual void init(const al::SceneInitInfo& initInfo);
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void control();
    virtual void drawMain();
    virtual void drawSub();

    void initializeAsync(const al::SceneInitInfo& initInfo);
    void initSceneObjHolder(al::SceneObjHolder*);
    void initAndLoadStageResource(const char*, s32);
    void initLiveActorKit(const al::SceneInitInfo& initInfo, s32 maxActors, s32 maxPlayers, s32 maxCameras);
    void initLiveActorKitImpl(const al::SceneInitInfo& initInfo, s32 maxActors, s32 maxPlayers, s32 maxCameras);
    void initDrawSystemInfo(const al::SceneInitInfo& initInfo);
    void initLiveActorKitWithGraphics(const al::GraphicsInitArg& graphicsInitArg, const al::SceneInitInfo& initInfo, s32 maxActors, s32 maxPlayers,
                                      s32 maxCameras);
    void initLayoutKit(const al::SceneInitInfo& initInfo);
    void initSceneStopCtrl();
    void initSceneMsgCtrl();
    void initScreenCoverCtrl();
    void endInit(const al::ActorInitInfo& initInfo);

    al::AudioKeeper* getAudioKeeper() const override;
    al::SceneObjHolder* getSceneObjHolder() const override;
    al::CameraDirector* getCameraDirector() const override;

    const sead::FixedSafeString<64>* getName() const { return &mName; }
};
}  // namespace al
