#ifndef FOLDERANDFILEOPERATIONSCOLLECTION_H
#define FOLDERANDFILEOPERATIONSCOLLECTION_H

#include <algorithm>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <qobject.h>
#include <stdio.h>
#include <string.h>

class FolderAndFileOperationsCollection : public QObject {
    Q_OBJECT
public:
    explicit FolderAndFileOperationsCollection(QObject *parent = nullptr);
    // read the number of Files in the reading Folder, recorded in 'count'
    int ReadNumOfFilesNameInTheReadFolder(std::string str, std::string ch);
    // read the current files' name in the reading folder, return to
    // 'ReadNumOfFilesInTheReadFolder'
    std::string Get_AllFileNames(std::string str);

    int count;
    // The former is the complete path, and the latter is the file name.
    char folder_path[300];
    char Completefile_list[1000][300];
    char SingleFileName_list[1000][300];

protected:
    static int cmp2(const void *a, const void *b);

private:
    //    friend MainWindow;
    //    friend DcmFormatConversion;
    // query and recorde the count of 'backslash'
    template <class C, class T> int CountBackSlash(const C &v, T val);

signals:

public slots:
};

#endif // FOLDERANDFILEOPERATIONSCOLLECTION_H
