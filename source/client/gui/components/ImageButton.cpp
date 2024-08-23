#include "ImageButton.hpp"



ImageButton::ImageButton(int id, const std::string& text) : Button(id, text) {
    field_3C = 16.0;
    m_textureName = "";
    field_34 = 0;
    field_38 = 0;
    field_44 = 0;
    field_48 = 0;
    m_renderPart = 0;
    field_40 = 16.0;
    field_4C = 1;
    field_50 = 1;
    //m_color = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
    m_yOffset = 16;
    setupDefault();
}
/*
ImageButton::ImageButton(int id, const std::string& text, const ImageDef& imageDef) : Button(id, text) {
    m_textureName = imageDef.textureName;
    field_34 = imageDef.xOffset;
    field_38 = imageDef.field_8;
    field_3C = imageDef.field_C;
    field_40 = imageDef.field_10;
    field_44 = imageDef.field_14;
    field_48 = imageDef.field_18;
    field_4C = imageDef.field_1C;
    field_50 = imageDef.field_20;
    m_renderPart = imageDef.renderPart;
    //m_color = Vec4(1.0f, 1.0f, 1.0f, 1.0f);
    m_yOffset = 16;
    setupDefault();
}*/

void ImageButton::render(Minecraft* pMinecraft, int a3, int a4) {
    if (!m_bVisible)
        return;

    Font* pFont = pMinecraft->m_pFont;
    Textures* pTexs = pMinecraft->m_pTextures;
    auto tesselator = &Tesselator::instance;

    //glColor4f(m_color.x, m_color.y, m_color.z, m_color.w);

    auto shouldDrawPressed = false;
    if (m_bEnabled && m_bPressed) {
        shouldDrawPressed = a3 >= m_xPos && a4 >= m_yPos && a3 < m_xPos + m_width && a4 < m_yPos + m_height;
    }

    auto secondImage = isSecondImage(m_bEnabled);//isSecondImage(m_isActive);

    renderBg(pMinecraft, a3, a4);

    if (!m_textureName.empty() && pTexs->loadAndBindTexture(m_textureName)) {
        auto color = shouldDrawPressed ? 0xFFFFFFFF : 0xFF808080;

        tesselator->begin(4);
        tesselator->color(color);

        auto v14 = (float)(field_3C * 0.5f) * (float)((float)m_width / field_3C);
        auto v15 = (float)(field_40 * 0.5f) * (float)((float)m_height / field_40);
        auto v16 = (float)((float)m_xPos + (float)m_textureName.length()) + v14;
        auto v17 = (float)((float)m_yPos + (float)field_38) + v15;

        if (field_68 && shouldDrawPressed) {
            v14 = v14 * 0.95f;
            v15 = v15 * 0.95f;
        }

        if (m_renderPart) {
            // Todo: fix up!
            /*int textureData = pTexs->loadAndBindTexture(m_textureName);
            if (textureData) {
                auto v20 = secondImage ? field_4C : 0;
                auto v22 = field_44 + v20;
                auto v24 = (float)v22 / (float)textureData->mipmap0.width;
                auto v23 = field_4C;
                if (secondImage)
                    v23 *= 2;
                auto v26 = (float)(field_44 + v23) / (float)textureData->mipmap0.width;
                auto v28 = (float)(field_48 + field_50) / (float)textureData->mipmap0.height;
                tesselator->vertexUV(
                    v16 - v14, v17 - v15, field_4, v24, (float)field_48 / (float)textureData->mipmap0.height);
                tesselator->vertexUV(v16 - v14, v17 + v15, field_4, v24, v28);
                tesselator->vertexUV(v16 + v14, v17 + v15, field_4, v26, v28);
                tesselator->vertexUV(
                    v16 + v14, v17 - v15, field_4, v26, (float)field_48 / (float)textureData->mipmap0.height);
            }*/
        }
        else {
            tesselator->vertexUV(v16 - v14, v17 - v15, field_4, 0.0f, 0.0f);
            tesselator->vertexUV(v16 - v14, v17 + v15, field_4, 0.0f, 1.0f);
            tesselator->vertexUV(v16 + v14, v17 + v15, field_4, 1.0f, 1.0f);
            tesselator->vertexUV(v16 + v14, v17 - v15, field_4, 1.0f, 0.0f);
        }

        tesselator->draw();
    }

    if (m_bEnabled){ //(m_isActive) {
        if (shouldDrawPressed){ //|| field_2C) {
            drawCenteredString(pFont, m_text, m_xPos + (m_width >> 1), m_yPos + m_yOffset + 1, 0xFFFFA0);
        }
        else {
            drawCenteredString(pFont, m_text, m_xPos + (m_width >> 1), m_yPos + m_yOffset, 0xE0E0E0);
        }
    }
    else {
        drawCenteredString(pFont, m_text, m_xPos + (m_width >> 1), m_yPos + m_yOffset, 0xFFA0A0A0);
    }
}

void ImageButton::setupDefault() {
    m_width = 48;
    m_height = 48;
    field_68 = 1;
}
/*
void ImageButton::setImageDef(const ImageDef& imageDef, bool setSizes) {
    m_textureName = imageDef.textureName;
    field_38 = imageDef.field_8;
    field_3C = imageDef.field_C;
    field_40 = imageDef.field_10;
    field_44 = imageDef.field_14;
    field_48 = imageDef.field_18;
    field_4C = imageDef.field_1C;
    field_50 = imageDef.field_20;
    m_renderPart = imageDef.renderPart;
    if (setSizes) {
        m_width = (int)imageDef.field_C;
        m_height = (int)imageDef.field_10;
    }
}*/