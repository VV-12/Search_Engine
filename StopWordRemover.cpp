#include "StopWordRemover.h"
#include <iostream>
#include <fstream>

StopWordRemover::StopWordRemover(const std::string& stopWordFilePath) {
    std::ifstream stopWordFile{stopWordFilePath};

    if (!stopWordFile) {
        std::cerr<<"Empty stop word list given";
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

void StopWordRemover::removeStopWord(Document& doc) {
    
    std::vector <std::string> tokenWithoutStopWords;

    for (const std::string token : doc.tokens) {
        if (StopWordRemover::stopWordSet.find(token) == StopWordRemover::stopWordSet.end()) {
            tokenWithoutStopWords.push_back(token);
        }
    }

    doc.tokens = tokenWithoutStopWords;
}

void StopWordRemover::removeStopWords(Document& doc) {
    removeStopWord(doc);
}