#include "employee.h"

employee::employee(){}
employee::employee(QString ID_emp,QString departement,QString first_name,QString password,QString last_name,QString ID_chef,int salary)
{
this->ID_emp=ID_emp;
this->departement=departement;
this->first_name=first_name;
this->password=password;
this->last_name=last_name;
this->ID_chef=ID_chef;
this->salary=salary;
}
bool employee::ajouter()
{
   QSqlQuery query;
   QString res = QString::number(salary);
   query.prepare("insert into employee (ID_emp,departement,first_name,password,last_name,ID_chef,salary)" "values (:ID_emp, :departement, :first_name, :password, :last_name, :ID_chef, :salary)");
   query.bindValue(":ID_emp", ID_emp);
   query.bindValue(":departement", departement);
   query.bindValue(":first_name", first_name);
   query.bindValue(":password", password);
   query.bindValue(":last_name", last_name);
   query.bindValue(":ID_chef", ID_chef);
   query.bindValue(":salary", res);
   return query.exec();
}
QSqlQueryModel * employee::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from employee");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

return model;
}
bool employee::supprimer(QString ID_emp)
{
QSqlQuery query;
query.prepare("Delete from  employee where ID_emp= :id");
query.bindValue(":id",ID_emp);
return query.exec();
}
bool employee::modifier(QString ID_emp)
{
QSqlQuery query;
QString res = QString::number(salary);
query.prepare("update employee set departement='"+departement+"', first_name='"+first_name+"', last_name='"+last_name+"', password='"+password+"', salary='"+res+"', ID_chef='"+ID_chef+"'where ID_emp='"+ID_emp+"'");
query.bindValue(":departement", departement);
query.bindValue(":first_name", first_name);
query.bindValue(":password", password);
query.bindValue(":last_name", last_name);
query.bindValue(":ID_chef", ID_chef);
query.bindValue(":salary", res);
return query.exec();

}
QSqlQueryModel * employee::searchID(QString ID_emp)
{
 QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from employee where ID_emp like '"+ID_emp+"%'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
 return model;
}
QSqlQueryModel * employee::searchF(QString first_name)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee where first_name like '"+first_name+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
    return model;
}
QSqlQueryModel * employee::searchL(QString last_name)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee where last_name like '"+last_name+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
    return model;
}
QSqlQueryModel * employee::sort_Lastn()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by Last_name");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;

}
QSqlQueryModel * employee::sort_firstn()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by first_name");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;

}
QSqlQueryModel * employee::sort_salary()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by salary");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;

}


