#ifndef SNAKE_H
#define SNAKE_H

#include "snake/engine.h"
#include "snake/field.h"
#include <QGraphicsRectItem>
#include <QVector>

class Field;

struct Chunk
{
    Spot *spot;
    QGraphicsRectItem *item;
    Chunk *next;
    QVector<int> path;
};

class Snake
{
    public:
            Snake(Field *parent = 0);
            ~Snake();
            void addSnake() const;
            void addChunk(int spot_id);
    private:
            Chunk *createChunk(Spot *spot);
            void initSnake();
            void updateChunkPath(Chunk *chunk) const;
    private:
            Field *m_field;
            QVector<Chunk*> m_snake;
            Chunk *m_head;
};

#endif // SNAKE_H
