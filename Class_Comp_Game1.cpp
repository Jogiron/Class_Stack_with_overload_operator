#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;

namespace CompGame {
	class ComputerGame
	{
	private:
		ComputerGame* pDownMember = NULL;
		
		string Name; //�������� ����
		string Descrip; //�������� ����
		int Cost = 0; //���������
		string Release_Date; //���� ������
		string Dev_Corporation; //������ ����������
		string OS; //������ �������
		string Recom_CPU;
		string Recom_GPU;
		string Recom_CountRAM;
		string Recom_MemoryDisc;
		string tmp; //���� ��� �������� ����� � ��� ���������������� �������� �� int

	public:
		void pDownRemember(ComputerGame* pdown)
		{
			this->pDownMember = pdown;
		}

		ComputerGame* pDownReturn()
		{
			if (this->pDownMember == NULL)
			{
				return NULL;
			}
			else return this->pDownMember;
		}

		void InputAtributs()
		{
			cout << "���������� ���� � ���������: " << endl;
				cout << "\t������� ����� �������� ����! ";
				std::getline(cin >> std::ws,this->Name);
				cout << "\t������� �������� ����! ";
				std::getline(cin >> std::ws, this->Descrip);
			returne:
				cout << "\t������� ��������� ����! ";
				std::getline(cin >> std::ws, this->tmp);
				try
				{
					this->Cost = stoi(tmp);
				}
				catch (std::invalid_argument ex) //std::ios_base::failure ex)//std::invalid_argument e)
				{
					cout << "������������ ���� ������!" << endl;
					goto returne;
				}
				catch (std::out_of_range ex)
				{
					cout << "���� ��� �� �������� ���� (�� ������ 2022 ����), �� ���� ����� ������� ���������� �������!" << endl;
					goto returne;
				}
				cout << "\t������� ���� ������ ����! ";
				getline(cin >> std::ws, this->Release_Date);
				cout << "\t������� �������� ����������, ��������� ����! "; 
				getline(cin >> std::ws, this->Dev_Corporation);
				cout << "\t������� ��� �����(��) �� �������� ����! ";
				getline(cin >> std::ws, this->OS);
				cout << "\t������� ��������������� ��������� ��� ����! ";
				getline(cin >> std::ws, this->Recom_CPU);
				cout << "\t������� ��������������� ���������� ��� ����! ";
				getline(cin >> std::ws, this->Recom_GPU);
				cout << "\t������� ��������������� ���������� ����������� ������ ��� ����! "; 
				getline(cin >> std::ws, this->Recom_CountRAM);
				cout << "\t������� ��������������� ���������� ����� �� ����� ��� ����! ";
				getline(cin >> std::ws, this->Recom_MemoryDisc);
			cout << "!!!���� ������� ���������!!!" << endl;
		}

		void DataObj()
		{
			cout << "������ (�����������) ��������� �������� �����" << endl << "�������� � �������� ���������� ����:" << endl
				<< "\t��������: " << this->Name << endl
				<< "\t��������: " << this->Descrip << endl
				<< "\t���������: " << this->Cost << endl
				<< "\t���� �������: " << this->Release_Date << endl
				<< "\t������������: " << this->Dev_Corporation << endl
				<< "\t���������: " << this->OS << endl
				<< "\t������������� ���������: " << this->Recom_CPU << endl
				<< "\t������������� ����������: " << this->Recom_GPU << endl
				<< "\t������������� ���������� ��: " << this->Recom_CountRAM << endl
				<< "\t������������� ���������� ����� �� �� : " << this->Recom_MemoryDisc << endl;
		}

		ComputerGame()
		{
			this->InputAtributs();
			cout << "������ ���� �������� 'Stack' ��� ������� ������!" << endl << "��� ������������ �������!" << endl;
		}

		ComputerGame(string name, int cost, string author)
		{
			this->Name = name;
			this->Cost = cost;
			this->Dev_Corporation = author;
			this->InputAtributs();
			cout << "������ ���� �������� 'Stack' ��� ������� ������!" << endl << "������ ���������� � �����!" << endl;
		}

