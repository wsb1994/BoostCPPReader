#include <iostream>
#include <boost/algorithm/algorithm.hpp>
#include <boost/asio.hpp>
#include "Book.h"
#include <stdlib.h>
#include <memory>
//libboost-all-dev

// handler to pass in objects and begin the threaded process
void parse(std::string inputFile, std::string outputFile) {
    std::unique_ptr<Book> newBook{new Book(inputFile, outputFile)};
    newBook->generateReport();
}

// reads in the list of filenames
std::vector<std::string> getFiles() {
    std::ifstream fin("filenames");
    std::string inputFile, outputFile, input;
    std::vector<std::string> textFiles;

    while (fin >> inputFile) {
        textFiles.push_back(inputFile);
    }

    fin.close();
    return textFiles;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> fileNames = getFiles();
    if (argc > 1) {
        ///////////////////////////////////////////////////////////////////////////
        int threads = atoi(argv[1]);
        boost::asio::thread_pool pool(threads);
        ///////////////////////////////////////////////////////////////////////////

        //************************************************************************
        for (auto inputFile : fileNames) {
            boost::asio::post(pool, std::bind(parse, inputFile, inputFile + ".report"));
        }
        //************************************************************************
        pool.join();
    } else {

        for (auto i : fileNames) {
            parse(i, i + ".report");
        }
    }
    return 0;
}
