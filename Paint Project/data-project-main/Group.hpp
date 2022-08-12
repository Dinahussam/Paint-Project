#pragma once

#include "AbstractGroup.hpp"
#include "VisualEntity.hpp"

class Group : public AbstractGroup, public VisualEntity
{
public:
    Group();
    ~Group();

    void add(VisualEntity *val) override;

    VisualEntity* getClicked(int x, int y);

    void draw(QPainter *painter) override;
    bool contains(int x, int y) override;

    void remove(int index) override;
    void remove(VisualEntity *val) override;

    void clear();

    // as visual entity inherits IDrawable and ITransformable, we need to
    // reimplement it again (just reuse implementation from AbstractGroup)
    QRect getBoundary() override          { return AbstractGroup::getBoundary(); }
    void setPosition(const QPoint &pos) override { AbstractGroup::setPosition(pos);     }
    QPoint getPosition() override         { return AbstractGroup::getPosition(); }
};
