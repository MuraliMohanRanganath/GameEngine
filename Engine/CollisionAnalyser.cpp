#include "CollisionAnalyser.h"
#include "CollisionData.h"
#include "Actor.h"
#include "MessagingSystem.h"
namespace Engine
{
	CollisionAnalyser* CollisionAnalyser::instance = nullptr;

	void CollisionAnalyser::HandleMessage(const HashString message, void* payLoad)
	{
		Collision data = *static_cast<Collision*>(payLoad);
		if (data.pOther->getGameObject()->getName() == "Player2" && (data.pActor->getGameObject()->getName() == "Wall1") || data.pActor->getGameObject()->getName() == "Hero")
		{
			data.pOther->getGameObject()->setPosition(Vector(500, 200, 0));
			data.pOther->getGameObject()->setVelocity(Vector(150, 0, 0));
		}
		if (data.pActor->getGameObject()->getName() == "Hero"&&data.pOther->getGameObject()->getName() == "Player2")
		{
			data.pActor->getGameObject()->setPosition(Vector(0, -300, 0));
			data.pActor->getPhysics()->forces = Vector::VectorZero;
		}
		if (data.pActor->getGameObject()->getName() == "Wall3"&&data.pOther->getGameObject()->getName() == "Hero") {
			data.pOther->getGameObject()->setPosition(Vector(0, -300, 0));
			data.pOther->getPhysics()->forces = Vector::VectorZero;
		}
		if (data.pActor->getGameObject()->getName() == "Hero"&&data.pOther->getGameObject()->getName() == "Wall3") {
			data.pActor->getGameObject()->setPosition(Vector(0, -300, 0));
			data.pActor->getPhysics()->forces = Vector::VectorZero;
		}
	}
	
	CollisionAnalyser* CollisionAnalyser::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new CollisionAnalyser();
			MessagingSystem::MessageHandlerSystem::getInstance()->RegisterHandler("TriggerCollision",instance);
		}
		return instance;
	}

	CollisionAnalyser::CollisionAnalyser()
	{

	}
}