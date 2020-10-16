//
// Created by willofhouse on 10/10/20.
//
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <regex.h>
#include <vector>
#include <unordered_map>

#ifndef UNTITLED_BOOK_H
#define UNTITLED_BOOK_H


class Book {

public:
    // Run the constructor and generate any dynamic memory that may be necessary
    Book(std::string inputFile, std::string outputFile);

    // Import a text, process, and generate information
    std::vector<std::string> getBook();

    //count the number of words in each text, generate a report.
    void generateReport();

    //use regex to remove special characters
    void stripText();


private:
    ///////////////////////////////////////////////////
    //Insert into the cache
    void cacheInsert();

    //////////////////////////////////////////////////

    std::string inputFilename;

    std::string outputFilename;

    std::unordered_map<std::string, size_t> cache;


    void cacheInsert(std::vector<std::string> text);
};


#endif //UNTITLED_BOOK_H
