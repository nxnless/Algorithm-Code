#include <iostream>
using namespace std;

struct record{
	int value;
	int inD;
	int oD;
	struct record *left;
	struct record *right;
};
