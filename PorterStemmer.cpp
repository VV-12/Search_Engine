#include "PorterStemmer.h"
#include <string>
#include <windows.h>

std::string PorterStemmer::stemToken(const std::string& token) {
    std::wstring wtoken = utf8ToWstring(token);

    stemmer(wtoken);

    return wstringToUtf8(wtoken);
}

std::wstring PorterStemmer::utf8ToWstring(const std::string& str) {
    if (str.empty())
        return {};

    int size = MultiByteToWideChar(
        CP_UTF8,
        0,
        str.data(),
        static_cast<int>(str.size()),
        nullptr,
        0
    );

    if (size == 0) {
        /* Handle error in case of unsuccessful conversion*/
    }

    std::wstring result(size, L'\0');

    MultiByteToWideChar(
        CP_UTF8,
        0,
        str.data(),
        static_cast<int>(str.size()),
        result.data(),
        size
    );

    return result;
}

std::string PorterStemmer::wstringToUtf8(const std::wstring& wstr)
{
    if (wstr.empty())
        return {};

    int size = WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr.data(),
        static_cast<int>(wstr.size()),
        nullptr,
        0,
        nullptr,
        nullptr
    );

    if (size == 0) {
        /* Handle error in case of unsuccessful conversion*/
    }

    std::string result(size, '\0');

    WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr.data(),
        static_cast<int>(wstr.size()),
        result.data(),
        size,
        nullptr,
        nullptr
    );

    return result;
}