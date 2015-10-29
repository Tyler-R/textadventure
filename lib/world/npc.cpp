//
//  npc.cpp
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-08.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#include <stdio.h>
#include "npc.h"


// constructor
// NPC::NPC(string type, string id){
// 	if (type == "monster") {
// 		Monster tempMonster;
        
//         setID(id);
// 		setName(tempMonster.getName());
//         setType(type);
//         setHP(tempMonster.getHP());
//         setAlive(tempMonster.getAlive());
//         setDamage(tempMonster.getDamage());
//         setDes(tempMonster.getDes());
        
//     }else if(type == "creature") {
//         Creature tempCreature;
        
//         setID(id);
//         setName(tempCreature.getName());
//         setType(type);
//         setHP(tempCreature.getHP());
//         setAlive(tempCreature.getAlive());
//         setDamage(int(0));
//         setDes(tempCreature.getDes());
        
//     }else {
// 		cout << "!!!!!! no such NPC !!!!!! \n";
// 	}
// }

NPC::NPC(string id){
    setID();
}

// destructor
//NPC::~NPC() {
//    delete npcID;
//    delete npcName;
//    delete npcType;
//    delete npcHP;
//    delete npcDamage;
//    delete isAlive;
//}

// Description functions
void NPC::addDescription(string s){
    npcDescription = s;
}
void NPC::addLongDesc(string s){
    longDesc = s;
}
void NPC::addShortDesc(string s){
    shortDesc = s;
}

string NPC::getDescription()const{
    return npcDescription;
}
string NPC::getLongDesc()const{
    return longDesc;
}
string NPC::getShortDesc()const{
    return shortDesc;
}
// Keyword functions
void NPC::addKeyword(vector<string>& s){
    for(int i=0; i < s.length(); i++){
        keyword.push_back(s[i]); 
    }
}
bool NPC::searchKeyword(string s)const{
    for(int i=0; i < keyword.length(); i++){
        if(keyword[i] == s) {
            return true;
        }
    }
    return false;
}
void removeKeyword(string s) {
    if(searchKeyword(s) == true){
        for(int i=0; i < keyword.length(); i++){
            if(keyword[i] == s){
                keyword.erase(keyword.begin()+i);
            }
        }
    }else{
        cout << "The Keyword are not exist!!!"<<endl;
    }
}
void removeAllKeyword(){
    keyword.clear();
}
vector<string> NPC::getKeyword()const{
    return keyword;
}
void NPC::printVector()const{
    for(int i = 0; i < keyword.length(); i++){
        cout <<keyword[i] << endl;
    }
}


void NPC::setID(string id) {
    npcID = id;
}
void NPC::setName(string s) {
    npcName = s;
}

void NPC::setType(string s) {
    npcType = s;
}

void NPC::setHP(int i) {
    npcHP = i;
}

void NPC::setAlive(bool b) {
    isAlive = b;
}

void NPC::setDamage(int i) {
    npcDamage = i;
}

void NPC::setDes(string des) {
    npcDes = des;
}


string NPC::getID() const{
    return npcID;
}

string NPC::getName() const{
    return npcName;
}

string NPC::getType() const{
    return npcType;
}

int NPC::getHP() const{
    return npcHP;
}

bool NPC::getAlive() const{
    return isAlive;
}

int NPC::getDamage() const{
    return npcDamage;
}

string NPC::getDes() const{
    return npcDes;
}

// action
void NPC::getHit() {
    if(npcHP > 1) { // reduce npc' HP by 1
        npcHP = npcHP - 1;
    }
    if(npcHP == 0){ // npc died
        isAlive = false;
    }
}



// helper function
void NPC::checkNPC() const{
    std::cout << "          NPC check function \n";
    std::cout << "the id is                     " << getID();
    std::cout << "\n";
    std::cout << "the name is                   " << getName();
    std::cout << "\n";
    std::cout << "the type is                   " << getType();
    std::cout << "\n";
    std::cout << "the HP is                     " << getHP();
    std::cout << "\n";
    std::cout << "the damage is                 " << getDamage();
    std::cout << "\n";
    std::cout << "is live(1) or dead(0)?        " << getAlive();
    std::cout << "\n";
    std::cout << "description: \n" << getDes();
    std::cout << "\n";
}


