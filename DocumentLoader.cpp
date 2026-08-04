#include "DocumentLoader.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>

// we will use this to read .txt files from the passed directory

std::vector <Document> loadDocuments(const std::string dirPath) {
    std::vector <Document> loadedDocs;
    uint64_t idCount = 0;

    if (!std::filesystem::is_directory(dirPath)) {
        std::cerr<<"Mentioned path is not a valid directory\n";
        return {};
    }

    std::vector <std::filesystem::path> filePaths;

    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.path().extension() == ".txt") {
            filePaths.push_back(entry.path());
        }
    }

    std::sort(filePaths.begin(), filePaths.end());

    for (const auto& filePath : filePaths) {
        std::ifstream inputFile{filePath};

        if (!inputFile) {
            continue;
        }

        Document doc;
        doc.id = idCount++;
        doc.fileName = filePath.filename().string();
        std::string contentLine = "";

        while (getline(inputFile, contentLine)) {
            doc.content += contentLine;
        }

        loadedDocs.push_back(doc);
    }

    return loadedDocs;
}