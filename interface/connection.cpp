#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
db= QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("BD_projet");
db.setUserName("rayen");//inserer nom de l'utilisateur
db.setPassword("rayen");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;

    return  test;
}
void Connection::closeConnection(){db.close();}
