#pragma once
#ifndef __TEST_APP_H__
#define __TEST_APP_H__

#include "app.h"

namespace ROOT_SPACE
{
    class testApp : public app
    {
    public:
        CREATEFUNC(testApp)

    protected:

        testApp(void);
        ~testApp(void);

        virtual int init(void) override;

        virtual int destory(void) override;
    };
}

#endif //__TEST_APP_H__