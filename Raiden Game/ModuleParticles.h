#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#include "SDL_mixer/include/SDL_mixer.h"

#define MAX_ACTIVE_PARTICLES 500

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	fPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	Uint32 delay = 0;
	bool fx_played = false;
	
	iPoint GetPos() const;
	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
	bool to_delete=false;
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0, char* FX_path= nullptr);

private:

	SDL_Texture* graphics = nullptr;
	
	Particle* active[MAX_ACTIVE_PARTICLES];
	//uint last_particle = 0;

public:

	Mix_Chunk* fx_shoot = nullptr;

};

#endif // __MODULEPARTICLES_H__