#include "Enemigo.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace sf; 
using namespace std;

Enemigo::Enemigo() : Object(){
	Reiniciar();
}

void Enemigo::Update() {
	
	m_sprite.move( m_speed);
	
	if (m_sprite.getPosition().x < -100) {
		Reiniciar();
	}
}

void Enemigo::Reiniciar() {
	m_sprite = Sprite();
	
	int nuevoTipo = rand() % imagenes.size();
	
	if (nuevoTipo == ultimoTipo || nuevoTipo == penultimoTipo) {
		nuevoTipo = (nuevoTipo + 1) % 10;
		if (nuevoTipo == ultimoTipo || nuevoTipo == penultimoTipo) {
			nuevoTipo = (nuevoTipo + 1) % 10;
		}
	}
	
	penultimoTipo = ultimoTipo;
	ultimoTipo = nuevoTipo;
	tipo = nuevoTipo;	
	
	
	if (m_texture.loadFromFile(imagenes[tipo])) {
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(escalas[tipo]);
		
		float posX = 640;
		float posY = posiciones[tipo].y;
		
		float spriteHeight = m_sprite.getGlobalBounds().height;
		posY = std::min(std::max(posY, spriteHeight), 480.0f - spriteHeight);
		
		m_sprite.setPosition(posX, posY);
		
		cout << "Enemigo tipo " << tipo << " cargado" << endl;
		
	} else {
		cout << "Error: No se pudo cargar la imagen " << imagenes[tipo] << endl;
	}
	
}
