#include <QApplication>

#include "AppTemplates/QtApp.h"
#include "AppTemplates/QtNativeImage.h"
#include "Engine.h"

#include "Example/PlatformerEngine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Frog::QtApp *app = Frog::QtApp::createApp("Platformer", 800, 600, new PlatformerEngine());
    app->run();

    return a.exec();
}
