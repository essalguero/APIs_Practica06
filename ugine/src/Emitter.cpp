#include "Emitter.h"

Emitter::Emitter(const Material& mat, bool autofade)
{
	material = mat;
	autoFade = autofade;
}

void Emitter::setRateRange(float min, float max)
{
	minEmittingInterval = min;
	maxEmittingInterval = max;
}

void Emitter::setVelocityRange(const glm::vec3& min, const glm::vec3& max)
{
	minVelocityInterval = min;
	maxVelocityInterval = max;
}

void Emitter::setSpinVelocityRange(float min, float max)
{
	minSpinInterval = min;
	maxSpinInterval = max;
}

void Emitter::setScaleRange(float min, float max)
{
	minScaleInterval = min;
	maxSpinInterval = max;
}

void Emitter::setLifetimeRange(float min, float max)
{
	minLifetimeInterval = min;
	maxLifetimeInterval = max;
}

void Emitter::setColorRange(const glm::vec4& min, const glm::vec4& max)
{
	minColorInterval = min;
	maxColorInterval = max;
}

void Emitter::emit(bool enable)
{
	float randomValue = glm::linearRand(minEmittingInterval, maxEmittingInterval);
	randomValue += pendingToEmit;

	int particlesToCreate = static_cast<int>(randomValue) / 1;

	pendingToEmit = randomValue - particlesToCreate;


	for (int i = 0; i < particlesToCreate; ++i)
	{
		//Emit particle
	}
}

bool Emitter::isEmitting()
{
	return emitting;
}

void Emitter::update(float deltaTime)
{
	for (auto it = particlesEmitted.rbegin(); it != particlesEmitted.rend(); ++it)
	{
		(*it).update(deltaTime);

		if ((*it).getRemainingLifetime() <= 0)
		{
			std::advance(it, 1);
			particlesEmitted.erase(it.base());
		}
	}
}

void Emitter::draw()
{

}
