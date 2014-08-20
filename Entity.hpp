#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{
    public:
        void set_vel(double velociter);

        double get_vel();
    private:
        double m_velocite;
};

#endif // ENTITY_H_INCLUDED
