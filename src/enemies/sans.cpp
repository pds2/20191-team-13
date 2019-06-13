#include <iostream>
#include <limits>
#include <cstdint> 
#include "helpers.hpp"
#include "enemies/sans.hpp"

Sans::Sans(int health, int attack, int defense): Enemy(health, attack, defense){
	this->fleeRate = 0;
	this->setBattleTexts();
	this->name = "Sans";
	this->quotes.push_back("The easiest enemy. Can only deal 1 damage.");
	this->quotesIndex = this->battleTextIndex = 0;
}
Sans::~Sans(){}


int Sans::getHealth(){
	return this->health;
}

int Sans::getAttack(){
	return this->attack  + Helpers::easyRandom(10);
}

int Sans::getBaseAttack(){
	return this->attack;
}

int Sans::takeDamage(int enemyAttack){
	int btSize = (int) this->battleTexts.size();
	if(this->battleTextIndex < btSize - 2){
		this->battleTextIndex++;
		return INT8_MAX - 1;
	} else if (this->battleTextIndex == btSize - 2) {
		return INT8_MAX;
	}
	int damage = ((enemyAttack - this->defense) > 0) ? enemyAttack - this->defense : 1;
	this->health -= damage;
	return this->health;
}

std::string Sans::getBattleText(){
	// return this->battleTexts[24];
	return this->battleTexts[this->battleTextIndex];
}

int Sans::getFleeRate(){
	return this->fleeRate;
}

std::string Sans::getName(){
	return this->name;
}

std::string Sans::getQuote(){
	std::string quote = this->quotes[this->quotesIndex];
	if(this->quotesIndex + 1 < (int)this->quotes.size()){
		this->quotesIndex++;
	}
	return quote;
}

void Sans::setBattleTexts(){
	this->battleTexts.push_back("it's a beautiful day outside. birds are singing, flowers are blooming... \n|\ton days like these, kids like you...\n|\tShould be burning in hell");
	this->battleTexts.push_back("what? you think i'm just gonna stand there and take it?");
	this->battleTexts.push_back("our reports showed a massive anomaly in the timespace continuum.\n|\ttimelines jumping left and right, stopping and starting...");
	this->battleTexts.push_back("until suddenly, everything ends.");
	this->battleTexts.push_back("heh heh heh... that's your fault isn't it?");
	this->battleTexts.push_back("you can't understand how this feels");
	this->battleTexts.push_back("knowing that one day, without any warning... it's all going to be reset.");
	this->battleTexts.push_back("look. i gave up trying to go back a long time ago.");
	this->battleTexts.push_back("and getting to the surface doesn't really appeal anymore, either.");
	this->battleTexts.push_back("cause even if we do... we'll just end up right back here, without any memory of it, right?");
	this->battleTexts.push_back("to be blunt... it makes it kind of hard to give it my all.");
	this->battleTexts.push_back("... or is that just a poor excuse for being lazy...? hell if i know.");
	this->battleTexts.push_back("all i know is... seeing what comes next... i can't afford not to care anymore.");
	this->battleTexts.push_back("ugh... that being said... you, uh, really like swinging that thing around, huh? ... listen\n|\tfriendship... it's really great, right? let's quit fighting.");
	this->battleTexts.push_back("welp, it was worth a shot. guess you like doing things the hard way, huh?");
	this->battleTexts.push_back("sounds strange, but before all this i was secretly hoping we could be friends.\n|\ti always thought the anomaly was doing this cause they were unhappy.\n|\tand when they got what they wanted, they would stop all this.");
	this->battleTexts.push_back("and maybe all they needed was... i dunno. some good food, some bad laughs, some nice friends.");
	this->battleTexts.push_back("but that's ridiculous, right? yeah, you're the type of person who won't EVER be happy.");
	this->battleTexts.push_back("you'll keep consuming timelines over and over, until... well. hey. take it from me, kid. someday... you gotta learn when to QUIT");
	this->battleTexts.push_back("and that day's TODAY");
	this->battleTexts.push_back("cause... y'see... all this fighting is really tiring me out");
	this->battleTexts.push_back("and if you keep pushing me... then i'll be forced to use my SPECIAL ATTACK.");
	this->battleTexts.push_back("yeah, my SPECIAL ATTACK. sound familiar? well, get ready.\n|\tcause after the next move, i'm going to USE IT.\n|\tso, if you don't want to see it, now would be a good time to die.");
	this->battleTexts.push_back("well, here goes nothing... are you ready? survive THIS and i'll show you my SPECIAL ATTACK!");
	this->battleTexts.push_back("huff... puff... all right. that's it. it's time for my special attack. are you ready? here goes nothing.\n|\t\
yep. that's right. it's literally nothing. and it's not going to be anything, either.\n|\t\
heh heh heh... ya get it? i know i can't beat you. one of your turns... you're just gonna kill me.\n|\t\
so, uh. i've decided... it's not gonna BE your turn. ever.\n|\t\
i'm just gonna keep having MY turn until you give up.\n|\t\
even if it means we have to stand here until the end of time.\n|\t\
capiche?\n|\n|\n|\t\
you'll get bored here. if you haven't gotten bored already, i mean. and then, you'll finally quit.\n|\n|\n|\t\
i know your type. you're, uh, very determined, aren't you? you'll never give up, even if there's, uh...\n|\t\
absolutely NO benefit to persevering whatsoever. if i can make that clear.\n|\t\
no matter what, you'll just keep going. not out of any desire for good or evil...\n|\t\
but just because you think you can. and because you \"can\"... ... you \"have to\".\n|\n|\n|\t\
but now, you've reached the end. there is nothing left for you now. so, uh, in my personal opinion...\n|\t\
the most \"determined\" thing you can do here?\n|\t\
is to, uh, completely give up. and... (yawn)\n|\t\
do literally anything else.");
	this->battleTexts.push_back("heh, didja really think you would be able-\n|\n|\n|\n|\n|\n|\t\
... ... ... so... guess that's it, huh? ... just... don't say i didn't warn you. welp.\n|\t\
i'm going to grillby's.\n|\t\
papyrus, do you want anything?");
}


