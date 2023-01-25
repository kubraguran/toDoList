#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <ctime>
using namespace std;

class ToDoItem 
{

private:
int id;
std::string description;
bool completed;


public:
ToDoItem(): id(0), description(""), completed(false) {};
 bool create(std:: string new_description) {
    id = rand() % 100 + 1; 
    description = new_description;
    return true;
 }
 int getId() {return id; };
 std::string getDescription() { return description; };
 bool isCompleted() {return completed; };
 
 void setCompleted(bool val) {
    completed = val;
 }




};

int main(int argc,char **argv) 

{


fstream pout;

char path [100]= "add your file address/todolist.txt";
pout.open(path, ios::app| ios::out );
 char input_option;
 int input_id;
 std::string input_description;
 std::string version = "v2.0.0";
 std::list<ToDoItem>todoItems;
 std::list<ToDoItem>::iterator it;
 

 srand(time(NULL));
 todoItems.clear();

 while(1){
 system("clear");


std::cout <<  "\x1b[32m to do list \x1b[0m" << version  << std::endl;
std::cout << std::endl << std::endl;

for(it = todoItems.begin(); it != todoItems.end(); it++){
    std::string completed = it->isCompleted() ? "done" : "not done";
    std::cout << it->getId() << " | " << it->getDescription()<< " | " << completed << std::endl;
    }

if(todoItems.empty()){
    std:: cout << "nothing in here" << std::endl;
}

std::cout<<std::endl<<std::endl;

std::cout << "[a]dd a new todo" << std::endl;
std::cout << "[c]omplete todo" << std::endl;
std::cout << "[q]uit todo" << std::endl;

std::cout<<std::endl;

switch (input_option)
{
case 'a':
std::cout << "\x1b[31m you added it \x1b[0m" << std::endl;
break;

case 'c':
std::cout << "\x1b[31m situation is changed \x1b[0m" << std::endl;
break;
}

std::cout << "choice: ";
std::cin >> input_option;

if(input_option == 'q'){
    std::cout << "everything is saved";
    break;
} else if(input_option == 'a'){
     std::cout << "\x1b[32m add your todo \x1b[0m" << std::endl;
     std::cin.clear();
     std::cin.ignore();
     std::getline(std::cin, input_description);
     ToDoItem newItem;
     newItem.create(input_description); 
     todoItems.push_back(newItem);
   pout << input_description << endl;
     

}else if(input_option == 'c'){
    std::cout << "\x1b[32m Enter id to mark completed:  \x1b[0m"<< std::endl;
    std::cin >> input_id;
    for(it = todoItems.begin(); it != todoItems.end(); it++){
     if(input_id == it->getId()){
        it->setCompleted(true);
           pout << it->getDescription() << " | " << (it->isCompleted() ? "done" : "not done") << endl;
        break;
     }
    }
       
}






 }
   pout.close();

return 0;
 

}

