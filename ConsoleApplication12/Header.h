#pragma once
#include <iostream>
using namespace std;
struct queues {
	const static int Size = 3;
	int sizes_of_queues[Size];
	int start[Size] = { 0,0,0 };
	int end[Size] = { 0,0,0 };
	int* queue;
};
void add_end(int , int , queues* );
void print(int , queues* );
void del_start(int , queues* );
bool is_full(int, queues* );
int lenth(int , queues* );
void alloc(queues* );
void del(queues* );
bool is_empty(int ,queues*);