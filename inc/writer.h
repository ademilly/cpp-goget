#ifndef WRITER_H
#define WRITER_H

#include "json.hpp"
#include <string>

namespace writer {

    std::string add_key(std::string filename, std::string key, std::string value);
    std::string remove_key(std::string filename, std::string key);
    bool write(std::string filename, json j);
}

#endif // WRITER_H