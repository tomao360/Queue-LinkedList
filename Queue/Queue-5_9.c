#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Item
{
	int val1;
	int val2;
	int id;
	struct Item* next;
	struct Item* prev;
};
struct Item* Head = NULL;
struct Item* Tail = NULL;
int ID_counter = 1;

//A function that pushes(adds) items to queue
void Push(int val1, int val2)
{
	struct Item* currentItem;
	currentItem = (struct Item*)malloc(sizeof(struct Item));
	if (currentItem == NULL)
	{
		printf("ERROR - Not enough memory");
		return;
	}
	else
	{
		currentItem->val1 = val1;
		currentItem->val2 = val2;

		if (Head == NULL)
		{
			Head = currentItem;
			Tail = currentItem;
			currentItem->next = NULL;
			currentItem->prev = NULL;
		}
		else
		{
			Head->prev = currentItem;
			currentItem->next = Head;
			currentItem->prev = NULL;
			Head = currentItem;
		}

		currentItem->id = ID_counter;
		ID_counter++;
	}
}

//A function that prints the linked list-queue
void printList()
{
	struct Item* currentItem = Tail;

	printf("The reasulting linked list:\n");
	while (currentItem != NULL)
	{
		printf("val1: %d val2: %d id: %d\n", currentItem->val1, currentItem->val2, currentItem->id);
		currentItem = currentItem->prev;
	}
}

//A function that removes an item from queue 
//FIFO-First In, First Out
struct Item* Pop()
{
	struct Item* ret = Tail;

	if (Tail->prev != NULL)
	{
		Tail = Tail->prev;
		Tail->next = NULL;
	}

	return ret;
}


int main()
{
	struct Item* popedItem;
	srand(time());

	char userResponse = NULL;
	while (userResponse != 'E')
	{
		printf("\nPlease enter one of the following choices:\n1-Insert item to the linked list-queue\n2-Print the linked list-queue\n3-Pop item from the linked list-queue\n4-Exit the program\n");
		userResponse = getch();

		switch (userResponse)
		{
		case '1': //Insert item to the linked list-queue
			Push(rand(), rand());
			break;
		case '2': //Print the linked list-queue
			printList();
			break;
		case '3': //Print - print the linked list-stack
			popedItem = Pop();
			printf("Item: val1: %d val2: %d id: %d\n", popedItem->val1, popedItem->val2, popedItem->id);
			free(popedItem);
			break;
		case '4': //Exit the program
			printf("Thank you for using our program\n");
			break;
		
		default:
			printf("Wrong selection, please try again\n");
			break;
		}
	}
	
	return 0;
}