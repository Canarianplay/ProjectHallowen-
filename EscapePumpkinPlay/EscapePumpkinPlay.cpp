// Escape from the pumpkin Play

/*
* Juego en el que el usuario tendra que realizar una serie de pruebas en un determinado tiempo
* Mientras las pruebas se superen la vela se mantendrá encendida, pero si no, ten cuidado, porquee
* si la vela se apaga y el tiempo se acaba tu vida se habra terminado
*/

/*
* TODOs:
*  1. Añadir más pruebas
*  2. Mejorar la gestion del tiempo (añadir una independiente para cada prueba)
*  3. Hacer que desaparezca la secuencia de letras a recordar
   4. Mejorar todo lo que seas capaz.
*/


#include <iostream>
#include <chrono>
#include <conio.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;

//Clase que representa la vela en nuestro juego y su estado
class Vela
{
	public:

		bool encendida;

		//Constructor
		Vela() : encendida(true) {}

		//Destructor
		~Vela() {}

		void apagar() 
		{
			encendida = false;
		}

		void dibujar() const 
		{
			if (encendida) 
			{
				cout << "   |  \n";
				cout << "  |||  \n";
				cout << "  ---  \n";
				cout << " |   | \n";
				cout << "|     |\n";
			}
			else
			{
				cout << "  ---  \n";
				cout << " |   | \n";
				cout << "|     |\n";
			}

		}
};

//Clase que nos representa el final del juego
class FinalJuego
{
	private:

		static void dibujarEscapado() 
		{
			std::cout << " \\o/\n";
			std::cout << "  |\n";
			std::cout << " / \\\n";
		}

		static void dibujarCalabazaAsesina()
		{
			std::cout << "   ___\n";
			std::cout << "  /   \\\n";
			std::cout << " | O O |\n";
			std::cout << "  \\_^_/\n";
		}

	public:
		// En este caso no usamos constructores ya que solo queremos mostrar el resultado 
		static void mostrarResultado(bool escapado) 
		{
			system("cls");

			if (escapado) 
			{
				dibujarEscapado();
				cout << "¡Felicidades! Has escapado de la calabaza asesina" << endl;
			}
			else 
			{
				dibujarCalabazaAsesina();
				cout << "La vela se apagó. Has sido atrapado por la calabaza asesina. GAME OVER" << endl;
			}
		}

};

//Clase que representa el tiempo global del juego y de las pruebas que se realizan
class GestorTiempo
{
	private:
		chrono::seconds duracionGlobal;
		chrono::seconds tiempoRestanteGlobal;
		chrono::seconds duracionPruebaActual;
		chrono::seconds tiempoRestantePruebaActual;

	public:
		//Constructor
		GestorTiempo(int min, int seg) : duracionGlobal(chrono::minutes(min) + chrono::seconds(seg)), tiempoRestanteGlobal(duracionGlobal), duracionPruebaActual(chrono::seconds(0)), tiempoRestantePruebaActual(chrono::seconds(0)) {}

		//Destructor
		~GestorTiempo() {}

		bool tiempoAgotado() 
		{
			return tiempoRestanteGlobal <= chrono::seconds(0);
		}

		void iniciarTiempoPrueba(chrono::seconds duracionPrueba) 
		{
			duracionPruebaActual = duracionPrueba;
			tiempoRestantePruebaActual = duracionPruebaActual;
		}

		bool tiempoPruebaAgotado() const
		{
			return tiempoRestantePruebaActual <= chrono::seconds(0);
		}

		void updateTiempo(chrono::seconds tiempoPasado)
		{
			tiempoRestanteGlobal -= tiempoPasado;
			tiempoRestantePruebaActual -= tiempoPasado;
		}

		//funciones get
		chrono::seconds getTiempoRestanteGlobal() const
		{
			return tiempoRestanteGlobal;
		}

		chrono::seconds getTiempoRestantePruebaActual() const
		{
			return tiempoRestantePruebaActual;
		}

};

//Clase padre que contiene el método que ejecuta las pruebas
class Prueba
{

	public:
		virtual void ejecutar() = 0;

};


//Clase para representar la prueba de la pulsacion de tecla
class PruebaTecla : public Prueba
{

	public:
		void ejecutar() override
		{
			cout << "Pulsa una tecla en menos de 10 segundos ... " << endl;

			auto inicio = chrono::high_resolution_clock::now();
			bool teclaPresionada = false;

			while(true)
			{
				if(_kbhit()) 
				{
					teclaPresionada = true;
					break;
				}

				auto ahora = chrono::high_resolution_clock::now();
				auto duracion = chrono::duration_cast<chrono::seconds>(ahora - inicio);

				if (duracion.count() >= 10)
				{
					break;
				}

				this_thread::sleep_for(chrono::milliseconds(100));
			}

			if(teclaPresionada)
			{
				cout << "TECLA PRESIONADA" << endl;
			}
			else
			{
				cout << "Tecla NO presionada. La vela se apaga" << endl;
			}
		}

};

