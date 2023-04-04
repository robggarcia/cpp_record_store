#include "classes.hpp"
#include <iostream>
#include <sstream>
#include <pqxx/pqxx>
using std::string;
using namespace std;

// *****************************
//            RECORD
// *****************************

// // constructor
// Record::Record(string artist, string album, string genre, int year)
//     : Artist(artist), Album(album), Genre(genre), Year(year) {}

void Record::printDetails()
{
    cout << Artist << endl;
    cout << Album << endl;
    cout << Genre << endl;
    cout << Year << endl;
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

void Record::newRecord()
{
    cout << "Enter the name of the Artist: ";
    cin >> Artist;
    cout << "Enter the name of the Album: ";
    cin >> Album;
    cout << "Entery the Genre: ";
    cin >> Genre;
    cout << "Entery the Year release: ";
    cin >> Year;
    cout << "Entery the Price of the Album: ";
    cin >> Price;

    stringstream stmt;
    stmt.str("");
    stmt << "INSERT INTO records (artist, album, genre, year, price) VALUES ('" << Artist << "','" << Album << "','" << Genre << "','" << Year << "','" << Price << "') RETURNING *;";
    string query = stmt.str();

    // connect to the db
    string conn_string = "host=localhost port=5432 dbname=record_store user=postgres password=postgres";
    pqxx::connection conn(conn_string);

    // start a transaction
    pqxx::work txn(conn);
    pqxx::result result = txn.exec(query);

    if (result.query().size() > 0)
        cout << endl
             << endl
             << "Record Inserted Successfully" << endl
             << endl
             << endl;
    else
        cout << endl
             << endl
             << "Entry ERROR!" << endl
             << endl
             << endl;

    txn.commit();
}