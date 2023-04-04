#include "classes.hpp"
#include <iostream>
using std::string;

// *****************************
//            RECORD
// *****************************

// constructor
Record::Record(string artist, string album, string genre, int year)
    : Artist(artist), Album(album), Genre(genre), Year(year) {}

void Record::printDetails()
{
    std::cout << Artist << std::endl;
    std::cout << Album << std::endl;
    std::cout << Genre << std::endl;
    std::cout << Year << std::endl;
}

// getters and setters
string Record::getArtist()
{
    return Artist;
}
void Record::setArtist(string artist)
{
    Artist = artist;
}
string Record::getAlbum()
{
    return Album;
}
void Record::setAlbum(string album)
{
    Album = album;
}

string Record::getGenre()
{
    return Genre;
}

void Record::setGenre(string genre)
{
    Genre = genre;
}

int Record::getYear()
{
    return Year;
}

void Record::setYear(int year)
{
    Year = year;
}
