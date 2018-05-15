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
	emitting = enable;
}

bool Emitter::isEmitting()
{
	return emitting;
}

void Emitter::update(float deltaTime)
{
	// Update existing particles
	std::vector<Particle>::reverse_iterator it = (particlesEmitted.rbegin());
	std::vector<Particle>::reverse_iterator send = (particlesEmitted.rend());
	for (int i = particlesEmitted.size() - 1; i >= 0; --i)
	{
		particlesEmitted.at(i).update(deltaTime);

		if (particlesEmitted.at(i).getRemainingLifetime() <= 0)
		{
			particlesEmitted.erase(particlesEmitted.begin() + i);
		}
	}

	// Create new particles when needed
	if (emitting)
	{
		float randomValue = glm::linearRand(minEmittingInterval, maxEmittingInterval);
		randomValue += pendingToEmit;

		int particlesToCreate = static_cast<int>(randomValue) / 1;

		pendingToEmit = randomValue - particlesToCreate;


		for (int i = 0; i < particlesToCreate; ++i)
		{
			//Emit particle
			Particle particle = Particle(material,
				glm::linearRand(minVelocityInterval, maxVelocityInterval),
				glm::linearRand(minSpinInterval, maxSpinInterval),
				glm::linearRand(minLifetimeInterval, maxLifetimeInterval), autoFade);
			particle.setPosition(position);
			particlesEmitted.push_back(particle);
		}
	}
}

void Emitter::draw()
{
	for (auto particle = particlesEmitted.begin(); particle != particlesEmitted.end(); ++particle)
	{
		(*particle).draw();
	}
}
