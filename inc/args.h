#ifndef ARGS_H
#define ARGS_H

#include <list>
#include <map>
#include <string>

namespace arguments {

    std::string join(std::list<std::string> strings, std::string delimiter);

    std::string usage();

    std::list<std::string> handle_arguments(
        int argc, char * argv[]
    );

    std::map<std::string, std::string> map_arguments(
        std::list<std::string> args_list
    );
}

#endif // ARGS_H