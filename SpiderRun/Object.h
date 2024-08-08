#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Object {
protected:
	Texture m_texture;
	Sprite m_sprite;
public:
	Object(std::string fname);//archivo de donde cargo la imagen 
	//el constructor me inicializa la textura y el sprite con el archivo que le indico
	// carga la textura, la asocia al sprite
	Object(){}; // constructor por defecto 
	void Draw(RenderWindow &window ); // todos los sprites se dibujan de la misma manera
	bool CollideWith(const Object &o )const;
};

#endif

