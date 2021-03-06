//
//  SceneNode.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 22/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef SceneNode_hpp
#define SceneNode_hpp

#include "Category.hpp"
#include "CommandIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <set>
#include <memory>
#include <utility>


namespace eng
{

struct  Command;

class SceneNode :   public sf::Transformable,
                    public sf::Drawable,
                    private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    typedef std::pair<SceneNode*, SceneNode*> Pair;

public:
    explicit                SceneNode(Category::Type category = Category::None);

    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);

    void                    update(sf::Time dt, GameCommandQueue& commands);

    sf::Vector2f            getWorldPosition() const;
    sf::Transform           getWorldTransform() const;

    void                    onCommand(const Command& command, sf::Time dt);
    virtual unsigned int    getCategory() const;

    void                    checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
    void                    checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
    void                    removeWrecks();
    virtual sf::FloatRect   getBoundingRect() const;
    virtual bool            isMarkedForRemoval() const;
    virtual bool            isDestroyed() const;

private:
    virtual void            updateCurrent(sf::Time dt, GameCommandQueue& commands);
    void                    updateChildren(sf::Time dt, GameCommandQueue& commands);

    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    std::vector<Ptr>        mChildren;
    SceneNode*              mParent;
    Category::Type          mDefaultCategory;
};

bool        collision(const SceneNode& lhs, const SceneNode& rhs);
float       distance(const SceneNode& lhs, const SceneNode& rhs);

}

#endif /* Scenenode_hpp */
