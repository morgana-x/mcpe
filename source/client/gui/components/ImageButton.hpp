//https://git.atipls.com/atipls/gists-public/src/branch/main/
#pragma once

#include <string>
#include "Button.hpp"


class ImageButton : public Button
{
public:
	ImageButton(int id, std::string const& text);
	//ImageButton(int id, std::string const& text, ImageDef const& imageDef);

	void render(Minecraft*, int, int) override;
	void renderBg(Minecraft*, int, int) override {}
    virtual void setYOffset(int yOffset) {
        m_yOffset = yOffset;
    }

    virtual void setupDefault();

    virtual bool isSecondImage(bool isHovered) {
        return isHovered;
    }

   // void setImageDef(ImageDef const& imageDef, bool setSizes);
private:
protected:
    std::string m_textureName;
    int field_34;
    int field_38;
    float field_3C;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    char m_renderPart;
    //Vec4 m_color;
    char field_68;
    int m_yOffset;
};

