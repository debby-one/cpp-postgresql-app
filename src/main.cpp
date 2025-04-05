#include <iostream>
#include <libpq-fe.h>

int main() {
    // 接続文字列を設定
    const char* conninfo = "dbname=test user=postgres password=yourpassword";

    // データベースに接続
    PGconn* conn = PQconnectdb(conninfo);

    // 接続状態を確認
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "データベース接続エラー: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        return 1;
    }
    std::cout << "データベースに接続しました。" << std::endl;

    // SQLクエリを実行
    const char* query = "SELECT * FROM your_table_name";
    PGresult* res = PQexec(conn, query);

    // クエリ結果を確認
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "クエリエラー: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    // データを標準出力に表示
    int nrows = PQntuples(res);
    int nfields = PQnfields(res);
    for (int i = 0; i < nrows; i++) {
        std::cout << "データ: ";
        for (int j = 0; j < nfields; j++) {
            std::cout << PQgetvalue(res, i, j) << " ";
        }
        std::cout << std::endl;
    }

    // リソースを解放
    PQclear(res);

    // 接続を切断
    PQfinish(conn);
    std::cout << "データベース接続を切断しました。" << std::endl;

    return 0;
}