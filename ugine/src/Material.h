#pragma once

#include "common.h"
#include "Shader.h"
#include "Texture.h"

class Material
{
public:
	Material(const std::shared_ptr<Texture>& tex = nullptr,
		const std::shared_ptr<Shader>& shader = nullptr);
	const std::shared_ptr<Shader>& getShader() const;
	std::shared_ptr<Shader>& getShader();
	void setShader(const std::shared_ptr<Shader>& shader);
	const std::shared_ptr<Texture>& getTexture() const;
	void setTexture(const std::shared_ptr<Texture>& tex);
	void prepare();

	const glm::vec4& getColor() const;
	void setColor(const glm::vec4& color);
	uint8_t getShininess() const;
	void setShininess(uint8_t shininess);

private:
	std::shared_ptr<Texture> materialTexture;
	std::shared_ptr<Shader> materialShader;

	glm::vec4 materialColor;
	uint8_t materialShininess;
};