#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#pragma once

#include "IObject.h"

#include <SDL.h>
#include <my-lib/math-vector.h>

using Vector = Mylib::Math::Vector<float, 2>;

struct Properties
{
public:
    Properties(float x, float y, float width, float height)
    {
        X = x;
        Y = y;
        Width = width;
        Heigth = height;    }

public:
    float Width, Heigth;
    float X, Y;
};

class GameObject : public IObject
{
public:
	Vector getPosition() const { return m_Position; }
    
    virtual ~GameObject() override = default;
    GameObject(const Properties& props): m_Width(props.Width), 
    m_Height(props.Heigth)
    {
        m_Position.x = props.X;
        m_Position.y = props.Y;
    }

protected:
    Vector m_Position;
    float m_Width, m_Height;
};

#endif // __GAME_OBJECT_H__