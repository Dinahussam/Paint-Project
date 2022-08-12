#pragma once
#include <QPushButton>
#include <functional>

class Canvas;
class QColorDialog;

class PropertyColorButton : public QPushButton
{
public:
    PropertyColorButton(QWidget *parent,
                        Canvas *canvas, QColor startColor);
    PropertyColorButton(QWidget *parent,
                        Canvas *canvas,
                        std::function<QColor()> getter,
                        std::function<void(QColor)> setter);
    void setGetterSetter(std::function<QColor()> getter,
                         std::function<void(QColor)> setter);
    void setColor(QColor color);
    QColor getColor() const;
    void unlink();
    QColorDialog* getColorDialog() const;
    ~PropertyColorButton();

private:
    PropertyColorButton(QWidget *parent, Canvas *canvas);
    QMetaObject::Connection m_connection;
    QColorDialog *m_colorDialog;
    Canvas *m_canvas;
    QColor m_color;
};

