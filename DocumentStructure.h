#ifndef DOCUMENT_STRUCTURE
#define DOCUMENT_STRUCTURE

#include <string>
#include <cstdint>
#include <vector>

struct Document {
    std::uint64_t id;
    std::string fileName;
    std::string content;
    std::vector <std::string> tokens;
};

#endif