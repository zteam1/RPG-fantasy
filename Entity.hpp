#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
    public:
        void set_vel(double velociter);
        void set_pos(sf::Vector2f position);

        double get_vel();
        sf::Vector2f get_pos();

    private:
        double m_velocite;
        sf::Vector2f m_positions;
};

#endif // ENTITY_H_INCLUDED
