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

        virtual bool init(void) override;

        virtual bool destory(void) override;

    };
}

#endif //__TEST_APP_H__