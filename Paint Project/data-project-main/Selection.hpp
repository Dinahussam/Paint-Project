#pragma once

#include "AbstractGroup.hpp"

class VisualEntity;
class Group;

class Selection : public AbstractGroup
{
public:
    Selection();
    virtual ~Selection();
    Selection(Selection const &other);
    Selection& operator=(Selection const &other);

    void draw(QPainter *painter) override;
    void add(VisualEntity *val) override;

    VisualEntity* getLastSelected();
    bool isSelected(VisualEntity *val);
    void toggleSelect(VisualEntity *val);
    void deselectAll();
//    Group* makeGroup();

private:
    VisualEntity* m_lastSelected;
};

