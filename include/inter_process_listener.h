#ifndef _INTER_PROCESS_LISTENER_H_
#define _INTER_PROCESS_LISTENER_H_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "stdtypes.h"
#include "log4cxx/logger.h"

namespace orc {

class InterProcessMessageParser;
class InterProcessListener 
    : public std::enable_shared_from_this<InterProcessListener>
{
    static log4cxx::LoggerPtr Logger_;
public:
    InterProcessListener( boost::asio::ip::tcp::socket socket );
    virtual ~InterProcessListener( void );

public:
    void start();

public:
    inline uint8_t* allocBuffer( size_t size_in_bytes )
    {
        uint8_t* new_buffer = nullptr;
        
        new_buffer = new uint8_t[size_in_bytes + 1];
        memset( new_buffer, 0x00, sizeof(new_buffer) );
       
        return new_buffer;
    }

    // inline std::string converter(uint8_t *str){
    //     return std::string::String((char *)str);
    // }

private:
    void receive( void );
    void close( void );

private:
    boost::asio::ip::tcp::socket socket_;
    InterProcessMessageParser* inter_process_message_parser_;
    uint8_t* buffer_;
    std::string result;
};

}

#endif // _INTER_PROCESS_LISTENER_H_
