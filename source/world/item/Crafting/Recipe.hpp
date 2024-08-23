#pragma once

#include "../ItemInstance.hpp";
#include "../Inventory/CraftingContainer.hpp";

class Recipe
{
public:
	int size();
	ItemInstance assemble(CraftingContainer paramCraftingContainer);
	bool matches(CraftingContainer paramCraftingContainer);
private:
};