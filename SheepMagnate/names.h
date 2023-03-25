#pragma once
#ifndef NAMES_H
#define NAMES_H

using namespace std;

struct SheepName
{
	// ��������� ���
	string name = __nameGenerate__();

	// ���
	bool isMale;

	// ��������� ����� � ����
	string __nameGenerate__()
	{
		short maleNamesSize = 66;
		string* maleNames = new string[maleNamesSize]{
			"Norman", "Cooper", "Seamus", "Ferdinand", "Duncan", "David", "Max", "Raymond", "Lloyd", "Dirk",
			"Luke", "Roger", "Grover", "Lancelot", "Douglas", "Goliath", "Rolph", "Zeus", "Lars", "Howard",
			"Dougal", "Jerry", "Casper", "Elmo", "Harvey", "Shep", "Felix", "Diablo", "Shrek", "Prince",
			"Lamby", "Friday", "Oliver", "Linus", "Noah", "Tom", "Russel", "Huck", "Owen", "Jack", "Wilson",
			"Clark", "Dutch", "Sherlock", "Jedburgh", "Sherman", "Lambert", "Frank", "Barney", "Stanley",
			"Buddy", "Quintin", "Wallace", "Jasper", "Walter", "Rambo", "Harold", "Ramsay", "Santiago",
			"Washington", "Lewis", "King", "Kurt", "Macintosh", "Eddie", "Royce"
		};

		short femaleNamesSize = 152;
		string* femaleNames = new string[femaleNamesSize]{
			"Amelia", "Freya", "Jenni", "Gloria", "Snowy", "Rose", "Marigold", "Rachel", "Lillian", "Edwina",
			"Kerryn", "Sophie", "Daisy", "Bertha", "Colleen", "Cora", "Isobel", "Ursula", "Naomi", "April",
			"Wanda", "Ivy", "Carlotta", "Sonata", "Cinderella", "Thelma", "Lacey", "Barbie", "Oprah", "Serena",
			"Sara", "Tara", "Buffy", "Jemma", "Belle", "Xena", "Clover", "Dawn", "Pearl", "Isabelle", "Ninah",
			"Molly", "Calliope", "Bertie", "Blossom", "Petunia", "Penny", "Lizzie", "Selena", "Lorraine", "Alma",
			"Wilma", "Louise", "Honey", "Esther", "Bella", "Pam", "Jasmine", "Ginger", "Lamberta", "Charm", "Sugar",
			"Kristy", "Rebecca", "Candy", "Charlotte", "Elizabeth", "Matilda", "Eva", "Cornelia", "Gypsy", "Jade",
			"Nanny", "Judith", "Margarita", "Clio", "Annie", "Aria", "Brenna", "Ingrid", "Liliana", "Collette",
			"Rosemary", "Tinkerbell", "Mary", "Emma", "Ethel", "Suzanne", "Pita", "Grace", "Alice", "Luna", "Windy",
			"Tipsy", "Daphne", "Dorothy", "Shanna", "Margaret", "Maggie", "Twinkle", "Millie", "Caroline", "Libby",
			"Magnolia", "Dolly", "Madeline", "Sweet Pea", "Leah", "Phoebe", "Edelweiss", "Cindy", "Ruth", "Celestia",
			"Queenie", "Aurora", "Olivia", "Dora", "Lilly", "Edith", "Sarah", "Bridget", "Maizie", "Iris", "Pixie",
			"Annabelle", "Bernice", "Opal", "Ella", "Galena", "Hazel", "Betty", "Venus", "Amy", "Fiona", "Stella",
			"Dahlia", "Chloe", "Perdita", "Cara", "Lana", "Astrid", "Moire", "Rosette", "Fannie", "Julia", "Mindy",
			"Sunshine", "Lucy", "Allegra", "Crystal", "Petal", "Pippi"
		};

		isMale = rand() % 2;

		string result = (isMale) ? maleNames[rand() % maleNamesSize] : femaleNames[rand() % femaleNamesSize];

		delete[] maleNames;
		delete[] femaleNames;

		return result;
	}
};

struct ClientName
{
	// ��������� ���
	string name = __nameGenerate__();

	// ���
	bool isMale;

