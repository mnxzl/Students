#include "iostream"
using namespace std;

#define COURSE_CAPACITY 100

struct Student{
	char name[20];
	int grade;
}students[COURSE_CAPACITY];

int studentCount = 0;

void list();
void add();
void drop();
void input(struct Student &student);
void out(struct Student &student);
int find(char* model);

int main()
{
	for(int i=0;i<COURSE_CAPACITY;i++){
		students[i].grade=-1;

	}


	int action;
	do{
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)ѧ���б�"<<endl;
		cout<<"2)����ѧ��"<<endl;
		cout<<"3)ѧ����ѡ"<<endl;
		cout<<"4)�˳�����"<<endl<<endl;


        cin>>action;
		switch(action){
		case 1:
			list();
			break;
		case 2:
			add();
			break;
		case 3:
			drop();
			break;
		case 4:
			return 0;
     	default:
			cout<<"���������������ѡ��";
		}
	}while(1);
}


void list(){
	cout<<"-------ѧ������-------"<<endl;
	cout<<"����\t"<<"����"<<endl;
	for(int i=0;i<studentCount;i++){
		if(-1!=students[i].grade){
		cout<<students[i].name<<"\t"<<students[i].grade<<endl;
		}else{
		cout<<students[i].name<<"\t"<<"δ���"<<endl;
		}
	}
	cout<<"-------ѧ������-------"<<endl<<endl;
}

void add(){
	struct Student newStudent;
	input(newStudent);

	int i = find(newStudent.name);
	if(i == studentCount&&i>101)
		cout<<"������������!"<<endl;
	if(i == studentCount){
		strcpy(students[i].name , newStudent.name);
		students[i].grade = newStudent.grade;
		studentCount++;
	}else{
		cout<<"�Ѿ������ѧ����!";
	}
}

void drop(){
	struct Student student;
	out(student);

	int pos = find(student.name);
	if(pos == studentCount){
		cout<<"û�����ѧ����"<<endl;
	}else{
		for(int i=pos;i<studentCount-1;i++){
			students[i]=students[i+1];
		}
		studentCount-=1;
	}
}

void input(struct Student &student){
	cout<<"������";
	cin>>student.name;
	cout<<"������";
	cin>>student.grade;
}

int find(char* model){
	int i;
	for(i=0;i<studentCount;i++){
		if(strcmp(students[i].name,model) == 0){
			break;
		}
	}
	return i;
}
void out(struct Student &student){
	cout<<"������";
	cin>>student.name;
	student.grade=-1;
}