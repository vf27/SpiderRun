#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
using namespace sf;
class Scene;
class Game {
private:
	RenderWindow m_window;
	Scene *m_scene; //polimorfismo , puntero a escena
	Scene *m_next_scene = nullptr; // me anoto cual sigue
public: 
	Game();
	void Run();
	void ProcessEvents();
	void Update();
	void Draw();
	void SetScene(Scene *next_scene);
	 
};

#endif