//Clase para representar la prueba de la ordenacion de número
class PruebaOrdenarNumeros : public Prueba
{

	public:
		void ejecutar() override 
		{
			std::vector<int> numerosDesordenados = { 14,6,7,56,41,9 };
			cout << "Ordename estos numero" << endl;

			for(int num : numerosDesordenados)
			{
				cout << num << " ";
			}

			cout << endl;

			auto inicio = chrono::high_resolution_clock::now();

			//Pedir al usuario que ordene los numeros
			std::vector<int> numerosUsuario;

			for(int i=0; i < numerosDesordenados.size(); ++i)
			{
				int num;
				cout << "Ingresa el número en la posicion " << i + 1 <<": ";
				cin >> num;

				numerosUsuario.push_back(num);
			}

			auto ahora = chrono::high_resolution_clock::now();
			auto duracion = chrono::duration_cast<chrono::seconds>(ahora - inicio);

			if(is_sorted(numerosUsuario.begin(), numerosUsuario.end()) && duracion.count() < 10)
			{
				cout << "Felicidades números ordenados a tiempo " << endl;
			}
			else
			{
				cout << "Lo siento no lo conseguiste. Vela apagada " << endl;
			}
		}

};

//Clase para representar la prueba de recordar la secuencia
class PruebaRecordarSecuencias : public Prueba
{
	private:
		string generadorSecuenciaAleatoria(int longitud) const
		{
			const string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string secuencia;
			srand(static_cast<unsigned int>(time(nullptr)));

			for (int i=0; i < longitud; ++i) 
			{
				secuencia += caracteres[rand() % caracteres.length()];
			}

			return secuencia;
		}

	public:
		void ejecutar() override
		{
			string secuencia = generadorSecuenciaAleatoria(6);
			cout << "Memorizate esta secuencia: " << secuencia << endl;
			this_thread::sleep_for(chrono::seconds(5));

			string respuestaUser;
			cout << "Ingresa la secuencia que recuerdas: ";
			cin >> respuestaUser;

			if(respuestaUser == secuencia)
			{
				cout << "Felicidades la secuencia es la misma" << endl;
			}
			else
			{
				cout << "Lo siento pero no la recordaste bien. La vela se apaga" << endl;
			}
		}

};

class Acertijo : public Prueba {
public:
	void ejecutar() override {
		std::string respuestaUsuario;
		std::cout << "Responde a la siguiente pregunta:\n";
		std::cout << "¿Cuál es el animal que tiene cuatro patas y maúlla? ";
		std::cin.ignore(); // Limpiar el buffer del teclado antes de la entrada de la respuesta
		std::getline(cin, respuestaUsuario);


		if (respuestaUsuario == "gato" || respuestaUsuario == "Gato") {
			std::cout << "Respuesta correcta.\n";
		}
		else {
			std::cout << "Respuesta incorrecta. La vela se apaga.\n";
		}
	}
};

void jugar()
{
	cout << "Bienvenido al juego de la calabza asesina" << endl;
	cout << "Pulse un teclara para comenzar el juego" << endl;
	_getch();

	Vela vela;
	GestorTiempo gestortiempo(1, 30);

	//Vector de Pruebas
	vector<Prueba*> pruebas;
	pruebas.push_back(new PruebaTecla());
	pruebas.push_back(new PruebaOrdenarNumeros());
	pruebas.push_back(new PruebaRecordarSecuencias());
	pruebas.push_back(new Acertijo());

	// Bucle principal del juego
	for (Prueba* prueba : pruebas)
	{
		if(gestortiempo.tiempoAgotado() || !vela.encendida)
		{
			break;
		}

		//Iniciar el jeugo (iniciamos la prueba)
		gestortiempo.iniciarTiempoPrueba(chrono::seconds(10));

		//Ejecutar prueba actual
		prueba->ejecutar();

		//Mostramos el estado actual de la vela
		cout << "Estado de la vela: " << endl;
		vela.dibujar();

		//Actualizamos el tiempo global del juego
		gestortiempo.updateTiempo(gestortiempo.getTiempoRestantePruebaActual());

		//Mostramos el tiempo
		cout << "Tiempo restante: " << gestortiempo.getTiempoRestanteGlobal().count() << endl;

		this_thread::sleep_for(chrono::milliseconds(2));
	}

	//Liberar el espacio de la memoria para cada una de las pruebas
	for(Prueba* prueba : pruebas)
	{
		delete prueba;
	}

	FinalJuego::mostrarResultado(vela.encendida);
}

int main()
{
	jugar();
	return 0;
}


