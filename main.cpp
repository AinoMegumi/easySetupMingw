#include <iostream>
#include <cstdlib>
#include <filesystem>

int main() {
    try{
        // すでにインストールしてある環境ではインストール不要なのでskip
        if (!std::filesystem::exists("C:\\ProgramData\\chocolatey\\bin\\choco.exe")) {
            std::cout << "GCCをインストールするために必要なプログラムをインストールします。" << std::endl;
            std::system("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe \"Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString(\'https://chocolatey.org/install.ps1\'))\"");
            std::cout << "OK" << std::endl;
            // インストールに失敗したらエラーを表示して終了
            if (!std::filesystem::exists("C:\\ProgramData\\chocolatey\\bin\\choco.exe") throw std::runtime_error("Failed to install chocolatey");
        }
        std::cout << "GCCをインストールします。" << std::endl;
        std::system("C:\\ProgramData\\chocolatey\\bin\\choco.exe install mingw");
        std::cout << "インストールが完了しました!" << std::endl;
        std::cout << "コマンドプロンプトを開き、gccコマンドが動作するかを確認してください。" << std::endl;
        std::system("pause");
    }
    catch (const std::exception& er) {
        std::cerr << er.what() << std::endl;
    }
    return 0;
}
