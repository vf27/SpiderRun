#include "Object.h"
using namespace sf;

Object::Object(std::string fname) {
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture);
}
void Object::Draw (RenderWindow &window ) {//recibo la ventana en la que se dibuja
	window.draw(m_sprite);
}

bool Object::CollideWith (const Object & o) const {
	auto r1 = this->m_sprite.getGlobalBounds();//le pido al sprite del objeto donde estoy
	auto r2 = o.m_sprite.getGlobalBounds();// le pido al sprite del otro objeto q me estan pasando
	return r1.intersects(r2);//me dice si se intersectan
}

