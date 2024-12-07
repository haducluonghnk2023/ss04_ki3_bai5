#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
void insertAtPosition(Node** head, int value, int position){
	Node* newNode = createNode(value);
	if(position < 0){
		printf("vi tri chen khong hop le.\n");
		free(newNode);
		return;
	}
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node *temp = *head;
	int indexCurrent = 0;
	while(temp != NULL & indexCurrent < position - 1){
		temp = temp->next;
		indexCurrent++;
	}
	if(temp == NULL){
		printf("vi tri vuot qua pham vi trong ds.\n");
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
// duyet ds
void printList(Node* head){
	Node* current = head;
	printf("ds hien tai:");
	while(current != NULL){
		printf("%d->",current->data);
		current = current->next;
	}
	printf("NULL\n");
}
// ham giai phong bo nho
void freeList(Node* head){
	Node* current = head;
	while(current != NULL){
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}
int main(){
	Node* head = NULL;
	int n,value,position;
	printf("nhap so phan tu ban dau:");
	scanf("%d",&n);
	for(int i = 0; i< n; i++){
		printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        insertAtPosition(&head, value, i);
	}
	printList(head);
	printf("nhap phan tu muon chen:");
	scanf("%d",&value);
	printf("nhap gia tri can chen:");
	scanf("%d",&position);
	insertAtPosition(&head, value, position);
    printList(head);
    free(head);
	return 0;
}

