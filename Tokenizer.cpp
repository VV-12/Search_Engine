#include "Tokenizer.h"
#include "DocumentLoader.h"
#include <iostream>


void tokenizer(std::vector <Document>& loadedDocs) {
    std::vector <std::vector <std::string>> tokenizedDocs;

    for (Document& doc : loadedDocs) {
        std::string currWord = "";

        for (char c : doc.content) {
            if (c >= 65 && c <= 90) {
                currWord += (c+32);
            }
            else if (c >= 97 && c <= 122) {
                currWord += c;
            }
            else {
                if (currWord != "") doc.tokens.push_back(currWord);
                currWord = "";
            }
        }

        if (currWord != "") {
            doc.tokens.push_back(currWord);
            currWord = "";
        }
    }
}