		ComputerGame(const ComputerGame& copy_game)
		{
			this->Name = copy_game.Name;
			this->Descrip = copy_game.Descrip;
			this->Cost = copy_game.Cost;
			this->Release_Date = copy_game.Release_Date;
			this->Dev_Corporation = copy_game.Dev_Corporation;
			this->OS = copy_game.OS;
			this->Recom_CPU = copy_game.Recom_CPU;
			this->Recom_GPU = copy_game.Recom_GPU;
			this->Recom_CountRAM = copy_game.Recom_CountRAM;
			this->Recom_MemoryDisc = copy_game.Recom_MemoryDisc;
		}

		~ComputerGame()
		{
			cout << "��� ������ ���������� �������!" << endl;
		};

		//Operator overload

		ComputerGame& operator = (const ComputerGame& copy_game)
		{
			this->Name = copy_game.Name;
			this->Descrip = copy_game.Descrip;
			this->Cost = copy_game.Cost;
			this->Release_Date = copy_game.Release_Date;
			this->Dev_Corporation = copy_game.Dev_Corporation;
			this->OS = copy_game.OS;
			this->Recom_CPU = copy_game.Recom_CPU;
			this->Recom_GPU = copy_game.Recom_GPU;
			this->Recom_CountRAM = copy_game.Recom_CountRAM;
			this->Recom_MemoryDisc = copy_game.Recom_MemoryDisc;
			return *this;
		}

		bool operator == (const ComputerGame& copy_game)
		{
			return (this->Name == copy_game.Name &&
					this->Descrip == copy_game.Descrip &&
					this->Cost == copy_game.Cost &&
					this->Release_Date == copy_game.Release_Date &&
					this->Dev_Corporation == copy_game.Dev_Corporation &&
					this->OS == copy_game.OS &&
					this->Recom_CPU == copy_game.Recom_CPU &&
					this->Recom_GPU == copy_game.Recom_GPU &&
					this->Recom_CountRAM == copy_game.Recom_CountRAM &&
					this->Recom_MemoryDisc == copy_game.Recom_MemoryDisc);
		}

		bool operator != (const ComputerGame& copy_game)
		{
			return !(this->Name == copy_game.Name &&
				this->Descrip == copy_game.Descrip &&
				this->Cost == copy_game.Cost &&
				this->Release_Date == copy_game.Release_Date &&
				this->Dev_Corporation == copy_game.Dev_Corporation &&
				this->OS == copy_game.OS &&
				this->Recom_CPU == copy_game.Recom_CPU &&
				this->Recom_GPU == copy_game.Recom_GPU &&
				this->Recom_CountRAM == copy_game.Recom_CountRAM &&
				this->Recom_MemoryDisc == copy_game.Recom_MemoryDisc);
		}

		bool operator < (const ComputerGame& copy_game)
		{
			return (this->Cost < copy_game.Cost);
		}

		bool operator > (const ComputerGame& copy_game)
		{
			return (this->Cost > copy_game.Cost);
		}

		bool operator <= (const ComputerGame& copy_game)
		{
			return (this->Cost <= copy_game.Cost);
		}

		bool operator >= (const ComputerGame& copy_game)
		{
			return (this->Cost <= copy_game.Cost);
		}
	};

	class Stack
	{
	private:
		ComputerGame* pHead = NULL;
		ComputerGame* pDown = NULL;
		int count_game = 0;

	public:
		void Add()
		{
			if (this->pHead == NULL)
			{
				this->pHead = new ComputerGame();
				this->count_game += 1;
				cout << "����� ��������� ������ ������ ��� ���� - : " << this->pHead << endl;
			}
			else
			{
				this->pDown = this->pHead;
				this->pHead = new ComputerGame("Doka2", 100, "Valve");
				this->pHead->pDownRemember(this->pDown);
				this->count_game += 1;
				cout << "����� ��������� ������ ������ ��� ���� - : " << this->pHead << endl;
			}
		}

