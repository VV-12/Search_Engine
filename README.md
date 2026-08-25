# C++ Text Search Engine

A basic terminal-based text search engine implemented in C++.

## How it works

The search pipeline is:

1. Load every `.txt` document from `documents/`.
2. Tokenize the document text.
3. Remove stop words using `assets/stopWords.txt`.
4. Stem the remaining tokens using the Porter stemmer.
5. Build an inverted index mapping each term to the documents containing it and its occurrence count.
6. Accept a word from the terminal, apply the same normalization/stemming, and return matching documents.

The results are ordered by the number of occurrences of the searched term, highest first.

## Build

The Porter stemmer currently uses Windows-specific APIs, so build this project with a Windows C++ compiler supporting C++17.

From the project root:

```bash
g++ -std=c++17 main.cpp DocumentLoader.cpp Tokenizer.cpp StopWordRemover.cpp PorterStemmer.cpp InvertedIndex.cpp -o search_engine
```

## Run

### To build the executable

```bash
g++ -std=c++17 main.cpp DocumentLoader.cpp Tokenizer.cpp StopWordRemover.cpp PorterStemmer.cpp InvertedIndex.cpp -o search_engine.exe
```

Run the executable from the repository root so that the relative paths `documents/` and `assets/stopWords.txt` resolve correctly:

```bash
./search_engine
```

On Windows PowerShell:

```powershell
.\search_engine.exe
```

Example interaction:

```text
Loading documents...
Successfully loaded  ... stop words
Loaded 6 documents.
Search engine is ready.

Enter a word to search (type 'exit' to quit).

Search: alice
Found ... matching document(s):
  - alice_in_wonderland.txt (... occurrences)

Search: sailing
Found ... matching document(s):
  - The_Misplaced_Battleship.txt (... occurrences)

Search: xyzabc
No matches found for 'xyzabc'.

Search: exit
Search engine closed.
```

## Current scope

This version intentionally focuses on the search-engine backend and terminal demonstration. It does not include a GUI, web interface, ranking algorithms such as TF-IDF/BM25, phrase search, or fuzzy search.
