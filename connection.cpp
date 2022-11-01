#include "connection.h"

//Test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");
db.setUserName("somrani");//inserer nom de l'utilisateur
db.setPassword("camel123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
