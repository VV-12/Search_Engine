#include "StopWordRemover.h"
#include <iostream>
#include <fstream>

StopWordRemover::StopWordRemover(const std::string& stopWordFilePath) {
    std::ifstream stopWordFile{stopWordFilePath};

    if (!stopWordFile) {
        throw std::runtime_error("Failed to open stop-word file : "+stopWordFilePath);
        return;
    }

    std::string stopWord = "";
    int loadedStopWords = 0;

    while (std::getline(stopWordFile, stopWord)) {
        stopWordSet.insert(stopWord);
        loadedStopWords++;
    }

    std::cout<<"Successfully loaded "<<loadedStopWords<<" stop words\n";
}

void StopWordRemover::removeStopWordsImpl(Document& doc) {
    
    std::vector <std::string> tokenWithoutStopWords;

    tokenWithoutStopWords.reserve(doc.tokens.size());

    for (const std::string& token : doc.tokens) {
        if (stopWordSet.find(token) == stopWordSet.end()) {
            tokenWithoutStopWords.push_back(token);
        }
    }

    doc.tokens = std::move(tokenWithoutStopWords);
}

void StopWordRemover::removeStopWords(Document& doc) {
    removeStopWordsImpl(doc);
}