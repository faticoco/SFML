#include "config.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    bool moving=false;
    bool moving_left=false;
    bool moving_up=false;
    bool moving_down=false;
    // Output project version
    std::cout << "Version: " << PROJECT_VERSION_MAJOR << "."
         << PROJECT_VERSION_MINOR << std::endl;
        
	
    // Create a window
    float height= 600 ;
    float width=800 ;
    sf::RenderWindow window(sf::VideoMode(width , height), "SFML Boilerplate");
    float sun_speed=5;
    window.setFramerateLimit(60);
    sf::CircleShape c(25);
    sf::CircleShape m(25);
    c.setFillColor(sf::Color::Yellow);
    m.setFillColor(sf::Color::White);
    c.setOrigin(sf::Vector2f(c.getRadius()/2 , c.getRadius()/2));
    m.setOrigin(sf::Vector2f(m.getRadius()/2 , m.getRadius()/2));
    sf::RectangleShape r(sf::Vector2f(50 , 25));
    r.setFillColor(sf::Color::White);   
    r.setPosition(400 , 300);
    m.setPosition(700 , 500);
    r.setOrigin(sf::Vector2f(r.getSize().x/2 ,r.getSize().y/2 ));
    // Handle closing the window
    while(window.isOpen()) 
    {
        sf::Event Event;
        while(window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
            if (Event.type == sf::Event::KeyPressed) {
                if (Event.key.code == sf::Keyboard::Escape)
                    window.close();
                if(Event.key.code == sf::Keyboard::Right){
                    moving=true;
                }
                if(Event.key.code == sf::Keyboard::Left){
                    moving_left=true;
                }
                if(Event.key.code == sf::Keyboard::Up){
                    moving_up=true;
                }
                if(Event.key.code == sf::Keyboard::Down){
                    moving_down=true;
                }
            }

            if (Event.type == sf::Event::KeyReleased) {
                if(Event.key.code == sf::Keyboard::Right){
                    moving=false;
                }
                if(Event.key.code == sf::Keyboard::Left){
                    moving_left=false;
                }
                if(Event.key.code == sf::Keyboard::Up){
                    moving_up=false;
                }
                if(Event.key.code == sf::Keyboard::Down){
                    moving_down=false;
                }
            }
        }
        if(moving)
        {
            if(c.getPosition().x+sun_speed < width)
            {
              c.move(sf::Vector2f(sun_speed , 0));
                
            }
        }
        if(moving_left)
        {
             if(c.getPosition().x-sun_speed > 0)
            {
              c.move(sf::Vector2f(-sun_speed , 0));
            }        
        }
        if(moving_up)
        {
              if(c.getPosition().y-sun_speed >0)
            {
              c.move(sf::Vector2f(0 , -sun_speed));
            }
        }
        if(moving_down)
        {
             if(c.getPosition().y+sun_speed < 600)
            {
              c.move(sf::Vector2f(0 , sun_speed));
            }
        }
        if(c.getGlobalBounds().intersects(m.getGlobalBounds()))
        {
            window.close();
        }
        
         if(c.getGlobalBounds().intersects(r.getGlobalBounds()))
        {
            c.setPosition(0 , 0);
        }
        
        window.clear(sf::Color::Blue);
        window.draw(c);
        window.draw(r);
        window.draw(m);
        window.display();
    }
    
    return 0;
}
