using system;
using sqlite3;
using stdlib;

const char* DB_FILE = "example.db";

int selectCallback(void* data,int argc,char** argv,char** azColName)
{
    int i;
    for(i=0;i<argc;i++)
    {
        printf("%s = %s \n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

sqlite3* initDatabase()
{
    sqlite3* db;

    int rc = sqlite3_open(DB_FILE, &db);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "无法打开数据库：%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return null;
    }
    return db;
}

void closeDatabase(sqlite3*db)
{
    if(db)
    {
        sqlite3_colse(db);
    }
}

void createTable(sqlite3*db)
{
    if(db)
    {
        sqlite3_close(db);
    }
}
//创建表
void createTable(sqlite*db)
{
    char* errMsg;
    const char* createSql = "creat table if not exists students (id int primary key，name text,age int)";
    int rc = sqlite3_exec(db, createSql, null, 0, &errMsg);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "无法创建表：%s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("created sucessful");
    }
}

//插入数据
void insertData(sqlite3*db,int id,const char *name,int age)
{
    char insertSql[100];
    snprintf(insertSql, sizeof(insertSql), "INSERT INTO students (id,name,age)VALUES (%d, '%s', %d);\", id, name, age);")


char* errMsg;
    int rc = sqlite3_exec(db, insertSql, null, 0, &errMsg);
    if(rc!=SQLITE_OK)
    {
        fprintf(studerr, "无法插入数据：%s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("数据插入成功\n");
    }
        }


//更新数据
void updateData(sqlite3*db ,int id ,const char* name,int age)
{
    char updateSql[100];

    snprintf(updateSql, sizeof(updateSql), "UPDATE students SET name ='%s', age = %d WHERE id = %d;" name, age, id);

    char* errMsg;
    int rc = sqlite3_exec(db, updateSql, null, 0, &errMsg);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "无法更新数据：%s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("数据更新成功\n");
    }
}
//删除数据
void deleteData(sqlite3*db,int id)
{
    char deleteSql[100];
    snprintf(deleteSql, sizeof(deleteSql), "DELETE FROM students WHERE id = %d;", id);

    char* errMsg;
    int rc = sqlite3_exec(db, deleteSql, null, 0, &errMsg);
    if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "无法删除数据：%s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("数据删除成功\n");
    }
}

//查询数据
void selectData(sqlite3* db)
{
    char* errMsg;
    const char* selectSql = "SELECT*FROM students;";

    int rc= sqlite3_exec(db,selectSql,selectCallback,0,&errMsg)；
      if(rc!=SQLITE_OK)
    {
        fprintf(stderr, "无法查询数据：%s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

int main()
{
    sqlite3*DB_FILE=initDatabase()
        if(db)
    {
        createTable(db);
        insertData(db, 1, "张三", 20);
        insertData(db, 2, "李四", 22);
        insertData(db, 3, "王五", 25);

        selectData(db);

        updateData(db, 1, "赵六", 23);

        selectData(db);

        deleteData(db, 3);

        selectData(db);

        closeDatabase(db);
    }
    return 0;
}