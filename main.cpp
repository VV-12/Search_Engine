#include "DocumentLoader.h"
#include "InvertedIndex.h"
#include "PorterStemmer.h"
#include "StopWordRemover.h"
#include "Tokenizer.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

namespace {
std::string normalizeQuery(std::string query) {
    std::string normalized;
    normalized.reserve(query.size());

    for (char c : query) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            normalized += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }

    return normalized;
}
}

int main() {
    constexpr const char* DOCUMENTS_PATH = "documents";
    constexpr const char* STOP_WORDS_PATH = "assets/stopWords.txt";

    std::cout << "Loading documents...\n";
    std::vector<Document> documents = loadDocuments(DOCUMENTS_PATH);

    if (documents.empty()) {
        std::cerr << "No documents were loaded. Make sure the program is run from the project root.\n";
        return 1;
    }

    Tokenizer tokenizer;
    StopWordRemover stopWordRemover(STOP_WORDS_PATH);
    PorterStemmer stemmer;

    for (Document& document : documents) {
        tokenizer.tokenize(document);
        stopWordRemover.removeStopWords(document);

        for (std::string& token : document.tokens) {
            token = stemmer.stemToken(token);
        }
    }

    InvertedIndex index;
    index.build(documents);

    std::cout << "Loaded " << documents.size() << " documents.\n";
    std::cout << "Search engine is ready.\n\n";
    std::cout << "Enter a word to search (type 'exit' to quit).\n";

    while (true) {
        std::cout << "\nSearch: ";

        std::string query;
        if (!std::getline(std::cin, query)) {
            break;
        }

        query = normalizeQuery(query);

        if (query == "exit") {
            break;
        }

        if (query.empty()) {
            std::cout << "Please enter a valid word.\n";
            continue;
        }

        // Apply the same stemming used when building the index.
        const std::string stemmedQuery = stemmer.stemToken(query);
        const std::vector<SearchResult> results = index.search(stemmedQuery);

        if (results.empty()) {
            std::cout << "No matches found for '" << query << "'.\n";
            continue;
        }

        std::cout << "Found " << results.size() << " matching document(s):\n";

        for (const SearchResult& result : results) {
            const auto documentIt = std::find_if(
                documents.begin(),
                documents.end(),
                [&](const Document& document) {
                    return document.id == result.documentId;
                }
            );

            if (documentIt != documents.end()) {
                std::cout << "  - " << documentIt->fileName
                          << " (" << result.occurrences << " occurrence"
                          << (result.occurrences == 1 ? "" : "s") << ")\n";
            }
        }
    }

    std::cout << "Search engine closed.\n";
    return 0;
}
