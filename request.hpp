#pragma once
#include <string>
#include <vector>

namespace http {
    struct request {
        std::string method;
        std::string resource;
        std::string version;
        std::vector<std::string> headers;
    };
}