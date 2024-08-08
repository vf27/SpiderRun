#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Object.h"
#include <string>
#include <vector>
using namespace std;

class Enemigo : public Object {
	int tipo, ultimoTipo ,penultimoTipo;
	int currentTipo = 0;
	vector<string> imagenes = {"Imagenes/Lagarto.png", "Imagenes/Octopus.png", "Imagenes/Duende.png", "Imagenes/Electro.png", "Imagenes/Venom.png",
		"Imagenes/Mysterio.png", "Imagenes/SandMan.png", "Imagenes/Vulture.png","Imagenes/HydroMan.png", "Imagenes/Thanos.png"};
	vector<Vector2f> posiciones = {{300,325}, {400,315}, {200,250},{300,317},{300,335},{300,320},{300,330},{300,255},{300,305},{300,320}};
	vector<Vector2f> escalas = {{0.19,0.19}, {0.19,0.19}, {0.2,0.2},{0.21,0.21},{0.2,0.2},{0.25,0.25},{0.2,0.2},{0.35,0.35},{0.27,0.27},{0.2,0.2}};	
	Vector2f m_speed = {-6,0}; 	
public:
	Enemigo();
	void Update();
	void Reiniciar();
	void Velocidad(Vector2f nueva_velocidad) { m_speed = nueva_velocidad; }
	Vector2f VelocidadActual() const { return m_speed; } 
};
#endif
