//
//  TextNode.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 10/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef TextNode_hpp
#define TextNode_hpp

#include "ResourceHolder.hpp"
#include "ResourceTypes.hpp"
#include "SceneNode.hpp"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


namespace eng
{

class TextNode : public SceneNode
{
    public:
        explicit            TextNode(const FontHolder& fonts, Fonts::ID font_used, const std::string& text = "Default text");

        void                setString(const std::string& text);


    private:
        virtual void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        sf::Text            mText;
};

}

#endif /* TextNode_hpp */
