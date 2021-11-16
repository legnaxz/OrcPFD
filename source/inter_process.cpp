#include "inter_process.h"
#include "inter_process_listener.h"
#include "tcp_server.h"

#include "manager.h"

#include <boost/thread/thread.hpp>

namespace orc {

class InterProcess::Private
{

public:
    Private( InterProcess* inter_process )
        :inter_process_( inter_process )
    {}

public:
    inline void run ( void ) 
    {
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::endpoint endpoint( boost::asio::ip::tcp::v4(),
            3011 );

        TcpServer<InterProcessListener> tcp_server( io_context, endpoint );

        tcp_server.listen();

        io_context.run();    
    }

    inline void start( void ) {
        thread_ = boost::thread( boost::bind( &InterProcess::run, inter_process_ ) );
    }

private:
    InterProcess* inter_process_;
    boost::thread thread_;
};

InterProcess::InterProcess( void )
    : private_( new Private( this ) )
{
}

InterProcess::~InterProcess( void )
{
    delete private_;
}

void InterProcess::start( void )
{
    private_->start();
}

void InterProcess::run( void )
{
    private_->run();
}

}