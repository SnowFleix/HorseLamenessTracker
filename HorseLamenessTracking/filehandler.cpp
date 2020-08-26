#include "filehandler.h"

/////////////////////////////////////////////////////////////
/// \brief FileHandler::FileHandler
/// Default constructor
///
FileHandler::FileHandler() {

}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::~FileHandler
/// Default destructor
///
FileHandler::~FileHandler() {

}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetFile
/// Opens the file dialog and returns a QFile of the chosen
/// file
///
/// \param widget
/// The widget calling the fileDialog
///
/// \return
/// A reference to the generated QFile
///
QFile& FileHandler::GetFile(QWidget* widget) {
    QString fileName = QFileDialog::getOpenFileName(widget, "Open Tracking Data", "C:/", "Tracking Files (*.htp)");
    QFile returnFile(fileName);
    return returnFile;
}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetFile
/// Returns a QFile from a specified path
///
/// \param path
/// Full path the file is stored at
///
/// \return
/// A reference to the generated QFile
///
QFile& FileHandler::GetFile(std::string path) {
    QFile returnFile(util::toQString(path));
    return returnFile;
}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetTextFromFile
/// Gets all the text from a file
///
/// \param path
/// The full path to where the file is saved
///
/// \return
/// The full file text
///
std::string FileHandler::GetTextFromFile(std::string path) {
    QFile temp(util::toQString(path));
    return GetAllText(temp);
}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetTextFromFile
/// Gets all the text from a file the user chooses in the
/// file dialog
///
/// \param widget
/// The parent widget
///
/// \return
/// The full data within the file as text
///
std::string FileHandler::GetTextFromFile(QWidget* widget) {
    QString fileName = QFileDialog::getOpenFileName(widget, "Open Tracking Data", "C:/", "Tracking Files (*.htp)");
    QFile returnFile(fileName);
    return GetAllText(returnFile);
}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetAllFilesFromDirectory
/// Gets all the files from a directory
///
/// \param directory
/// The full path to the directory
///
/// \return
/// A vector of QFiles (only *.htp files) that are within the directory
///
std::vector<QFile> FileHandler::GetAllFilesFromDirectory(std::string directory) {
    std::vector<QFile> returnType;
    return returnType;
}

/////////////////////////////////////////////////////////////
/// \brief FileHandler::GetAllText
/// Gets all the text from a passed file
///
/// \param file
/// The the file to read the text from
///
/// \return
/// All the text from the file
///
std::string FileHandler::GetAllText(QFile& file) {
    if(!file.open(QFile::ReadOnly | QFile::Text)) return "";
    QTextStream in(&file);
    return util::QStringToStdString(in.readAll());
}
