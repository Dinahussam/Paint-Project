#pragma once

#include <QWidget>
#include <vector>
#include <memory>

class VisualEntity;
class Group;
class ActiveSelection;
class Tool;
class SelectionTool;

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0);
    virtual ~Canvas();
    VisualEntity *getVEFromPosition(int x, int y);
    void setBackgroundColor(QColor val);
    void addVisualEntity(VisualEntity *val);
    void setActiveTool(Tool *val);
    Group *getMainGroup();
    void setMainGroup(Group *group);

protected:
    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent *event) override;

private:
    Group *m_mainGroup;
    ActiveSelection *m_selection;
    Tool *m_activeTool;
};

