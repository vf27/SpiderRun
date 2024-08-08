#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"


using namespace sf;

//inicializa la ventana
Game::Game(): m_window(VideoMode(640,480),"SpiderRun") { //constructor
	m_window.setFramerateLimit(60);
	m_scene = new Menu(); //le indico la escena inicial, inicializo con un puntero a menu
}
//Bucle de evento
void Game::Run ( ) {
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if(m_next_scene){
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}
void Game::ProcessEvents ( ) {
	Event e;
	while(m_window.pollEvent(e)) {
		if(e.type == Event::Closed)
			m_window.close();	
	}
}
void Game::Update ( ) {
	m_scene->Update(*this);//le paso el juego
}

void Game::Draw ( ) { 
	m_scene->Draw(m_window); //puntero a escena
}

void Game::SetScene (Scene *next_scene) {
	m_next_scene = next_scene;	
}
