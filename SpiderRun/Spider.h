#ifndef SPIDER_H
#define SPIDER_H
#include "Object.h"
using namespace sf;

class Spider : public Object {
	
	Vector2f m_speed , m_pos;
	Texture m_texturaQuieto,m_texturaSalto, m_texturaAgachado;
	bool saltando, agachado; 
	float alturaOriginal;
	
public:
	Spider();
	void Update(sf :: FloatRect platform1_bounds,sf :: FloatRect platform2_bounds);
	
};

#endif

