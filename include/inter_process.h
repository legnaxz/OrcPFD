#ifndef _INTER_PROCESS_H_
#define _INTER_PROCESS_H_

#include "singletone.h"

namespace orc {

class InterProcess : public Singleton<InterProcess>
{
    class Private;
    friend class InterProcess::Private;
    typedef Private* PrivatePtr;

    friend class Singleton<InterProcess>;

private:
    InterProcess( void );

public:
    ~InterProcess( void );

public:
    void start( void );

private:
    void run( void );

private:
    PrivatePtr private_;
};

}
#endif // _INTER_PROCESS_H_