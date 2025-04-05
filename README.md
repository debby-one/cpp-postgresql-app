# C++ PostgreSQL App

このプロジェクトは、C++を使用してPostgreSQLデータベースに接続し、指定されたテーブルからデータを取得して標準出力に表示するアプリケーションです。

## プロジェクト構成

- `src/main.cpp`: アプリケーションのエントリーポイント。データベースに接続し、データを取得して表示します。
- `include/database.hpp`: データベース接続に関するクラスや関数の宣言を含むヘッダーファイル。
- `lib`: 必要なライブラリを格納するディレクトリ。
- `Makefile`: プロジェクトのビルド設定を含むファイル。コンパイルコマンドやリンクオプションが指定されています。

## セットアップ手順

1. PostgreSQLデータベースをインストールし、必要なテーブルを作成します。
2. このリポジトリをクローンします。
   ```
   git clone <repository-url>
   ```
3. 必要な依存関係をインストールします。PostgreSQLのC++ライブラリ（例: libpqxx）を使用する場合、以下のコマンドを実行します。
   ```
   sudo apt-get install libpqxx-dev
   ```
4. プロジェクトをビルドします。
   ```
   make
   ```
5. アプリケーションを実行します。
   ```
   ./cpp-postgresql-app
   ```

## 依存関係

- C++コンパイラ（g++など）
- PostgreSQLデータベース
- libpqxx（PostgreSQLのC++ライブラリ）

## 使用方法

アプリケーションを実行すると、指定されたテーブルからデータが取得され、標準出力に表示されます。データベース接続の詳細は、`src/main.cpp`内で設定する必要があります。