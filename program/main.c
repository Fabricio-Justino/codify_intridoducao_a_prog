#include <stdio.h>

enum {
  END_STRING_CHARACTER = '\0',
  ENTER_CHARACTER = '\n'
};


unsigned int stringLength(char *string) {
  unsigned int lenth = 0;

  while (string[lenth] != END_STRING_CHARACTER
		&& string[lenth] != ENTER_CHARACTER){
    lenth++;
  }

  return lenth;
}

int isALowwerCharacter(char character) {
  return character >= 'a' && character <= 'z';
}

int isAUpperCharacter(char character) {
  return character >= 'A' && character <= 'Z';
}

int indexOf(char *source, char target) {
	for (int i = 0; source[i] != END_STRING_CHARACTER; i++) {
		if (source[i] == target)
			return i;
	}
	
	return -1;
}

void rolaEsquerda(char *word, int size, int num) {
	const int LENGTH_OF_TASK = num % size;
	if (LENGTH_OF_TASK == 0) return;
	
  char *firstWordCharacters = malloc(LENGTH_OF_TASK);
	
  int afterNum = 0;
  int firstWordCharactersIterator = 0;

  for (int i = 0; i < size; i++) {
    if (i < LENGTH_OF_TASK) {
      firstWordCharacters[i] = word[i];
    }

    if (i >= LENGTH_OF_TASK) {
      word[afterNum++] = word[i];
    }

    if (i > size - LENGTH_OF_TASK -1) {
      word[i] = firstWordCharacters[firstWordCharactersIterator++];
    }
  }
}

void advance(char *word, int size, int adv) {
	const int NUMBER_OF_LETTERS_IN_APLHA = 26;
	
  for (int i = 0; i < size; i++) {
     const int NEXT_CHARACTER = word[i] + adv;

    if (isALowwerCharacter(word[i])) {	
        word[i] = 'a' + ((NEXT_CHARACTER - 'a') % NUMBER_OF_LETTERS_IN_APLHA);
    } else if (isAUpperCharacter(word[i])) {
				word[i] = 'A' + (((NEXT_CHARACTER) - 'A') % NUMBER_OF_LETTERS_IN_APLHA);
    }
  }
}


void tranform(char *word, int size, char *source, char *provider) {
 for (int i = 0; i < size; i++) {
		int providerIndex = indexOf(source, word[i]);
	 
	 	if (providerIndex >= 0) {
			word[i] = provider[providerIndex];
		}
 }
}

void codify(char *vet, int size) {
  for (int i = 0; i < 100; i++) {
    rolaEsquerda(vet, size, i / 2);
    advance(vet, size, i / 3);
    tranform(vet, size, "abcdefghijklm", "bamdfhgjcielk");
  }
}

int main(void) {
	printf("digite alguma palavra qualer para ser codificada! (maximo de 255 caracter)\n");
  char word[255];// = "alfa_omega";
	fgets(word, sizeof(word), stdin);
	printf("frase normal: %s", word);
	codify(word, stringLength(word));
	printf("sua mensageme codificada: %s", word);

  
  return 0;
}