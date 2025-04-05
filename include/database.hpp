#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <pqxx/pqxx> 
#include <string>
#include <vector>

class Database {
public:
    Database(const std::string& connectionString);
    ~Database();

    bool connect();
    void disconnect();
    std::vector<std::vector<std::string>> fetchData(const std::string& query);

private:
    std::string connectionString;
    pqxx::connection* conn;
};

#endif // DATABASE_HPP