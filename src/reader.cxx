#include <fstream>
#include <streambuf>
#include <string>

#include "reader.h"

std::string reader::read(std::string filename) {

    json j = read_json(filename);

    return j.dump();
}

std::string reader::read(std::string filename, std::string key) {

    json j = read_json(filename);

    return j.count(key) > 0 ? j[key] : "";
}

json reader::read_json(std::string filename) {

    std::ifstream ifs(filename);

    return json::parse(
        std::string(
            (std::istreambuf_iterator<char>(ifs)), 
            std::istreambuf_iterator<char>()
        )
    );
}