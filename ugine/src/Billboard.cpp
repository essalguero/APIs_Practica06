#include "Billboard.h"
#include "Buffer.h"
#include "Vertex.h"
#include "State.h"

Billboard::Billboard(const Material& mat)
{
	material = mat;
	size = material.getTexture()->getSize();
	spin = 0;

	vector<Vertex> vertexVector;
	vector<uint16_t> indicesVector = {0, 1, 2, 2, 3, 0};

	Vertex vertex;
	vertex.normal = glm::vec3(0.0f, 0.0f, 1.0f);
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertex.texture = glm::vec2(0, 0);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertex.texture = glm::vec2(size.x, 0);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertex.texture = glm::vec2(size.x, size.y);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertex.texture = glm::vec2(0, size.y);
	vertexVector.push_back(vertex);


	buffer = Buffer::create(vertexVector, indicesVector);

	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

const Material& Billboard::getMaterial() const
{
	return material;
}

Material& Billboard::getMaterial()
{
	return material;
}

const glm::vec2& Billboard::getSize() const
{
	return size;
}

void Billboard::setSize(const glm::vec2& size)
{
	this->size = size;
}

float Billboard::getSpin() const
{
	return spin;
}

void Billboard::setSpin(float spin)
{
	this->spin = spin;
}

void Billboard::draw()
{
	glm::mat4 newModelMatrix = glm::transpose(State::viewMatrix);
	newModelMatrix[0][3] = 0;
	newModelMatrix[1][3] = 0;
	newModelMatrix[2][3] = 0;
	newModelMatrix[3] = glm::vec4(position.x, position.y, position.z, 1.0f);
	//newModelMatrix = glm::scale(glm::rotate(glm::transpose(newModelMatrix), spin, glm::vec3(0, 0, spin)), scale);
	newModelMatrix = glm::rotate(newModelMatrix, glm::radians(spin), glm::vec3(0, 0, 1));
	newModelMatrix = glm::scale(newModelMatrix, glm::vec3(size, 1));
	State::modelMatrix = newModelMatrix;

	material.setColor(glm::vec4(1.0f));
	material.setBlendMode(Material::BlendMode::ALPHA);
	material.setDepthWrite(true);

	material.prepare();
	std::shared_ptr<Shader> shader = material.getShader();
	buffer->draw(shader);
}