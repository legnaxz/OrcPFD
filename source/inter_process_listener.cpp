#include "inter_process_listener.h"

#include "inter_process_message_parser.h"

#include <iostream>

#define COMMAND_MAX 1024
namespace orc 
{
    log4cxx::LoggerPtr InterProcessListener::Logger_ = log4cxx::Logger::getLogger(" InterProcessListener ");

    InterProcessListener::InterProcessListener( boost::asio::ip::tcp::socket socket )
        : socket_( std::move( socket ) )
        //, inter_process_message_parser_( new InterProcessParser() )
    {}

    void InterProcessListener::start( void )
    {
        std::cout << "out 1 " <<std::endl;
        receive();
    }

    InterProcessListener::~InterProcessListener( void )
    {
        close();

        //delete inter_process_message_parser_;
    }

    void InterProcessListener::receive( void )
    {
        auto self( shared_from_this() );
                std::cout << "out 1 " <<std::endl;

        buffer_ = allocBuffer( COMMAND_MAX );
                std::cout << "out 1 " <<std::endl;

        boost::asio::async_read(socket_,
                            boost::asio::buffer( buffer_, COMMAND_MAX ),
                            [this, self]( boost::system::error_code error_code, std::size_t transferred_bytes ) {
                                if( false !=error_code.failed() ) {
                                    if( boost::asio::error::eof == error_code ) {
                                        LOG4CXX_DEBUG( Logger_, "Client disconnected ..." );
                                    }
                                    else {
                                        LOG4CXX_ERROR( Logger_, "Async read error: \"" << error_code.message().c_str() << "\"" );
                                    }

                                    close();
                                }
                                else {
                                    result = (char*)buffer_;
                                    std::cout<< result << std::endl;
                                }
                            });

    }

    void InterProcessListener::close( void )
    {
        if ( false == socket_.is_open() ) {
            LOG4CXX_DEBUG( Logger_, "Close socket... ");
            socket_.close();
        }
    }


}
