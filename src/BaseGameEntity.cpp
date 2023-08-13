#include "BaseGameEntity.h"
#include <iostream>

int BaseGameEntity::m_iNextValidID = 0;

void BaseGameEntity::SetID()
{
    m_ID = m_iNextValidID;
    m_iNextValidID = m_ID + 1;

    std::cout << "m_ID: " << m_ID << std::endl;

    assert((m_ID + 1 == m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
}