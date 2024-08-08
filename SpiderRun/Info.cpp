#include "Info.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"

Info::Info() {
	m_tfondo.loadFromFile("Imagenes/fondoPuntajes.png");			//FONDO FIJO 
	m_sfondo.setTexture(m_tfondo);
	m_sfondo.setPosition(0,0);
	
	m_font1.loadFromFile("Font1.ttf");
	m_t1.setFont(m_font1);
	
	m_t1.setString("COMO JUGAR");
	m_t1.setFillColor({125, 4, 0});
	m_t1.setPosition(180,120);
	m_t1.setCharacterSize(60);
	
	m_font2.loadFromFile("Font2.ttf");
	m_t2.setFont(m_font2);
	
	m_t2.setString("Debes evitar los \nEnemigos durante \nel mayor tiempo \nposible  \n\nPresiona la barra \nespaciadora para \nsaltar");
	m_t2.setFillColor(Color::Black);
	m_t2.setPosition(200,210);
	m_t2.setCharacterSize(25);
	
	m_t3.setFont(m_font2);
	m_t3.setString("Pesione Escape para volver al menu");
	m_t3.setFillColor(Color::Yellow);
	m_t3.setPosition(10,455);
	m_t3.setCharacterSize(20);
}

void Info::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) //si apreto escape vuelvo al menu
		game.SetScene(new Menu());
}

void Info::Draw (RenderWindow & window) {
	window.draw(m_sfondo);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.display();	
}

