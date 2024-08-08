#include "Puntos.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include "Game.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
using namespace sf; 

Puntos::Puntos() {
	m_tfondo.loadFromFile("Imagenes/fondoPuntajes.png");
	m_sfondo.setTexture(m_tfondo);
	m_sfondo.setPosition(0,0);
	
	m_font1.loadFromFile("Font2.ttf");
	m_font2.loadFromFile("Font1.ttf");
	
	m_t1.setFont(m_font2);
	m_t1.setString("PUNTUACIONES  \nMAS ALTAS:");
	m_t1.setFillColor(Color::Red);
	m_t1.setPosition(200,80);
	m_t1.setCharacterSize(40);
	
	p1.setFont(m_font1);
	p1.setString("1:"); 
	p1.setFillColor(Color::White);
	p1.setPosition(200,180);
	p1.setCharacterSize(50);
	
	p2.setFont(m_font1);
	p2.setString("2:"); 
	p2.setFillColor(Color::White);
	p2.setPosition(200,230);
	p2.setCharacterSize(50);
	
	p3.setFont(m_font1);
	p3.setString("3:"); 
	p3.setFillColor(Color::White);
	p3.setPosition(200,280);
	p3.setCharacterSize(50);
	
	p4.setFont(m_font1);
	p4.setString("4:"); 
	p4.setFillColor(Color::White);
	p4.setPosition(200,330);
	p4.setCharacterSize(50);
	
	p5.setFont(m_font1);
	p5.setString("5:");
	p5.setFillColor(Color::White);
	p5.setPosition(200,380);
	p5.setCharacterSize(50);
	
	
	Carga();
	
	stringstream ss;
	ss<<vectorPuntajes[0]<<endl<<vectorPuntajes[1]<<endl<<vectorPuntajes[2]
		<<endl<<vectorPuntajes[3]<<endl<<vectorPuntajes[4]<<endl;
	scores.setFont(m_font1);
	scores.setCharacterSize(50);
	scores.setFillColor(Color::Blue);
	scores.setPosition(290,180);
	scores.setString(ss.str());
	
	m_t2.setFont(m_font1);
	m_t2.setString("Presione Escape para volver al menu");
	m_t2.setFillColor(Color::Yellow);
	m_t2.setPosition(40,455);
	m_t2.setCharacterSize(18);
	
}

void Puntos::Update(Game &game){
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu()); 
}

void Puntos::Carga(){
	int aux;
	ifstream archivoPuntos("Puntajes.txt");
	while (archivoPuntos >> aux) {
		vectorPuntajes.push_back(aux);
	}
	archivoPuntos.close();
}



void Puntos::Draw(RenderWindow &window){
	window.clear(Color(255,255,255,255));
	window.draw(m_sfondo); 
	window.draw(m_t1); 
	window.draw(m_t2);
	window.draw(p1); 
	window.draw(p2); 
	window.draw(p3); 
	window.draw(p4); 
	window.draw(p5); 
	window.draw(scores);
	window.display();
	
}

