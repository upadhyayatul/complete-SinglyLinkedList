#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};
node *Start = NULL;

void insertNodeLast(){
    node *temp = new node();
    cout<<"Insert data as Last:";
    cin>>temp->data;
    temp->link = NULL;
    if(Start == NULL)
        Start = temp;
    else{
        node *il = Start;
        while(il->link!=NULL)
            il = il->link;
        il->link = temp;
        free(il);
    }
}

void insertNodeStart(){
    node *temp = new node();
    cout<<"Insert data at Start:";
    cin>>temp->data;
    temp->link = NULL;
    if(Start == NULL)
        Start = temp;
    else{
        node *is = Start;
        temp->link = is;
        Start = temp;
        free(is);
    }
}

void insertNodeBetween(){
    node *temp = new node();
    cout<<"Insert data in between:";
    cin>>temp->data;
    temp->link = NULL;
    if(Start == NULL)
        Start = temp;
    else{
        node *ib = Start;
        int pos,count = 1;
        cout<<"Insert data at position less 4:";
        cin>>pos;
        while(count < (pos-1)){
            ib = ib->link;
            count+=1;
        }
        temp->link = ib->link;
        ib->link = temp;
        free(ib);

    }
}

void deleteNodeStart(){
    node *ds = Start;
    if(Start == NULL)
        cout<<"empty LinkedList";
    else{
        Start = ds->link;
    }
    free(ds);
    cout<<"First node deleted \n";
}

void deleteNodeLast(int num){
    node *dl = Start;
    int count = 1;
    if(Start == NULL)
        cout<<"empty Linkedlist";
    else{
        while(count < num - 1){
            dl = dl->link;
            count += 1;
        }
        dl->link = NULL;
        free(dl);
        cout<<"Last node deleted \n";
    }
}

void deleteNodeBetween(int num){
    node *db = Start;
    int pos,count = 1;
    cout<<"postion node to be deleted less than "<<num<<"\n";
    cin>>pos;
    if(Start == NULL)
        cout<<"empty LinkedList";
    else{node *temp;
        while(count < (pos-1)){
            db = db->link;
            count+=1;

        }
        temp = db->link;
        db->link = temp->link;
        //free(db); 
    }
    cout<<"node deleted from between \n";
}

void display(){
    node *ptr;
    ptr = Start;
    while(ptr != NULL){
        cout<<ptr->data<<" "<<ptr->link<<"  ";
        ptr = ptr->link;
    }
}

int main(){
    int count = 0, num;
    cout<<"enter the nodes to be inserted at last \n";
    cin>>num;
    while(1){
        insertNodeLast();
        count += 1;
        if(count == num)
            break;
    }
    //insertNodeStart();
    //insertNodeBetween();
    //deleteNodeStart();
    //deleteNodeLast(num);
    deleteNodeBetween(num);
    display();
    return 0;
}