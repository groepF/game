#include "ContactListener.h"
#include "../util/Log.h"
#include "../../game/Game.h"

void ContactListener::BeginContact(b2Contact* contact)
{
	auto fixtureA = contact->GetFixtureA()->GetBody()->GetUserData();
	auto fixtureB = contact->GetFixtureB()->GetBody()->GetUserData();

	if ((fixtureA == "red_goal" || fixtureB == "red_goal") && (fixtureA == "ball" || fixtureB == "ball"))
	{
		if (game) game->teamBScored();
	}

	if ((fixtureA == "blue_goal" || fixtureB == "blue_goal") && (fixtureA == "ball" || fixtureB == "ball"))
	{
		if(game) game->teamAScored();
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
}

void ContactListener::setGame(Game* game)
{
	this->game = game;
}
