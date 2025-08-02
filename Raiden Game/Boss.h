#ifndef __BOSS_H__
#define __BOSS_H__

#include "Enemy.h"
#include "ModuleParticles.h"

class Boss : public Enemy
{
private:


	Animation idle;
	Particle explosion;
	Particle bouncing_shot;
	Particle star_shot;
	Particle color_rotatory_shot;
	Mix_Chunk* fx_shoot = nullptr;
	void OnCollision(Collider* collider, int num_enemy);
	void Dead(Collider* shooter, int num_enemy);


	float increment_y;
	float initial_y;
	float speed;
	


	float hits_life;
	int shoot_number = 0;
	void ShotVector(Particle& shot, iPoint velocity_vector, fPoint shot_initial_pos, unsigned int delay=0);
	void Shot(Particle& shot, iPoint aim_position, fPoint shot_initial_pos);
	uint score_points;
	bool shot_vector=false;
	bool burst_shot=false;
	Uint32 born;
	Uint32 shot_timer;
	Uint32 star_shot_timer;




public:

	Boss(int x, int y, int shoot_num);
	void Move();




};

#endif// __BOSS_H__