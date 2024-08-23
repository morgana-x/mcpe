#include "Recipes.hpp"
#include "../Inventory/CraftingContainer.hpp";
Recipes::Recipes()
{
	/*
	*    (new ToolRecipies()).addRecipes(this);
    (new WeaponRecipies()).addRecipes(this);
    (new OreRecipies()).addRecipes(this);
    (new FoodRecipies()).addRecipes(this);
    (new StructureRecipies()).addRecipes(this);
    (new ArmorRecipes()).addRecipes(this);
    (new ClothDyeRecipes()).addRecipes(this);
	*/

}

ItemInstance Recipes::getItemFor(CraftingContainer paramCraftingContainer)
{
	return *(new ItemInstance(0, 0, 0));
}

void Recipes::addShapedRecipe(ItemInstance paramItemInstance, int paramVarArgs)
{

}
void Recipes::addShapelessRecipe(ItemInstance paramItemInstance, int paramVarArgs)
{

}
