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
		
		string Name; //Название игры
		string Descrip; //Описание игры
		int Cost = 0; //Стоимость
		string Release_Date; //Дата выхода
		string Dev_Corporation; //Студия разработки
		string OS; //Операц система
		string Recom_CPU;
		string Recom_GPU;
		string Recom_CountRAM;
		string Recom_MemoryDisc;
		string tmp; //Поле для внесения числа и его последовательной проверки на int

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
			cout << "Добавление игры в коллекцию: " << endl;
				cout << "\tВведите новое название игры! ";
				std::getline(cin >> std::ws,this->Name);
				cout << "\tВведите описание игры! ";
				std::getline(cin >> std::ws, this->Descrip);
			returne:
				cout << "\tВведите стоимость игры! ";
				std::getline(cin >> std::ws, this->tmp);
				try
				{
					this->Cost = stoi(tmp);
				}
				catch (std::invalid_argument ex) //std::ios_base::failure ex)//std::invalid_argument e)
				{
					cout << "Неправильный ввод данных!" << endl;
					goto returne;
				}
				catch (std::out_of_range ex)
				{
					cout << "Если это не иранский риал (на момент 2022 года), то меня очень печалит количество циферок!" << endl;
					goto returne;
				}
				cout << "\tВведите дату релиза игры! ";
				getline(cin >> std::ws, this->Release_Date);
				cout << "\tВведите название корпорации, создавшую игру! "; 
				getline(cin >> std::ws, this->Dev_Corporation);
				cout << "\tВведите под какую(ие) ОС подходит игра! ";
				getline(cin >> std::ws, this->OS);
				cout << "\tВведите рекомендованный процессор для игры! ";
				getline(cin >> std::ws, this->Recom_CPU);
				cout << "\tВведите рекомендованную видеокарту для игры! ";
				getline(cin >> std::ws, this->Recom_GPU);
				cout << "\tВведите рекомендованное количество оперативной памяти для игры! "; 
				getline(cin >> std::ws, this->Recom_CountRAM);
				cout << "\tВведите рекомендованное количество места на диске для игры! ";
				getline(cin >> std::ws, this->Recom_MemoryDisc);
			cout << "!!!Игра успешно добавлена!!!" << endl;
		}

		void DataObj()
		{
			cout << "Чтение (разрушающее) ГОЛОВНОГО элемента СТЕКА" << endl << "Описание и свойства вытащенной игры:" << endl
				<< "\tНазвание: " << this->Name << endl
				<< "\tОписание: " << this->Descrip << endl
				<< "\tСтоимость: " << this->Cost << endl
				<< "\tДата выпуска: " << this->Release_Date << endl
				<< "\tРазработчики: " << this->Dev_Corporation << endl
				<< "\tПлатформа: " << this->OS << endl
				<< "\tРекомендуемый процессор: " << this->Recom_CPU << endl
				<< "\tРекомендуемая видеокарта: " << this->Recom_GPU << endl
				<< "\tРекомендуемое количество ОП: " << this->Recom_CountRAM << endl
				<< "\tРекомендуемое количество места на ЖД : " << this->Recom_MemoryDisc << endl;
		}

		ComputerGame()
		{
			this->InputAtributs();
			cout << "Объект типа элемента 'Stack' был успешно создан!" << endl << "Это единственный элемент!" << endl;
		}

		ComputerGame(string name, int cost, string author)
		{
			this->Name = name;
			this->Cost = cost;
			this->Dev_Corporation = author;
			this->InputAtributs();
			cout << "Объект типа элемента 'Stack' был успешно создан!" << endl << "Объект присоединён к стеку!" << endl;
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
			cout << "Был вызван деструктор объекта!" << endl;
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
				cout << "Адрес начальной ячейки памяти для игры - : " << this->pHead << endl;
			}
			else
			{
				this->pDown = this->pHead;
				this->pHead = new ComputerGame("Doka2", 100, "Valve");
				this->pHead->pDownRemember(this->pDown);
				this->count_game += 1;
				cout << "Адрес начальной ячейки памяти для игры - : " << this->pHead << endl;
			}
		}

		void get_Obj_Data()
		{
			if (this->pHead != NULL)
			{
				this->pHead->DataObj();
				cout << "!!!Элемент успешно прочитан и удалён!!!" << endl;
				this->Del_Head();
			}
			else
			{
				cout << "Чтение ГОЛОВНОГО элемента СТЕКА! Неудачная попытка, СТЕК в данный момент пуст" << endl;
			}
		}

		void cout_Count()
		{
			cout << "В стеке находится " << this->count_game << " объект(а,ов)" << endl;
		}

		short int return_count_elements()
		{
			return this->count_game;
		}

		void Check()
		{
			if (this->pHead == NULL)
			{
				cout << "СТЕК в данный момент пуст" << endl;
			}
			else
			{
				cout << "В СТЕКЕ находится(ятся) элемент(ы) " << endl;
			}
		}

		void Del_Head()
		{
			if (this->pHead != NULL)
			{
				cout << this->pHead << " - Адрес очищенной ячейки памяти" << endl;
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
				cout << "Удаление верхнего элемента невозможно! Стек - пуст!" << endl;
			}
		}

		void Destroy_All_Elements()
		{
			while (this->pHead != NULL)
			{
				this->Del_Head();
			}
			cout << "!!!СТЕК был успешно полностью очищен!!!" << endl;
		}

		Stack()
		{
			this->pHead = NULL;
			this->pDown = NULL;
			cout << "Стек был успешно создан!" << endl;
		}

		//Operator overload -> 3 stage of lesson
		void Assignment()
		{
			if (this->count_game >= 2)
			{
				*this->pDown = *this->pHead;
				cout << "Нижнему элементу были присвоены значения из верхнего элемента" << endl;
			}
			else { cout << "Недостаточное количество элементов" << endl; }
		}

		void Different()
		{
			if (this->count_game >= 2)
			{
				if (*this->pDown == *this->pHead)
					cout << "Элементы структуры данных равны!" << endl;
				else if(*this->pDown != *this->pHead)
					cout << "Элементы структуры данные не равны!" << endl;
			}
			else { cout << "Недостаточное количество элементов" << endl; }
		}

		void Proverka_Operatorov_Games()
		{
			if (this->count_game >= 2)
			{
				cout << "(this->pHead > this->pDown) == " << (this->pHead > this->pDown) << endl;
				cout << "(this->pHead >= this->pDown) == " << (this->pHead >= this->pDown) << endl;
				cout << "(this->pHead < this->pDown) == " << (this->pHead < this->pDown) << endl;
				cout << "(this->pHead <= this->pDown) == " << (this->pHead <= this->pDown) << endl;
			} else { cout << "Недостаточное количество элементов" << endl; }
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
			tmp << "!!!СТЕК был успешно полностью очищен!!!" << endl;
			return tmp;
		}
	};
}