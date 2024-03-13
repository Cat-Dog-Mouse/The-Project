#include "stusql.h"
#include "stusql.h"
#include <QMessageBox>
//#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
stuSql * stuSql::ptrstuSql = nullptr;
stuSql::stuSql(QObject *parent) : QObject(parent)
{
    /*if(QSqlDatabase::drivers().isEmpty())
        QMessageBox::information(nullptr,tr("NO database drivers found"),
                                 tr("this demo requires at least one qt database driver."
                                    "please check the documentation how to build the"
                                    "qt sql plugins."));
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("G:\\data.db");
    if(!db.open())
        QMessageBox::warning(nullptr,tr("unable to open database"),tr("error"));

    QSqlQuery q("",db);*/
//    init();
//    StuInfo s;
//    s.sno="201815121";
//    addStu(s);
//    getStuCnt();
//    getPageStu(2,3);//第二页三个数据
//    delStu();

//    q.exec("INSERT INTO student VALUES('201815121','张刚' ,'男',20,'15098010000')");
//    q.exec("INSERT INTO student VALUES('201815122','吴敏'  ,'女',20,'13215894111')");
//    q.exec("INSERT INTO student VALUES('201815124','张浩中','男',19,'17856299998')");
//    q.exec("INSERT INTO student VALUES('201815125','李智敏','女',20,'15666639558')");
//    q.exec("INSERT INTO student VALUES('201815126','赵茜慧','女',21,'17852987456')");
//    q.exec("INSERT INTO student VALUES('201815127','高明哲','男',19,'18022233233')");
//    q.exec("INSERT INTO student VALUES('201815128','张新辉','男',20,'18689997171')");
//    q.exec("INSERT INTO student VALUES('201815129','刘成'  ,'男',18,'18689880444')");
//    q.exec("INSERT INTO book VALUES('1001','西游记' ,'吴承恩','神魔',18,2)");
//    q.exec("INSERT INTO book VALUES('1002','水浒传' ,'施耐庵','世情',20,0)");
//    q.exec("INSERT INTO book VALUES('1003','三国演义' ,'罗贯中','历史',20,0)");
//    q.exec("INSERT INTO book VALUES('1004','红楼梦' ,'曹雪芹','古典',19,1)");
//    q.exec("INSERT INTO book VALUES('1005','傲慢与偏见' ,' 简·奥斯汀','写实',20,0)");
//    q.exec("INSERT INTO book VALUES('1006','福尔摩斯全集' ,'柯南道尔','侦探',19,1)");
//    q.exec("INSERT INTO book VALUES('1007','三体' ,'吴承恩','科幻',20,0)");
//    q.exec("INSERT INTO book VALUES('1008','解忧杂货铺' ,'东野圭吾','悬疑',19,1)");
//    q.exec("INSERT INTO borrow VALUES('201815121','1001','未还' ,'2022-12-08','2022-12-23')");
//    q.exec("INSERT INTO borrow VALUES('201815122','1001','未还' ,'2022-12-09','2022-12-24')");
//    q.exec("INSERT INTO borrow VALUES('201815124','1004','未还' ,'2022-12-07','2022-12-22')");
//    q.exec("INSERT INTO borrow VALUES('201815126','1006','未还' ,'2022-12-10','2022-12-25')");
//    q.exec("INSERT INTO borrow VALUES('201815128','1008','未还' ,'2022-12-05','2022-12-20')");
}

void stuSql::init()
{
    if(QSqlDatabase::drivers().isEmpty())

       /* QMessageBox::information(nullptr,tr("NO database drivers found"),
                                 tr("this demo requires at least one qt database driver."
                                    "please check the documentation how to build the"
                                    "qt sql plugins."));*/
    qDebug()<<"NO database drivers found";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    //记得把db文件放在exe文件同级文件夹
#if 0
    auto str = QCoreApplication::applicationDirPath()+"data.db";
    qDebug()<<str;
#endif
    m_db.setDatabaseName("G:\\data.db");
    if(!m_db.open())
        qDebug()<<"db not open";
}
/*
exec()内就是要测试的sql语句，
info是结构体，代表一个元组，按info里的码顺序输入值，arg()是要传进去的参数也是要按顺序
%1，%2这些是参数，直接替换成要输入的数值
可能有的错误有语句的表写错了、标点符号不符合规范、sql语句的填写顺序没有和arg，info一样。
有问题直接告诉我我好改，手机打字太慢了，所以写在注释上，寄
*/
quint32 stuSql::getStuCnt()//求学生数量
{
    QSqlQuery sql(m_db);
    sql.exec("select count(sno) from student;");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt =  sql.value(0).toUInt();

    }
    return uiCnt;
}

quint32 stuSql::getBookCnt()//求书本数量
{
    QSqlQuery sql(m_db);
    sql.exec("select count(bno) from book;");
    quint32 uiCnt = 0;
    while(sql.next()){
        uiCnt =  sql.value(0).toUInt();

    }
    return uiCnt;
}

