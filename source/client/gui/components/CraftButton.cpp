#include "CraftButton.hpp"
#include "ImageButton.hpp"

CraftButton::CraftButton(int id, int x, int y, const std::string& str) :
	ImageButton(id, str)
{

}
CraftButton::CraftButton(int id, int x, int y, int width, int height, const std::string& str) :
	ImageButton(id, str)
{

}

CraftButton::CraftButton(int id) :
	ImageButton(id, "")
{

}

void CraftButton::init(Textures* param_1)
{
	
}

void CraftButton::setSize(int width, int height)
{
	m_width = width;
	m_height = height;
}
void CraftButton::setSize(float width, float height)
{
	m_width = (int)width;
	m_height = (int)height;
}