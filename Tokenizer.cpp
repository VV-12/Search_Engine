#include "Tokenizer.h"

void Tokenizer::tokenizeDocument(Document& doc) {
    std::string currWord = "";

    for (const char c : doc.content) {
        if (std::isalpha(c)) {
            currWord += std::tolower(c);
        }
        else {
            if (!currWord.empty()) doc.tokens.push_back(currWord);
            currWord = "";
        }
    }

    if (!currWord.empty()) doc.tokens.push_back(currWord);
}

void Tokenizer::tokenize(Document& loadedDoc) {
    Tokenizer::tokenizeDocument(loadedDoc);
}