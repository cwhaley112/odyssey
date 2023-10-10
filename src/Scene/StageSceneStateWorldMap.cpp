#include "Scene/StageSceneStateWorldMap.h"

#include <cstdlib>
#include "al/Library/Scene/Scene.h"


StageSceneStateWorldMap::StageSceneStateWorldMap(const char* stateName, al::Scene* scene, ShineTowerRocket* shineTowerRocket, const al::SceneInitInfo& sceneInitInfo, const al::ActorInitInfo& actorInitInfo, const al::LayoutInitInfo& layoutInitInfo, StageSceneStateCollectionList* stageSceneStateCollectionList) : HostStateBase<al::Scene>(stateName), mScene(scene), mShineTowerRocket(shineTowerRocket), mStageSceneStateCollectionList(stageSceneStateCollectionList) /*,mViewRenderer(actorInitInfo->getGraphicsSystemInfo()->mViewRenderer)*/ {
    memset(mSimpleLayoutWorldSelect, 0, 0x98); // might need to & arg1
    std::memcpy(&mMatrix34, &sead::Matrix34f::ident, 0x30);
    al::Scene* newScene = new al::Scene("WorldMapStage");
    // newScene->mName // dont think i need to call assureTerminationImpl_ should be inlined in constructor
    // newScene->initAndLoadStageResource(newScene->mName.mStringTop, 1); // may be in inlined Scene constructor? TODO check
}