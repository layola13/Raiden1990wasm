#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModuleStageCompleted.h"
#include "ModuleLevel1.h"

#include<stdio.h>
#include "SDL/include/SDL_timer.h"

ModulePlayer::ModulePlayer()
{
	
	
	graphics = NULL;
	current_animation = NULL;
	

	

	//Player image

	idle.PushBack({ 80, 13, 24, 27 });


	//move animation boost

	boost.PushBack({ 147, 619, 24, 32 });
	boost.PushBack({ 178, 619, 24, 32 });

	//move animation right 
	
	right.PushBack({ 114, 14, 20, 27 });
	right.PushBack({ 149, 14, 15, 27 });
	right.loop = false;
	right.speed = 0.05f;

	//move animation left
	
	left.PushBack({ 51, 14, 20, 27 });
	left.PushBack({ 22, 14, 15, 27 });
	left.loop = false;
	left.speed = 0.05f;

	

	//Raiden basic shot 
	
	basic_shot.anim.PushBack({ 22, 31, 5, 5 });	//animation
	basic_shot.anim.speed = 1.0f;
	basic_shot.speed.y = -3;
	basic_shot.speed.x = 0;
	basic_shot.life = 1850;
	basic_shot.anim.loop = true;

	//Raiden left basic shot 

	left_basic_shot.anim.PushBack({ 22, 31, 5, 5 });	
	left_basic_shot.anim.speed = 1.0f;
	left_basic_shot.speed.y = -3;
	left_basic_shot.speed.x = -1;
	left_basic_shot.life = 1850;
	left_basic_shot.anim.loop = true;

	//Raiden right basic shot 

	right_basic_shot.anim.PushBack({ 22, 31, 5, 5 });	
	right_basic_shot.anim.speed = 1.0f;
	right_basic_shot.speed.y = -3;
	right_basic_shot.speed.x = 1;
	right_basic_shot.life = 1850;
	right_basic_shot.anim.loop = true;

	//Raiden triple basic shot 

	triple_shot.anim.PushBack({ 33, 31, 8, 5 });	
	triple_shot.anim.speed = 1.0f;
	triple_shot.speed.y = -3;
	triple_shot.speed.x = 0;
	triple_shot.life = 1850;
	triple_shot.anim.loop = true;

	//Raiden left triple basic shot 

	left_triple_shot.anim.PushBack({ 33, 31, 8, 5 });	
	left_triple_shot.anim.speed = 1.0f;
	left_triple_shot.speed.y = -3;
	left_triple_shot.speed.x = -1;
	left_triple_shot.life = 1850;
	left_triple_shot.anim.loop = true;

	//Raiden right triple basic shot 

	right_triple_shot.anim.PushBack({ 33, 31, 8, 5 });	
	right_triple_shot.anim.speed = 1.0f;
	right_triple_shot.speed.y = -3;
	right_triple_shot.speed.x = 1;
	right_triple_shot.life = 1850;
	right_triple_shot.anim.loop = true;

	//Raiden external right triple basic shot 

	ext_right_triple_shot.anim.PushBack({ 33, 31, 8, 5 });
	ext_right_triple_shot.anim.speed = 1.0f;
	ext_right_triple_shot.speed.y = -3;
	ext_right_triple_shot.speed.x = 2;
	ext_right_triple_shot.life = 1850;
	ext_right_triple_shot.anim.loop = true;

	//Raiden external left triple basic shot 

	ext_left_triple_shot.anim.PushBack({ 33, 31, 8, 5 });	
	ext_left_triple_shot.anim.speed = 1.0f;
	ext_left_triple_shot.speed.y = -3;
	ext_left_triple_shot.speed.x = -2;
	ext_left_triple_shot.life = 1850;
	ext_left_triple_shot.anim.loop = true;

	//Raiden bomb

	bomb.anim.PushBack({ 552,171,8,16 });
	bomb.anim.PushBack({ 564,171,8,16 });
	bomb.anim.PushBack({ 575,171,8,16 });
	bomb.anim.PushBack({ 585,171,8,16 });
	bomb.anim.PushBack({ 595,171,8,16 });
	bomb.anim.PushBack({ 605,171,8,16 });
	bomb.anim.PushBack({ 615,171,8,16 });
	bomb.anim.PushBack({ 626,171,8,16 });
	bomb.anim.speed = 0.08f;
	bomb.speed.y = -2.5f;
	bomb.speed.x = 0.;
	bomb.life = 1300;
	bomb.anim.loop = true;

	//Raiden misile shot 

	misile_left.anim.PushBack({ 359, 170, 6, 15 });
	misile_left.anim.PushBack({ 376, 170, 6, 15 });
	misile_left.anim.speed = 1.0f;
	misile_left.speed.y = -4.5f;
	misile_left.speed.x = 0;
	misile_left.life = 1500;
	misile_left.anim.loop = true;

	misile_right.anim.PushBack({ 359, 170, 6, 15 });
	misile_right.anim.PushBack({ 376, 170, 6, 15 });
	misile_right.anim.speed = 1.0f;
	misile_right.speed.y = -4.5f;
	misile_right.speed.x = 0;
	misile_right.life = 1500;
	misile_right.anim.loop = true;

	misile_mid.anim.PushBack({ 359, 170, 6, 15 });
	misile_mid.anim.PushBack({ 376, 170, 6, 15 });
	misile_mid.anim.speed = 0;
	misile_mid.speed.y = -4.5f;
	misile_mid.speed.x = 0;
	misile_mid.life = 1500;
	misile_mid.anim.loop = true;

	//Raiden laser shot 

	laser_shot.anim.PushBack({ 309, 132, 1, 15 });	
	laser_shot.anim.speed = 1.0f;
	laser_shot.speed.y = -7;
	laser_shot.speed.x = 0;
	laser_shot.life =700;
	laser_shot.anim.loop = true;

	//Raiden big laser shot 

	big_laser_shot.anim.PushBack({ 256, 132, 4, 15 });	
	big_laser_shot.anim.speed = 1.0f;
	big_laser_shot.speed.y = -7;
	big_laser_shot.speed.x = 0;
	big_laser_shot.life = 700;
	big_laser_shot.anim.loop = true;

	hit_dmg = 1.0f;
	bomb_dmg = 0.2f;

	dead_explosion.anim.PushBack({ 7,202,32,30 });
	dead_explosion.anim.PushBack({ 40,202,32,30 });
	dead_explosion.anim.PushBack({ 76,202,32,30 });
	dead_explosion.anim.PushBack({ 116,202,32,30 });
	dead_explosion.anim.PushBack({ 164,202,32,30 });
	dead_explosion.anim.PushBack({ 0,0,0,0 });
	dead_explosion.anim.speed = 0.1f;
	dead_explosion.life = 1000;
	
	//Raiden Bomb Explosion
	bomb_explosion.anim.PushBack({ 0, 633, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 633, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 633, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 633, 168, 154 });
	bomb_explosion.anim.PushBack({ 0, 790, 168, 151 });
	bomb_explosion.anim.PushBack({ 168, 790, 168, 151 });
	bomb_explosion.anim.PushBack({ 336, 790, 168, 151 });
	bomb_explosion.anim.PushBack({ 505, 790, 168, 151 });
	bomb_explosion.anim.PushBack({ 0, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 168, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 336, 941, 168, 154 });
	bomb_explosion.anim.PushBack({ 504, 941, 168, 154 });
	bomb_explosion.anim.speed = 0.2f;
	bomb_explosion.life = 3000;
	bomb_explosion.anim.loop = false;



}

