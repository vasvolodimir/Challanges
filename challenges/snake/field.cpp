#include "snake/field.h"

Field::Field(QObject *parent)
    : QObject(parent),
      m_arena(nullptr),
      m_width(1300),
      m_height(700),
      m_spot_size(20)
{
    int width = Window::instance().getScene()->width();
    int height = Window::instance().getScene()->height();

    mapFieldBorders(width, height);
    createSpots();
}

Field &Field::instance()
{
    static Field instance;

    return instance;
}

Field::~Field()
{

}

void Field::mapFieldBorders(size_t width, size_t height)
{
    calcStartPoint(width, height);

    m_arena = new QGraphicsRectItem;
    m_arena->setBrush(Qt::black);
    m_arena->setRect(m_start_point.x(), m_start_point.y(), m_width, m_height);
    Window::instance().addItem(m_arena);
}

double Field::calcCoordinate(size_t &dimension, size_t scene_dimension)
{
    if (dimension < scene_dimension)
        return (scene_dimension - dimension) / 2;

    if (dimension > scene_dimension)
    {
        while(dimension > scene_dimension)
            dimension -= 100;

        if (dimension < scene_dimension)
            return (scene_dimension - dimension) / 2;
    }

    return 0;
}

QPointF Field::calcStartPoint(size_t width, size_t height)
{
    m_start_point.setX(calcCoordinate(m_width, width));
    m_start_point.setY(calcCoordinate(m_height, height));

    return m_start_point;
}

void Field::createSpots()
{
    bool draw = true;
    double x = m_start_point.x();
    double y = m_start_point.y();
    int id = 0;

    if (draw)
        drawLines(x, y);

    for(size_t i = y; i < y + m_height; i += m_spot_size)
        for(size_t j = x; j < x + m_width; j += m_spot_size)
        {
            m_spots.push_back(new Spot(id, QRect(j, i, m_spot_size,
                             m_spot_size)));
            id++;
        }
 }

void Field::drawLines(double x, double y) const
{
    QGraphicsLineItem *line;

    /* XXX: Vertical lines */
    for(size_t i = x + m_spot_size; i < x + m_width; i += m_spot_size)
    {
        line = new QGraphicsLineItem(i, y, i, y + m_height);
        line->setPen(QPen(Qt::white, 1, Qt::DashLine));
        Window::instance().addItem(line);
    }

    /* XXX: Horizontal lines */
    for(size_t i = y + m_spot_size; i < y + m_height; i += m_spot_size)
    {
        line = new QGraphicsLineItem(x, i, x + m_width, i);
        line->setPen(QPen(Qt::white, 1, Qt::DashLine));
        Window::instance().addItem(line);
    }
}
