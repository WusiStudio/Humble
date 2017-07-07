#pragma once
#ifndef __APP_H__
#define __APP_H__
#include "../../IMemory/include/IMemory.h"

namespace ROOT_SPACE
{
    class app: public object
    {
    public:
        CREATEFUNC(app);
    protected:

        app(void);
        ~app(void);

        virtual int init(void) override;

        virtual int destory(void) override;

        
    private:

    };
}

#endif //__APP_H__