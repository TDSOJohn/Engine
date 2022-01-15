//
//  PostEffect.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 22/07/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef PostEffect_hpp
#define PostEffect_hpp

#include <SFML/System/NonCopyable.hpp>


namespace sf
{
    class RenderTarget;
    class RenderTexture;
    class Shader;
}

namespace eng
{

class PostEffect : sf::NonCopyable
{
    public:
        virtual                     ~PostEffect();
        virtual void                apply(const sf::RenderTexture& input, sf::RenderTarget& output) = 0;

        static bool                 isSupported();


    protected:
        static void                 applyShader(const sf::Shader& shader, sf::RenderTarget& output);
};
}

#endif /* PostEffect_hpp */
