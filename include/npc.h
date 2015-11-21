//
//  npc.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef NPC_H_
#define NPC_H_
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "entity.h"

using namespace std;

class NPC : public Entity {
    
private:
    // attributes (yaml)
    string npcID;
    string npcDescription;
    string longDesc;
    string shortDesc;
    vector<string> keywords;
    const int DEAD_DAMAGE = 0;

    // save for later (status)
    int npcHP;
    bool isAlive;
    int npcDamage;
    string npcDes;

public:

    // functions (status)
    void setHP();
    void setAlive();
    void setDamage();

    int getHP() const;
    int getDamage()const;
    bool getAlive()const;   // live or dead
    
    //constructor
	NPC(string type, string ID); // type(monster or creature), the ID of this NPC
    NPC(string id);
    NPC(NPC *npc); // copy
    //destructor
    ~NPC();
    
    // functions
	void setID(string id);
	string getID() const;

    // descriptions
    void addDescription(string s);
    void addLongDesc(string s);
    void addShortDesc(string s);
    string getDescription()const;
    string getLongDesc()const;
    string getShortDesc()const;
    
    // keyword
    void addKeyword(string s);
    void addKeywords(vector<string> s);
    bool searchKeyword(string s) const;
    void removeKeyword(string s);
    void removeAllKeyword();
    vector<string> getKeyword()const;
    // helper function ( check keywords )
    void printVector() const;


    // helper function (status)
    void checkNPC() const;	// print out all attributes of npc

    // BATTLE METHOD added by Jason, edited by Jordan
    int getHit(int damage); // reduce HP by damage

};
#endif
