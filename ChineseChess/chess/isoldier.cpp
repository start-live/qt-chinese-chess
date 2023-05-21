﻿#include "isoldier.h"

#include "iglobal.h"

ISoldier::ISoldier(QObject *parent)
    : IAbstractChess(parent)
{

}

ISoldier::~ISoldier()
{

}

IChessType ISoldier::type()
{
    return IChessType::Soldier;
}

QList<IChessStep*> ISoldier::allPossibleSteps()
{
    QList<IChessStep*> stepList;

    QPoint newPos;
    IChessStep* pStep = nullptr;
    //上
    newPos = this->m_pos + QPoint(0, -1);
    pStep = canMoveTo(newPos);
    if (pStep != nullptr)
        stepList.append(pStep);

    //下
    newPos = this->m_pos + QPoint(0, 1);
    pStep = canMoveTo(newPos);
    if (pStep != nullptr)
        stepList.append(pStep);

    //左
    newPos = this->m_pos + QPoint(-1, 0);
    pStep = canMoveTo(newPos);
    if (pStep != nullptr)
        stepList.append(pStep);

    //右
    newPos = this->m_pos + QPoint(1, 0);
    pStep = canMoveTo(newPos);
    if (pStep != nullptr)
        stepList.append(pStep);

    return stepList;
}

bool ISoldier::canMove(const QPoint &newPos)
{
    //兵不能后退
    IAbstractChess* pGeneray = IGlobal::global().findChess(IChessType::General, m_camp);
    qint32 maxY = this->m_pos.y();
    qint32 minY = pGeneray->pos().y();
    if (pGeneray->pos().y() > this->m_pos.y())
    {
        maxY = pGeneray->pos().y();
        minY = this->m_pos.y();
    }
    if (newPos.y() > minY && newPos.y() < maxY)
        return false;

    //新位置与自己位置不是相隔一列或一行
    qint32 xDistance = qAbs(this->m_pos.x() - newPos.x());
    qint32 yDistance = qAbs(this->m_pos.y() - newPos.y());
    if (xDistance > 1 || yDistance > 1)
        return false;

    //可以移动到该位置
    return true;
}
