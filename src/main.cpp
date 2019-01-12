#include "window.h"
#include <QApplication>

#ifdef CONFIG_SNAKE_MODULE
#include "snake/field.h"
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window::instance();

#ifdef CONFIG_SNAKE_MODULE
    Field::instance();
#endif

    return a.exec();
}
