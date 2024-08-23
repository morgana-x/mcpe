#include "CraftAutoScreen.hpp"


CraftAutoScreen::CraftAutoScreen() : 
	m_btnClose(1, "Close"),
	m_btnCraftSelectedItemButton(2, "Craft")
{
}


void CraftAutoScreen::init()
{
	setupPositions();
}

void CraftAutoScreen::render(int x, int y, float f)
{
	renderBackground(); // Remove after testing, this only serves as indicator and I haven't checked if the actual rendering code calls this!

	drawCenteredString(m_pFont, "Crafting Screen Goes here!", m_width / 2, 24, 0xFFFFFF);
	Screen::render(x, y, f);
}
void CraftAutoScreen::buttonClicked(Button* pButton)
{
	// Button Craft Selected
	if (pButton->m_buttonId == m_btnCraftSelectedItemButton.m_buttonId) //this + 0x108)
	{
		craftSelectedItem();
		return;
	}
	// Button Close Menu
	if (pButton->m_buttonId == m_btnClose.m_buttonId) // this + 0x90
	{
		m_pMinecraft->setScreen(nullptr);
		return;
	}
	// Select Crafting Items(?)
	/*
	*   uVar2 = *(int *)(param_1 + 0x30) - 100;
  if (uVar2 < 100) {
    ppCVar1 = *(CItem ***)(*(int *)(this + 0x58) + uVar2 * 0xc);
    if (ppCVar1 != *(CItem ***)(*(int *)(this + 0x58) + uVar2 * 0xc + 4)) {
      onItemSelected(this,*ppCVar1);
      ScrollingPane::setSelected(*(ScrollingPane **)(this + 400),0,true);
    }
    *(uint *)(this + 100) = uVar2;
    *(Button **)(this + 0x1a4) = param_1;
  }
	*/
}
void CraftAutoScreen::mouseClicked(int x, int y, int type)
{

}
void CraftAutoScreen::mouseReleased(int x, int y, int type)
{

}
void CraftAutoScreen::removed()
{

}
void CraftAutoScreen::addItem(Recipe *param_1)
{

}

void CraftAutoScreen::setupPositions()
{
	//std::string local_80 = "gui/spritesheet.png";

	//CraftButton::setSize()
	m_btnClose.m_width = m_width / 4;
	m_btnCraftSelectedItemButton.m_yPos = m_height / 2;

	m_buttons.push_back(&m_btnClose);
	m_buttons.push_back(&m_btnCraftSelectedItemButton);
	m_buttonTabList.push_back(&m_btnClose);
	m_buttonTabList.push_back(&m_btnCraftSelectedItemButton);
}

void CraftAutoScreen::craftSelectedItem()
{
}

void CraftAutoScreen::recheckRecipes()
{

}