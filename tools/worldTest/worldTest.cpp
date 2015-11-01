#include <string>
#include <iostream>
#include <memory>
#include "world.h"
#include "user.h"


using namespace std;

int main() {
	
	cout << "--Welcome to the worldTest module.--" << endl;

	cout << endl << "--Now instantiating the World--" << endl;
	World newWorld;

	cout << endl << "--Now instantiating the Users--" << endl;

	User PlayerOne(false, "Player One", "abc123", newWorld.getRoom(0), "This is Player One.");

	//User PlayerOne;

	cout << endl << "--Now testing interaction with Current Room--" << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne.getRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look Around the Room--" << endl;
	cout << PlayerOne.lookAround() << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : PlayerOne.lookExits()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & obj : PlayerOne.lookObjList()) {
	    cout << obj << endl;
	}

	cout << endl << "--Printing Keywords of Current Room--" << endl;

	PlayerOne.getRoom()->printKeywords();

	cout << endl << "--Adding New Keywords to Room--" << endl;
	PlayerOne.getRoom()->addKeyword("Foyer");
	PlayerOne.getRoom()->addKeyword("Entrance Hall");
	PlayerOne.getRoom()->addKeyword("Vestibule");

	PlayerOne.getRoom()->printKeywords();

	cout << endl << "--Now using Lobby's Keywords to look at the Lobby--" << endl;
	
	cout << endl << "--Looking at 'Lobby'--" << endl;
	cout << PlayerOne.lookAt("Lobby") << endl;

	cout << endl << "--Looking at 'Foyer'--" << endl;
	cout << PlayerOne.lookAt("Foyer") << endl;

	cout << endl << "--Looking at 'vestibule'--" << endl;
	cout << PlayerOne.lookAt("vestibule") << endl;

	cout << endl << "--Now using an invalid Keyword to look at the Lobby--" << endl;

	cout << endl << "--Looking at 'caboose'--" << endl;
	cout << PlayerOne.lookAt("caboose") << endl;

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing moving to different rooms--" << endl;

	cout << endl << "--From the Lobby, we move 'north'--" << endl;

	cout << PlayerOne.moveTo("north") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne.getRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << PlayerOne.lookAround()  << endl;

	for (auto & door : PlayerOne.lookExits()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects in the Room--" << endl;

	for (auto & door : PlayerOne.lookObjList()) {
	    cout << door << endl;
	}

	vector<string> bathroomKeywords;

	bathroomKeywords.push_back("Washroom");
	bathroomKeywords.push_back("Restroom");
	bathroomKeywords.push_back("Powder Room");

	cout << endl << "--Adding New Keywords to Bathroom--" << endl;
	PlayerOne.getRoom()->addKeywords(bathroomKeywords);

	PlayerOne.getRoom()->printKeywords();

	cout << endl << "--Moving to 'shower'--" << endl;

	cout << PlayerOne.moveTo("shower") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne.getRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << PlayerOne.lookAround()  << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : PlayerOne.lookExits()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : PlayerOne.lookObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Moving to 'Powder Room'--" << endl;

	cout << PlayerOne.moveTo("powder room") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne.getRoom()->getDesc() << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : PlayerOne.lookExits()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : PlayerOne.lookObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Moving to 'east' (an invalid location)--" << endl;

	cout << PlayerOne.moveTo("east") << endl;	

	cout << endl << "--Moving to 'library' (an invalid location)--" << endl;

	cout << PlayerOne.moveTo("library") << endl;	

	cout << endl << "--Moving to 'foyer'--" << endl;

	cout << PlayerOne.moveTo("foyer") << endl;	

	cout << endl << "--Looking at Current Room--" << endl;
	cout << PlayerOne.getRoom()->getDesc() << endl;

	cout << endl << "--Getting a Good Look at the Room--" << endl;
	cout << PlayerOne.lookAround()  << endl;

	cout << endl << "--Looking at Exits--" << endl;

	for (auto & door : PlayerOne.lookExits()) {
	    cout << door << endl;
	}

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : PlayerOne.lookObjList()) {
	    cout << door << endl;
	}

	cout << endl << "----" << endl;	
	cout << endl << "----" << endl;	

	cout << endl << "--Now testing NPC interaction--" << endl;	

	cout << endl << "--Getting List of Objects--" << endl;

	for (auto & door : PlayerOne.lookObjList()) {
	    cout << door << endl;
	}

	cout << endl << "--Looking at NPCs--" << endl;

	cout << endl << "--Looking at 'butler'--" << endl;
	cout << endl << PlayerOne.lookAt("butler") << endl;	

	cout << endl << "--Looking at 'knight'--" << endl;
	cout << endl << PlayerOne.lookAt("knight") << endl;	

	cout << endl << "--Using Keywords to look at NPCs--" << endl;

	cout << endl << "--Looking at 'servant'--" << endl;
	cout << endl << PlayerOne.lookAt("servant") << endl;	

	cout << endl << "--Looking at 'swordsman'--" << endl;
	cout << endl << PlayerOne.lookAt("swordsman") << endl;	

	cout << endl << "--Now looking at lists of Keywords for each Object.--" << endl;

	cout << endl << "--Here are the swordsman's keywords--" << endl;
	for (auto & obj : PlayerOne.lookObjKeywords("swordsman")) {
	    cout << obj << endl;
	}

	cout << endl << "--Here are the lobby's keywords--" << endl;
	for (auto & obj : PlayerOne.lookObjKeywords("lobby")) {
	    cout << obj << endl;
	}

	cout << endl << "--Here are the north door's keywords--" << endl;
	for (auto & obj : PlayerOne.lookObjKeywords("north")) {
	    cout << obj << endl;
	}


	cout << endl << "--EndTest--" << endl;
}
