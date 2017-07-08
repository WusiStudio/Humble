#pragma once
#ifndef __APP_H__
#define __APP_H__
#include "IMemory.h"

namespace ROOT_SPACE
{
    class app: public object
    {
    public:
        CREATEFUNC(app);
    protected:

        app(void);
        ~app(void);

        virtual bool init(void) override;

        virtual bool destory(void) override;

        
    private:

    };
}

#endif //__APP_H__