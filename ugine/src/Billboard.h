#pragma once

#include "common.h"
#include "Material.h"
#include "Entity.h"
#include "Buffe0r.h"

class Billboard : public Entity
{
public:
	Billboard(const Material& mat);
	const Material& getMaterial() const;
	Material& getMaterial();
	const glm::vec2& getSize() const;
	void setSize(const glm::vec2& size);
	float getSpin() const;
	void setSpin(float spin);
	virtual void draw() override;

private:
	Material material;
	glm::vec2 size;
	float spin;
	std::shared_ptr<Buffer> buffer;
};