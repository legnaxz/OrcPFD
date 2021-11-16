#ifndef _PMS_STDTYPES_H_
#define _PMS_STDTYPES_H_

#define PMS_DISABLE_COPY(Class)             \
    Class(const Class&) = delete;           \
    Class& operator=(const Class&) = delete

#define PMS_DISABLE_MOVE(Class)             \
    Class(Class&&) = delete;                \
    Class& operator=(Class&&) = delete

#include <string>
#include <vector>
#include <queue>

#include <sstream>

namespace pms {

typedef std::vector<std::string> StringList;
typedef std::vector<uint8_t*> BufferList;
typedef std::queue<uint8_t*> BufferQueue;

inline const char* booleanToString( bool boolean ) noexcept {
    return boolean ? "true" : "false";
}

inline const std::string stringListToString( const StringList& string_list ) noexcept {
    if( 0 != string_list.size() ) {
        std::ostringstream ss;
        ss << string_list[0];

        for( StringList::size_type i = 1; i < string_list.size(); ++i ) {
            ss << "," << string_list[i];
        }

        return ss.str();
    }

    return "";
}

}

#endif // #ifndef _PMS_STDTYPES_H_
