#ifndef MATCH_H
#define MATCH_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Spider.h"
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Enemigo.h"
#include <SFML/Graphics/Rect.hpp>
using namespace std;
using namespace sf;

class Match : public Scene {
	Spider m_spider;
	Enemigo m_enemigo;
	Sprite m_sfondo, m_splataforma1,m_splataforma2, m_sfondoNoche;
	Texture m_tfondo, m_tplataforma1,m_tplataforma2, m_tfondoNoche;
	Vector2f m_speed = {-3,0};
	FloatRect plataformaRect;
	Font m_font;
	Text m_t1, m_t2,m_tNivel;;
	string m_t3;
	int puntos=0;
	int noche = false;
	int nivel = 1;
	int siguienteNivel = 500; 
public:
	Match();
	void Update(Game &game)override;
	void Draw(RenderWindow &window)override;
	void Carga();
};

#endif




