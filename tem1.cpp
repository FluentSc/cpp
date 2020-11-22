#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
};

node *TailInit();
node *Find(node *head,int i);//i is element position
int Add(node *head,int i,int data);
int Delete(node *head,int i);
int Change(node *head,int i,int data);
int Length(node *head);
void Print(node *head);

int main(){
    cout<<"Hello world!"<<endl;
    system("pause");
}
node *TailInit(){
    node *head=new node();
    node *tail,*tem;
    head->data=0;
    head->next=NULL;
    tail=head;
    cout<<"Start to init LinkList!\n";
    int tem_data;
    cout<<"please input data :  ";
    cin>>tem_data;
    while (tem_data!=9999)
    {
        tem->data=tem_data;
        tail->next=tem;
        tail=tem;
        cout<<"please input data :  ";
        cin>>tem_data;
    }
    tail->next=NULL;
    cout<<"init successful! \n";
    return head;
    
}
int Length(node *head){
    if(head->next==NULL){
        return 0;
    }else{
        node *tem=head->next;
        int i=1;
        while(tem->next!=NULL){
            i++;
            tem=tem->next;
        }
        return i;
    }
}
node *Find(node *head,int i){
    int l=Length(head);
    if(l==0)return NULL;
    int q=1;
    if(i<0)return NULL;
    if(i==0)return head;
    if(i>l)return NULL;
    if(head->next!=NULL){
        node *tem=head->next;
        while(tem&&q!=i){
            tem=tem->next;
            q++;
        }
        return tem;

    }else
    {
        return NULL;
    }
    
}
int Add(node *head,int i,int data){

    node *tem=Find(head,i-1);
    if(tem!=NULL){
        node *new_node=new node();
        new_node->data=data;
        new_node->next=tem->next;
        tem->next=new_node;
        return 1;
    }else{
        return 0;
    }
}
int Delete(node *head,int i){
    node *tem=Find(head,i-1);
    node *m=tem->next;
    if(m!=NULL){
        tem->next=m->next;
        delete m;
        return 1;
    }else{
        return 0;
    }
}

int Change(node *head,int i,int data){
    node *tem=Find(head,i);
    if(tem!=NULL){
        tem->data=data;
        return 1;
    }else{return 0;}
}

void Print(node *head){
    if(head->next!=NULL){
        node *tem=head->next;
        while (tem!=NULL)
        {
            cout<<"--"<<tem->data;
            tem=tem->next;
        }
        
    }
}