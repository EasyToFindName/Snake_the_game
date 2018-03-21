#pragma once
#include "DynamicObject.h"
#include "Direction.h"
#include "RandomGenerator.h"
#include "Map.h"
class MovingFood : public DynamicObject {
public:
	MovingFood(const Point& startPos, const sf::Time& timer);
	MovingFood(const MovingFood&);
	~MovingFood();

	Point nextPos() const;
	void changeDirection();

	virtual void postProcessing(Map& m) override;
public: //Movable implementation
	virtual bool move() override;
public: //Drawable implementation
	virtual void draw(sf::RenderWindow&) const override;
public: //Reactor impolementation
	virtual bool affect(Snake& s) override;
	virtual bool affect(CircularSaw&) override;	
	virtual bool affect(MovingFood& f) override;
public: //Reactable implementation
	virtual bool reactOn(Reactor& r) override;
protected:
	Direction genRandomDir() const;
private:
	Direction m_dir;
	mutable RandomGenerator m_rand;
};

