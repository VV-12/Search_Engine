#include "Tokenizer.h"

void tokenizer(std::vector <Document>& loadedDocs) {

    for (Document& doc : loadedDocs) {
        std::string currWord = "";

        for (char c : doc.content) {
            if (std::isalpha(c)) {
                currWord += std::tolower(c);
            }
            else {
                if (!currWord.empty()) doc.tokens.push_back(currWord);
                currWord = "";
            }
        }

        if (!currWord.empty()) {
            doc.tokens.push_back(currWord);
            currWord = "";
        }
    }
}