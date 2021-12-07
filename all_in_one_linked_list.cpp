#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void traverse(node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


void add_new_node_and_data_after_nth_node(node* head,int n, int x)
{
    int count = 1;
    while(count<n){
        head = head->next;
        count++;
    }
    node* new_node = new node();
    new_node->next = head->next;
    head->next = new_node;
    head->next->data = x;
}


void add_new_node_and_data_at_end(node* n, int x)
{
    node* new_end = new node();
    while(n->next!=NULL){
        n = n->next;
    }
    n->next = new_end;
    new_end->next = NULL;
    new_end->data = x;
}


node* add_new_node_at_front(node* head, int x)
{
    node* new_head = new node();
    new_head->next = head;
    new_head->data = x;
    head = new_head;
    return head;
}


void delete_node_where_data_is_x(node* head, int x)
{
    while(head->next->data!=x){
        head = head->next;
    }
    head->next = head->next->next;
}


void change_data_of_nth_node_to_x(node* head, int n, int x)
{
    int k = 1;
    while(k<n){
        head = head->next;
        k++;
    }
    head->data = x;
}


node* delete_node_at_xth_node(node *head, int x)
{
    if(x==1)return head->next;
    node* ptr = head;
    int k = 2;

    while(k<x){
        ptr = ptr->next;
        k++;
    }
    node*qwer;
    qwer = ptr->next;
    ptr->next = ptr->next->next;
    delete qwer;
    return head;
}


