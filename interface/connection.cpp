#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
db= QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("projet_cpp");
db.setUserName("rayan");//inserer nom de l'utilisateur
db.setPassword("rayan");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}
void Connection::closeConnection(){db.close();}