QList<StuInfo> stuSql::getPageStu(quint32 page, quint32 uiCnt)//查询第几页学生数据，从第零页开始。
{
     QList<StuInfo> l;
     QSqlQuery sql(m_db);
     QString strsql = QString("select * from student order by sno limit %1 offset %2").
             arg(uiCnt).
             arg(page*uiCnt);
     sql.exec(strsql);
     StuInfo info;
     while(sql.next()){
         info.sno =  sql.value(0).toString();
         info.sname =  sql.value(1).toString();
         info.ssex =  sql.value(2).toString();
         info.sage =  sql.value(3).toUInt();
         info.phone =  sql.value(4).toString();
         l.push_back(info);
     }
     return l;


}

bool stuSql::addStu(StuInfo info)//增加学生
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into student values('%1','%2','%3','%4','%5')").
            arg(info.sno).
            arg(info.sname).
            arg(info.ssex).
            arg(info.sage).
            arg(info.phone );
    return sql.exec(strSql);
}

bool stuSql::addBook(BookInfo info)//增加书本
{/*struct BookInfo{
    QString bno;
    QString bname;
    QString author;
    QString type;
    qint32 amount;
    qint32 frequency;
*/
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into book values('%1','%2','%3',%4,%5)").
            arg(info.bno).
            arg(info.bname).
            arg(info.author).
            arg(info.type).
            arg(info.amount).
            arg(info.frequency);
    return sql.exec(strSql);
}

bool stuSql::delStu(QString sno)//删除学生
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where sno = %1").arg(sno));
//    quint32 uiCnt = 0;
//    while(sql.next()){
//        uiCnt =  sql.value(0).toUInt();
//    }
//    return uiCnt;

}

bool stuSql::delBook(QString bno)//删除课本
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from book where bno = %1").arg(bno));
    /*struct BookInfo{
        QString bno;
        QString bname;
        QString author;
        QString type;
        qint32 amount;
        qint32 frequency;
    */

}

bool stuSql::clearStuTable()//清理学生表
{
    QSqlQuery sql(m_db);

    return sql.exec("delete from student ");
}

bool stuSql::clearBookTable()//清书本表
{
    QSqlQuery sql(m_db);
    return sql.exec("delete from book ");
}

bool stuSql::UpdateStuInfo(StuInfo info)//更新学生
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update student set sname = %1,ssex = %2,sage= %3,phone = %4 where sno = %5").
            arg(info.sname).
            arg(info.ssex).
            arg(info.sage).
            arg(info.phone).
            arg(info.sno);
//    bool ret =
       return sql.exec(strSql);
//  QSqlError e = sql.lastError();
//   if(e.isValid()){
//        qDebug()<<e.text();
//   }

//   return ret;
}

bool stuSql::UpdateBookInfo(BookInfo info)//更新课本
{
    /*struct BookInfo{
        QString bno;
        QString bname;
        QString author;
        QString type;
        qint32 amount;
        qint32 frequency;
    */
    QSqlQuery sql(m_db);
    QString strSql = QString("update book set bname = '%1',author='%2',type = '%3'，amount = %4，frequency = %5 where bno = '%6'").
            arg(info.bname).
            arg(info.author).
            arg(info.type).
            arg(info.amount).
            arg(info.bno);
    bool ret = sql.exec(strSql);
   QSqlError e = sql.lastError();
   if(e.isValid()){
        qDebug()<<e.text();
   }

   return ret;
}

QList<UserInfo> stuSql::getAllUser()//获取所有用户
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);

    sql.exec("select * from username");
    UserInfo info;
    while(sql.next()){
        info.username =  sql.value(0).toString();
        info.password =  sql.value(1).toString();
        info.aut =  sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

QList<BookInfo> stuSql::getAllBook()//获取所有课本
{
    /*struct BookInfo{
        QString bno;
        QString bname;
        QString author;
        QString type;
        qint32 amount;
        qint32 frequency;
    */
    QList<BookInfo> l;
    QSqlQuery sql(m_db);

    sql.exec("select * from book");
    BookInfo info;
    while(sql.next()){
        info.bname =  sql.value(0).toString();
        info.bno =  sql.value(1).toString();
        info.author =  sql.value(2).toString();
        info.type = sql.value(3).toString();
        info.amount = sql.value(4).toUInt();
        info.frequency = sql.value(0).toUInt();
        l.push_back(info);
    }
    return l;
}

bool stuSql::isExit(QString strUser)//用户是否存在
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select * from username where username = '%1'").arg(strUser));
    return sql.next();
}

bool stuSql::updateUser(UserInfo info)//更新用户
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update username set password = '%1',aut = '%2' where username = '%3'").
            arg(info.password).
            arg(info.aut).
            arg(info.username);
    bool ret = sql.exec(strSql);
   QSqlError e = sql.lastError();
   if(e.isValid()){
        qDebug()<<e.text();
   }

   return ret;
}


bool stuSql::AddUser(UserInfo info)//增加用户
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into username values('%1','%2','%3')").
            arg(info.username).
            arg(info.password).
            arg(info.aut);
    return sql.exec(strSql);
}

bool stuSql::delUser(QString strUserName)//删除用户
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delect from username where username = '%1'").arg(strUserName));

}
