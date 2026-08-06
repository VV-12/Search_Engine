#ifndef STOPWORDREMOVER_H
#define STOPWORDREMOVER_H

#include <string>
#include "DocumentStructure.h"
#include <unordered_set>

class StopWordRemover {
    public:
    StopWordRemover(const std::string& stopWordFilePath);

    void removeStopWords(Document& doc);

    private:
    std::unordered_set <std::string> stopWordSet;

    void removeStopWordsImpl(Document& doc);
};

#endif