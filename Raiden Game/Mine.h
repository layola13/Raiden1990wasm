#ifndef __MINE_H__
#define __MINE_H__

#include "Enemy.h"
#include "ModuleParticles.h"
#include "Path.h"

class Mine : public Enemy
{
private:
	
	Animation idle;
	Particle explosion;
	Particle color_rotatory_shot;
	Mix_Chunk* fx_shoot = nullptr;
	fPoint original_pos;
	void OnCollision(Collider* collider, int num_enemy);
	void ShotVector(Particle& shot, iPoint velocity_vector, fPoint shot_initial_pos);
	void Shot(Particle& shot, iPoint aim_position, fPoint shot_initial_pos);

	float speed;	
	float hits_life;
	int shoot_number = 0;
	uint score_points;
	void Dead(Collider* shooter, int num_enemy);





public:

	Mine(int x, int y, int shoot_num);
	void Move();


	

};

#endif// __MINE_H__