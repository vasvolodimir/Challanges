#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

#include "window.h"
#include "engine.h"
#include "snake.h"

class Snake;

class Field : public QObject
{
    Q_OBJECT

    Field(QObject *parent = 0);
    Field(const Field&);
    Field &operator=(Field &);

    public:
            static Field &instance();
            ~Field();
            QVector<Spot*> &getSpots();

    private:
            void mapFieldBorders(size_t width, size_t height);
            QPointF calcStartPoint(size_t width, size_t height);
            double calcCoordinate(size_t &dimension, size_t scene_dimension);
            void createSpots();
            void drawLines(double x, double y) const;
    private:
            QGraphicsRectItem *m_arena;
            size_t m_width, m_height;
            QPointF m_start_point;
            size_t m_spot_size;
            QVector<Spot*> m_spots;
            size_t m_vcount, m_hcount;
            Snake *m_snake;
};

#endif // FIELD_H
