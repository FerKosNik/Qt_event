#pragma once

#include <QtWidgets>

class MouseObserver : public QLabel
{
public:
    MouseObserver(QWidget* pParents = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);

    void dumpEvent(QMouseEvent* pe, const QString &message);
    QString buttonInfo(QMouseEvent* pe);
    QString modifirstInfo(QMouseEvent* pe);
};
