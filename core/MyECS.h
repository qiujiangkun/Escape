#if !defined(ECSCORE_H)
#define ECSCORE_H

#include "engine/system.h"
#include "engine/utils.h"
#include <entt/entity/registry.hpp>

namespace Escape {
    using World = entt::registry;

    class SystemManager : public System {
    protected:
        World *world = new World();
    public:
        SystemManager() {}

        World *getWorld() {
            return world;
        }

        ~SystemManager() override {
            delete world;
        }
    };

    class ECSSystem : public System {
    public:
        World *getWorld() {
            return findSystem<SystemManager>()->getWorld();
        }
    };

} // namespace Escape

#endif // ECSCORE_H
