#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[20]; // 지하철 역 이름 저장
    int dist; // 현재 지하철 역에서 다음 역까지의 걸리는 시간
    struct ListNode* link; // 다음 지하철 역 노드의 주소를 저장하는 구조체 포인터
}ListNode;

ListNode* create_node(char data[], int dist) {
    ListNode* new_node;
    new_node = (ListNode*)malloc(sizeof(ListNode));

    strcpy(new_node -> data,data); // 지하철 역 이름 입력
    new_node -> dist = dist; // 현재 위치에서 다음 역까지 걸리는 시간 입력
    new_node -> link = NULL; // NULL 링크 입력

    return new_node;
}

void insert_node(ListNode** phead, ListNode *p, ListNode* new_node, int p_dist) {
    if(*phead == NULL) { // 공백리스트인 경우
        new_node -> link = NULL;
        *phead = new_node;
        new_node -> dist = p_dist;
    }

    else if (p == NULL) { //p가 NULL이면 첫번째 노드로 삽입
        new_node -> link = *phead;
        *phead = new_node;
         new_node -> dist = p_dist;
    }

    else {              // p 다음에 삽입
        new_node->link = p->link;
        p->link = new_node;
        p -> dist = p_dist;
    }
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed,int p_dist)
{
    if( p== NULL) // 삭제될 노드가 최선행 노드인 경우
    *phead = (*phead)->link;
    else        // p 다음 노드 제거
    p->link = removed->link;
    p->dist = p_dist;
    free(removed);
}

ListNode* search(ListNode* head, char find_station[]) {
    ListNode* p;
    p = head;

    while( p != NULL ) {
        if(strcmp(p->data,find_station)==0) return p;
         p = p->link;
    }
    return p; // 탐색 실패일 경우 NULL 반환
}

void display(ListNode* head) {
    ListNode*p = head;
 if (p != NULL) {
            printf("%s(%d)", p->data, p->dist);
                                   p = p->link;
                                       }
  
                   while (p != NULL) {
                               printf(" -> %s(%d)", p->data, p->dist);
                                       p = p->link;
                                           }
           printf("\n");

}
void Time(ListNode* head, ListNode* depart, ListNode* leave ) {
    ListNode*p = head;
    int time = 0;
    while (p != depart) p = p->link;
 if(p==depart) {
     while (p != leave) {
            time += p->dist;
            p = p->link;
        }
 }
 printf("\nFrom %s to %s: %d\n\n", depart->data, leave->data, time);
}



int main(void) {
    ListNode* head = NULL;
    insert_node(&head, head, create_node("Airport",0),0);
    display(head);
      insert_node(&head,search(head,"Airport"),create_node("Aewol",0),20);
display(head);
insert_node(&head,search(head,"Aewol"),create_node("Seogwipo",0),40);
display(head);
insert_node(&head,search(head,"Seogwipo"),create_node("Seongsan",0),30);
display(head);
insert_node(&head,search(head,"Aewol"),create_node("Moseulpo",30),30);
display(head);
Time(head, search(head,"Aewol" ),search(head,"Seongsan"));
remove_node(&head,search(head,"Aewol"),search(head,"Moseulpo"),40);
display(head);
Time(head, search(head,"Aewol" ),search(head,"Seongsan"));
    return 0;
}