#include <iostream>
#include <string>
#include <Windows.h>
#include <direct.h>

std::string getFilePath()
{
    char path[FILENAME_MAX];
    _getcwd(path, sizeof(path));
    return path;
}

void renamefile()
{

    TCHAR szExeFileName[MAX_PATH];
    GetModuleFileName(NULL, szExeFileName, MAX_PATH);
    std::string path = std::string(szExeFileName);
    std::string exe = path.substr(path.find_last_of("\\") + 1, path.size());

    srand(time(0));
    char letters[] = "01V8YutSgDmzEX8pK3gimydac1Sn2eWa9g3z";
    char newname[20];

    int z = rand() % 6 + 6;
    for (int i = 0; i < z; i++)
    {
        char x = letters[rand() % 36];
        newname[i] = x;
    }
    newname[z] = 0x0;
    strcat_s(newname, ".exe\0");
    rename(exe.c_str(), newname);
}

int main()
{
    renamefile();
    Sleep(100);
    return 0;
}
