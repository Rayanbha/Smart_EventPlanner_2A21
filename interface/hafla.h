#ifndef HAFLA_H
#define HAFLA_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QFileDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
//#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>

class Events
{
private :
    int id_event ;
    QString id_emp ;
    QString nom_event;
    QString type_event;
    QString client_event;
    QDate date_event;
    float cost_event;
    int guest_number ;
    float reduction_event ;


public:
    Events();
    Events( int ,QString , QString , QString  , QString , QDate , float , int  );
    QSqlQueryModel * afficher();
        bool ajouter();
          bool supprimer(QString) ;
         bool modifier(int id_event );
         QSqlQueryModel *tri_date();
         QSqlQueryModel* tri_type();
         QSqlQueryModel * recherche(QString );
         QSqlQueryModel* tri_id();
       void statistique(QVector<double>* ticks,QVector<QString> *labels);
       //  void CREATION_PDF();
         float alerte();

};

namespace Ui {
class hafla;
}

class hafla : public QDialog
{
    Q_OBJECT

public:
    explicit hafla(QWidget *parent = nullptr);
    ~hafla();
private slots:

    void on_pushButton_add_event_clicked();
    void on_pushButton_delete_event_clicked();
     void on_pushButton_modify_event_clicked();

     void on_tableView_event_activated(const QModelIndex &index);

     void on_TRI_NAME_clicked();

     void on_TRI_DATE_clicked();

     void on_TRI_TYPE_clicked();

     void on_pushButton_pdf_event_clicked();
     ////stat
    QVector<double> statistiques();
     void makePlot();

    void on_pushButton_statistic_event_clicked();
    void on_tableView_event_doubleClicked(const QModelIndex &index);
       //  void on_tableView_event_clicked(const QModelIndex &index);
    void on_pushButtontop_event_2_clicked();

    void on_pushButton_reduction_event_clicked();
    void on_search_event_textChanged(const QString &arg1);

private:
    Ui::hafla *ui;
    Events etmp ;
};


#endif // HAFLA_H
