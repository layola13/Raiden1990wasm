#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleAudio;
class ModuleIntro;
class ModuleLevel1;
class ModuleLevel2;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class ModuleParticles;
class ModuleStageCompleted;
class Module;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class ModulePowerUps;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleStageCompleted* stageCompleted;
	ModuleIntro* intro;
	ModuleLevel1* level1;
	ModuleLevel2* level2;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles*particles;
	ModuleCollision* collision;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModulePowerUps* powerup;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__