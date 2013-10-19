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
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)学生列表"<<endl;
		cout<<"2)新增学生"<<endl;
		cout<<"3)学生退选"<<endl;
		cout<<"4)退出程序"<<endl<<endl;


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
			cout<<"您输入错误，请重新选择！";
		}
	}while(1);
}


void list(){
	cout<<"-------学生名单-------"<<endl;
	cout<<"姓名\t"<<"分数"<<endl;
	for(int i=0;i<studentCount;i++){
		if(-1!=students[i].grade){
		cout<<students[i].name<<"\t"<<students[i].grade<<endl;
		}else{
		cout<<students[i].name<<"\t"<<"未打分"<<endl;
		}
	}
	cout<<"-------学生名单-------"<<endl<<endl;
}

void add(){
	struct Student newStudent;
	input(newStudent);

	int i = find(newStudent.name);
	if(i == studentCount&&i>101)
		cout<<"超过人数限制!"<<endl;
	if(i == studentCount){
		strcpy(students[i].name , newStudent.name);
		students[i].grade = newStudent.grade;
		studentCount++;
	}else{
		cout<<"已经有这个学生了!";
	}
}

void drop(){
	struct Student student;
	out(student);

	int pos = find(student.name);
	if(pos == studentCount){
		cout<<"没有这个学生！"<<endl;
	}else{
		for(int i=pos;i<studentCount-1;i++){
			students[i]=students[i+1];
		}
		studentCount-=1;
	}
}

void input(struct Student &student){
	cout<<"姓名：";
	cin>>student.name;
	cout<<"分数：";
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
	cout<<"姓名：";
	cin>>student.name;
	student.grade=-1;
}