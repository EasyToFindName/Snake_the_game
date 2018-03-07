#include "RenderCanvas.h"

RenderCanvas::RenderCanvas()
{
}

RenderCanvas::~RenderCanvas()
{
}

RenderCanvas::RenderCanvas(const RenderCanvas & canvas)
{

}

RenderCanvas & RenderCanvas::operator=(const RenderCanvas & canvas)
{
	return *this;
}

bool RenderCanvas::operator<(const RenderCanvas & canvas)
{
	return this->m_layer < canvas.m_layer;
}

void RenderCanvas::setDrawCallback(std::function<void(sf::RenderTarget&, sf::RenderStates states)> function)
{
	m_drawCallback = function;
}

void RenderCanvas::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	if(m_drawCallback)
		m_drawCallback(target, states);
}
