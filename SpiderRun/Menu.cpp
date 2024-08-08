#include "Menu.h"
#include "Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Puntos.h"
#include "Info.h"
using namespace sf;

Menu::Menu() {
	m_tfondo.loadFromFile("Imagenes/fondoMenu.png");
	m_sfondo.setTexture(m_tfondo);
	m_sfondo.setPosition(0,0);
	
	m_font.loadFromFile("Font2.ttf");
	m_t1.setFont(m_font);
	m_t2.setFont(m_font);
	m_t3.setFont(m_font);
	
	m_t3.setString("Presione I para ver las Instrucciones");
	m_t3.setFillColor({255,255,0});
	m_t3.setPosition(50,365);
	m_t3.setCharacterSize(18);
	
	m_t1.setString("Presione Enter para comenzar el juego");
	m_t1.setFillColor({255,255,0});
	m_t1.setPosition(30,380);
	m_t1.setCharacterSize(18);
	
	m_t2.setString("Presione T para ver la tabla de posiciones");
	m_t2.setFillColor({255,255,0});
	m_t2.setPosition(0.5,395);
	m_t2.setCharacterSize(18);
	
	
}

void Menu::Update (Game &game) { // el update recibe el juego para poder pedirle que cambie la escena
	if(Keyboard::isKeyPressed(Keyboard::Key::Return)) //cuando menu detecte un enter deberia decirle al juego
		game.SetScene(new Match());					// que cambie su puntero y que apunte a un match
	if(Keyboard::isKeyPressed(Keyboard::Key::T)) 
		game.SetScene(new Puntos());					
	
	if(Keyboard::isKeyPressed(Keyboard::Key::I)) 
		game.SetScene(new Info());					
}

void Menu::Draw (RenderWindow & window) {
	//window.clear({230,230,230}); //bordo
	window.draw(m_sfondo);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.display();	
}