ModulePlayer::~ModulePlayer()
{}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->fonts->UnLoad(yellow_font_score);
	App->fonts->UnLoad(red_font_score);
	/*if (spaceship_collider != nullptr) {
	spaceship_collider->to_delete = true;
	}*/

	return true;
}

// Load assets
bool ModulePlayer::Start()
{
	App->collision->Enable();
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Images/Raiden_Spaceship.png"); 
	if (graphics == nullptr) {
		LOG("Error loading player textures %s", SDL_GetError);
		ret = false;
	}
	spaceship_speed = 1;
	
	if (App->player2->player2==false) { 

		position.x = 111; //position if there's only 1 player
		position.y = 150;


		
	}
	else {

		position.x = 71; //position if there are 2 players
		position.y = 150;

	}
	current_animation = &idle;
	
	godmode_activated = " G ";
	user_interface = "    1UP   HI.SCORE    2UP ";
	red_font_score = App->fonts->Load("Assets/Images/Font.png", "> ?@ABCDEFGHIJKLMNOPQRSTUVWXYZ!¡?_*#$%&'()x+.-,;[].{.}/0123456789:", 3);
	yellow_font_score = App->fonts->Load("Assets/Images/Font.png", "> ?@ABCDEFGHIJKLMNOPQRSTUVWXYZ!¡?_*#$%&'()x+.-,;[].{.}/0123456789:", 3);
	// * -> "
	// [ -> tm
	//	]. -> Pts
	//	{. -> Cts
	//	}. -> Pcs

	if (spaceship_collider==nullptr)
	spaceship_collider = App->collision->AddCollider({ 0,0, 24, 26 }, COLLIDER_PLAYER, this);

	total_bombs = 3;
	bomb_thrown = 0;
	bomb_life = 0;
	last_bomb = 0;

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	position.y -= spaceship_speed;
	int speed = 2;

	if (!App->level1->first_animation) {// not able to move during first animation
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad[0] == KEY_STATE::KEY_REPEAT) //---UP
		{
			position.y -= speed;
			if (-position.y*SCREEN_SIZE > App->render->camera.y) {
				position.y = -App->render->camera.y / SCREEN_SIZE; //upper player limit. ------->The relation between camera.y and position.y is camera.y=-position.y*SCREEN_SIZE
			}

		}


		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad[1] == KEY_STATE::KEY_REPEAT)//---DOWN
		{
			position.y += speed;
			if ((-(position.y - SCREEN_HEIGHT + 27)*SCREEN_SIZE) < App->render->camera.y) { //lower player limit (27 is height of spaceship)
				position.y = ((-App->render->camera.y / SCREEN_SIZE) - 27 + SCREEN_HEIGHT);
			}


		}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad[2] == KEY_STATE::KEY_REPEAT)//---RIGHT
		{
			position.x += speed;
			App->render->camera.x -= 4;
			if (current_animation != &right)
			{
				right.Reset();
				current_animation = &right;
				
			}
			if (App->render->camera.x <= -154) {//right camera limit
				App->render->camera.x = -154;
				if (position.x >= 275) { //right player limit
					position.x = 275;
				}
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad[3] == KEY_STATE::KEY_REPEAT)//---LEFT

		{
			position.x -= speed;
			App->render->camera.x += 4;
			if (current_animation != &left)
			{
				left.Reset();
				current_animation = &left;				
			}
			if (App->render->camera.x >= 100) {//left camera limit
				App->render->camera.x = 100;
				if (position.x <= -48) { //left player limit
					position.x = -48;
				}
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || App->input->gamepad[4] == KEY_STATE::KEY_DOWN)// --SPACE SHOT
		{
			if (Red_Powerup_Lvl >= Blue_Powerup_Lvl) {// the shot type is the greater level between the blue and the red powerup (in case of equal level predominates the red ones. ) 
				switch (Red_Powerup_Lvl)
				{
				case 0:
					App->particles->AddParticle(basic_shot, position.x + 9, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Simple_Shot.wav");//Adds a particle (basic_shot) in front of the spaceship.					
					break;
				case 1:
					App->particles->AddParticle(basic_shot, position.x + 5, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Red_Powerup_Shot.wav"); // Adds 2 particles
					App->particles->AddParticle(basic_shot, position.x + 13, position.y, COLLIDER_PLAYER_SHOT, 0);
					break;
				case 2:
					App->particles->AddParticle(left_basic_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Red_Powerup_Shot.wav"); // Adds 3 particles
					App->particles->AddParticle(right_basic_shot, position.x + 15, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(basic_shot, position.x + 9, position.y, COLLIDER_PLAYER_SHOT, 0);
					break;
				case 3:
					App->particles->AddParticle(left_triple_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Red_Powerup_Shot.wav"); // Adds 3 particles (triple)
					App->particles->AddParticle(right_triple_shot, position.x + 15, position.y, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(triple_shot, position.x + 9, position.y, COLLIDER_PLAYER_SHOT, 0);
					break;
				case 4:
					App->particles->AddParticle(left_triple_shot, position.x + 5, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Red_Powerup_Shot.wav"); // Adds 5 particles (triple)
					App->particles->AddParticle(right_triple_shot, position.x + 13, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(triple_shot, position.x + 9, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(ext_left_triple_shot, position.x + 1, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(ext_right_triple_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 0);
					break;

				}
			}
			else if (Blue_Powerup_Lvl > Red_Powerup_Lvl) {			// ----------------------------------------------------------------------CHANGE ALL FX
				switch (Blue_Powerup_Lvl)
				{
				case 0:
					break;
				case 1:
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_BluePowerUp_Shot1.wav");//Adds 2 particle (laser_shot) in front of the spaceship.
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 50);
					break;
				case 2:
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_BluePowerUp_Shot1.wav");//Adds 5 particle (laser_shot) in front of the spaceship.
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(laser_shot, position.x + 12, position.y, COLLIDER_PLAYER_SHOT, 240);
					break;
				case 3:
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_BluePowerUp_Shot2.wav");//Adds 10 particle (laser_shot) in front of the spaceship.
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 240);
					break;
				case 4:
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_BluePowerUp_Shot2.wav");//Adds 23 particle (laser_shot) in front of the spaceship.
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 10);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 70);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 140);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 4, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 16, position.y, COLLIDER_PLAYER_SHOT, 240);
					break;
				case 5:
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 0, "Assets/Audio/Fx_Simple_Shot.wav");//Adds 13 particle (laser_shot) in front of the spaceship.
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 3, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 0);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 60);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 120);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 180);
					App->particles->AddParticle(big_laser_shot, position.x + 17, position.y, COLLIDER_PLAYER_SHOT, 240);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 10);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 70);
					App->particles->AddParticle(big_laser_shot, position.x + 10, position.y, COLLIDER_PLAYER_SHOT, 140);

					break;

				}
			}
			switch (M_Powerup_Lvl)
			{
			case 0:
				break;
			case 1:
				App->particles->AddParticle(misile_left, position.x - 6, position.y, COLLIDER_PLAYER_SHOT, 0);
				App->particles->AddParticle(misile_right, position.x + 24, position.y, COLLIDER_PLAYER_SHOT, 0);
				break;
			case 2:
				App->particles->AddParticle(misile_left, position.x - 6, position.y, COLLIDER_PLAYER_SHOT, 30);
				App->particles->AddParticle(misile_mid, position.x + 9, position.y, COLLIDER_PLAYER_SHOT, 0);
				App->particles->AddParticle(misile_right, position.x + 24, position.y, COLLIDER_PLAYER_SHOT, 30);
				break;
			case 3:
				App->particles->AddParticle(misile_left, position.x - 6, position.y, COLLIDER_PLAYER_SHOT, 30);
				App->particles->AddParticle(misile_right, position.x + 24, position.y, COLLIDER_PLAYER_SHOT, 30);
				App->particles->AddParticle(misile_left, position.x - 2, position.y, COLLIDER_PLAYER_SHOT, 0);
				App->particles->AddParticle(misile_right, position.x + 20, position.y, COLLIDER_PLAYER_SHOT, 0);
				break;

			}

		}

		if ((App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN || App->input->gamepad[8] == KEY_STATE::KEY_REPEAT) && total_bombs > 0 && SDL_GetTicks() - last_bomb > 5000) //-----BOMB! (only when ur player has bombs and passed 5s from the last bomb)
		{
			bomb_thrown = SDL_GetTicks();
			App->particles->AddParticle(bomb, position.x + 8, position.y, COLLIDER_EXPLOSION, 0, "Assets/Audio/Fx_Drop_Bomb");
			saved_position = position;
			total_bombs--;
			last_bomb = SDL_GetTicks();
		}
		if (bomb_thrown != 0 && SDL_GetTicks() - bomb_thrown > 1300) {// 1.3s to generate the explosion of the bomb(damaging collider)
			App->particles->AddParticle(bomb_explosion, saved_position.x - 70, saved_position.y - 250, COLLIDER_BOMB, 0, "Assets/Audio/Fx_Bomb_Explosion");
			bomb_thrown = 0;
			bomb_life = SDL_GetTicks();
			saved_position = { 0,0 };

		}
		if (bomb_life != 0 && SDL_GetTicks() - bomb_life > 3000) {// bomb life 3s then delete particle
			bomb_life = 0;
			bomb_explosion.to_delete;
		}




		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE //check error
			&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE && !App->level1->first_animation) {
			current_animation = &idle;			
		}


	}


		if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN || App->input->gamepad[5] == KEY_STATE::KEY_REPEAT)//GOD MODE (press right stick on controller)

		{
			if (!godmode) {
				godmode = true;
			}
			else {
				godmode = false;
			}
		}

		if ((App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_DOWN) && (App->fade->IsFading() == false))//DIRECT WIN/LOSE
		{
			App->fade->FadeToBlack(this, App->stageCompleted);

		}



		if (spaceship_collider != nullptr)
			spaceship_collider->SetPos(position.x, position.y);

		// Draw everything --------------------------------------
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		// Draw UI (score) --------------------------------------

		if (score > high_score)
			high_score = score;

		if (App->player2->score > high_score&&App->player2->IsEnabled()) {
			high_score = App->player2->score;
		
		}
		


		sprintf_s(score_text, 10, "%8d", score);
		sprintf_s(high_score_text, 10, "%7d", high_score);

		App->fonts->BlitText(0, 1, red_font_score, user_interface);
		App->fonts->BlitText(0, 9, yellow_font_score, score_text);
		App->fonts->BlitText(88, 9, yellow_font_score, high_score_text);
		if (godmode) {
			App->fonts->BlitText(0, 1, yellow_font_score, godmode_activated);// Yellow "G" in left upper corner when godmode activated.
		}

		return UPDATE_CONTINUE;
	}




