#pragma once

#include "al/Library/LiveActor/ActorInitFunction.h"
#include "al/Library/Nerve/NerveStateBase.h"
#include "al/Library/Scene/Scene.h"
#include "container/seadPtrArray.h"

namespace al {
class LayoutActor;
class LiveActorGroup;
} // namespace al

// double check these are not al TODO
class SimpleLayoutAppearWaitEnd;
class WipeSimple;
class TalkMessage;
class KeyRepeatCtrl;
class WorldMapParts;
class WorldMapKoopaShip;
class ShineTowerRocket;
class ShineTowerCommonKeeper;class WorldMapMovieUpdater;
class ViewRenderer;
class WorldMapCamera;
class DirLightParam;
class StageSceneStateCollectionList;

class StageSceneStateWorldMap : public al::HostStateBase<al::Scene> {
private:
    SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelect;
    SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelectMovie;
    al::LayoutActor* mLayoutActor1;
    al::LayoutActor* mLayoutActor2;
    void* unk_0x88;
    void* unk_0x88_2;
    SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelectCursor;
    WipeSimple* mWipeWorld;
    WipeSimple* mWipeWorldSelectCapture;
    TalkMessage* mTalkMessage;
    KeyRepeatCtrl* mKeyRepeatCtrl;
    al::Scene* mScene;
    al::LiveActor* mLiveActor;
    al::LiveActorGroup* mLiveActorGroup;
    void* unk_0x88_3;
    void* unk_0x88_4;
    void* unk_0x10;
    WorldMapParts* mWorldMapParts;
    WorldMapKoopaShip* mWorldMapKoopaShip;
    ShineTowerRocket* mShineTowerRocket;
    ShineTowerCommonKeeper* mShineTowerCommonKeeper = nullptr;
    sead::Matrix34f mMatrix34;
    s32 mCurrentWorldId = 0;
    s32 mMapChoice = -1;
    s32 mNextLockedWorldId = -1;
    s32 mUnlockWorldNum = 0;
    s32 mCurrentWorldIndex = 0;
    // s32 unk_0x4;
    void* unk_0x44 = nullptr;
    s32 mNextLockedWorldNum = 0;
    s32 mCurWorldNum = -1;
    void* unk_0x8 = nullptr;
    WorldMapMovieUpdater* mWorldMapMovieUpdater;
    ViewRenderer* mViewRenderer = nullptr;
    WorldMapCamera* mWorldMapCamera = nullptr;
    DirLightParam* mDirLightParam = nullptr;
    StageSceneStateCollectionList* mStageSceneStateCollectionList;
    bool mCanUnlockMoreWorlds = false;
    bool mGotAllMoonsInWorld = false;
    sead::PtrArrayImpl* mPtrArray = nullptr;

public:
    StageSceneStateWorldMap(const char* stateName, al::Scene* scene, ShineTowerRocket* shineTowerRocket, const al::SceneInitInfo& sceneInitInfo, const al::ActorInitInfo& actorInitInfo, const al::LayoutInitInfo& layoutInitInfo, StageSceneStateCollectionList* stageSceneStateCollectionList);
    virtual ~StageSceneStateWorldMap();

    void appear() override;
    void kill() override;
    void control() override;

    void appearWorldSelectLayout();
    void exeCollectionListExit();
    void exeCollectionListMain();
    void exeDemoPrep();
    void exeDemoStart();
    void exeDemoWorldComment();
    void exeDemoWorldOpen();
    void exeDemoWorldSelect();
    void exeDemoWorldUnlock();
    bool isCloseEndWipe() const;
    bool isOpenCollectionList() const;
    bool isOpenEndWipe() const;
    static StageSceneStateWorldMap* tryCreate(al::Scene* scene, const al::SceneInitInfo& sceneInitInfo, const al::ActorInitInfo& actorInitInfo, const al::LayoutInitInfo& layoutInitInfo, StageSceneStateCollectionList* stageSceneStateCollectionList);
    bool tryOpenWorldMap();
};