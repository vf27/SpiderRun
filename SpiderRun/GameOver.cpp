#include "GameOver.h"
#include "Menu.h"
#include "Match.h"
#include <SFML/Window/Keyboard.hpp>
#include <fstream>
#include <iostream>
#include "Puntos.h"
using namespace std;

GameOver::GameOver(int x) {

	m_tfondo.loadFromFile("Imagenes/fondoGameOver2.png");
	m_sfondo.setTexture(m_tfondo);
	m_sfondo.setPosition(0,0);
	
	Cargar(x);
	
	t6=to_string(x);
	m_t5.setString(t6);  //PUNTUACION ACTUAL QUE LE PASO DESDE MATCH 
	
	t8=to_string(puntajes[0]); 
	m_t8.setString(t8); 
	
	
	m_font.loadFromFile("Font2.ttf");
	
	m_t1.setFont(m_font);
	m_t1.setString("Presione Enter para volver a jugar");
	m_t1.setFillColor(Color::Yellow);
	m_t1.setPosition(20,435);
	m_t1.setCharacterSize(20);
	
	m_t2.setFont(m_font);
	m_t2.setString("Presione Escape para volver al menu");
	m_t2.setFillColor(Color::Yellow);
	m_t2.setPosition(0.5,455);
	m_t2.setCharacterSize(20);

	m_t4.setFont(m_font);
	m_t4.setString("Tu puntuacion:");
	m_t4.setFillColor(Color::Red);
	m_t4.setPosition(150,310);
	m_t4.setCharacterSize(25);
	
	m_t5.setFont(m_font);		// se muestra la Puntuacion Actual
	m_t5.setFillColor(Color::White);
	m_t5.setPosition(430,310);
	m_t5.setCharacterSize(25);
	
	m_t3.setFont(m_font);
	m_t3.setString("Mejor puntuacion:");
	m_t3.setFillColor(Color::Red);
	m_t3.setPosition(120,340);
	m_t3.setCharacterSize(25);
	
	m_t8.setFont(m_font);		// se muestra el puntaje mas alto
 	m_t8.setFillColor(Color::White);
	m_t8.setPosition(480,340);
	m_t8.setCharacterSize(25);
	
	m_t6.setFont(m_font);
	m_t6.setString("Presione T para ver la tabla de posiciones");
	m_t6.setFillColor(Color::Red);
	m_t6.setPosition(0.5, 390);
	m_t6.setCharacterSize(18);
		
}

void GameOver::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Return))
		game.SetScene(new Match());
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
		game.SetScene(new Menu()); 
	
	if(Keyboard::isKeyPressed(Keyboard::Key::T))
		game.SetScene(new Puntos());

}

void GameOver::Draw (RenderWindow & window) {
	window.clear({0,0,0});        
	window.draw(m_sfondo);   
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t5);
	window.draw(m_t8);
	window.draw(m_t3);
	window.draw(m_t4);
	window.draw(m_t6);
	window.display(); 
}

void GameOver::Cargar (int x ) {
	ifstream archi("Puntajes.txt");
	if (!archi) {	//chequeo que se pueda abrir el archivo
		cout << "Error: No se pudo abrir el archivo Puntajes.txt para lectura" << endl;
		return;
	}
	int aux;
	while(archi>>aux){ 				//uso la lectura como condicion de corte para guardar 
		puntajes.push_back(aux);	//los puntajes existentes en el vector 
	};
	archi.close();                                                   
	
	puntajes.push_back(x);			//guardo el nuevo puntaje 
	sort(puntajes.begin(),puntajes.end(),std::greater<int>());	//ordeno el vector
	
	if (puntajes.size() > 5) {
		puntajes.resize(5);  // mantengo solo los 5 mejores puntajes
	}
	
	ofstream archi2("Puntajes.txt", ios::trunc);	//borro el contenido del archivo de texto 
	if (!archi2) {									//chequeo que se pueda abrir para escritura
		cout << "Error: No se pudo abrir el archivo Puntajes.txt para escritura" << endl;
		return;
	}
	
	for (int i = 0; i < puntajes.size(); i++) {		//escribo el vector en el archivo
		archi2 << puntajes[i] << endl;
	}
	archi2.close();
	
//	cout << "Puntaje actual: " << x << endl;
//	cout << "Mejor puntaje: " << puntajes[0] << endl;  
}

