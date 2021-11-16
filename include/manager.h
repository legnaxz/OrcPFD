#ifndef _ORC_MANAGER_H_
#define _ORC_MANAGER_H_

#include "common.h"
#include "singletone.h"
#include "config.h"

#include "directory_watcher.h"
#include "directory_watch_listener.h"

#include <sys/types.h>
#include <sys/stat.h>

namespace orc{

    class DirectoryWatchListener;

    class Manager : public Singleton<Manager>
    {
        class Private;
        friend class Manager::Private;
        typedef Private* PrivatePtr;

        friend class Singleton<Manager>;

    public:
        class OrcConfigFileInfo : public Config::SubSet {
            friend class Manager;

        private:
            OrcConfigFileInfo( void );

        public:
            const std::string& version( void ) const {
                return version_;
            }

        private:
            bool bind( void ) override;

        private:
            std::string version_;    
        };

    private:
        Manager ( void );

    public:
        ~Manager( void );
    
    public: 
        bool initialize( const std::string& configFilePath );
        
        const OrcConfigFileInfo& orcConfigFileInfo( void ) {
            return orc_config_file_info_;
        }

    public:
        void waitForever( void );
        
    private:
        PrivatePtr private_;

        OrcConfigFileInfo orc_config_file_info_;
    };

}

#endif