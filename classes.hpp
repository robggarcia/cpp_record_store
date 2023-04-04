#include <iostream>
using std::string;

class Record
{
private:
    string Artist;
    string Album;
    string Genre;
    int Year;

public:
    Record(string artist, string album, string genre, int year);
    void printDetails();
    string getArtist();
    void setArtist(string artist);
    string getAlbum();
    void setAlbum(string album);
    string getGenre();
    void setGenre(string genre);
    int getYear();
    void setYear(int year);
};