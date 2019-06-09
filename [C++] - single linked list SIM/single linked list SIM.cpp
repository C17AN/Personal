// Integrated linked list simulator
// last updated 2019/05/23

/* HOWTO
If you want to Add node, press 1 on the main menu.
Or, if you want to Delete node, press 2 on the main menu.
And you can print the Current list by pressing 3 on the main menu (Working)

+ "Index" means the index of node which positioned before the Added / Deleted node.
For example, if you want to delete second node, you'll have to input 1, not 2.
*/  

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE 
{
  int data;
  struct NODE *next;
} node;

int menu = 1, node_data;
int node_cnt = 0, node_idx;

void addNode(node *target, int node_data)
{
  node *new_Node = (node *)malloc(sizeof(node));
  new_Node -> next = target -> next;
  new_Node -> data = node_data;
  target -> next = new_Node;
}

void delNode(node *target)
{
  node *tempNode = target -> next;
  target -> next = tempNode -> next;
  free(tempNode);
}

int main()
{
  node *head = (node *)malloc(sizeof(node));
  node *temp_node = (node *)malloc(sizeof(node));
  head -> next = NULL;


  while(menu)
  {
    puts("---------------------");
    puts("Press 1 : Add Node");
    puts("Press 2 : Delete Node");
    puts("Press 3 : Print Linked List");
    puts("Press 0 : Quit");
    puts("---------------------");
    temp_node = head; 

    scanf("%d", &menu);
    switch(menu)
    {
      case 1:
        if(node_cnt < 1)
        {
          printf("Input first data : ");
          scanf("%d", &node_data);
          addNode(head, node_data);
          node_cnt++;
          printf("New Node Added!\n");
        }
        else
        {
          puts("Input index to add node\n");
          puts("Current List Structure : ");
          printf("HEAD NODE(NULL)");
          for(int i = 1; i < node_cnt + 1; i++)
          {
            temp_node = temp_node -> next;
            printf(" -> node %d(%d)", i, temp_node -> data);            
          }
          temp_node = head;
          printf("\nIndex : ");
          scanf("%d", &node_idx);

          if(node_idx > node_cnt)
            puts("Not enought Nodes!\n");

          else
          {
            printf("Input data of new node : ");
            scanf("%d", &node_data);
            for(int i = 0; i < node_idx; i++)
              temp_node = temp_node -> next;

            addNode(temp_node, node_data);
            temp_node = head;
            node_cnt++;
            printf("New Node Added!\n");
          }
        }
        break;

      case 2:
        if(node_cnt < 1) puts("Not enough Nodes!\n");
        else
        {
          puts("Input index to delete node");
          puts("Current List Structure : ");
          printf("HEAD NODE(NULL)");

          for(int i = 1; i < node_cnt + 1; i++)
          {
            temp_node = temp_node -> next;
            printf(" -> node %d(%d)", i, temp_node -> data);            
          }
          temp_node = head;
          printf("\nIndex : ");
          scanf("%d", &node_idx);

          if(node_idx >= node_cnt)
            puts("Not enought Nodes!\n");

          else
          {
            for(int i = 1; i <= node_idx; i++)
              temp_node = temp_node -> next;

            delNode(temp_node);
            temp_node = head;
            node_cnt--;
            printf("Node %d deleted\n", node_idx + 1);
          }                    
        }
        break;
      case 3:
        printf("忙式式式式式式式式式式式式式式忖\n");
        printf("弛      HEAD    弛\n");
        printf("戌式式式式式式式式式式式式式式戎\n");        

        for(int i = 1; i <= node_cnt; i++)
        {
          temp_node = temp_node -> next;

            printf("        早       \n");
            printf("忙式式式式式式式式式式式式式式忖\n");
            printf("弛    NODE %d    弛\n", i);
            printf("弛  Data : %d   弛\n", temp_node -> data);            
            printf("戌式式式式式式式式式式式式式式戎\n");                        
        }
        temp_node = head;
        break;
    }
  }
  puts("Exiting Program...");
  for(int i = 0; i < node_cnt; i++)
  {
    temp_node = temp_node -> next;
    free(temp_node);
  }
  free(head);  
  
}

