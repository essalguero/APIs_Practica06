#include "Emitter.h"

Emitter::Emitter(const Material& mat, bool autofade = true)
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

}

bool Emitter::isEmitting()
{
	return emitting;
}

void Emitter::update(float deltaTime)
{

}

void Emitter::draw()
{

}
