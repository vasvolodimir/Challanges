#ifndef ENGINE_H
#define ENGINE_H

#include <QRect>

struct Spot
{
    int id;
    QRect area;

    Spot(int _id, QRect _area)
        : id(_id),
          area(_area)
    { }
};

#endif // ENGINE_H
