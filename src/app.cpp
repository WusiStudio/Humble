#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include "VGraphical.h"
#include "app.h"

namespace ROOT_SPACE
{

    app::app(void)
    {

    }

    app::~app(void)
    {

    }

    bool app::init(void)
    {
        if( object::init() )
        {
            return true;
        }

        //------------------------------------------------------
        //init app running environment									
        //------------------------------------------------------
        if (!glfwInit()) 
        {
            LOG.error("Cannot initialize GLFW.\nExiting ...");
            return true;
        }

        if(initGraphical())
        {
            return true;
        }

        return false;
    }

    bool app::destory(void)
    {
        return object::destory();
    }
}