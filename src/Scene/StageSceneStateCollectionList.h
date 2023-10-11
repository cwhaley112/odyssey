#pragma once

#include "al/Library/Nerve/NerveStateBase.h"

namespace al {

class LayoutInitInfo;
class RollParts;
class Scene;
class SimpleLayoutAppearWaitEnd;

} // namespace al

class CursorParts;
class FooterParts;
class HackListLayout;
class InputSeparator;
class MapLayout;
class SceneAudioSystemPauseController;
class ShineListLayout;
class SouvenirListLayout;
class StageSceneStateStageMap;
class StageSceneStateCollectBgm;

class StageSceneStateCollectionList : public al::HostStateBase<al::Scene> {
private:
    ShineListLayout* mShineListLayout;
    HackListLayout* mHackListLayout;
    SouvenirListLayout* mSouvenirListLayout;
    StageSceneStateStageMap* mStageSceneStateStageMap;
    StageSceneStateCollectBgm* mStageSceneStateCollectBgm;
    InputSeparator* mInputSeparator;
    al::SimpleLayoutAppearWaitEnd* mSimpleLayoutParRoll;
    CursorParts* mCursorParts;
    al::SimpleLayoutAppearWaitEnd* mSimpleLayoutMapFooter;
    FooterParts* mFooterParts;
    al::RollParts* mRollParts;
    char16_t** mRollPartsPaneStringSize;
    s32 mListLayoutIndexIn;
    s32 mListLayoutIndexOut;
    s32 mStageMapLen;
    char mFlags[4];
    bool mPlayingBgm;
    bool mSetByAchievement;
    bool mSetByMusic;
    bool mSetByMap;
    bool mLeftOut;
    bool mSetOpen;
    bool mNeedsUpdate;
    SceneAudioSystemPauseController* mSceneAudioSystemPauseController;

public:
    StageSceneStateCollectionList(const char*, al::Scene*, const al::LayoutInitInfo&, MapLayout*, StageSceneStateCollectBgm*, SceneAudioSystemPauseController*);
    ~StageSceneStateCollectionList() override;
    
    void init() override;
    void appear() override;
    void kill() override;
    void control() override;

    void changeLeft();
    void changeRight();
    void exeChangeView();
    void exeClose();
    void exeViewBgmList();
    void exeViewHackList();
    void exeViewShineList();
    void exeViewSouvenirList();
    void exeViewStageMap();
    void setOpenByAchievementNpc();
    void setOpenByMusicNpc();
    void setOpenInWorldMap(s32 worldId);
    void updateText();
};