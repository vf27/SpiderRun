#include "Match.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "Menu.h"
#include "GameOver.h"
#include <cstdlib>
#include <ctime>
#include "Enemigo.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


#include <iostream>
using namespace std;
using namespace sf;


Match::Match(){
	m_tfondo.loadFromFile("Imagenes/fondoDia.png");			//FONDO FIJO 
	m_sfondo.setTexture(m_tfondo);
	m_sfondo.setPosition(0,0);
	
	m_tplataforma1.loadFromFile("Imagenes/plataforma.png");			//PLATAFORMA FIJA 
	m_splataforma1.setTexture(m_tplataforma1);
	m_splataforma1.setPosition(0, 412);
	
	plataformaRect = m_splataforma1.getGlobalBounds();
	
	m_tplataforma2.loadFromFile("Imagenes/plataforma.png");			//PLATAFORMA 2 FIJA 
	m_splataforma2.setTexture(m_tplataforma2);
	m_splataforma2.setPosition(plataformaRect.width, 412);
	
	m_font.loadFromFile("Font2.ttf");
	
	m_t1.setFont(m_font);
	m_t1.setString("Puntos: ");
	m_t1.setFillColor(Color::Yellow);
	m_t1.setPosition(370,0);
	m_t1.setCharacterSize(25);
	
	m_t3 = to_string(puntos);
	m_t2.setFont(m_font);
	m_t2.setString(m_t3);
	m_t2.setFillColor(Color::Yellow);
	m_t2.setPosition(520,0);
	m_t2.setCharacterSize(25);
	
	m_tNivel.setFont(m_font);
	m_tNivel.setString("Nivel: 1"); // inicializo el nivel en 1 
	m_tNivel.setFillColor(Color::Yellow);
	m_tNivel.setPosition(10, 0);
	m_tNivel.setCharacterSize(25);
	
	m_tfondoNoche.loadFromFile("Imagenes/fondoNoche.png");
	m_sfondoNoche.setTexture(m_tfondoNoche);
	m_sfondoNoche.setPosition(0,0);
	
	
}
void Match::Update (Game &game ) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) //si apreto escape vuelvo al menu
		game.SetScene(new Menu());
	
	if (m_splataforma1.getPosition().x < -plataformaRect.width) {
		m_splataforma1.setPosition(plataformaRect.width-5, 412);
	}
	if (m_splataforma2.getPosition().x < -plataformaRect.width) {
		m_splataforma2.setPosition(plataformaRect.width-5, 412);
	}
	
	m_splataforma1.move(m_speed);
	m_splataforma2.move(m_speed);
	
	srand(time(NULL));	
	puntos = (puntos)+1;
	
	m_spider.Update(m_splataforma1.getGlobalBounds(),m_splataforma2.getGlobalBounds()); // le paso la ubicacion exacta de donde esta la plataforma
	m_enemigo.Update();
	
	if (m_spider.CollideWith(m_enemigo)) {
		game.SetScene(new GameOver(puntos));
		return;
	}

	if (puntos >= siguienteNivel) {
		nivel++;
		siguienteNivel += 500;
		m_tNivel.setString("Nivel: " + to_string(nivel));
		
		noche = !noche; //cambio el fondo 
		if (nivel <= 7) { //cuando llega al nivel 8 se mantiene 
			Vector2f nuevaVelocidad = m_enemigo.VelocidadActual();
			nuevaVelocidad.x -= 1.0f; // aumento la velocidad 
			m_enemigo.Velocidad(nuevaVelocidad);
		}
	}
	
	m_t3 = to_string(puntos);			
	m_t2.setString(m_t3);
}


void Match::Draw ( RenderWindow &window) {
	window.clear(Color(230,230,230,255));
	
	if (noche) window.draw(m_sfondoNoche);
	else window.draw(m_sfondo);
	
	window.draw(m_splataforma1);
	window.draw(m_splataforma2);
	m_spider.Draw(window); // le indico al spider que se dibuje en la ventana de juego

	m_enemigo.Draw(window);
	
	window.draw(m_tNivel);
	window.draw(m_t2);
	window.draw(m_t1);
	window.display();
}
