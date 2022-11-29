#pragma once
#include <iostream>
#include "Header.h"
void add_end(int num_queue, int value, queues* q) {
	bool is_full(int, queues*);
	if (!is_full(num_queue, q)) {
		q->queue[q->end[num_queue - 1]] = value;
		q->end[num_queue - 1]++;
		return;
	}	
	else {
		cout << "queue is full \n";
		return;
	}
};

void print(int num_queue, queues* q) {
	
	
	if (q->start[num_queue - 1] != q->end[num_queue - 1]) {
		cout << "queue " << num_queue << ": ";
		for (int i = q->start[num_queue - 1]; i < q->end[num_queue - 1]; i++)	cout << q->queue[i] << " ";
		cout << "\n";
	}
	else cout << "queue " << num_queue << " is empty\n";
	return;
};
void del_start(int num_queue, queues* q) {
	
	if (q->start[num_queue - 1] == q->end[num_queue - 1]) { cout << "queue is empty\n"; return; }
	else {
		q->queue[q->start[num_queue - 1]] = NULL;
		q->start[num_queue - 1]++;		

	}
}
bool is_empty(int num_queue, queues* q) {
	return q->start[num_queue - 1] == q->end[num_queue - 1];
}
bool is_full(int num_queue, queues* q) {
	int lenth(int, queues*);
	return (q->sizes_of_queues[num_queue - 1] == lenth(num_queue, q)) || (q->start[num_queue] == q->end[num_queue - 1]);
}
int lenth(int num_queue, queues* q) {
	return q->end[num_queue - 1] - q->start[num_queue - 1];
}
void alloc(queues* q)
{
	try {
		int count = 0;
		for (int i = 0; i < q->Size; i++)
			count += q->sizes_of_queues[i];
		q->queue = new int[count];
		for (int i = 1; i < q->Size; i++)
		{
			q->end[i] = q->sizes_of_queues[i - 1] + q->end[i - 1];
			q->start[i] = q->sizes_of_queues[i - 1] + q->start[i - 1];

		}

	}
	catch (bad_alloc e)
	{
		cout << "can't give memory\n";
	}
}
void del(queues* q)
{
	delete[]q->queue;
	q->end[0] = 0;
	q->start[0] = 0;
	for (int i = 1; i < q->Size; i++)
	{
		q->end[i] = q->sizes_of_queues[i - 1] + q->end[i - 1];
		q->start[i] = q->sizes_of_queues[i - 1] + q->start[i - 1];

	}

}




/*void del_start(int num_queue, queues* q) {

	if (q->start[num_queue - 1] == q->end[num_queue - 1]) { cout << "queue is empty\n"; return; }
	else {
		
		int* old_values;
		old_values = q->queue;
		try
		{
		q->queue = new int[q->end[q->Size - 1]-1 ];
		for (int i = 0; i < q->start[num_queue - 1]; i++)
				{//значения до 1 эл нужной очереди
					q->queue[i] = old_values[i];
				}

		for (int i = q->start[num_queue - 1]; i < q->end[q->Size - 1]-1; i++)
				{//значения после 1 эл нужной очереди
					q->queue[i] = old_values[i+1];
				}

		q->end[num_queue - 1]--;
		for (int i = num_queue; i < q->Size; i++) {
			q->start[i]--;
			q->end[i]--;
		}

		delete[]old_values;

		}
		catch (bad_alloc e)
		{
		cout << "can't give memory\n";
		}


	}
}*/


/*void add_end(int num_queue, int value, queues* q) {
	
	if (q->sizes_of_queues[num_queue - 1] != lenth(num_queue, q))
	{//память под элемент не выделена
	  int* old_values;
	  old_values = q->queue;
	  try {
		  q->queue = new int[q->end[q->Size - 1] + 2];
		  for (int ii = 0; ii < q->end[num_queue - 1]; ii++)
		  {//значения до посл эл нужной очереди
			  q->queue[ii] = old_values[ii];
		  }
		  q->queue[q->end[num_queue - 1]] = value;
		  for (int i = q->end[num_queue - 1]+1; i < q->end[q->Size - 1]; i++)
		  {//значения после посл эл нужной очереди
			  q->queue[i] = old_values[i-1];
		  }
		  q->end[num_queue - 1]++;
		  for (int i = num_queue; i < q->Size; i++) {
			  q->start[i]++;
			  q->end[i]++;
		  }
		  delete[]old_values;
		  return;
	  }
	  catch (bad_alloc e) {
		  cout << "can't give memory\n";
	  }
  }

	else {
		cout << "queue is full \n";
		return;
	}
};*/