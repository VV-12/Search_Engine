#ifndef STOPWORDREMOVER_H
#define STOPWORDREMOVER_H

#include <string>
#include <vector>
#include "DocumentStructure.h"
#include <unordered_set>

class StopWordRemover {
    public:
    StopWordRemover(std::string& stopWordFilePath);

    void removeStopWords(Document& doc);

    private:
    std::unordered_set <std::string> stopWordSet;

    void removeStopWord(Document& doc);
};

#endif