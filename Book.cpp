//
// Created by willofhouse on 10/10/20.
//
#include "Book.h"
#include <iomanip>

// Run the constructor and generate any dynamic memory that may be necessary

struct output {
    std::string key;
    int count;

    inline bool operator<(output a) {
        return count < a.count;
    }

    inline bool operator>(output a) {
        return count > a.count;
    }

    inline bool operator<=(output a) {
        return count <= a.count;
    }

    inline bool operator>=(output a) {
        return count >= a.count;
    }
};

Book::Book(std::string inputFile, std::string outputFile) {
    this->inputFilename = inputFile;
    this->outputFilename = outputFile;

    std::vector<std::string> text = this->getBook();
    this->cacheInsert(text);
}

// Import a text, process, and generate information
std::vector<std::string> Book::getBook() {

    std::ifstream fin(this->inputFilename);
    std::string input;
    std::vector<std::string> text;
    while (fin >> input) {
        if (input != "")
            text.push_back(input);
    }
    fin.close();
    return text;
}

//count the number of words in each text, generate a report.
void Book::generateReport() {
    std::ofstream fout(this->outputFilename);
    std::vector<output> output;
    for (auto const &pair: this->cache) {
        struct output newOutPut;
        newOutPut.count = pair.second;
        newOutPut.key = pair.first;
        output.push_back((newOutPut));
    }
    //sort in reverse order for fun
    std::sort(output.rbegin(), output.rend());
    for (auto const &pair: output) {
        fout << std::setw(20) << std::left << pair.key << ":  " << std::setw(10) << pair.count << std::endl;
    }
    fout.close();
}

//use regex to remove special characters
 void Book::stripText() {

}

#expensive, probably don't need to do that.
void Book::cacheInsert(std::vector<std::string> text) {
    auto cache = this->cache;
    std::for_each(std::begin(text), std::end(text), [&cache](std::string c) {
        cache[c]++;
    });
    this->cache = cache;
}
