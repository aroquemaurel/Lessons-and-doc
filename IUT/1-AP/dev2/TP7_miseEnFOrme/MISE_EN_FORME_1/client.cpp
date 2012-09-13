#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mettreEnForme(char name[]) ;

int main(void)
{
	mettreEnForme("fichierAMettreEnForme.txt");
}

void mettreEnForme(char name[]) {
	ifstream f;
	f.open(name);
	string ch;
	while(!f.eof()){
		cout << ch << " ";
		f >> ch;
		if(ch[0] == '#'){
			switch(ch[1]){
				case 'C':
					centrerLigne(
							,`< const ListeMots &l>`,`< const int largeur>`)

			}

		}

	}
	f.close();

}


