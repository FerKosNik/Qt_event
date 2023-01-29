#include "MouseObserver.h"


MouseObserver::MouseObserver(QWidget *pParents)
    :QLabel(pParents)
{
    setAlignment(Qt::AlignCenter);

    setText("Init state");
}

void MouseObserver::mousePressEvent(QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse was pressed");
}

void MouseObserver::mouseReleaseEvent([[maybe_unused]]QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse was released");
}

void MouseObserver::mouseMoveEvent([[maybe_unused]]QMouseEvent *pe)
{
    dumpEvent(pe, "Mouse is moving");
}

void MouseObserver::dumpEvent(QMouseEvent *pe, const QString &message)
{
    setText(message
            + "\n buttons()= " + buttonInfo(pe)
            + "\n x()= " + QString::number (pe->x())
            + "\n y()= " + QString::number (pe->y())
            + "\n globalX()= " + QString::number (pe->globalX())
            + "\n globalY()= " + QString::number (pe->globalY())
            + "\n modifiers()= " + modifirstInfo(pe)
            );
}

QString MouseObserver::buttonInfo(QMouseEvent *pe)
{
    QString strButtons;

    if (pe->buttons() & Qt::LeftButton)
        strButtons += "Left ";

    if (pe->buttons() & Qt::MidButton)
        strButtons += "Mid ";

    if (pe->buttons() & Qt::RightButton)
        strButtons += "Right ";

    return strButtons;
}

QString MouseObserver::modifirstInfo(QMouseEvent *pe)
{
    QString strModifiers;

    if (pe->modifiers() & Qt::ShiftModifier)
        strModifiers += "Shift ";
    if (pe->modifiers() & Qt::ControlModifier)
        strModifiers += "Control ";
    if (pe->modifiers() & Qt::AltModifier)
        strModifiers += "Alt ";

    return strModifiers;
}
