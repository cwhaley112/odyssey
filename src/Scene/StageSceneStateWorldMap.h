#pragma once

#include "al/Library/LiveActor/ActorClippingFunction.h"
#include "al/Library/LiveActor/ActorInitFunction.h"
#include "al/Library/Nerve/NerveStateBase.h"
#include "container/seadPtrArray.h"

namespace al {
class DirLightParam;
class KeyRepeatCtrl;
class LayoutActor;
class LiveActorGroup;
class Scene;
class SceneInitInfo;
class SimpleLayoutAppearWaitEnd;
class ViewRenderer;
class WipeSimple;
} // namespace al

class TalkMessage;
class WorldMapParts;
class WorldMapRoute;
class WorldMapKoopaShip;
class ShineTowerRocket;
class ShineTowerCommonKeeper;
class StageSceneStateCollectionList;
class WorldMapCamera;
class WorldMapMovieUpdater;


struct WorldMapRouteSelection {
    WorldMapRoute* mSelection1;
    WorldMapRoute* mSelection2;
};

class StageSceneStateWorldMap : public al::HostStateBase<al::Scene> {
private:
    al::SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelect;
    al::SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelectMovie;
    al::LayoutActor* mParFooter;
    al::LayoutActor* mParCounter;
    al::LayoutActor** mWorldSelectionParts; // len = 17
    al::LayoutActor** mBalloonFindParts; // len = 17
    al::SimpleLayoutAppearWaitEnd* mSimpleLayoutWorldSelectCursor;
    al::WipeSimple* mWipeWorld;
    al::WipeSimple* mWipeWorldSelectCapture;
    TalkMessage* mTalkMessage;
    al::KeyRepeatCtrl* mKeyRepeatCtrl;
    al::Scene* mScene;
    al::LiveActor* mLiveActor;
    al::LiveActorGroup* mWorldMapActorGroup;
    WorldMapParts** mWorldMapPointList; // len = 17
    WorldMapRoute** mWorldMapRouteList; // len = 17
    WorldMapRouteSelection* mWorldMapRouteSelection;
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
    float* mWorldMapIdList = nullptr; // len = 17
    s32 mNextLockedWorldNum = 0;
    s32 mCurrentWorldNum = -1;
    s32* mWorldMapUnlockIdList = nullptr; // this one is weird. used to index other lists
    WorldMapMovieUpdater* mWorldMapMovieUpdater;
    al::ViewRenderer* mViewRenderer = nullptr;
    WorldMapCamera* mWorldMapCamera = nullptr;
    al::DirLightParam* mDirLightParam = nullptr;
    StageSceneStateCollectionList* mStageSceneStateCollectionList;
    bool mCanUnlockMoreWorlds = false;
    bool mGotAllMoonsInWorld = false;
    sead::PtrArrayImpl* mPtrArray = nullptr;

public:
    StageSceneStateWorldMap(const char* stateName, al::Scene* scene, ShineTowerRocket* shineTowerRocket, const al::SceneInitInfo& sceneInitInfo, const al::ActorInitInfo& actorInitInfo, const al::LayoutInitInfo& layoutInitInfo, StageSceneStateCollectionList* stageSceneStateCollectionList);
    ~StageSceneStateWorldMap() override;

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
    void exeEnd();
    void exeExit();
    void exeIgnoreMessage();
    void exeInit();
    void exeWait();
    bool isCloseEndWipe() const;
    bool isOpenCollectionList() const;
    bool isOpenEndWipe() const;
    static StageSceneStateWorldMap* tryCreate(al::Scene* scene, const al::SceneInitInfo& sceneInitInfo, const al::ActorInitInfo& actorInitInfo, const al::LayoutInitInfo& layoutInitInfo, StageSceneStateCollectionList* stageSceneStateCollectionList);
    bool tryOpenWorldMap();
};