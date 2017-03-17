#include <cstdlib>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "setup.h"

std::string setup::setup() {

    const char* env_p = std::getenv("HOME");
    std::string gogetdir = ".goget/";
    std::string storage = std::string(env_p) + "/" + gogetdir + "kv-store.json";

    if (static_cast<bool>(std::ifstream(storage))) {

        return storage;
    } else {

        const int dir_err = mkdir(
            (std::string(env_p) + "/" + gogetdir).c_str(), 
            S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH
        );

        return dir_err != -1 ? storage : "FAILURE";
    }        
}