node* reverse_all_nodes(node* head)
{
    node* next_node = NULL;
    node* prev_node = NULL;
    node* curr_node = head;
    
    while(curr_node !=NULL){
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node;
    return head;
}


node* reverse_n_times_from_right(node* head, int n)
{
    node* ptr1 = head;    // next of this will be new NULL;
    node* ptr2 = head;    // this will be new head;
    node* ptr3 = head;    // this pointer will be going till NULL;
    int count = 0;

    while(count<n){
        ptr3 = ptr3->next;
        count++;
    }
    ptr3 = ptr3->next;
    ptr2 = ptr2->next;
    while(ptr3!=NULL){
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    node* ptr4 = ptr2;
    while(ptr4->next!=NULL){
        ptr4 = ptr4->next;
    }
    ptr4->next = head;
    ptr1->next = NULL;
    head = ptr2;
    
    return head;
}


node* remove_duplicates(node* head)
{
    node* ptr1 = head;
    node* ptr2 = head;
    
    while(ptr1->next!=NULL){
        ptr2 = ptr2->next;
        while(ptr1->data==ptr2->data){
            if(ptr2->next==NULL){
                ptr2 = NULL;
                break;
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1->next = ptr2;
        if(ptr1->next!=NULL){
            ptr1 = ptr1->next;
        }   
    }
    return head;
}


node* remove_all_duplicates(node* head)
{
    // taking care of edge testcases
    if(head==NULL || head->next==NULL) return head;

    node* new_head = new node();
    new_head->next = head;
    new_head->data = -1;
    head = new_head;

    node* ptr0 = head;
    node* ptr1 = head->next;
    node* ptr2 = ptr1->next;

    while(ptr1->next!=NULL){
        if(ptr1->data==ptr2->data){
            int k = ptr1->data;
            while(ptr1->data==k){
                if(ptr2->next==NULL && ptr2->data==k){
                    ptr0->next = NULL;
                    return head->next;
                }
                else if(ptr2->next==NULL && ptr2->data!=k){
                    ptr0->next = ptr2;
                    return head->next;
                }
                else{
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next; 
                }
            }
        }
        else{
            ptr0->next = ptr1;
            ptr0 = ptr0->next;
            ptr1 = ptr1->next;
            
            if(ptr2!=NULL){
                ptr2 = ptr2->next;
            }
        }   
    }
    return head->next;
}




// node* swap_nodes_in_pair(node* head)
// {
//     node* ptr0 = head;
//     int len = 0;
//     while(ptr0!=NULL){
//         ptr0 = ptr0->next;
//         len++;
//     }

//     if(len==1 || len==0) return head;

//     // reversing all nodes first;
//     node* next_node = NULL;
//     node* prev_node = NULL;
//     node* curr_node = head;
    
//     while(curr_node !=NULL){
//         next_node = curr_node->next;
//         curr_node->next = prev_node;
//         prev_node = curr_node;
//         curr_node = next_node;
//     }
//     head = prev_node;
//     // reversing completed

//     node* ptr1 = head;

//     if(len%2==1)
//     {
//         ptr1 = ptr1->next;
//     }

//     int temp;

//     while(true){
//         temp = ptr1->data;
//         ptr1->data = ptr1->next->data;
//         ptr1->next->data = temp;

//         if(ptr1->next->next!=NULL){
//             ptr1 = ptr1->next->next;
//         }
//         else{
//             break;
//         }
//     }

//     // reversing again to get the correct output
//     next_node = NULL;
//     prev_node = NULL;
//     curr_node = head;
    
//     while(curr_node !=NULL){
//         next_node = curr_node->next;
//         curr_node->next = prev_node;
//         prev_node = curr_node;
//         curr_node = next_node;
//     }
//     head = prev_node;

//     return head;
// }


node* reverse_linked_list_from_m_node_to_n_node(node* head, int m, int n)
{
    // taking care of edge testcases
    if(m==n || head->next==NULL || head==NULL) return head;

    node* next_node = head;
    node* prev_node = head;
    node* curr_node = head;
    int m_count = 1;
    int n_count = 1;
    node* ptrn = head;

    while(m_count<m){
        next_node = next_node->next;
        curr_node = curr_node->next;
        if(m_count<m-1){
            ptrn = ptrn->next;
        }
        m_count++;
    }

    while(n_count<n+1){
        prev_node = prev_node->next;
        n_count++;
    }

    while(m_count<n_count){
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
        m_count++;
    }
    if(m==1){
        head = prev_node;
        return head;
    }
    else{
        ptrn->next = prev_node;
        return head;
    }
}







int main(){
    
    node* head = new node();
    head->data = 1;


    while(true){
        cout<<"1.  Traverse the linked list"<<endl;
        cout<<"2.  Add new node and its data at the end of the linked list"<<endl;
        cout<<"3.  Add new node and its data after n node"<<endl;
        cout<<"4.  Add new node and its data at front"<<endl;
        cout<<"5.  Delete a node where its data is (x)"<<endl;
        cout<<"6.  Delete the node at nth position"<<endl;
        cout<<"7.  Change data of nth node to (x)"<<endl;
        cout<<"8.  Reverse the whole linked list"<<endl;
        cout<<"9.  Reverse the linked list n-times from right"<<endl;
        cout<<"10. Reverse the linked from m node to n node"<<endl;
        cout<<"11. Delete duplicate data/node"<<endl;
        cout<<"12. Delete all duplicate data/nodes"<<endl;
        cout<<"13. Swap nodes in pair    -------in progress"<<endl;
        cout<<"14. Exit"<<endl;
        cout<<endl<<endl;   

        int t;
        cin>>t;
        cout<<endl;

        switch (t) {
           
            case 1:
                cout<<"Traversing the linked list"<<endl;
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 2:
                int x2;
                cout<<"Input data to be added"<<endl;
                cin>>x2;
                add_new_node_and_data_at_end(head, x2);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 3:
                int n3,x3;
                cout<<"Input node position (nth node)"<<endl;
                cin>>n3;
                cout<<"Input data to be added"<<endl;
                cin>>x3;
                add_new_node_and_data_after_nth_node(head, n3, x3);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 4: 
                int x4;
                cout<<
                "Input data to be added"<<endl;
                cin>>x4;
                head = add_new_node_at_front(head, x4);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 5:
                int x5;
                cout<<"Input data to be deleted"<<endl;
                cin>>x5;
                delete_node_where_data_is_x(head, x5);
                traverse(head);
                cout<<endl<<endl;
                break;
           
            case 6:
                int n6;
                cout<<"Input node position to be deleted"<<endl;
                cin>>n6;
                head = delete_node_at_xth_node(head, n6);
                traverse(head);
                cout<<endl<<endl;
                break;

            case 7: 
                int n7,x7;  
                cout<<"Input node    position (nth node)"<<endl;
                cin>>n7;    
                cout<<"Input data to be changed"<<endl;
                cin>>x7;
                change_data_of_nth_node_to_x(head, n7, x7);
                traverse(head);
                cout<<endl<<endl;
                break;

            case 8:
                head = reverse_all_nodes(head);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 9:
                int n9;
                cout<<"How many times you want to shift the linked list from right"<<endl;
                cin>>n9;
                head = reverse_n_times_from_right(head,n9);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 10:
                int m10;
                cout<<"input m"<<endl;
                cin>>m10;
                int n10;
                cout<<"input n"<<endl;
                cin>>n10;
                head = reverse_linked_list_from_m_node_to_n_node(head,m10,n10);
                traverse(head);
                cout<<endl<<endl;
                break;

            case 11:
                head = remove_duplicates(head);
                traverse(head);
                cout<<endl<<endl;
                break;
            
            case 12:
                head = remove_all_duplicates(head);
                traverse(head);
                cout<<endl<<endl;
                break;

            case 13:
                // head = swap_nodes_in_pair(head);
                // traverse(head);
                // cout<<endl<<endl;
                break;

            case 14:
                return 0;
        }
    }

    return 0;
}