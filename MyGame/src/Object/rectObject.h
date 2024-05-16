#ifndef __RECT_OBJECT_H__
#define __RECT_OBJECT_H__

#pragma once

#include "gameObject.h"

struct Properties
{
    float Width, Heigth;
    float X, Y;
};

class RectObject : public GameObject
{
public:
    RectObject(const Properties& props): m_Width(props.Width), 
    m_Height(props.Heigth)
    {
        m_Position.x = props.X;
        m_Position.y = props.Y;
    }

protected:
    float m_Width, m_Height;
};

#endif // __RECT_OBJECT_H__