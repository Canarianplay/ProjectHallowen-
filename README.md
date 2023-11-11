# Project Halloween 2023

En este repositorio podrás encontrar lso dos proyectos realizados para el especial
Halloween 2023 en mi canal 🎃.

# Generador de nombre para tu monstruo de Halloween (C++)
## Contenido
¿No sabes que nombre ponerte para la fiesta de halloween?... pues deja que MonsterNameGenerator lo haga por ti
Se trata de un juego que podrás jugar de dos formas diferentes y el cual te dará una serie de diferentes nombres
posibles para tu disfraz.

¡¡¡ATENCIÓN ⚠️!!!
Lo que actualmente s eencuentra subido en el proyecto no es la versión final del juego, una vez te lo descargues
encontrar varios comentarios con "TODO" a lo largo del código. Te invito a que te retes y completes tu este generador.

# Juego: ¿Serás capaz de huir de ella? (C++)

##Descripción:
Crea un juego de consola en el que los usuarios deben realizar acciones específicas para encender o apagar una vela de una calabaza virtual. El objetivo del juego es mantener la vela encendida el mayor tiempo posible.

##Diseño del juego:
Define los acertijos, pruebas o puzles que los jugadores deben resolver para mantener la vela encendida.
Meter un acertijo de toda la vida y que el usuario tenga que responder correctamente en menos de 30seg
Meter una acción (pulsar un tecla) y que el usuario tenga que hacerlo en menos de 10seg
Meter una lista de números desordenados y que el usuario tenga que ordenarlos en 1 minuto
Mostrar una secuencia de letras que luego desaparecen tras 5seg y el usuario tendrá que repetirla correctamente en 10seg

Diseña una mecánica para el tiempo en el juego. Puedes usar la función std::chrono para medir el tiempo transcurrido.

Cada prueba tendrá su propio crono
El juego tendrá un crono global cuya duración será de 1:30 minuto, por lo tanto el juego tendrá esa duración y al final de ella se revisará si la vela está encendida o apagada.


##Estructura del proyecto:

Divide el proyecto en diferentes archivos fuente (por ejemplo, uno para el juego principal, otro para los acertijos, otro para la gestión del tiempo, etc.).
Organiza tus clases y funciones de manera lógica para mantener el código limpio y modular.
Implementación de la mecánica del juego:
Todo en el mismo fichero

Crea una clase que represente la vela y mantenga un estado de encendido o apagado.
Implementa la lógica para resolver los acertijos o pruebas. Puedes usar estructuras de datos como vectores o listas para administrar las pruebas.
Clase main principal
Clase para representar la vela encendida y apagada
Clase para representar alguien escapando o la calabaza asesina
1 clase para cada una de las pruebas 
Clase para la gestión del tiempo global y de cada prueba



##Gestión de tiempo:

Utiliza la biblioteca <chrono> para rastrear el tiempo transcurrido y para establecer límites de tiempo para cada desafío.
Asegúrate de manejar eventos de tiempo para apagar la vela si el jugador no resuelve el acertijo a tiempo.


## License
Realizado por CanarianPlay 🍌
Si tienes dudas o mejoras que comentar no dudes en ponerte en contacto conmigo en cualquiera de mis RRSS o a través de mi email, te dejo por aquí los datos.
- [Twitch](https://www.twitch.tv/canarianplay) 👾
- [Instagram](https://www.instagram.com/canary_play/) 📸
- [TikTok](https://www.tiktok.com/@canarianplay) 💣
- [Youtube](https://www.youtube.com/channel/UCLKRz6v2PXB9qUSIsuHZXpQ) 🎥
- Email: canaryplay33@gmail.com 📩
