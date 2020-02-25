//
// Created by jack on 20-2-25.
//

#ifndef ESCAPE_DISPLAY_H
#define ESCAPE_DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include "separate_application.h"
#include "engine/window_ogre.h"
#include <OgreRenderSystem.h>
#include "MyECS.h"
#include "engine/utils.h"
#include "weapons.h"
#include "movement.h"
#include "serialization.h"
#include "agent.h"
#include <sstream>
#include "logic.h"

namespace Escape {

    class DisplayOgre : public WindowOgre {
        Logic *logic;
        World *world;
        Ogre::SceneNode *rects;

    public:
        DisplayOgre();

        ~DisplayOgre() = default;

        std::pair<Ogre::SceneNode *, Ogre::Entity *>
        newBox(float cx, float cy, float width, float height, float r, float g, float b);

        std::pair<Ogre::SceneNode *, Ogre::Entity *> newBox(float cx, float cy, float width, float height);

        Ogre::Vector3 pickUp(unsigned int absoluteX, unsigned int absoluteY);

        void initialize() override;

        virtual void processInput() override;

        void render() override;

        virtual void postProcess() override;

        void renderAgent(Entity ent);

        void renderBullet(Entity ent);

        void windowResized(int width, int height) override;
    };
} // namespace Escape



#endif //ESCAPE_DISPLAY_H