#include "ContactListener.h"

ContactListener::ContactListener(Game* game)
{
	this->game = game;
}

void ContactListener::BeginContact(b2Contact* contact)
{
	auto fixtureA = contact->GetFixtureA()->GetBody()->GetUserData();
	auto fixtureB = contact->GetFixtureB()->GetBody()->GetUserData();

	if (fixtureA == "red_goal" || fixtureB == "red_goal" && fixtureA == "ball" || fixtureB == "ball")
	{
		game->teamAScored();
	}

	if (fixtureA == "blue_goal" || fixtureB == "blue_goal" && fixtureA == "ball" || fixtureB == "ball")
	{
		game->teamBScored();
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
}
