#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Scene.h"
using namespace sf;

class Game;

class Scene {
public:
	Scene();//polimorfismo
	virtual void Update(Game &game) = 0;
	virtual void Draw(RenderWindow &window) = 0;
	virtual void ProcessEvent(Event &e){}
};

#endif

