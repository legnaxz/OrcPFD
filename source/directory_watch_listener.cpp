#include "directory_watch_listener.h"

#include <iostream>

namespace orc {

DirectoryWatchListener::DirectoryWatchListener( const std::string& base_dir, const std::string& intermediate_dir ){
        base_dir_ = base_dir;
        intermediate_dir_ = intermediate_dir;
}

DirectoryWatchListener::~DirectoryWatchListener(){}

void DirectoryWatchListener::handleFileAction( unsigned long watchid, const std::string& filename, orc::Action action )
{
    if ( filename.find( ".wav" ) != std::string::npos && orc::Actions::Add == action)
    {
        int finish_split = 0;
        int finish_bash = 0;
        std::cout << "a__DIR (" << base_dir_ + ") FILE (" + filename + ") has event " << action << std::endl;
        std::string command_original_file_move = "mv " + base_dir_ + filename + " /home/yes/destination/";
        std::string command_splited_file_move = "mv " + intermediate_dir_  + removeExtension(filename) + "*" + " /home/yes/destination/";
        //thread_ = boost::thread( &Codecs::wavSplit, codec_, base_dir_, filename );
        
        //finish_split = codec_.wavSplit( base_dir_, filename );
        finish_bash = system( command_original_file_move.c_str() );
        finish_bash = system( command_splited_file_move.c_str() );
        file_count_++;
    }

    if ( filename.find( ".wav" ) != std::string::npos && orc::Actions::Delete == action )
    {
        std::cout << "a__DIR (" << base_dir_ + ") FILE (" + filename + ") has event " << action << std::endl;
        file_count_--;
    }

}

}