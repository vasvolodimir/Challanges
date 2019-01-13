#include "snake/engine.h"

Engine::Engine(QObject *parent)
    : QObject(parent),
      m_timer(nullptr)
{

}

Engine &Engine::instance()
{
    static Engine instance;

    return instance;
}

void Engine::handleKeyPress(QKeyEvent *event)
{

}

QTimer *Engine::createTimer(QObject *parent, int interval, QObject *handler,
                            const char *slot, QTimer **timer)
{
    (*timer) = new QTimer(parent);
    (*timer)->setInterval(interval);
    connect(*timer, SIGNAL(timeout()), handler, slot);

    return *timer;
}

void Engine::move()
{

}