void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	switch (c2->type) {
	case COLLIDER_POWERUP_MEDAL:
		//App->particles->AddParticle(bonus_medal, position.x + 9, position.y, COLLIDER_PLAYER, 0, "Assets/Audio/Fx_Medal_Bonus.wav");
		score += 500;	
		fx_shoot = App->audio->Load_Fx("Assets/Audio/Fx_Medal_Bonus.wav");
			if (!fx_shoot) {
				LOG("Error loading shoot's fx: %s", Mix_GetError)
			}
			App->audio->Play_Fx(fx_shoot);
			
		
		break;

	case COLLIDER_POWERUP_BLUE:
		Blue_Powerup_Lvl++;
		if (Blue_Powerup_Lvl >= 5) {
			Blue_Powerup_Lvl = 4;
			score += 5000;
		}
		break;
	case COLLIDER_POWERUP_R:
		Red_Powerup_Lvl++;
		if (Red_Powerup_Lvl >= 5) {
			Red_Powerup_Lvl = 4;
			score += 5000;
		}
		break;
	case COLLIDER_POWERUP_M:
		M_Powerup_Lvl++;
		if (M_Powerup_Lvl >= 4) {
			M_Powerup_Lvl = 3;
			score += 5000;
		}
		break;
	case COLLIDER_POWERUP_B:
		total_bombs++;
		if (total_bombs >= 6) {
			total_bombs = 6;		
		}
		break;

	case COLLIDER_ENEMY_SHOT :
		if (c1 == spaceship_collider && destroyed == false && App->fade->IsFading() == false&&godmode==false) {
			Dead();
		}
	case COLLIDER_ENEMY:
		if (c1 == spaceship_collider && destroyed == false && App->fade->IsFading() == false && godmode==false ) {
			Dead();
		}

	}
}

void ModulePlayer::Dead() {

	
	Red_Powerup_Lvl = 0;
	M_Powerup_Lvl = 0;
	Blue_Powerup_Lvl = 0;
	sprintf_s(score_text, 10, "%8d", score);
	sprintf_s(high_score_text, 10, "%7d", high_score);

	if (App->player2->IsEnabled()) {
		App->player2->Red_Powerup_Lvl = 0;
		App->player2->M_Powerup_Lvl = 0;
		App->player2->Blue_Powerup_Lvl = 0;
		App->player2->destroyed = true;
	
	}
	
	destroyed = true;
	
	App->player2->player2 = false;
	App->fade->FadeToBlack((Module*)App->level1, (Module*)App->intro);
	App->particles->AddParticle(dead_explosion, position.x, position.y, COLLIDER_EXPLOSION,0, "Assets/Audio/Fx_Player_Explosion.wav");
	App->textures->Unload(graphics);
		
}