#ifndef PORTER_STEMMER_H
#define PORTER_STEMMER_H

#include "english_stem.h"
#include <string>

class PorterStemmer {
    private:
    stemming::english_stem <std::wstring> stemmer;
    std::wstring utf8ToWstring(const std::string& str);
    std::string wstringToUtf8(const std::wstring& wstr);


    public:
    std::string stemToken(const std::string& token);
};

#endif