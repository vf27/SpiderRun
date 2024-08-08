#ifndef PUNTOS_H
#define PUNTOS_H
#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Spider.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


#include <vector>
using namespace std;
using namespace sf; 

class Puntos : public Scene{
public:
	Puntos();
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void Carga();
private:
	Texture m_tfondo;
	Sprite m_sfondo; 
	Text m_t1,m_t2, p1 , p2 , p3 , p4 , p5, scores;
	Font m_font1,m_font2; 
	vector<int> vectorPuntajes; 
};
#endif

