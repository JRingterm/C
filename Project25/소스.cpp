#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class DVD {
private:
	string title;//����
	int cost;//�뿩��
	string supervisor;//�����̸�
	static int DVD_num;//DVD��ȣ
	int d_state;//�뿩����
	int count;//�뿩�� Ƚ��
	int who_rent;
public:
	DVD() {
		title = "��ϴ����";
		cost = 0;
		supervisor = "����";
		d_state = 0;
		count = 0;
		who_rent = -1;
	}
	DVD(string title, int cost, string supervisor) {
		this->title = title;
		this->cost = cost;
		this->supervisor = supervisor;
		d_state = 0;
		count = 0;
		who_rent = -1;
	}
	void init_DVD(DVD *D) {//�ʱ� DVD ����
		ifstream f("DVD.txt");
		string title;
		string super;
		int cost;
		int popular, lend;
		while (!f.eof()) {
			f >> title;
			f >> cost;
			f >> super;
			f >> popular;
			f >> lend;
			D[DVD_num].setTitle(title);
			D[DVD_num].setCost(cost);
			D[DVD_num].setSuper(super);
			D[DVD_num].count = popular;
			D[DVD_num].who_rent = lend;
			DVD_num++;
		}
	}
	int getWho_rent() { return who_rent; }
	string getTitle() { return title; }
	int getCost() { return cost; }
	string getSuper() { return supervisor; }
	int getDVD_num() { return DVD_num; }
	int getD_state() { return d_state; }
	int getCount() { return count; }
	void setCost(int cost) { this->cost = cost; }
	void setTitle(string title) { this->title = title; }
	void setSuper(string super) { supervisor = super; }
	void setCount() { count++; }
	void add_DVD(DVD *D) {
		ofstream in("DVD.txt", ios::app );
		string title;
		int cost;
		string super;
		cout << "�߰��� DVD �̸��� ����, �����̸� �Է�: " << endl;
		cin >> title >> cost >> super;
		D[DVD_num].setTitle(title);
		D[DVD_num].setCost(cost);
		D[DVD_num].setSuper(super);
		in << title << " " << cost << " " << super << " " << count << " " << who_rent << endl;
		DVD_num++;
		ifstream fp("DVD.txt");
		string ptitle;
		string psuper;
		int pcost;
		int ppopular, plend;
		while (!fp.eof()) {
			fp >> ptitle;
			fp >> pcost;
			fp >> psuper;
			fp >> ppopular;
			fp >> plend;
			D[DVD_num].setTitle(ptitle);
			D[DVD_num].setCost(pcost);
			D[DVD_num].setSuper(psuper);
			D[DVD_num].count = ppopular;
			D[DVD_num].who_rent = plend;
			//DVD_num++;
		}
	}
	void set_whoRent(int who_rent) { this->who_rent = who_rent; }
	void setD_state(int d_state) { this->d_state = d_state; }
	string search_DVD(DVD *D) {
		string title;
		int select = 1;
		cout << "===================DVD �˻�===================" << endl;
		cout << "�˻��Ͻ� DVD �̸��� �Է��ϼ���: ";
		cin >> title;
		cout << endl;
		for (int i = 0; i < D->DVD_num; i++) {
			if (D[i].getTitle() == title) {
				cout << "***�˻����***" << endl;
				cout << D[i].getTitle() << ", ����: " << D[i].getSuper() << endl;
				cout << "�뿩��: " << D[i].getCost() << "��" << endl;
				cout << "�뿩(����=0/�Ұ���=1): " << D[i].getD_state() << endl;
				return D[i].getTitle();
			}
		}
		cout << "*�˻� ����� ã�� �� �����ϴ�." << endl;
		return "abc";
	}

	friend void print_DVD(DVD *D) {
		cout << "===================DVD List===================" << endl;
		for (int i = 0; i < D->DVD_num-1; i++) {
			cout << "Title: " << D[i].title << endl;
			cout << "Cost: " << D[i].cost << endl;
			cout << "Supervisor: " << D[i].supervisor << endl;
			cout << "Rental (possible=0/impossible=1): " << D[i].d_state << endl;
			cout << "Popularity: " << D[i].count << endl;
			cout << endl;
		}
	}
};
int DVD::DVD_num = 0;

class login_p {
public:
	string name;
	int p_num;
	int log;
	int num;
};

