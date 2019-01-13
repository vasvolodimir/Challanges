#include "snake/snake.h"

Snake::Snake(Field *parent)
    : m_field(parent),
      m_snake(0),
      m_head(nullptr)
{
    initSnake();
}

Snake::~Snake()
{
    for(int i=0; i<m_snake.size(); i++)
        delete m_snake[i];

    /* XXX: Chunk items should free by window class */
}

void Snake::initSnake()
{
    size_t init_count = 3;
    QVector<Spot*> spots = m_field ? m_field->getSpots() : QVector<Spot*>();

    if (spots.isEmpty())
    {
        qDebug() << "Init snake error!";
        return;
    }

    for(size_t i=init_count; i>0; i--)
        m_snake.push_back(createChunk(spots[i - 1]));
}

Chunk *Snake::createChunk(Spot *spot)
{
    Chunk *chunk = new Chunk;

    if (!m_head)
    {
        m_head = chunk;
        chunk->next = nullptr;
    }
    else
        chunk->next = m_snake.back();

    chunk->spot = spot;
    chunk->item = new QGraphicsRectItem(spot->area);

    if (chunk == m_head)
        chunk->item->setBrush(Qt::yellow);
    else
        chunk->item->setBrush(Qt::green);

    updateChunkPath(chunk);

    return chunk;
}

void Snake::updateChunkPath(Chunk *chunk) const
{
    Chunk *current = chunk->next;

    while(current)
    {
        chunk->path.push_back(current->spot->id);
        current = current->next;
    }
}

void Snake::addSnake() const
{
    for(int i=0; i<m_snake.size(); i++)
        Window::instance().addItem(m_snake[i]->item);
}

void Snake::addChunk(int spot_id)
{
    QVector<Spot*> spots = m_field ? m_field->getSpots() : QVector<Spot*>();

    if (spots.isEmpty())
    {
        qDebug() << "Chunk adding error!";
        return;
    }

    createChunk(spots[spot_id]);
}
