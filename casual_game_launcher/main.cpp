#ifndef OBJECTS
#include"objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef LOG
#include"log.hpp"
#define LOG
#endif // !LOG

#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS


#ifndef LAUNCHER
#include "launcher.hpp"
#define LAUNCHER
#endif // !LAUNCHER

int main(){

	GameLauncher launcher(1450);

	launcher.start();
}