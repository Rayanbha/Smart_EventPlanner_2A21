#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class employee
{
    QString ID_emp,departement,first_name,password,last_name,ID_chef;
    int salary;
public:
    //constructeurs
    employee();
    employee(QString,QString,QString,QString,QString,QString,int);
    //getters
    QString getID(){return ID_emp;}
    QString getdepartement(){return departement;}
    QString getfirst(){return first_name;}
    QString getpassword(){return password;}
    QString getlast(){return last_name;}
    QString getchef(){return ID_chef;}
    int getsalary(){return salary;}
    //setters
    void setID(QString ident){ID_emp=ident;}
    void setdepartement(QString d){departement=d;}
    void setfirst(QString f){first_name=f;}
    void setpassword(QString p){password=p;}
    void setlast(QString l){last_name=l;}
    void setchef(QString c){ID_chef=c;}
    void setsalary(int sal){salary=sal;}
    //fonction
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString ID_emp);
    QSqlQueryModel * searchID(QString ID_emp);
    QSqlQueryModel * searchF(QString first_name);
    QSqlQueryModel * searchL(QString last_name);
    QSqlQueryModel * sort_Lastn();
    QSqlQueryModel * sort_firstn();
    QSqlQueryModel * sort_salary();

};

#endif // EMPLOYEE_H
