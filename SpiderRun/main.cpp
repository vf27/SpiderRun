#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	srand(time(NULL));
	Game g;
	g.Run(); 
	return 0;
}

