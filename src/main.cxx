#include <iostream>

#include "args.h"
#include "reader.h"
#include "setup.h"
#include "writer.h"

int main(int argc, char * argv[]) {

    auto args = arguments::handle_arguments(argc, argv);
    auto args_map = arguments::map_arguments(args);

    std::string storage = setup::setup();
    std::cout << storage << std::endl;

    if (args_map["help"] == "true") {

        std::cout << arguments::usage() << std::endl;
        return 0;
    }

    if (args_map["list"] == "true") {

        std::cout << reader::read(storage) << std::endl;
        return 0;
    }

    if ((args_map["key"] == "") && (args_map["value"] == "")) {

        std::cout << arguments::usage() << std::endl;
        return 0;
    }

    if (
        (args_map["save"] == "true") &&
        ((args_map["key"] != "") && (args_map["value"] != "")) 
    ) {

        std::cout << writer::add_key(
            storage, args_map["key"], args_map["value"]
        ) << std::endl;
    } else if ((args_map["delete"] == "true") && (args_map["key"] != "")) {

        std::cout << writer::remove_key(
            storage, args_map["key"]
        ) << std::endl;
    } else if (args_map["value"] == "") {

        std::cout << reader::read(storage, args_map["key"]) << std::endl;
    } else {

        std::cout << arguments::usage() << std::endl;
        return 0;
    }

    return 0;
}
