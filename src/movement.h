#if !defined(MOVEMENT_H)
#define MOVEMENT_H
#include "engine/MyECS.h"
#include <glm/glm.hpp>
#include "components.h"
namespace Escape
{
class MovementSystem : public ECSSystem
{
public:
    void move(Entity *ent, const glm::vec2 &speed)
    {
        ent->assign<Velocity>(speed.x, speed.y);
    }
    void update(clock_type delta) override
    {
        world->each<Velocity>([&](Entity *ent, ComponentHandle<Velocity> vel) {
            auto &&pos = ent->get<Position>();
            assert(pos.isValid());
            // FIXME assertion failed after loading map
            pos.get() += vel.get() * delta;
        });
    }

private:
};

} // namespace Escape

#endif // MOVEMENT_H
