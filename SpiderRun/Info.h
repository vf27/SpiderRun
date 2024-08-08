#ifndef INFO_H
#define INFO_H
#include "Scene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Info : public Scene {
private:
	Font m_font1, m_font2;
	Text m_t1,m_t2,m_t3;
	Sprite m_sfondo;
	Texture m_tfondo;
	
public:
	Info();
	void Update (Game & game)override;
	void Draw (RenderWindow & window) override;
	
};

#endif

