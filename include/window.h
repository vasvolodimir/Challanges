#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Window : public QGraphicsView
{
    Q_OBJECT

    Window(QWidget *parent = 0);
    Window(const QWidget&);
    Window &operator=(Window &);

public:
    static Window &instance(QWidget *parent = 0);
    ~Window();

    QSize sizeHint() const;
    void addItem(QGraphicsItem *item);
    void setBrush(QBrush brush);
    QGraphicsScene *getScene() const;

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    QGraphicsScene *createScene(QWidget *parent, QGraphicsScene **scene);

private:
        QGraphicsScene *m_scene;
};

#endif // WINDOW_H
