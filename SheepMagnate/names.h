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
		const short maleNamesSize = 66;
		string* maleNames = new string[maleNamesSize]{
			"Norman", "Cooper", "Seamus", "Ferdinand", "Duncan", "David", "Max", "Raymond", "Lloyd", "Dirk",
			"Luke", "Roger", "Grover", "Lancelot", "Douglas", "Goliath", "Rolph", "Zeus", "Lars", "Howard",
			"Dougal", "Jerry", "Casper", "Elmo", "Harvey", "Shep", "Felix", "Diablo", "Shrek", "Prince",
			"Lamby", "Friday", "Oliver", "Linus", "Noah", "Tom", "Russel", "Huck", "Owen", "Jack", "Wilson",
			"Clark", "Dutch", "Sherlock", "Jedburgh", "Sherman", "Lambert", "Frank", "Barney", "Stanley",
			"Buddy", "Quintin", "Wallace", "Jasper", "Walter", "Rambo", "Harold", "Ramsay", "Santiago",
			"Washington", "Lewis", "King", "Kurt", "Macintosh", "Eddie", "Royce"
		};

		const short femaleNamesSize = 152;
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

#endif