#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlDatabase>
struct StuInfo{
    QString   sno;
    QString   sname;
    QString	ssex;
    quint8  sage;
    QString phone;

};
struct UserInfo{
    QString username;
    QString password;
    QString aut;
};
struct BookInfo{
    QString bno;
    QString bname;
    QString author;
    QString type;
    qint32 amount;
    qint32 frequency;

};
struct BorInfo
{
    QString sno;
    QString bno;
    qint8 bcondition;
    QString borrow_time;
    QString return_time;
};
class stuSql : public QObject
{
    Q_OBJECT
public:
    static stuSql *ptrstuSql;
    static stuSql *getinstance()
    {
    if(nullptr == ptrstuSql){
        ptrstuSql = new stuSql;

    }
    return ptrstuSql;


    }
    explicit stuSql(QObject *parent = nullptr);
    void init();
//查询学生数量
    quint32 getStuCnt();
//查询书本数量
    quint32 getBookCnt();
//查询第几页学生数据，从第零页开始。
    QList<StuInfo> getPageStu(quint32 page,quint32 uiCnt);
//增加学生
    bool addStu(StuInfo);
//增加书本
    bool addBook(BookInfo);
//删除学生
    bool delStu(QString sno);
//删除书本
    bool delBook(QString bno);
//清空学生表
    bool clearStuTable();
//清空书本表
    bool clearBookTable();
//修改学生信息
    bool UpdateStuInfo(StuInfo info);
//修改书本信息
    bool UpdateBookInfo(BookInfo info);
//查询所有用户
    QList<UserInfo> getAllUser();
//查询所有书本
    QList<BookInfo> getAllBook();
//查询用户是否存在
    bool isExit(QString strUser);
//更新用户信息
    bool updateUser(UserInfo info);
//添加单个用户
    bool AddUser(UserInfo info);

//删除单个用户
    bool delUser(QString strUserName);

signals:
private:
    QSqlDatabase m_db;
};

#endif // STUSQL_H
