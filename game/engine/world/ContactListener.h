#pragma once
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include "../../game/entities/Ball.h"

class ContactListener : public b2ContactListener
{
	void BeginContact(b2Contact* contact) override
	{
		/*//check if fixture A was a ball
		auto bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Ball*>(bodyUserData)->startContact();

		//check if fixture B was a ball
		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Ball*>(bodyUserData)->startContact();*/

		auto fixtureA = contact->GetFixtureA()->GetBody()->GetUserData();
		auto fixtureB = contact->GetFixtureB()->GetBody()->GetUserData();

		/*
		auto a = static_cast<std::string*>(fixtureA);
		auto b = static_cast<std::string*>(fixtureA);

		if (a)
		{
			Log::error(*a);
		}

		if (b)
		{
			Log::error(*b);
		}

		delete a;
		delete b;*/

		if (fixtureA == "red_goal" || fixtureB == "red_goal")
		{
			Log::error("Je hebt gescoord!!");
		}
	}

	void EndContact(b2Contact* contact) override
	{
		/*//check if fixture A was a ball
		auto bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Ball*>(bodyUserData)->endContact();

		//check if fixture B was a ball
		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<Ball*>(bodyUserData)->endContact();*/
		// Log::error("Einde van contact.");
	}
};
