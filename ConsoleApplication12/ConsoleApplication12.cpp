 #include <iostream>
#include "Header.h"
//#include"Source.cpp"
using namespace std;
int main(){
	
	queues queue1{10,20,30};
	alloc(&queue1);
	for (int i = 0; i < 10; i++) 
	{
		add_end(1, i, &queue1);
		
		
	}
	print(1, &queue1);
	for (int i = 0; i < 20; i++)
	{
		add_end(2, i, &queue1);
	}
	print(2, &queue1);
	for (int i = 0; i < 30; i++)
	{
		add_end(3, i, &queue1);

	}
	print(3, &queue1);

	del_start(1, &queue1);
	del_start(1, &queue1);
	del_start(1, &queue1);
	del_start(2, &queue1);
	del_start(2, &queue1);	
	print(1, &queue1);
	add_end(2, 1, &queue1);
	print(2, &queue1);
	print(3, &queue1);
	
	
	for (int i = 0; i < 60; i++) cout << queue1.queue[i] << "-";


	return 0;

}