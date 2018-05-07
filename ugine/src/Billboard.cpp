#include "Billboard.h"
#include "Buffer.h"
#include "Vertex.h"

Billboard::Billboard(const Material& mat)
{
	material = mat;
	size = material.getTexture()->getSize();
	spin = 0;

	vector<Vertex> vertexVector;
	vector<uint16_t> indicesVector = {0, 1, 2, 1, 3, 2};

	Vertex vertex;
	vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexVector.push_back(vertex);
	vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexVector.push_back(vertex);


	buffer = Buffer::create(vertexVector, indicesVector);

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

}