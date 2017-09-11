/**
 * Create a templated value-like library class to store books, movies etc
 * Each library item has the data and a set of related works
 * Each related work object has a ptr to the related works item.
 */ 
#include <iostream>

#include "Library.hpp"

// class to store the description of an item.
class Description {
public:
    Description(const std::string& d) : desc{d} {}
    friend std::ostream& operator<<(std::ostream&, const Description &);
private:
    std::string desc;
};

// function to print out a description object
std::ostream& operator<<(std::ostream &os, const Description &d) {
    os << d.desc;
    return os;
}

// class to store a Book
class Book {
public:
    Book(const std::string& b) : name{b} {}
    friend bool operator==(const Book&, const Book &);
    friend std::ostream& operator<<(std::ostream&, const Book &);
private:
    std::string name;
};

// method to compare books
bool operator==(const Book& a, const Book & b) {
    return a.name == b.name;
}

// method to print the book details
std::ostream& operator<<(std::ostream &os, const Book &b) {
    os << b.name;
    return os;
}

// TODO: create this class
class Movie {
public:
    Movie(const std::string& n, const std::string& dir, int s) : name{n}, director{dir}, stars{s} {}
    friend bool operator==(const Movie&, const Movie&);
    friend std::ostream& operator<<(std::ostream&, const Movie &);
private:
    std::string name;
    std::string director;
    int stars;
};

// method to compare movies
bool operator==(const Movie& a, const Movie &b) {
    return (a.name == b.name) && (a.stars == b.stars) && (a.director == b.director);
}

// method to print the movie details
std::ostream& operator<<(std::ostream &os, const Movie &b) {
    os << "(" << b.name << ", " << b.director << ", " << b.stars << ")\n";
    return os;
}

int main() {
    // create a book library
    Library<int, Description> intLibrary;


    intLibrary.add(1);
    intLibrary.add(2);
    Description d("they are both numbers less than 3 and greater than 0");
    intLibrary.addRelated(1, 2, d);

    std::cout << "the items related to 1 are...\n";
    intLibrary.printRelated(1);
}

