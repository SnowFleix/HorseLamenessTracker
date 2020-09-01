#ifndef FILEHANDLER_H
#define FILEHANDLER_H

//QT libraries
#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QFileDialog>

//STL libraries
#include <string>

//Header files
#include "utilfunctions.h"

class FileHandler
{
public:
    FileHandler();
    ~FileHandler();

    QFile& GetFile(QWidget* widget);
    QFile& GetFile(std::string path);
    std::string GetTextFromFile(std::string path);
    std::string GetTextFromFile(QWidget* widget);
    std::vector<QFile> GetAllFilesFromDirectory(std::string directory);

private:
    std::string GetAllText(QFile& file);
};

#endif // FILEHANDLER_H
