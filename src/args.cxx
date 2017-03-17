#include <numeric>

#include "args.h"

std::string arguments::join(
    std::list<std::string> strings, std::string delimiter
) {

    return std::accumulate(
        std::next(strings.begin()), strings.end(), strings.front(),
        [=](std::string left, std::string right) {

            return left + delimiter + right;
        }
    );
}

std::string arguments::usage() {

    std::list<std::string> lines = {
        "Usage: goget [options] key (value)", 
        "",
        "goget retrieves to standard ouput values previously saved under a key",
        "Options:",
        "  -s\tsaves value under key",
        "  -d\tdelete key",
        "  -l\tlist saved key-values",
        "  -h\tdisplay this text",
        "",
        "Example:",
        ">> goget -s mysecret somesecret",
        ">> goget mysecret",
        "output: somesecret",
        ">> goget -l",
        "output: {\"mysecret\": \"somesecret\"}",
        ">> goget -d mysecret",
        ">> goget mysecret",
        "output: "
    };

    return join(lines, "\n");
}

std::list<std::string> arguments::handle_arguments(int argc, char * argv[]) {

    std::list<std::string> args_list;
    for (auto i = 1; i < argc; ++i) {

        args_list.push_back(std::string(argv[i]));
    }

    return args_list;
}

std::map<std::string, std::string> arguments::map_arguments(
    std::list<std::string> args_list
) {
    
    std::map<std::string, std::string> args_map = {
        {"save", "false"},
        {"delete", "false"},
        {"list", "false"},
        {"help", "false"},
        {"key", ""},
        {"value", ""}
    };

    for (auto n : args_list) {

        if (n == "-s") {

            args_map["save"] = "true";
        } else if (n == "-d") {

            args_map["delete"] = "true";
        } else if (n == "-l") {

            args_map["list"] = "true";
        } else if (n == "-h") {

            args_map["help"] = "true";
        } else if (args_map["key"] == "") {

            args_map["key"] = n;
        } else if (args_map["value"] == "") {

            args_map["value"] = n;
        }
    }

    return args_map;
}

