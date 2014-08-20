#include <SFML/Graphics.hpp>
#include "Entity.h"

void Entity::set_vel(double velociter)
{
    m_velocite = velociter;
}

double Entity::get_vel()
{
    return m_velocite;
}
