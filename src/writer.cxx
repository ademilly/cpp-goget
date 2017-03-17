#include <fstream>

#include "reader.h"
#include "writer.h"

using json = nlohmann::json;

std::string writer::add_key(
    std::string filename, std::string key, std::string value
) {

    json j = reader::read_json(filename);
    j[key] = value;

    return write(filename, j) ? "Key `" + key + "` saved with SUCCESS" : "FAILURE";
}

std::string writer::remove_key(std::string filename, std::string key) {

    json j = reader::read_json(filename);
    j.erase(key);

    return write(filename, j) ? "Key `" + key + "` deleted with SUCCESS" : "FAILURE";
}

bool writer::write(std::string filename, json j) {

    std::ofstream ofs(filename, std::ofstream::out);

    ofs << j.dump();
    ofs.close();

    return true;
}
