#pragma once

#include "../Item.hpp"
#include "../Inventory/CraftingContainer.hpp"
#include "Recipe.hpp"
class Recipes
{
public:
	static int ANY_AUX_VALUE;
	static Recipes instance;

	static std::array<Recipe, 512> recipes;


	Recipes();
	// Todo: Add CraftingContainer Class
	virtual ItemInstance getItemFor(CraftingContainer paramCraftingContainer);
	
private:
	virtual void addShapedRecipe(ItemInstance paramItemInstance, int paramVarArgs); // Todo: Add proper paramVarArg class
	virtual void addShapelessRecipe(ItemInstance paramItemInstace, int paramVarArgs);
};