class Person {
	string name;
	int p_num;
	int state;
	static int num;
public:
	vector<string> list[3];
	Person() {
		name = " ";
		p_num = 0;
		state = 0;
		vector<string> list[3];
	}
	void Join(string name, int p_num) {
		this->name = name;
		this->p_num = p_num;
		num++;
	}
	void setState(int x) {
		if (x == 1) {
			if (state > 3)
				cout << "�뿩���� �ʰ�" << endl;
			else
				state++;
		}
		else
			state--;
	}
	int getNum() { return num; }
	int getState() { return state; }
	string getName() { return name; }
	int  getP_num() { return p_num; }
	void add_DVDlist(string title) {
		list->push_back(title);
	}
	void Person_state(Person *P) {
		string name;
		int p_num;
		cout << "===================ȸ������===================" << endl;
		try {
			cout << "ȸ���̸� �Է�: ";
			cin >> name;
			cout << "�н����� �Է�: ";
			cin >> p_num;
			if (cin.fail())
				throw 'a';
			cout << "========���� å ���=======" << endl;
			for (int i = 0; i < P[i].getNum(); i++) {
				if (P[i].getName() == name && P[i].getP_num() == p_num) {
					for (auto p = P[i].list->begin(); p != P[i].list->end(); ++p) {
						cout << i + 1 << "." << *p << endl;
					}
				}
				else
					cout << "���� å ����" << endl;
			}
		}
		catch (char e) {
			cout << "�н����带 �ٽ� Ȯ�����ּ���." << endl;
			cin.clear();
			fseek(stdin, 0, SEEK_END);
		}
	}
	void Join(Person* p) {
		string name;
		int p_num;
		int i = 0;
		cout << "===================ȸ�����===================" << endl;
		try {
			cout << "*Enter your Name: ";
			cin >> name;
			cout << "*Enter your last phone number(4 digits): ";
			cin >> p_num;
			if (cin.fail())
				throw 'a';
			p[num].Join(name, p_num);
			cout << "**Registered Complete!**" << endl;
		}
		catch (char e) {
			cerr << "Error: Not a number" << endl;
			cin.clear();
			fseek(stdin, 0, SEEK_END);
		}
	}
};

int Person::num = 0;
//�α���
int Login(string name, int p_num, Person* p) {
	for (int i = 0; i < p[i].getNum(); i++) {
		if (p[i].getName() == name && p[i].getP_num() == p_num) {
			cout << "Login Complete!" << endl;
			return 1;
		}
	}
	cout << "Login Failed.." << endl;
	return 0;
}
//����

//�α��� ������ȯ
login_p Try_login(Person* p) {
	string name;
	int p_num;
	int i = 0;
	try {
		cout << "Enter your Name: ";
		cin >> name;
		cout << "Enter your last phone number(4 digits): ";
		cin >> p_num;
		if (cin.fail())
			throw 'a';
		cout << endl;
		int log = Login(name, p_num, p);
		login_p log_p;
		log_p.name = name;
		log_p.log = log;
		log_p.p_num = p_num;

		return log_p;
	}
	catch (char e) {
		cout << "�н����带 �ٽ� Ȯ�����ּ���." << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);
	}
}

void Rent_DVD(DVD *D, Person *P) {
	string title = D->search_DVD(D);
	cout << "====================�뿩�ϱ�==================" << endl;
	login_p log_p;
	cout << "�뿩�ϱ� ���� �α��� ���ּ���" << endl;
	log_p = Try_login(P);
	if (log_p.log == 1) {
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			if (D[i].getTitle() == title && D[i].getD_state() == 0) {
				D[i].setD_state(1);
				for (int j = 0; j < P[j].getNum(); j++) {
					if (P[j].getName() == log_p.name && P[j].getP_num() == log_p.p_num) {
						P[j].setState(log_p.log);
						P[j].add_DVDlist(title);
						log_p.num = P[j].getNum();
						D[i].setCount();
						cout << "*" << title << "�� �뿩�Ͽ����ϴ�." << endl;
					}
				}
				D[i].set_whoRent(log_p.num);
			}
			else if (D[i].getD_state() == 1)
				cout << "�� DVD�� �̹� �뿩���̶� ���� �� �����ϴ�." << endl;
		}

	}
	else
		cout << "�α��� ���з� �뿩 �Ұ�" << endl;
}

