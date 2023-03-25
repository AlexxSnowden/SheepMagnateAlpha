#pragma once
#ifndef NAMES_H
#define NAMES_H

using namespace std;

struct SheepName
{
	// Текстовое имя
	string name = __nameGenerate__();

	// Пол
	bool isMale;

	// Генерация имени и пола
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
	// Текстовое имя
	string name = __nameGenerate__();

	// Пол
	bool isMale;

	// Генерация имени и пола
	string __nameGenerate__()
	{
		short maleNamesSize = 100;
		string* maleNames = new string[maleNamesSize]{
			"Александр", "Дмитрий", "Максим", "Сергей", "Андрей", "Алексей", "Артём", "Илья", "Кирилл", "Михаил",
			"Никита", "Матвей", "Роман", "Егор", "Арсений", "Иван", "Денис", "Евгений", "Даниил", "Тимофей",
			"Владислав", "Игорь", "Владимир", "Павел", "Руслан", "Марк", "Константин", "Тимур", "Олег", "Ярослав",
			"Антон", "Николай", "Глеб", "Данил", "Савелий", "Вадим", "Степан", "Юрий", "Богдан", "Артур", "Семен",
			"Макар", "Лев", "Виктор", "Елисей", "Виталий", "Вячеслав", "Захар", "Мирон", "Дамир", "Георгий", "Давид",
			"Платон", "Анатолий", "Григорий", "Демид", "Данила", "Станислав", "Василий", "Федор", "Родион", "Леонид",
			"Одиссей", "Валерий", "Святослав", "Борис", "Эдуард", "Марат", "Герман", "Даниэль", "Петр", "Амир", "Всеволод",
			"Мирослав", "Гордей", "Артемий", "Эмиль", "Назар", "Савва", "Ян", "Рустам", "Игнат", "Влад", "Альберт", "Тамерлан",
			"Айдар", "Роберт", "Адель", "Марсель", "Ильдар", "Самир", "Тихон", "Рамиль", "Ринат", "Радмир", "Филипп", "Арсен",
			"Ростислав", "Святогор", "Яромир"
		};

		short femaleNamesSize = 100;
		string* femaleNames = new string[femaleNamesSize]{
			"Анастасия", "Анна", "Мария", "Елена", "Дарья", "Алина", "Ирина", "Екатерина", "Арина", "Полина", "Ольга",
			"Юлия", "Татьяна", "Наталья", "Виктория", "Елизавета", "Ксения", "Милана", "Вероника", "Алиса", "Валерия",
			"Александра", "Ульяна", "Кристина", "София", "Марина", "Светлана", "Варвара", "Софья", "Диана", "Яна",
			"Кира", "Ангелина", "Маргарита", "Ева", "Алёна", "Дарина", "Карина", "Василиса", "Олеся", "Аделина",
			"Оксана", "Таисия", "Надежда", "Евгения", "Элина", "Злата", "Есения", "Милена", "Вера", "Мирослава",
			"Галина", "Людмила", "Валентина", "Нина", "Эмилия", "Камилла", "Альбина", "Лилия", "Любовь", "Лариса",
			"Эвелина", "Инна", "Агата", "Амелия", "Амина", "Эльвира", "Ярослава", "Стефания", "Регина", "Алла",
			"Виолетта", "Лидия", "Амалия", "Наталия", "Марьяна", "Анжелика", "Нелли", "Влада", "Виталина", "Майя",
			"Тамара", "Мелания", "Лиана", "Василина", "Зарина", "Алия", "Владислава", "Самира", "Антонина", "Ника",
			"Мадина", "Наташа", "Каролина", "Снежана", "Юлиана", "Ариана", "Эльмира", "Ясмина", "Жанна"
		};

		short surnamesSize = 96;
		string* surnames = new string[surnamesSize]{
			"Иванов", "Васильев", "Петров", "Смирнов", "Михайлов", "Фёдоров", "Соколов", "Яковлев", "Попов", "Андреев",
			"Алексеев", "Александров", "Лебедев", "Григорьев", "Степанов", "Семёнов", "Павлов", "Богданов", "Николаев",
			"Дмитриев", "Егоров", "Волков", "Кузнецов", "Никитин", "Соловьёв", "Тимофеев", "Орлов", "Афанасьев", "Филиппов",
			"Сергеев", "Захаров", "Матвеев", "Виноградов", "Кузьмин", "Максимов", "Козлов", "Ильин", "Герасимов", "Марков",
			"Новиков", "Морозов", "Романов", "Осипов", "Макаров", "Зайцев", "Беляев", "Гаврилов", "Антонов", "Ефимов", "Леонтьев",
			"Давыдов", "Гусев", "Данилов", "Киселёв", "Сорокин", "Тихомиров", "Крылов", "Никифоров", "Кондратьев", "Кудрявцев",
			"Борисов", "Жуков", "Воробьёв", "Щербаков", "Поляков", "Савельев", "Трофимов", "Чистяков", "Баранов", "Сидоров",
			"Соболев", "Карпов", "Белов", "Миллер", "Титов", "Львов", "Фролов", "Игнатьев", "Комаров", "Прокофьев", "Быков", "Абрамов",
			"Голубев", "Пономарёв", "Мартынов", "Кириллов", "Миронов", "Фомин", "Власов", "Федотов", "Назаров", "Ушаков", "Денисов",
			"Константинов", "Воронин", "Наумов"
		};

		isMale = rand() % 2;

		string result = (isMale) ? maleNames[rand() % maleNamesSize] + ' ' + surnames[rand() % surnamesSize] : femaleNames[rand() % femaleNamesSize] + ' ' + surnames[rand() % surnamesSize] + 'а';

		delete[] maleNames;
		delete[] femaleNames;
		delete[] surnames;

		return result;
	}
};

