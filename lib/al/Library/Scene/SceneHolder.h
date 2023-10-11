#pragma once

#include "basis/seadTypes.h"

namespace al {

class ActorInitInfo;
class LiveActor;
class StageInfo;
class Scene;

StageInfo* getStageInfoMap(const Scene*, s32);
void initPlacementByStageInfo(const StageInfo*, const char*, const ActorInitInfo&);
void initPlacementObjectMap(Scene*, const ActorInitInfo&, const char*);
void initPlacementObjectDesign(Scene*, const ActorInitInfo&, const char*);
void initPlacementObjectSound(Scene*, const ActorInitInfo&, const char*);
LiveActor* tryInitPlacementSingleObject(Scene*, const ActorInitInfo&, s32, const char*);
LiveActor* tryInitPlacementSingleObject(Scene*, const ActorInitInfo&, s32, const char*, const char*);

}  // namespace al