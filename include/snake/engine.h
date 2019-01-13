#ifndef ENGINE_H
#define ENGINE_H

#include <QRect>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>

struct Spot
{
    int id;
    QRect area;

    Spot(int _id, QRect _area)
        : id(_id),
          area(_area)
    { }
};

class Engine : public QObject
{
    Q_OBJECT

    Engine(QObject *parent = 0);
    Engine(const Engine &);
    Engine &operator =(Engine &);

    public:
            static Engine &instance();
            void handleKeyPress(QKeyEvent *event);

    private:
            QTimer *createTimer(QObject *parent, int interval, QObject *handler,
                                const char *slot, QTimer **timer);
    private slots:
                void move();

    private:
            QTimer *m_timer;
};

#endif // ENGINE_H
