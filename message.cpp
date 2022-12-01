#include "message.h"

message::message(){}
message::message(QString msg)
{
  this->msg=msg;
}
QSqlQueryModel * message::affichermsg()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from message");
model->setHeaderData(0,Qt::Vertical,QObject::tr("message"));


return model;
}
bool message::sendmsg()
{
   QSqlQuery query;
   query.prepare("insert into message (msg)" "values (:msg)");
   query.bindValue(":msg", msg);
   return query.exec();
}
