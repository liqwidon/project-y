#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"
#include <string>
#include <vector>
#include <QString>
using namespace std;

/// \brief modes of notes(with/without date&&time)
enum MODES
{
    note = 0,
    event = 1,
    notice = 2
};

/// \brief memoNoteOutputInfo serves to structurize info got from the table
/// data type caused by output format from table
struct memoNoteOutputInfo
{
    const unsigned char* mode;
    const unsigned char* name;
    const unsigned char* text;
    const unsigned char* date;
    const unsigned char* time;
};


/// \brief memoNoteInputInfo serves to structurize info needed to put into the table
struct memoNoteInputInfo
{
    string mode;
    string name;
    string text;
    string date;
    string time;
};

struct QStringInfo
{
    QString mode;
    QString name;
    QString text;
    QString date;
    QString time;
};

class Database
{
public:
    Database(){};

    /// \brief create Calendary if not exists yet(open it else)
    void createTable();

    /// \brief insert row with data into the db
    /// \param info - input info
    void insert(memoNoteInputInfo info);
    
    void insert(vector<QString> info);

    vector<QStringInfo> select();

    /// \brief search in the table by any attribute
    /// \param modifier - the basis of the search
    vector<QStringInfo> selectSearch(string modifier);

    void update(string name, memoNoteInputInfo info);

    /// \brief delete all table
    void deleteTable();

    /// \brief delete chosen raws(notes)
    /// \param modifier the basis of the selection what to delete
    void deleteChosen(string modifier);


    void close();

private:
    sqlite3* db;
    char* err;
};

#endif // DATABASE_H
