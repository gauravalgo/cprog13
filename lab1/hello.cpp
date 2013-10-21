#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;
 
int main(int argc, char* argv[]) {
	string startOutput = "Hello";
	string world = " world";
	string output = "";
	string endOutput = "!\n";
	if(argc == 1){
		output = world;
	}
	else if(argc == 2){
		//if not integer
		if(atoi(argv[1])==0){
			output = " ";
			output = output +argv[1];
		}
		//if integer
		else{
			for (int i = 0; i < atoi(argv[1]); ++i){
				output = output + world;
			}
		}
	}
	else if(argc == 3){
		string addOutput = argv[2];
		for (int i = 0; i < atoi(argv[1]); ++i)
		{
			output += " "+addOutput;
		}
	}
	cout << startOutput << output << endOutput;
   return 0;
}