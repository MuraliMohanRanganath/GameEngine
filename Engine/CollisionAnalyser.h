#ifndef __COLLISION_ANALYSER_H
#define __COLLISION_ANALYSER_H
#include "MessageHandler.h"
namespace Engine
{
	class CollisionAnalyser: public MessagingSystem::IMessageHandler
	{
	public:
	virtual void HandleMessage(const HashString message, void* payLoad);
	static CollisionAnalyser* getInstance();
	private:
		static CollisionAnalyser* instance;
		CollisionAnalyser();
		float lastUpdate;
	};
} // namespace Engine
#endif // __COLLISION_ANALYSER_H