		void get_Obj_Data()
		{
			if (this->pHead != NULL)
			{
				this->pHead->DataObj();
				cout << "!!!������� ������� �������� � �����!!!" << endl;
				this->Del_Head();
			}
			else
			{
				cout << "������ ��������� �������� �����! ��������� �������, ���� � ������ ������ ����" << endl;
			}
		}

		void cout_Count()
		{
			cout << "� ����� ��������� " << this->count_game << " ������(�,��)" << endl;
		}

		short int return_count_elements()
		{
			return this->count_game;
		}

		void Check()
		{
			if (this->pHead == NULL)
			{
				cout << "���� � ������ ������ ����" << endl;
			}
			else
			{
				cout << "� ����� ���������(����) �������(�) " << endl;
			}
		}

		void Del_Head()
		{
			if (this->pHead != NULL)
			{
				cout << this->pHead << " - ����� ��������� ������ ������" << endl;
				if (this->pHead->pDownReturn() == NULL)
				{
					free(this->pHead);
					pHead = NULL;
					this->count_game--;
				}
				else
				{
					this->pDown = this->pHead->pDownReturn();
					free(this->pHead);
					this->count_game--;
					this->pHead = this->pDown;
					this->pDown = this->pDown->pDownReturn();
				}
			}
			else
			{
				cout << "�������� �������� �������� ����������! ���� - ����!" << endl;
			}
		}

		void Destroy_All_Elements()
		{
			while (this->pHead != NULL)
			{
				this->Del_Head();
			}
			cout << "!!!���� ��� ������� ��������� ������!!!" << endl;
		}

		Stack()
		{
			this->pHead = NULL;
			this->pDown = NULL;
			cout << "���� ��� ������� ������!" << endl;
		}

		//Operator overload -> 3 stage of lesson
		void Assignment()
		{
			if (this->count_game >= 2)
			{
				*this->pDown = *this->pHead;
				cout << "������� �������� ���� ��������� �������� �� �������� ��������" << endl;
			}
			else { cout << "������������� ���������� ���������" << endl; }
		}

		void Different()
		{
			if (this->count_game >= 2)
			{
				if (*this->pDown == *this->pHead)
					cout << "�������� ��������� ������ �����!" << endl;
				else if(*this->pDown != *this->pHead)
					cout << "�������� ��������� ������ �� �����!" << endl;
			}
			else { cout << "������������� ���������� ���������" << endl; }
		}

		void Proverka_Operatorov_Games()
		{
			if (this->count_game >= 2)
			{
				cout << "(this->pHead > this->pDown) == " << (this->pHead > this->pDown) << endl;
				cout << "(this->pHead >= this->pDown) == " << (this->pHead >= this->pDown) << endl;
				cout << "(this->pHead < this->pDown) == " << (this->pHead < this->pDown) << endl;
				cout << "(this->pHead <= this->pDown) == " << (this->pHead <= this->pDown) << endl;
			} else { cout << "������������� ���������� ���������" << endl; }
		}
		
		bool operator < (const Stack& copy_stack)
		{
			return (this->count_game < copy_stack.count_game);
		}

		bool operator > (const Stack& copy_stack)
		{
			return (this->count_game > copy_stack.count_game);
		}

		bool operator <= (const Stack& copy_stack)
		{
			return (this->count_game >= copy_stack.count_game);
		}

		bool operator >= (const Stack& copy_stack)
		{
			return (this->count_game <= copy_stack.count_game);
		}

		std::istream& operator >> (std::istream& tmp)
		{
			this->Add();
			return tmp;
		}
		
		std::ostream& operator << (std::ostream& tmp)
		{
			while (this->pHead != NULL)
			{
				this->get_Obj_Data();
			}
			tmp << "!!!���� ��� ������� ��������� ������!!!" << endl;
			return tmp;
		}
	};
}