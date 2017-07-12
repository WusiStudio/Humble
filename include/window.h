#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include <string>
#include <map>
#include <functional>

#include "IMemory.h"

namespace ROOT_SPACE
{
    class window: public object
    {
    public:
        CREATEFUNC(window);
    protected:
        window(void);
        ~window(void);

        static void __key_callback( GLFWwindow* p_window, int p_key, int p_scancode, int p_action, int p_mods );
        static void __refresh_callback( GLFWwindow* p_window );
        static void __resize_callback( GLFWwindow* p_window, int p_width, int p_height );

        virtual bool init(void) override;
        virtual bool initWithInfo( const uint32_t p_width, const uint32_t p_height, const std::string & p_title );
        virtual bool destory(void) override;

        virtual void onKeyCallBack( const int p_key, const int p_scancode, const int p_action, const int p_mods );
        virtual void onResize( const int p_width, const int p_height );
    private:

        static std::map< GLFWwindow * , window * > smWindows;

        GLFWwindow *    mWindowHandle;

        uint32_t        mWindowWidth;
        uint32_t        mWindowHeight;
        int             mWindowPosX;
        int             mWindowPosY;
        std::string     mWindowTitle;

        std::function< void ( const int p_key ) > mKeyDown;
        std::function< void ( const int p_key ) > mKeyUp;
        
    };
};

#endif //__WINDOW_H__