	// ��������� ����� � ����
	string __nameGenerate__()
	{
		short maleNamesSize = 100;
		string* maleNames = new string[maleNamesSize]{
			"���������", "�������", "������", "������", "������", "�������", "����", "����", "������", "������",
			"������", "������", "�����", "����", "�������", "����", "�����", "�������", "������", "�������",
			"���������", "�����", "��������", "�����", "������", "����", "����������", "�����", "����", "�������",
			"�����", "�������", "����", "�����", "�������", "�����", "������", "����", "������", "�����", "�����",
			"�����", "���", "������", "������", "�������", "��������", "�����", "�����", "�����", "�������", "�����",
			"������", "��������", "��������", "�����", "������", "���������", "�������", "�����", "������", "������",
			"�������", "�������", "���������", "�����", "������", "�����", "������", "�������", "����", "����", "��������",
			"��������", "������", "�������", "�����", "�����", "�����", "��", "������", "�����", "����", "�������", "��������",
			"�����", "������", "�����", "�������", "������", "�����", "�����", "������", "�����", "������", "������", "�����",
			"���������", "��������", "������"
		};

		short femaleNamesSize = 100;
		string* femaleNames = new string[femaleNamesSize]{
			"���������", "����", "�����", "�����", "�����", "�����", "�����", "���������", "�����", "������", "�����",
			"����", "�������", "�������", "��������", "���������", "������", "������", "��������", "�����", "�������",
			"����������", "������", "��������", "�����", "������", "��������", "�������", "�����", "�����", "���",
			"����", "��������", "���������", "���", "����", "������", "������", "��������", "�����", "�������",
			"������", "������", "�������", "�������", "�����", "�����", "������", "������", "����", "���������",
			"������", "�������", "���������", "����", "������", "�������", "�������", "�����", "������", "������",
			"�������", "����", "�����", "������", "�����", "�������", "��������", "��������", "������", "����",
			"��������", "�����", "������", "�������", "�������", "��������", "�����", "�����", "��������", "����",
			"������", "�������", "�����", "��������", "������", "����", "����������", "������", "��������", "����",
			"������", "������", "��������", "�������", "������", "������", "�������", "������", "�����"
		};

		short surnamesSize = 96;
		string* surnames = new string[surnamesSize]{
			"������", "��������", "������", "�������", "��������", "Ը�����", "�������", "�������", "�����", "�������",
			"��������", "�����������", "�������", "���������", "��������", "������", "������", "��������", "��������",
			"��������", "������", "������", "��������", "�������", "��������", "��������", "�����", "���������", "��������",
			"�������", "�������", "�������", "����������", "�������", "��������", "������", "�����", "���������", "������",
			"�������", "�������", "�������", "������", "�������", "������", "������", "��������", "�������", "������", "��������",
			"�������", "�����", "�������", "������", "�������", "���������", "������", "���������", "����������", "���������",
			"�������", "�����", "��������", "��������", "�������", "��������", "��������", "��������", "�������", "�������",
			"�������", "������", "�����", "������", "�����", "�����", "������", "��������", "�������", "���������", "�����", "�������",
			"�������", "��������", "��������", "��������", "�������", "�����", "������", "�������", "�������", "������", "�������",
			"������������", "�������", "������"
		};

		isMale = rand() % 2;

		string result = (isMale) ? maleNames[rand() % maleNamesSize] + ' ' + surnames[rand() % surnamesSize] : femaleNames[rand() % femaleNamesSize] + ' ' + surnames[rand() % surnamesSize] + '�';

		delete[] maleNames;
		delete[] femaleNames;
		delete[] surnames;

		return result;
	}
};

struct CompanyName
{
	// ��� ��������
	// 0 - �������� ������
	// 1 - �������� ����
	short companyType;

	// ��������� ���
	string name = __nameGenerate__();

	// ��������� �����
	string __nameGenerate__()
	{
		short woolNamesSize = 12;
		string* woolNames = new string[woolNamesSize]{
			"Bettabuy's", "Crudgington Brewery", "Los Pollos Hermanos", "Muffin Buffalo", "Soylent Corporation",
			"Stay Puft Corporation", "Sunshine Desserts", "Abstergo Industries", "Acme Corporation", "Blue Sun Corporation",
			"Digivation Industries", "Upton-Webber"
		};

		short meatNamesSize = 120;
		string* meatNames = new string[meatNamesSize]{
			"������� ��� �������", "�������� � ��������", "��� ��������", "��� ������", "������� ���������", "��� ��������",
			"�� �������", "���������� ������", "���� ������", "������� ������", "������ Club", "������ House", "������ �� �����",
			"������ �� ���� ����", "�������� �� ������", "����� �������", "����� ������", "������������ ��������", "��������� ����",
			"��������� �������", "��������� ����", "��������� �����", "����� ��������", "������� ������", "������ �����", "������ ����������",
			"����� ����������", "����� ������", "���� ������", "�� �����", "�������� ������", "�������� ����", "��� �������", "��� ��������",
			"������ ��������", "��������� ������", "������ �����", "����� �����", "������ ����", "��������� �������", "������ ����",
			"�������� ������", "������� ������", "������� ����", "� ������", "������� �������", "���� �� ����", "������� ����",
			"�� � ������", "������ � �����", "������� ����", "������ ����", "������� ����", "�� �����", "������ ���", "������ ����",
			"�������", "�� �������", "������� � ��������", "������� ����?", "������-������", "�������FF", "����������", "��������",
			"������-������", "������-����", "������-����", "������ �� ����", "������ ���������", "���� ���������", "��������� ����",
			"��������� ������", "��������� ���", "��������� �����", "��������� ���", "��� ������", "��������� ������", "��������� ���",
			"��������� ������", "Fast������", "Shashlyk Lab", "Shashlyk na dom", "Yum-Yum", "Shashlyk City", "Shashlyk Zone",
			"Tasty Meat", "Set on Fire", "Grilled Meat", "On the coals", "Shashlik Khan", "Shashlik House", "Kebabs", "For Barbecue",
			"Shashlik with friends", "Shall we fry the meat?", "Shish", "ShashlikOFF", "Shashlykovich", "Barbecue Picnic", "Shashlik House",
			"Shashlik Hits", "Shashlik from the Chef", "Best Shashlik", "Mega Shashlik", "Shashlik Shashlik", "Mega Barbecue", "Barbecue Yard",
			"Barbecue Patio", "Shashlik Party", "Shashlik Time", "Barbecue house", "Shashlik world", "Eat Shashlik", "Barbecue Pier", "Shashlik Mir",
			"Mir Shashlika", "Barbecue Paradise", "Barbecue Corner", "Shashlik Paradise", "Shashlik to the table"
		};

		string result = (companyType) ? meatNames[rand() % meatNamesSize] : woolNames[rand() % woolNamesSize];

		delete[] woolNames;
		delete[] meatNames;

		return result;
	}
};

#endif