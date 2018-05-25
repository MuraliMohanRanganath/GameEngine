#include "PlayerController.h"
#include "MessagingSystem.h"
#include "Vector.h"

#include "Actor.h"
namespace Engine
{


	const HashString PlayerController::ClassType = "PlayerController";
	void PlayerController::keyPressed()
	{
	
	}
	void PlayerController::safeCast(IActorController & controller)
	{
		if (controller.m_type == ClassType)
		{
			PlayerController* controller = reinterpret_cast<PlayerController*>(&controller);
			controller->keyPressed();
		}
	}
	PlayerController::PlayerController():IActorController(ClassType),speed(0.0)
	{

	}
	void PlayerController::roatateImage(double dt)
	{
		double roatation = actorControlled->getGameObject()->getRotation();
		roatation += speed * dt;
		actorControlled->getGameObject()->setRoation((float)roatation);
	}
	void PlayerController::update(double dt)
	{
		roatateImage(dt);
	}
	PlayerController::~PlayerController()
	{

	}
	void 	PlayerController::setActor( Actor* actor)
	{
		actorControlled = actor;
	}
	Actor* PlayerController::getActor() const
	{
		return actorControlled;
	}
	void PlayerController::HandleMessage(const HashString message, void* payLoad)
	{
	}
}