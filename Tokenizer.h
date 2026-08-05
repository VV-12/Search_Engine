#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "DocumentStructure.h"
#include <string>
#include <vector>

class Tokenizer {
    public:
    void tokenize(Document& loadedDoc);

    private:
    void tokenizeDocument(Document& doc);
};

#endif