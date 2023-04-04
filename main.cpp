#include <iostream>
#include <pqxx/pqxx>
#include "classes.hpp"

using std::string;

int main()
{
    try
    {
        // connect to the db
        string conn_string = "host=localhost port=5432 dbname=record_store user=postgres password=postgres";
        pqxx::connection conn(conn_string);

        // start a transaction
        pqxx::work txn(conn);

        // drop tables
        txn.exec("DROP TABLE IF EXISTS records;");
        // txn.commit();

        // create a table
        txn.exec("CREATE TABLE records( id SERIAL PRIMARY KEY, artist VARCHAR(255) UNIQUE NOT NULL, album VARCHAR(255) NOT NULL, genre VARCHAR(255) NOT NULL, year INTEGER NOT NULL);");

        // insert into table
        txn.exec("INSERT INTO records (artist, album, genre, year) VALUES ('DEVO', 'Duty Now For The Future', 'Punk', 1979)");

        // Commit the transaction
        // txn.commit();
        std::cout << "Table created successfully!" << std::endl;

        // retrieve results from table
        pqxx::result result = txn.exec("SELECT id, artist FROM records");
        for (pqxx::result::const_iterator row = result.begin(); row != result.end(); ++row)
        {
            std::cout << "id: " << row[0].as<int>() << ", artist: " << row[1].as<std::string>() << std::endl;
        }
        txn.commit();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Record record1 = Record("Devo", "Duty Now For The Future", "Rock", 1978);
    // record1.printDetails();
    std::cout << "Success" << std::endl;
    return 0;
}