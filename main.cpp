#include <qfile.h>
#include <qstring.h>

#include "mainframe.h"
#include "application.h"

#include "Game.h"

int main(int argc, char *argv[]) {

    // Application
    Application application(argc, argv);

    // Just to have the maps!
    Game::getInstance().NewGame();

    // Load css
    QFile File(":/PowerGrid/Resources/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    // Main frame
    MainFrame mainframe("Power Grid");

    // Attach observer
    Game::getInstance().Attach(&mainframe);

    // Apply css
    application.setStyleSheet(StyleSheet);

    // Return
    return application.exec();
}