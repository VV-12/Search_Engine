#include "InvertedIndex.h"

#include <algorithm>

void InvertedIndex::build(const std::vector<Document>& documents) {
    index.clear();

    for (const Document& document : documents) {
        for (const std::string& token : document.tokens) {
            ++index[token][document.id];
        }
    }
}

std::vector<SearchResult> InvertedIndex::search(const std::string& token) const {
    std::vector<SearchResult> results;

    const auto termIt = index.find(token);
    if (termIt == index.end()) {
        return results;
    }

    results.reserve(termIt->second.size());
    for (const auto& [documentId, occurrences] : termIt->second) {
        results.push_back({documentId, occurrences});
    }

    std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
        if (a.occurrences != b.occurrences) {
            return a.occurrences > b.occurrences;
        }
        return a.documentId < b.documentId;
    });

    return results;
}
