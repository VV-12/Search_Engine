#ifndef DOCUMENT_LOADER_H
#define DOCUMENT_LOADER_H

#include <string>
#include <vector>

struct Document {
    int id;
    std::string fileName;
    std::string content;
};

std::vector <Document> loadDocuments(std::string dirPath);

#endif