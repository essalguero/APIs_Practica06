#include "Particle.h"

Particle::Particle(
	const Material& mat,
	const glm::vec3& vel,
	float spinVel,
	float lifetime,
	bool autofade)
{
	material = mat;
	spin = spinVel;
	remainingLifetime = lifetime;
	automaticFade = autofade;
}

float Particle::getRemainingLifetime() const
{
	return remainingLifetime;
}

void Particle::update(float deltaTime)
{

}