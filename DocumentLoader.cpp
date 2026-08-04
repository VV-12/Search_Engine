#include "DocumentLoader.h"
#include <fstream>
#include <iostream>
#include <filesystem>

// we will use this to read files in a directory

std::vector <Document> loadDocuments(const std::string dirPath) {
    std::vector <Document> loadedDocs;
    uint64_t idCount = 0;

    if (!std::filesystem::is_directory(dirPath)) {
        std::cerr<<"Mentioned path is not a valid directory\n";
        return {};
    }

    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.path().extension() == ".txt") {
            Document newDoc;

            std::ifstream textFile{entry.path()};

            if (!textFile) {
                continue;
            }

            std::string content = "";
            
            newDoc.fileName = entry.path().filename().string();
            newDoc.id = idCount++;

            while (std::getline(textFile, content)) {
                newDoc.content += content + "\n";
            }

            loadedDocs.push_back(newDoc);
        }
    }

    return loadedDocs;
}