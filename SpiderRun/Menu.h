#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;

class Menu : public Scene{
	Font m_font;
	Text m_t1,m_t2,m_t3;
	Sprite m_sfondo;
	Texture m_tfondo;
public:
	Menu();
	void Update(Game &game)override;
	void Draw(RenderWindow &window)override;
};

#endif

