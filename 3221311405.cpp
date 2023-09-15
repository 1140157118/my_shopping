#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem { 
    char name[50]; 
    int quantity;  
    struct ShoppingItem* next; 
}; 
struct ShoppingItem* shoppingList = NULL; 
void addItem(char itemName[], int itemQuantity) { 
    struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem)); 
    strcpy(newItem->name,itemName);
    newItem->quantity=itemQuantity;
    newItem->next=shoppingList;
    shoppingList=newItem;
} 
void removeItem(char itemName[]) { 
    struct ShoppingItem* current = shoppingList; 
    struct ShoppingItem* previous = NULL; 
 
    while (current != NULL) { 
        if (strcmp(current->name, itemName) == 0) { 
            if (previous != NULL) { 
                previous->next = current->next; 
            } else { 
                shoppingList = current->next; 
            } 
            free(current); 
            break; 
        } 
		 previous=current;
		 current=current->next;
    } 
}
void displayList() { 
    struct ShoppingItem* current = shoppingList; 
 
    printf("�����嵥:\n"); 
    while (current != NULL) { 
        printf("%s - ����:%d\n", current->name, current->quantity); 
        current=current->next;
    } 
} 
void updateQuantity(char itemName[], int newItemQuantity) { 
    struct ShoppingItem* current = shoppingList; 
 
    while (current != NULL) { 
        if (strcmp(current->name, itemName) == 0) { 
            current->quantity=newItemQuantity;
            break; 
        } 
        current = current->next; 
    } 
} 
int totalQuantity() { 
    struct ShoppingItem* current = shoppingList; 
    int total = 0; 
 
    while (current != NULL) { 
      total++;
	  current=current->next;
    } 
 
    return total; 
} 
void findItem(char itemName[]) { 
    struct ShoppingItem* current = shoppingList; 
 
    printf("������Ʒ \"%s\" ��\n", itemName); 
    while (current != NULL) { 
        if (strcmp(current->name, itemName) == 0) { 
            printf("%s - ������%d\n", current->name, current->quantity); 
            return; 
        } 
        current=current->next;
    } 
 
    printf("δ�ҵ���Ʒ \"%s\"��\n", itemName); 
} 
void sortList() { 
    struct ShoppingItem* current = shoppingList; 
    struct ShoppingItem* nextItem = NULL; 
    char tempName[50]; 
    int tempQuantity; 
 
    while (current != NULL) { 
        nextItem = current->next; 
 
        while (nextItem != NULL) { 
            if (strcmp(current->name, nextItem->name) > 0) { 
               strcpy(tempName,current->name); 
               strcpy(current->name,nextItem->name);
               strcpy(nextItem->name,tempName);
                tempQuantity = current->quantity; 
                current->quantity = nextItem->quantity; 
                nextItem->quantity = tempQuantity; 
            } 
            nextItem = nextItem->next; 
        } 
        current = current->next; 
    } 
}
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) { 
    struct ShoppingItem* current = *list1;  
	while(current->next!=NULL)
	current=current->next;     
    current->next = *list2; 
    *list2 = NULL; 
} 
void deleteItem(char itemName[], int deleteAll) { 
    struct ShoppingItem* current = shoppingList; 
    struct ShoppingItem* prev = NULL; 
 
    while (current != NULL) { 
        if (strcmp(current->name, itemName) == 0) { 
            if (prev == NULL) { 
                struct ShoppingItem* temp = shoppingList; 
                shoppingList=shoppingList->next;
                free(temp); 
                if (!deleteAll) break; 
            } else { 
				prev->next=current->next;
                free(current); 
                current = prev->next; 
                if (!deleteAll) break; 
            } 
        } else { 
            prev = current; 
            current = current->next; 
        } 
    } 
}
void clearList() { 
    while (shoppingList != NULL) { 
        struct ShoppingItem *temp= shoppingList;
        shoppingList=shoppingList->next;
        free(temp); 
    } 
}
int main(){
	int a;
	printf("1�������Ʒ�������嵥��\n2���ӹ����嵥���Ƴ���Ʒ��\n3���鿴�����嵥��\n4���޸Ĺ����嵥����Ʒ��������\n5����չ����嵥�� \n6�����㹺���嵥����Ʒ���������� \n7�����ҹ����嵥�е���Ʒ�� \n8���������嵥��\n9���ϲ������嵥�� \n10��ɾ�������嵥�е���Ʒ��\n");
	printf("����1~10�����Ӧ��������0�˳���������������Ч\n");
	scanf("%d",&a);
	while(a!=0){
		if(a==1){
			char itemName[50];
			int itemQuantity;
			printf("������Ʒ����\n");
			scanf("%s",itemName);
			printf("������Ʒ����\n"); 
			scanf("%d",&itemQuantity);
			addItem(itemName,itemQuantity);
		}else if(a==2){
			char itemName1[50];
			printf("����Ҫ�Ƴ�����Ʒ����\n");
			scanf("%s",itemName1);
			removeItem(itemName1);
		}else if(a==3){
			displayList();
		}else if(a==4){
			char itemName2[50];
			int newItemQuantity;
			printf("����Ҫ�޸���Ʒ������\n");
			scanf("%s",itemName2);
			printf("�����޸ĺ����Ʒ����\n");
			scanf("%d",&newItemQuantity);
			updateQuantity(itemName2,newItemQuantity);
		}else if(a==6){
			int num;
			num=totalQuantity();
			printf("��Ʒ������%d\n",num);
		}else if(a==5){
			clearList();
		}else if(a==7){
			char itemName3[50];
			printf("����Ҫ���ҵ���Ʒ��\n");
			scanf("%s",itemName3);
			findItem(itemName3); 
		}else if(a==8){
			sortList();
		}else if(a==9){
			
		}else if(a==10){
			char itemName4[50];
			int deleteAll;
			printf("����Ҫɾ������Ʒ����\n");
			scanf("%s",itemName4);
			printf("�Ƿ�ɾ��ȫ��ͬ����Ʒ����������1������������0\n");
			scanf("%d",&deleteAll);
			deleteItem(itemName4,deleteAll);
		}else
		printf("������Ч\n"); 
		printf("1�������Ʒ�������嵥��\n2���ӹ����嵥���Ƴ���Ʒ��\n3���鿴�����嵥��\n4���޸Ĺ����嵥����Ʒ��������\n5����չ����嵥�� \n6�����㹺���嵥����Ʒ���������� \n7�����ҹ����嵥�е���Ʒ�� \n8���������嵥��\n9���ϲ������嵥�� \n10��ɾ�������嵥�е���Ʒ��\n");
	    printf("����1~10�����Ӧ��������0�˳���������������Ч\n");
	    scanf("%d",&a);
	}
	return 0;
}

