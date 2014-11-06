/*
 * HashTable_Test.cc
 *
 *  Created on: 2014年11月4日
 *      Author: qmwx
 */
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Random.h"

class Person{
		std::string key;
		std::string personName;
	public:
		Person(){

		}
		Person(const std::string& id, const std::string& name): key(id), personName(name){

		}
		std::string getKey()const{
			return key;
		}
		friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
std::ostream& operator<<(std::ostream& os, const Person& p){
	os << p.key << "\t" << p.personName << "\t";
	return os;
}

int main()
{

	Random r;
	HashTable<Person> ht;
	for(int i = 0; i < 64*1024; i++){
		std::string id = r.getPhoneNum(13);
		std::string name = r.getRandomString(11);

		ht.put(id, Person(id, name));
	}

	ht.print(std::cerr);
	std::cerr << "$$$$$$$$$$$$$$$$$$$$$" << std::endl;
	for(int i = 0; i < 12; i++){
		std::string key = r.getPhoneNum(2);
		bool con = false;
		std::cerr << (con = ht.contains(key)) << std::endl;
		if(con){
			std::cerr << ht.get(key) << std::endl;
		}
	}
	//std:: cerr << ht.get("123") << std::endl;
	//std:: cerr << ht.get("23") << std::endl;
	return 0;
}



