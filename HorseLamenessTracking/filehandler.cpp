#include "filehandler.h"

FileHandler::FileHandler() {

}

FileHandler::~FileHandler() {

}

QFile& FileHandler::GetFile(QWidget* widget) {
    QString fileName = QFileDialog::getOpenFileName(widget, "Open Tracking Data", "C:/", "Tracking Files (*.htp)");
    QFile returnFile(fileName);
    return returnFile;
}

QFile& FileHandler::GetFile(std::string path) {
    QFile returnFile(util::toQString(path));
    return returnFile;
}

std::string FileHandler::GetTextFromFile(std::string path) {
    QFile temp(util::toQString(path));
    return GetAllText(temp);
}

std::string FileHandler::GetTextFromFile(QWidget* widget) {

}

std::vector<QFile> FileHandler::GetAllFilesFromDirectory(std::string directory) {

}

std::string FileHandler::GetAllText(QFile& file) {
    std::string fileText = "";
    if(!file.open(QFile::ReadOnly | QFile::Text)) return "";
    QTextStream in(&file);
    fileText << in.readAll();
}
