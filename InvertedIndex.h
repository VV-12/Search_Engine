#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include "DocumentStructure.h"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

struct SearchResult {
    std::uint64_t documentId;
    std::size_t occurrences;
};

class InvertedIndex {
public:
    void build(const std::vector<Document>& documents);
    std::vector<SearchResult> search(const std::string& token) const;

private:
    // term -> (document id -> number of occurrences in that document)
    std::unordered_map<std::string, std::unordered_map<std::uint64_t, std::size_t>> index;
};

#endif
