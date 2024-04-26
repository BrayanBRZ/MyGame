#ifndef __RIGIDBODY_H__
#define __RIGIDBODY_H__

#include "../Object/gameObject.h"
#include <my-lib/math-vector.h>

using Vector = Mylib::Math::Vector<float, 2>;

inline constexpr float UNI_MASS = 1.0f;
inline constexpr float FRICTION = 0.8f;

inline constexpr int UPWARD = -1;
inline constexpr int DOWNWARD = 1;

inline constexpr int RIGHTWARD = 1;
inline constexpr int LEFTWARD = -1;

class RigidBody
{
public:
    Vector m_Force;

    RigidBody() = default;

    // Setters
    inline void SetMass(float mass) { m_Mass = mass; }
    inline void SetFriction(double Fr) { m_Friction = Fr; }

    // Force
    inline void ApplyForce(Vector F) { m_Force = F; }
    inline void ApplyForceX(float fX) { m_Force.x = fX; }
    inline void ApplyForceY(float fY) { m_Force.y = fY; }
    inline void UnsetForce() { m_Force.set_zero(); }

    // Getters
    inline float GetMass() { return m_Mass; }
    inline Vector Velocity() { return m_Velocity; }
    inline Vector Acceleration() { return m_Acceleration; }

    // Update methode
    void Update(float dt, Vector& position)
    {
        m_Acceleration.x = (m_Force.x * m_Friction) / m_Mass;
        m_Acceleration.y = (m_Force.y * m_Friction) / m_Mass;
        m_Velocity = m_Acceleration * dt;
        position += m_Velocity * dt;
    }

private:
    float m_Mass { UNI_MASS };
    float m_Friction { FRICTION };

    Vector m_Velocity {};
    Vector m_Acceleration {};
};

#endif //__RIGIDBODY_H__