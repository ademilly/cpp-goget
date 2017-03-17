#ifndef READER_H
#define READER_H

#include <string>

#include "json.hpp"

using json = nlohmann::json;
namespace reader {

    std::string read(std::string filename);
    std::string read(std::string filename, std::string key);
    json read_json(std::string filename);
}

#endif // READER_H