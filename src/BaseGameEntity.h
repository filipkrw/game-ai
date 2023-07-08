#ifndef BASE_GAME_ENTITY_H
#define BASE_GAME_ENTITY_H

#include <iostream>
#include "util/Vector2.h"

class BaseGameEntity
{
private:
    int m_ID;
    static int m_iNextValidID;
    void SetID(int val) { m_ID = val; }

protected:
    Vector2 m_vPosition;
    Vector2 m_vScale;
    double m_dRotation;

public:
    BaseGameEntity(int id)
    {
        std::cout << id << std::endl;
        SetID(id);
    }

    BaseGameEntity(int id, Vector2 position, Vector2 scale, double rotation)
    {
        SetID(id);
        m_vPosition = position;
        m_vScale = scale;
        m_dRotation = rotation;
    }

    // virtual ~BaseGameEntity() {}
    // virtual void Update() = 0;

    int ID() const { return m_ID; }
    Vector2 Pos() const { return m_vPosition; }
};

#endif // BASE_GAME_ENTITY_H