struct CompanyName
{
	// Тип компании
	// 0 - покупает шерсть
	// 1 - покупает мясо
	short companyType;

	// Текстовое имя
	string name = __nameGenerate__();

	// Генерация имени
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
			"Беседка для шашлыка", "Разговор с шашлыком", "Дом шашлыков", "Дон Шашлык", "Любимая шашлычная", "Мир шашлыков",
			"На шашлыки", "Славянский шашлык", "Хочу шашлык", "Царский шашлык", "Шашлык Club", "Шашлык House", "Шашлык на углях",
			"Шашлык от дяди Феди", "Насадили на шампур", "Самый вкусный", "Самый сочный", "Традиционный шашлычок", "Шашлычное меню",
			"Шашлычное ассорти", "Шашлычный микс", "Шашлычный вальс", "Город шашлыков", "Русский шашлык", "Шашлык мечты", "Лучшая Шашлычница",
			"Давай Пошашлычим", "Давай шашлык", "Твой шашлык", "На углях", "Пылающий мангал", "Пылающие угли", "Три шампура", "Под шашлычок",
			"Теплое местечко", "Ароматный дворик", "Поляна вкуса", "Сытый домик", "Мясной вкус", "Ароматный кусочек", "Мясное чудо",
			"Чудесный шашлык", "Царский шашлык", "Румяное мясо", "С дымком", "Вкусная тарелка", "Мясо на огне", "Вкусный стол",
			"Ты и шашлык", "Шашлык к столу", "Вкусное мясо", "Пожарь меня", "Жареное мясо", "На углях", "Шашлык Хан", "Шашлык Хаус",
			"Шашлыки", "На шашлыки", "Шашлыки с друзьями", "Пожарим мясо?", "Шашлык-Машлык", "ШашлыкоFF", "Шашлыкович", "Шашлычки",
			"Шашлык-Пикник", "Шашлык-Хаус", "Шашлык-Хитс", "Шашлык от шефа", "Лучшая Шашлычная", "Мега шашлычная", "Шашлычный двор",
			"Шашлычный дворик", "Шашлычный дом", "Шашлычный домик", "Шашлычный мир", "Ешь шашлык", "Шашлычный причал", "Шашлычный рай",
			"Шашлычный уголок", "FastШашлык", "Shashlyk Lab", "Shashlyk na dom", "Yum-Yum", "Shashlyk City", "Shashlyk Zone",
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