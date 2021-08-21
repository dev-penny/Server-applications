#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE	0


#define pososto_new_apps 0.3
#define total_apps 100
/* Link list node */
struct Node {
	int data;

	int id;
	int siz;
	char name[50];
	char tim[50];
	int state;
	//0 anamoni 1 executing 2 finished

	int exectime;

	struct Node* next;
};

/* function to insert a new_node in a list. 
 pointer to head_ref ----> modify the head of the input linked list*/
void sortedInsert(struct Node** head_ref, struct Node* new_node) {
	struct Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	} else {
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

int countlist(struct Node *head) {

	int cc = 0;
	struct Node *cur = head;
	while (cur != NULL) {
		cc++;
		cur = cur->next;
	}
	return cc;
}

struct Node *getrandomanddelete(struct Node *head, int total) {

	if (total > 5) {
		int num2 = (rand() % (total - 1)) + 3;
	//	printf("EINAI %d \n", num2);
		if ((num2 > 2) && (num2 < total - 1)) {

			struct Node *cur = head;
			struct Node *prev = NULL;
			struct Node *prevc = NULL;

			int ii = 0;
			while (1) {
				prev = cur;

				cur = cur->next;
				ii++;

				if (ii == num2) {

					prev->next = cur->next;
					return cur;

				}

			}

		} else
			return NULL;

	} else
		return NULL;
}


/* Function to create a new node */
struct Node *newNode(int new_data) {
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

/* Function to print linked list */
void printList(struct Node *head) {
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}


typedef struct Node_t {
	struct Node *data;
	struct Node_t *prev;
} NODE;

/* the HEAD of the Queue, hold the amount of node's that are in the queue*/
typedef struct Queue {
	NODE *head;
	NODE *tail;
	int size;
	int limit;
} Queue;

Queue *ConstructQueue(int limit);
void DestructQueue(Queue *queue);
int Enqueue(Queue *pQueue, NODE *item);
NODE *Dequeue(Queue *pQueue);
int isEmpty(Queue* pQueue);

Queue *ConstructQueue(int limit) {
	Queue *queue = (Queue*) malloc(sizeof(Queue));
	if (queue == NULL) {
		return NULL;
	}
	if (limit <= 0) {
		limit = 65535;
	}
	queue->limit = limit;
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void DestructQueue(Queue *queue) {
	NODE *pN;
	while (!isEmpty(queue)) {
		pN = Dequeue(queue);
		free(pN);
	}
	free(queue);
}

int Enqueue(Queue *pQueue, NODE *item) {
	
	if ((pQueue == NULL) || (item == NULL)) {
		return FALSE;
	}
	// if(pQueue->limit != 0)
	if (pQueue->size >= pQueue->limit) {
		return FALSE;
	}
	/*the queue is empty*/
	item->prev = NULL;
	if (pQueue->size == 0) {
		pQueue->head = item;
		pQueue->tail = item;

	} else {
		/*adding item to the end of the queue*/
		pQueue->tail->prev = item;
		pQueue->tail = item;
	}
	pQueue->size++;
	return TRUE;
}

NODE * Dequeue(Queue *pQueue) {
	/*the queue is empty*/
	NODE *item;
	if (isEmpty(pQueue))
		return NULL;
	item = pQueue->head;
	pQueue->head = (pQueue->head)->prev;
	pQueue->size--;
	return item;
}
NODE * firstqueue(Queue *pQueue) {
	/*the queue is empty*/
	NODE *item;
	if (pQueue != NULL) {
		item = pQueue->head;

		return item;
	} else
		return NULL;
}

int isEmpty(Queue* pQueue) {
	if (pQueue == NULL) {
		return FALSE;
	}
	if (pQueue->size == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int main() {
	int idno = 1;
	struct app {
		int id;
		int siz;
		char name[50];
		char tim[50];
		int state;
		//0 anamoni 1 executing 2 finished

		int exectime;
	};

	int i;


    //STEP 1
	printf("Start\n");
	int noapps = 0;
	printf("How many apps:");
	scanf("%d", &noapps);
	int ii = 1;

	struct Node* head = NULL;
	Queue *pQ = ConstructQueue(-7);

	for (ii = 1; ii <= noapps; ii++) {

	
		struct Node *new_node = newNode(5);
		//	struct Node *newapp=(struct Node*)malloc(sizeof(struct app));
		new_node->id = idno;
		printf("Id no %d \n", idno);
		printf("Size of app:");
		scanf("%d", &new_node->data);
		printf("Name of app:");
		scanf("%s", new_node->name);
		new_node->state = 0;

		printf("time of app:");
		scanf("%d", &new_node->exectime);
		//	newapp->data=-1;


		idno++;
		sortedInsert(&head, new_node);

	}

	srand(time(0));
	
	//STEP 2
	int k = 0;
	for (k = 1; k <= 100; k++) { //100.000 Discrete Steps.(100 for test)
		printf("step %d \n", k);
		int num = (rand() % (100 + 1)) + 0;  //print the chance , testing the chance , its working at 90%
		//  printf("%d \n", num);

		int num2 = (rand() % (10 + 1)) + 0;
		//   printf("%d \n", num);



		if ((num <= 40)&&(countlist(head)<(total_apps*pososto_new_apps))) {  //STEP 3 40% chance to create new app

			
			idno++;
			printf("add new to list -- id no %d \n", num);
			struct Node *new_node = newNode(5);
			//	struct Node *newapp=(struct Node*)malloc(sizeof(struct app));
			new_node->id = idno;
			int numc = (rand() % (10 + 1)) + 0;
			
			new_node->exectime = numc;
			char tname[40];
			sprintf(tname, "%d", idno);

			new_node->state = 0;


			int numc2 = (rand() % (300 + 1)) + 10; 
			new_node->data = numc2;
			//	newapp->data=-1;

			idno++;
			sortedInsert(&head, new_node); //STEP 7
		}
		int nowinlist = countlist(head);

		printf("IN LIST NOW %d in queueu now %d \n", countlist(head),pQ->size); // STEP 10 Average (how much in the List) 
		if (num2 < 3) {  //STEP 4 30% chance to create new app

			struct Node *cure = getrandomanddelete(head, nowinlist);
			//	printf("d IN LIST NOW %d \n",countlist(head));
			NODE *pN;
			if (cure != NULL) {
			//	printf("HERE\n");
			//	printf("SLUSTOR %d\n", cure->exectime);
				pN = (NODE*) malloc(sizeof(NODE));
				pN->data = cure;
				Enqueue(pQ, pN);
			}
		}

		//STEP 9
		NODE *ff = firstqueue(pQ);
		int tim = 0;
		if (ff != NULL) {
		//	printf("EINAI TO PROTO %d \n\n\n", ff->data->exectime);
			tim = ff->data->exectime;

			if (ff->data->exectime == 0) {
			//	printf("BYE BYE \n");
				Dequeue(pQ);
			}


			(ff->data->exectime)--;

		}



	}

	printList(head);

}

