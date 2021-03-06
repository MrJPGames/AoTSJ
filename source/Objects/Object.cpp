#include <math.h>
#include <cstdlib> //For rand
#include "Object.h"
#define PI 3.14159265
#define WIDTH 400
#define HEIGHT 240
#define TYPES 26
#define SPECIALTYPES 11

Object::Object(){
	isAlive=0;
	direction=0;
	speed=0;
	x=0;
	y=0;
	angle=0;
	scale=1;
	rot_dir=1;
	special=0;
	type = rand() % TYPES;
	if ((rand() % 100) == 42){ //Special item!
		type = rand() % SPECIALTYPES;
		special=1;
	}
}

Object::Object(int var1, int var2){
	setPos(var1, var2);
}

void Object::kill(){
	isAlive=0;
	rot_dir=-rot_dir;
	special=0;
	type = rand() % TYPES;
	if ((rand() % 100) == 42){ //Special item!
		type = rand() % SPECIALTYPES;
		special=1;
	}
}

void Object::resurect(){
	isAlive=1;
}

void Object::setPos(int var1, int var2){
	x=var1;
	y=var2;
}

void Object::setSpeed(float var1){
	speed=var1;
}

void Object::setDirection(int dir){
	direction=dir;
}

void Object::setType(int in_type){
	type=in_type;
}

void Object::update(){
	y-=speed*cos(direction*(PI/180));
	x+=speed*sin(direction*(PI/180));
	angle+=2*PI/180;
	if (x > WIDTH+64){
		kill();
	}else if (x < -64){
		kill();
	}
	if (y > HEIGHT+64){
		kill();
	}else if (y < -64){
		kill();	
	}
}

int Object::getX(){
	return round(x);
}

int Object::getY(){
	return round(y);
}

bool Object::getAlive(){
	return isAlive;
}

float Object::getAngle(){
	return angle;
}

float Object::getScale(){
	return scale;
}

void Object::setScale(float s){
	scale=s;
}

int Object::getType(){
	return type;
}

void Object::setSpecial(bool is_special){
	special=is_special;
}

int Object::isSpecial(){
	return special;
}