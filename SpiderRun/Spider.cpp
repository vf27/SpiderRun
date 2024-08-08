#include "Spider.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
using namespace std;
using namespace sf;

Spider::Spider() : Object("Imagenes/SpiderQuieto.png"){ // constructor del spider
	m_sprite.setScale(0.2,0.2);
//	m_sprite.setPosition(20,365);
	m_texturaSalto.loadFromFile("Imagenes/SpiderSaltando.png");
	m_texturaAgachado.loadFromFile("Imagenes/SpiderAgachado.png");
	saltando = false;
	agachado = true; 
}

void Spider::Update (sf :: FloatRect platform1_bounds,sf :: FloatRect platform2_bounds ) {
	
	m_speed.y +=.5;						//velocidad a la que se tiene que mover
	m_pos += m_speed;					//donde se tiene que mover
	
	m_sprite.setPosition(m_pos);		//movimiento
	auto sprite_bounds = m_sprite.getGlobalBounds();
	
	if (sprite_bounds.intersects(platform1_bounds) || sprite_bounds.intersects(platform2_bounds)) { //los limites del spider chocan con los limites de la plataforma
		m_speed.y = 0; //detiene la velocidad vertical del spider 
		m_pos.y = platform1_bounds.top - sprite_bounds.height; // ubica el sprite teniendo en cuenta el limite superior de la plataforma y el la altura del sprite
		saltando = false;
		m_sprite.setTexture(m_texture);  // Volver al sprite normal
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			m_speed.y = -15;
			saltando = true;
			m_sprite.setTexture(m_texturaSalto);  // Cambiar al sprite de salto
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			
			m_sprite.setTexture(m_texturaAgachado);  // Cambiar al sprite de salto
		}
		
	} else {
		saltando = true;
		m_sprite.setTexture(m_texturaSalto);  // Mantener el sprite de salto mientras está en el aire
	}
	
	
	m_sprite.setPosition(m_pos);
}
