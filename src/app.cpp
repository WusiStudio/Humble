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

        if(VGraphical::initGraphical())
        {
            return true;
        }

        mWindow = &window::Create();

        return false;
    }

    bool app::destory(void)
    {
        glfwTerminate();
        return object::destory();
    }
}