#include "ContactListener.h"
#include "../util/Log.h"
#include "../../game/Game.h"

void ContactListener::BeginContact(b2Contact* contact)
{
	auto fixtureA = contact->GetFixtureA()->GetBody()->GetUserData();
	auto fixtureB = contact->GetFixtureB()->GetBody()->GetUserData();

	if ((fixtureA == "red_goal" || fixtureB == "red_goal") && (fixtureA == "ball" || fixtureB == "ball"))
	{
		Log::error("Red team scored");
		if (game) {
			game->scored = true;
			game->teamAScored();
		}
	}

	if ((fixtureA == "blue_goal" || fixtureB == "blue_goal") && (fixtureA == "ball" || fixtureB == "ball"))
	{
		Log::error("Blue team scored");
		if (game) {
			game->scored = true;
			game->teamBScored(); 
		}
	}
}

void ContactListener::EndContact(b2Contact* contact)
{
}

void ContactListener::setGame(Game* game)
{
	this->game = game;
}
