#include<iostream>
using namespace std;
template<class type>
class Node
{
  public:
  Node():link(NULL),prev(NULL){};
  void set_data(type data){this->data=data;}
  void set_link(Node*link){this->link=link;}
  void set_prev(Node*prev){this->prev=prev;}

  Node* get_link(){return link;}
  Node* get_prev(){return prev;}
  type get_data(){return data;}
 private:
 type data;
 Node*link;
 Node*prev;
};
template<class type>
class LinkedList{
public:
LinkedList():head(NULL),tail(NULL),count(0){} // o(1)
bool is_empty(){return(head==NULL?true:false);}// o(1)
void insert_first(type newitem)// o(1)
{
Node<type>*newnode=new Node<type>;
newnode->set_data(newitem);
if(is_empty()){
 head=tail=newnode;
}else{
Node<type>*old=head;
head=newnode;
old->set_prev(newnode);
newnode->set_link(old);
}
count++;
}
void insert_after(type item,type newitem)// o(N)
{
Node<type>*temp=head;
while(temp!=NULL){
if(temp->get_data()==item)
 {
Node<type>*newnode=new Node<type>;
newnode->set_data(newitem);
newnode->set_link(temp->get_link());
newnode->set_prev(temp);
temp->set_link(newnode);
if(item==tail->get_data())
tail=newnode;

count++;
break;
}
else{
temp=temp->get_link();
}
}
}
void insert_before(type item,type newitem)// o(N)
{
 Node<type>* current = head;
while(current->get_link()!=NULL||tail->get_data()==item)
{
if(current->get_data()==item)
 {
Node<type>*newnode=new Node<type>;
current->get_prev()->set_link(newnode);
newnode->set_prev(current->get_prev());
newnode->set_link(current);
current->set_prev(newnode);
newnode->set_data(newitem);
count++;
break;
 }
else if(current->get_data()==tail->get_data())
{
Node<type>*newnode=new Node<type>;
Node<type>*current=tail->get_prev();
newnode->set_prev(current);
newnode->set_link(current->get_link());
current->set_link(newnode);
count++;
break;
}
else current=current->get_link();
}
}
void append(type newitem) // o(1)
{
if(is_empty()){
insert_first(newitem);
}
else{
Node<type>*old=tail;
Node<type>*newnode=new Node<type>;
newnode->set_data(newitem);
old->set_link(newnode);
newnode->set_prev(old);
tail=newnode;
count++;
}
}
void delete_first() // o(1)
{
Node<type>*temp=head;
head=temp->get_link();
head->set_prev(NULL);
delete temp;
count--;
}
void delete_end() // o(1)
{
 Node<type>* old = tail;
 Node<type>* current=old->get_prev();
tail=current;
 current->set_link(NULL);
 count--;
 delete old;
}

int size() // o(1)
{
return count;
}
void delete_before(type item ) // o(N)
{
  Node<type>*temp=head;
Node<type>*cur;
while(temp!=NULL){
 if(item==temp->get_data())
 {     cur=temp->get_prev();
  temp->set_prev(cur->get_prev());
 cur->get_prev()->set_link(temp);
 delete cur;
count--;
 break;
 }
temp=temp->get_link();
}
}
void delete_after(type item) // o(N)
{
  Node<type>*temp=head;
  Node<type>*cur;
while(temp!=NULL){
 if(item==temp->get_data())
 {
     cur=temp->get_link();
   temp->set_link(cur->get_link());
 cur->get_link()->set_prev(temp);
 delete cur;
count--;
 break;
 }
temp=temp->get_link();
}
}
bool isfind(type item) // o(N)
{
Node<type>*temp=head;
while(temp!=NULL){
if(item==temp->get_data())
return true;

temp=temp->get_link();
}
return false;
}
void replace(type old_item,type new_item) // o(N)
{
Node<type>*temp=head;
bool exist=false;
while(temp!=NULL){
if(old_item==temp->get_data())
{
 exist=true;
 temp->set_data(new_item);
break;
}
temp=temp->get_link();
}
if(exist==false)
cout<<"NOT found";}
void display() // o(N)
{
 Node<type>*temp=head;
int n=0;
cout<<"******all element******\n";
while(temp!=NULL){
 n++;
 cout<<"item "<<n<<":"<<temp->get_data()<<endl;
 temp=temp->get_link();
}
}
void displaybyrecursion() // o(N)
{
static Node<type>*temp=head;
static int n=0;
if(temp==NULL)
return ;
else{
n++;
 cout<<"item "<<n<<":"<<temp->get_data()<<endl;
  temp=temp->get_link();
displaybyrecursion();
}
}
private:
Node<type>*head;
Node<type>*tail;
int count;
};
int main() {
LinkedList<string>Names;
Names.insert_first("Esmael medhat omar");
Names.insert_first("medhat omar elhabiby");
Names.append("Asem medhat omar");
Names.insert_before("Asem medhat omar","Omar medhat omar ");
Names.insert_before("Asem medhat omar","mar medhat omar ");
Names.insert_after("Esmael medhat omar","elsayed");
Names.delete_after("Esmael medhat omar");
Names.insert_after("Asem medhat omar","esmael");
Names.delete_end();
//cout<<Names.isfind("Asem medhat omar")<<endl;
//Names.insert_after("Omar medhat omar ","esmael omar ");
//Names.delete_end();
//Names.delete_end();
//Names.delete_end();
Names.delete_first();
//Names.insert_after("Asem medhat omar","Esmael alhabiby");
Names.display();
//Names.displaybyrecursion();
cout<<Names.size();

return 0;

}
