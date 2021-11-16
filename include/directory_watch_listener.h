#ifndef _DIRECTORY_WATCH_LISTENER_H_
#define _DIRECTORY_WATCH_LISTENER_H_

#include "common.h"
#include "boost/thread.hpp"

namespace orc {

typedef Actions::Action Action;

class DirectoryWatchListener
{

public:
    DirectoryWatchListener( const std::string& base_dir, const std::string& intermediate_dir );
    ~DirectoryWatchListener();
    void handleFileAction( unsigned long id, const std::string& filenamem, Action action );

public:
    inline std::string removeExtension( const std::string filename )
        {
            size_t lastdot = filename.find_last_of(".");
            if ( lastdot == std::string::npos ) {
                return filename;
            }
            return filename.substr( 0, lastdot );
        }

private:
    boost::thread thread_;

    long file_count_ = 0;

    std::string intermediate_dir_;
    std::string base_dir_;
};

};

#endif // _DIRECTORY_WATCH_LISTENER_H_