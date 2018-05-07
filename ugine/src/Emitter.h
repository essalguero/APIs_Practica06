#pragma once

#include "common.h"
#include "Entity.h"
#include "Material.h"

class Emitter : public Entity
{
public:
	Emitter(const Material& mat, bool autofade = true);
	void setRateRange(float min, float max);
	void setVelocityRange(const glm::vec3& min, const glm::vec3& max);
	void setSpinVelocityRange(float min, float max);
	void setScaleRange(float min, float max);
	void setLifetimeRange(float min, float max);
	void setColorRange(const glm::vec4& min, const glm::vec4& max);
	void emit(bool enable);
	bool isEmitting();
	virtual void update(float deltaTime) override;
	virtual void draw() override;

private:
	Material material;
	bool autoFade;
	bool emitting;
	float minEmittingInterval;
	float maxEmittingInterval;
	float minVelocityInterval;
	float maxSpinInterval;
	float minSpinInterval;
	float maxVelocityInterval;
	float minScaleInterval;
	float maxScaleInterval;
	glm::vec4 minColorInterval;
	glm::vec4 maxColorInterval;


};