#include "folderandfileoperationscollection.h"

FolderAndFileOperationsCollection::FolderAndFileOperationsCollection(
    QObject *parent)
    : QObject(parent) {}

int FolderAndFileOperationsCollection::ReadNumOfFilesNameInTheReadFolder(
    std::string rootdirPath, std::string ch) {
    DIR *dir;
    struct dirent *ptr;
    count = 0;
    std::string x, dirPath, filename;           // Intermediate variable
    dir = opendir((char *)rootdirPath.c_str()); // open one Folder

    while ((ptr = readdir(dir)) != NULL) {
        x        = ptr->d_name;
        dirPath  = rootdirPath + '/' + x;
        filename = x;

        //        char ch[5] = ".dcm";
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            if ((dirPath.c_str())[strlen(dirPath.c_str()) - 4 + i] != ch[i]) {
                flag = false;
            }
        }
        //        printf("d_name : %s\n", dirPath.c_str());
        if (flag) {
            //            printf("d_name : %s\n", filename.c_str());
            strcpy(Completefile_list[count], dirPath.c_str());
            strcpy(SingleFileName_list[count], filename.c_str());
            count++;
        }
    }
    std::qsort(Completefile_list, count, sizeof(char) * 300, cmp2);
    std::qsort(SingleFileName_list, count, sizeof(char) * 300, cmp2);
    closedir(dir);
}

std::string
FolderAndFileOperationsCollection::Get_AllFileNames(std::string str) {
    int countBackSlash = CountBackSlash(str, '/');
    const char *p      = str.c_str();
    int i              = 0;
    while (i++ < countBackSlash) {
        p = strchr(p, '/');
        if (!p)
            break;
        p++;
    }
    return p;
}

int FolderAndFileOperationsCollection::cmp2(const void *a, const void *b) {
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    return strcmp(s1, s2);
}

template <class C, class T>
int FolderAndFileOperationsCollection::CountBackSlash(const C &v, T val) {
    typename C::const_iterator iter = std::find(v.begin(), v.end(), val);
    int cnt                         = 0;
    while (iter != v.end()) {
        ++cnt;
        ++iter;
        iter = std::find(iter, v.end(), val);
    }
    return cnt;
}
