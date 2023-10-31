/*               Project: Monster Name Generator
* 
* Crear un programa de consola que genere nombres de monstruos aleatorios.
* 
* La selección del nombre vendrá dada por las respuestas del usuario en funcion
* de algunas preguntas echas por la aplicación
* 
* 
*           ¡¡¡FELIZ HALLOWEEN 2023!!!
*/ 

/*   TODO GENERALES:
* 
*  1. Mejorar el sisitema de bucles que tenemos
*  2. Mejorar la selección de lo nombres en función de las prespuestas dadas por el usuario
*  3. Mejorar la estructura (Desde añadir nuevas clases, quitar métodos, quitar clases,....)
*  4. Mejorar el sistema de combinación del juego, es decir, permitir jugar a las dos posibilidades pero habiendo mejorado
*     la interfaz con el usuario y si es necesario hacerlo en una segunda clase.
* 
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

//Creamos una clase que representa el generador de nombre de monstruos
class MonsterNameGenerator 
{
    private:
        string monsterName;
        vector<string> FirstNameMonster = { "Zombi","Vampiro","El señor","Momia","Bruja","Fantasma","Demonio","Monja","Pasayo","Calabza","Esqueleto","Cucaracha", "Hombre lobo"}; //TODO: añadir mas nombres
        vector<string> LastNameMonster = { "Sangriento","Apestoso","Asesino","de la noche","Toxico","peludo","gordito","cuchillo","colmillos" }; //TODO: añadir mas nombres
        vector<string> NameMonsterCompleted;

        //Seleccion first name
        void ChooseFirstNameMonster() 
        {
            int choice;

            for(size_t i = 0; i < 3; ++i)
            {
                cout << "Selecciona una parte del monstruo(" << i + 1 << "/3):" << endl;

                for (size_t j = 0; j < FirstNameMonster.size(); ++j)
                {
                    cout << j + 1 << "." << FirstNameMonster[j] << endl;
                }

                cin >> choice;
                if (choice >= 1 && choice <= FirstNameMonster.size())
                {
                    NameMonsterCompleted.push_back(FirstNameMonster[choice - 1]);
                }
                else
                {
                    cout << "Selección no valida. Por favor, elige entre una de las opciones" << endl;
                    --i;
                }
                
            }

        }

        //Seleccion last name
        void ChooseLastNameMonster()
        {
            int choice;

            for (size_t i = 0; i < 3; ++i)
            {
                cout << "Selecciona una parte del monstruo(" << i + 1 << "/3):" << endl;

                for (size_t j = 0; j < LastNameMonster.size(); ++j)
                {
                    cout << j + 1 << "." << LastNameMonster[j] << endl;
                }

                cin >> choice;
                if (choice >= 1 && choice <= FirstNameMonster.size())
                {
                    NameMonsterCompleted.push_back(LastNameMonster[choice - 1]);
                }
                else
                {
                    cout << "Selección no valida. Por favor, elige entre una de las opciones" << endl;
                    --i;
                }

            }

        }

        //Completed name monster
        void CombinePartsNameMonster() 
        {
            for(const string& parts: NameMonsterCompleted)
            {
                monsterName += parts;
            }

        }

        //Función para relaizar las preguntas del generador (TODO: completar y mejorar el conjunto de preguntas posibles)
        void AskQuestionsForUser()
        {
            int selection1,
                selection2,
                selection3;

            vector<int> responses;
            cout << "¿Que te da menos miedo? 1.Payasos 2.Fantas" << endl;
            cin >> selection1;
            cout << "¿Que te da menos asco? 1.cucarachas 2.vísceras" << endl;
            cin >> selection2;
            cout << "¿Que le harías a tu peor enemigo? 1.Cortarle las p... 2.Arrancarle los o..." << endl;
            cin >> selection3;

            responses.push_back(selection1);
            responses.push_back(selection2);
            responses.push_back(selection3);

            ChooseFirstNameMonsterWithQuestion(responses);
            ChooseLastNameMonsterWithQuestion(responses);

        }

        //Seleccion first name
        void ChooseFirstNameMonsterWithQuestion(vector<int> res)
        {
            for (size_t i = 0; i < res.size(); i++)
            {
                if (res[i] = 1)
                {
                    NameMonsterCompleted.push_back("Bruja");

                    if (i == 1)
                    {
                        NameMonsterCompleted.push_back("Calabaza");
                    }
                    else if (i == 2)
                    {
                        NameMonsterCompleted.push_back("Hombre lobo");
                    }
                }
                else if (res[i] = 2)
                {
                    NameMonsterCompleted.push_back("Toxico");

                    if (i == 1)
                    {
                        NameMonsterCompleted.push_back("Peludo");
                    }
                    else if (i == 2)
                    {
                        NameMonsterCompleted.push_back("Apestoso");
                    }
                }
                else
                {
                    cout << "Esa opción no esta contemplada... :(" << endl;
                }
            }

        }

        //Seleccion last name
        void ChooseLastNameMonsterWithQuestion(vector<int> res)
        {
            for (size_t i = 0; i < res.size(); i++)
            {
                if (res[i] = 1)
                {
                    NameMonsterCompleted.push_back("Payaso");

                    if( i == 1)
                    {
                        NameMonsterCompleted.push_back("Cucaracha");
                    }
                    else if (i == 2)
                    {
                        NameMonsterCompleted.push_back("Asesino");
                    }
                }
                else if (res[i] = 2)
                {
                    NameMonsterCompleted.push_back("Fantasma");

                    if (i == 1)
                    {
                        NameMonsterCompleted.push_back("Zombie");
                    }
                    else if (i == 2)
                    {
                        NameMonsterCompleted.push_back("Demonio");
                    }
                }
                else
                {
                    cout << "Esa opción no esta contemplada... :(" << endl;
                }
            }

        }

    public:

        //Constructor
        MonsterNameGenerator()
        {
            srand(static_cast<unsigned>(time(nullptr)));
        }

        //Destructor
        ~MonsterNameGenerator() {}

        void PlayGeneratorNameMonster(int play) 
        {
            if (play == 1)
            {
                ChooseFirstNameMonster();
                ChooseLastNameMonster();
            }
            else if (play == 2)
            {
                AskQuestionsForUser();
            }
            
            CombinePartsNameMonster();
        }

        string GetNameMonster()
        {
            return monsterName;
        }

};



int main()
{
    int play = 0;

    cout << "¿De cual de las maneras quiere jugar? WUAJAJAJAJAJA " << endl;
    cout << "1. Genera tu mismo el nombre (ME ABURROOOO)" << endl;
    cout << "2. Deja que la aplicacion lo haga (ESTA SI MI NINO)" << endl;
    cout << endl;
    cout << "ATENCION: Introduzca solamente 1 o 2" << endl;
    cin >> play;

    MonsterNameGenerator nameGenerator;
    nameGenerator.PlayGeneratorNameMonster(play);

    cout << "¡Tu monstruo de Halloween 2023 es: " << nameGenerator.GetNameMonster() << " !" << endl;
    return 0;
}

