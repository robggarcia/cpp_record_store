#include <iostream>
using std::string;

class Record
{
private:
    string Artist;
    string Album;
    string Genre;
    int Year;
    int Price;

public:
    // Record(string artist, string album, string genre, int year);
    void printDetails();
    string getArtist();
    void setArtist(string artist);
    string getAlbum();
    void setAlbum(string album);
    string getGenre();
    void setGenre(string genre);
    int getYear();
    void setYear(int year);

    void newRecord();
    void updatePrice();
    void searchRecord();
    void updateRecord();
    void displayRecord();
};

class User
{
private:
    string Name;
    int Purchases;
    bool Admin;

public:
    void addUser();
    void searchUser();
    void setAdmin();
    bool checkAdmin();
    void addPurchase();
};

class Purchase
{
private:
    int RecordId;
    int UserId;
    int Quantity;

public:
    void newPurchase();
    void displayPurchase();
};