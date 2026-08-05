#include "Tokenizer.h"

void Tokenizer::tokenizeDocument(Document& doc) {
    doc.tokens.clear();

    std::string currWord = "";

    for (char c : doc.content) {
        if (std::isalpha(c)) {
            currWord += std::tolower(c);
        }
        else {
            if (!currWord.empty()) doc.tokens.push_back(currWord);
            currWord.clear();
        }
    }

    if (!currWord.empty()) doc.tokens.push_back(currWord);
}

void Tokenizer::tokenize(Document& loadedDoc) {
    tokenizeDocument(loadedDoc);
}