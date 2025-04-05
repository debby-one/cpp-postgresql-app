#include <iostream>
#include <libpq-fe.h>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

void showDialog(const std::string& message) {
#ifdef _WIN32
    MessageBoxA(NULL, message.c_str(), "情報", MB_OK | MB_ICONINFORMATION);
#elif __APPLE__
    std::string command = "osascript -e 'display dialog \"" + message + "\"'";
    system(command.c_str());
#elif __linux__
    std::string command = "zenity --info --text=\"" + message + "\"";
    system(command.c_str());
#else
    std::cerr << "ダイアログ表示はこのOSでサポートされていません。" << std::endl;
#endif
}

int main() {
    // 接続文字列を設定
    const char* conninfo = "dbname=test user=postgres password=yourpassword";

    // データベースに接続
    PGconn* conn = PQconnectdb(conninfo);

    // 接続状態を確認
    if (PQstatus(conn) != CONNECTION_OK) {
        std::string errorMessage = "データベース接続エラー: " + std::string(PQerrorMessage(conn));
        showDialog(errorMessage);
        PQfinish(conn);
        return 1;
    }
    showDialog("データベースに接続しました。");

    // SQLクエリを実行
    const char* query = "SELECT * FROM your_table_name";
    PGresult* res = PQexec(conn, query);

    // クエリ結果を確認
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::string errorMessage = "クエリエラー: " + std::string(PQerrorMessage(conn));
        showDialog(errorMessage);
        PQclear(res);
        PQfinish(conn);
        return 1;
    }

    // データをダイアログに表示
    int nrows = PQntuples(res);
    int nfields = PQnfields(res);
    std::ostringstream oss;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < nfields; j++) {
            oss << PQgetvalue(res, i, j) << " ";
        }
        oss << "\n";
    }
    showDialog("取得したデータ:\n" + oss.str());

    // リソースを解放
    PQclear(res);

    // 接続を切断
    PQfinish(conn);
    showDialog("データベース接続を切断しました。");

    return 0;
}