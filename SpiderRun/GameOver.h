#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <vector>
#include "Match.h"
using namespace std;

class GameOver : public Scene {
public:
	GameOver(int x);
	void Update (Game & game);
	void Draw (RenderWindow & window);
	void Cargar(int x); //funcion para cargar los puntos 
private:
	Texture m_tfondo;
	Sprite m_sfondo;
	Font m_font;
	Text m_t1, m_t2, m_t3, m_t4, m_t5,m_t6, m_t8; 
	string t6, t8;
	vector<int>puntajes; 
};

#endif

