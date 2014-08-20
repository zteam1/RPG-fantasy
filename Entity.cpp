#include <SFML/Graphics.hpp>
#include "Entity.h"

void Entity::set_vel(double velociter)
{
    m_velocite = velociter;
}

void Entity::set_pos(sf::Vector2f position)
{
    m_positions = position;
}

double Entity::get_vel()
{
    return m_velocite;
}

sf::Vector2f Entity::get_pos()
{
    return m_positions;
}
