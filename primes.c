#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct primeNode{
	uint64_t prime, counter;
	struct primeNode *next;
};

int main(){
	uint64_t counter = 3;

	struct primeNode *root = malloc(sizeof(struct primeNode)), *current, *sqrt = root, *last = root;
	root->prime = 3;
	root->counter = 9;
	root->next = NULL;

	printf("2\n3\n");

	while(1){
		counter += 2;

		if(counter < sqrt->counter){
				current = root;
				while(current != sqrt){
					if(current->counter < counter)
						current->counter += current->prime * 2;

					if(current->counter > counter)
						current = current->next;
					else
						break;
				}

			printf("%"PRIu64"\n", counter);

			last->next = malloc(sizeof(struct primeNode));
			last->next->prime = counter;

			last = last->next;
		}else{	
			sqrt = sqrt->next;
			sqrt->counter = sqrt->prime * sqrt->prime;
		}
	}
	return 0;
}
