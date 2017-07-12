#include "window.h"
#include "log.hpp"

namespace ROOT_SPACE
{

    std::map< GLFWwindow * , window * > window::smWindows;

    window::window( void )
    {
        mWindowWidth = 600;
        mWindowHeight = 500;
        mWindowPosX = 0;
        mWindowPosY = 0;
        mWindowTitle = "Humble";
        mKeyDown = nullptr;
        mKeyUp = nullptr;
    }

    window::~window( void )
    {

    }

    void window::__key_callback( GLFWwindow * p_window, int p_key, int p_scancode, int p_action, int p_mods )
    {
        if( smWindows.find( p_window ) != smWindows.end() )
        {
            smWindows[p_window]->onKeyCallBack( p_key, p_scancode, p_action, p_mods );
        }
    }

    void window::__refresh_callback( GLFWwindow * p_window )
    {
        if( smWindows.find( p_window ) != smWindows.end() )
        {
            // smWindows[p_window]->draw();
        }
    }

    void window::__resize_callback( GLFWwindow* p_window, int p_width, int p_height )
    {
        if( smWindows.find( p_window ) != smWindows.end() )
        {
            smWindows[p_window]->onResize( p_width, p_height );
        }
    }

    bool window::init( void )
    {
        if( object::init() )
        {
            return true;
        }

        glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );

        mWindowHandle = glfwCreateWindow( (int)mWindowWidth, (int)mWindowHeight, mWindowTitle.c_str(), nullptr, nullptr );
        if( !mWindowHandle )
        {
            LOG.error("Cannot create a window in which to draw!");
            return true;
        }
        
        smWindows[mWindowHandle] = this;

        // glfwSetWindowUserPointer( mWindowHandle, this );
        glfwSetKeyCallback( mWindowHandle, window::__key_callback );
        glfwSetWindowRefreshCallback( mWindowHandle, window::__refresh_callback );
        glfwSetFramebufferSizeCallback( mWindowHandle, window::__resize_callback );
        // glfwSetWindowPosCallback( mWindowHandle,  )

        return false;
    }

    bool window::initWithInfo( const uint32_t p_width, const uint32_t p_height, const std::string & p_title )
    {
        mWindowWidth = p_width;
        mWindowHeight = p_height;
        mWindowTitle = p_title;
        return init();
    }


	bool window::destory ( void )
	{
        smWindows.erase( mWindowHandle );
        glfwDestroyWindow( mWindowHandle );
		return object::destory ();
	}

    void window::onKeyCallBack( const int p_key, const int p_scancode, const int p_action, const int p_mods )
    {
        LOG.info( "p_key: {0}, p_scancode: {1}, p_action: {2}, p_mods: {3}", p_key, p_scancode, p_action, p_mods );
    }

    void window::onResize( const int p_width, const int p_height )
    {
        mWindowWidth = (uint32_t)p_width;
        mWindowHeight = (uint32_t)p_height;
    }
}