#include "stdafx.h"
#include "MovementComponent.h"

//Constructor / Destructor
MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{

}

//accessors
const float & MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f & MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;

	case MOVING:
		if (this->velocity.x != 0.f && this->velocity.y != 0.f)
			return true;
		break;

	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;
		break;

	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
			return true;
		break;

	case MOVING_UP:
		if (this->velocity.y < 0.f)
			return true;
		break;

	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
			return true;
		break;
	
	}
	return false;
}








void MovementComponent::move(const float dir_x, const float dir_y,const float& dt)
{
	//acceleration
	this->velocity.x += this->acceleration * dir_x;

	if (this->velocity.x > 0.f) //check for right
	{
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;
	}
	else if (this->velocity.x < 0.f) // check for left
	{
		if(this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;
	}
	

	this->velocity.y += this->acceleration * dir_y;

	
}


void MovementComponent::update(const float & dt)
{
	/*
	Decelerate the sprite and controls the maximun velocity
	Moves the Sprite.
	*/
	if (this->velocity.x > 0.f) // check for positive x
	{
		//Max Velocity
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Decelaration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;

	}
	else if (this->velocity.x < 0.f) //check for negative x
	{
		//Max Velocity
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	///////////////////////////////////////////////////////////////////

	if (this->velocity.y > 0.f) // check for positive y
	{
		//Max Velocity
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Decelaration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;

	}
	else if (this->velocity.y < 0.f) //check for negative y
	{
		//Max Velocity
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}

	//Final move
	this->sprite.move(this->velocity * dt); //use velocity
}
