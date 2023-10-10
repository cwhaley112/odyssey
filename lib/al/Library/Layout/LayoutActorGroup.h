#pragma once

#include <container/seadPtrArray.h>
#include "al/Library/HostIO/HioNode.h"

namespace al {
class LayoutActor;

class LayoutActorGroup : public HioNode{
private:
    const char* mName;
    s32 mCapacity;
    s32 mCount = 0;
    LayoutActor** mBuffer;
public:
    LayoutActorGroup(const char* name, s32 capacity);
    LayoutActor* tryFindDeadActor() const;
    LayoutActor* findDeadActor() const;

    virtual void registerActor(LayoutActor* layoutActor);

};
}  // namespace al