void Return_DVD(DVD *D, Person *P) {
	cout << "�ݳ��ϱ�" << endl;
	string title = D->search_DVD(D);
	login_p log_p;
	log_p = Try_login(P);
	if (log_p.log == 1) {
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			for (int i = 0; i < P[i].getNum(); i++) {
				if (P[i].getName() == log_p.name && P[i].getP_num() == log_p.p_num) {
					for (int j = 0; j < D[j].getDVD_num()-1; j++) {
						if (D[j].getTitle() == title) {
							D[j].set_whoRent(-1);
							for (int k = 0; k < P[i].list->size(); k++) {
								if (P[i].list->at(k) == D[j].getTitle())
									P[i].list->erase(P[i].list->begin() + k);
							}
							D[j].setD_state(0);
							cout << title << "�� �ݳ�." << endl;
							return;
						}
					}
				}
			}
		}
	}
	else
		cout << "�α��� ���з� �ݳ� �Ұ�" << endl;
}
class Manager :public DVD, public Person {
private:
	int password = 3712;
public:
	int in_manager(Manager m, DVD *D, Person *P) {
		int select = 0;
		while (select != 3) {
			cout << "================������ ���================" << endl;
			cout << "=                1.DVD ���               =" << endl;
			cout << "=                2.ȸ����ȸ               =" << endl;
			cout << "=                  3.����                 =" << endl;
			cout << "===========================================" << endl;
			cin >> select;
			if (select == 1) {
				D->add_DVD(D);
			}
			else if (select == 2) {
				for (int i = 0; i < P->getNum(); i++) {
					cout << i + 1 << ".ȸ�� �̸�: " << P[i].getName() << endl;
				}
			}
		}
		cout << "���α׷� ����" << endl;
		return 0;
	}

	void alert_manager(Manager m, DVD *D, Person *P) {
		int pw;
		cout << "������ ������ �����Ϸ��� �н����带 �Է��ϼ���: " << endl;
		cin >> pw;
		if (m.password == pw) {
			cout << "������ ���� ��ȯ�մϴ�." << endl;
			in_manager(m, D, P);
		}
		else
			cout << "�н����尡 �ٸ��ϴ�." << endl;
	}
};
int main() {
	int select_menu = 0;
	DVD *D = new DVD[50];
	Person *P = new Person[50];
	Manager M;

	D->init_DVD(D);
	try {
		while (select_menu != 8) {
			cout << "==================DVD �뿩��==================" << endl;
			cout << "=            �޴��� �Է��ϼ���(����)         =" << endl;
			cout << "=                 1.DVD ���                 =" << endl;
			cout << "=                 2.DVD �˻�                 =" << endl;
			cout << "=                 3.ȸ�����                 =" << endl;
			cout << "=              4.���� ������Ȳ               =" << endl;
			cout << "=                 5.�뿩�ϱ�                 =" << endl;
			cout << "=                 6.�ݳ��ϱ�                 =" << endl;
			cout << "=            7.������ ���� ��ȯ            =" << endl;
			cout << "=                   8.����                   =" << endl;
			cout << "==============================================" << endl;
			cout << "�޴��� �����ϼ���(1~8): ";
			cin >> select_menu;
			if (select_menu > 10 && select_menu < 1)
				throw 0;
			else if (cin.fail())
				throw 'a';

			if (select_menu == 1)
				print_DVD(D);
			else if (select_menu == 2)
				D->search_DVD(D);
			else if (select_menu == 3)
				P->Join(P);
			else if (select_menu == 4)
				P->Person_state(P);
			else if (select_menu == 5)
				Rent_DVD(D, P);
			else if (select_menu == 6)
				Return_DVD(D, P);
			else if (select_menu == 7)
				M.alert_manager(M, D, P);
		}
	}
	catch (int e) {
		cout << "�޴��� �ش��ϴ� ���ڷ� �Է��ϼ���!" << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);
	}
	catch (char e) {
		cout << "�޴��� �ش��ϴ� ���ڷ� �Է��ϼ���!" << endl;
		cin.clear();
		fseek(stdin, 0, SEEK_END);

	}
	cout << "DVD �뿩 ���α׷��� �����մϴ�." << endl;
	if (select_menu == 8) {
		ofstream in("DVD.txt");
		ofstream pin("Person.txt");
		for (int i = 0; i < D->getDVD_num()-1; i++) {
			in << D[i].getTitle() << " " << D[i].getCost() << " " << D[i].getSuper() << " " << D[i].getCount() << " " << D[i].getWho_rent() << endl;
		}
		for (int i = 0; i < P->getP_num(); i++) {
			pin << P[i].getName() << " " << P[i].getP_num() << " " << P[i].getNum();
			for (auto p = P[i].list->begin(); p != P[i].list->end(); ++p) {
				pin << " " << *p;
			}
			pin << endl;
		}
		return 0;
	}
	return 0;
}