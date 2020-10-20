# TP1

####  Alumno: Colombo Juan Ignacio
####  Padron: 103471
####  Link GitHub: https://github.com/juanicolombo97/TP1




#### El trabajo consiste en la realizacion de tres encriptadores. El primero es el cesar, el cual recibe una clave numerica y un mensaje a encriptar o desencriptar, donde a cada caracter del mensaje le suma o resta respectivamente la clave recibida. Luego tenemos el cifrado vigenere, el cual es parecido al anterior, pero con la diferencia que recibe una clave alfanumerica. Finalmente tenemos el cifrador rc4, en este caso se recibe un mensaje y una clave, y consta de dos etapas. La primera es la KSA en donde se arma un vector de 256 elementos inicializados del 0 al 255, luego se pasa a llenar un vector de las mismas dimensiones con la clave recibida, repitiendola hasta llenarlo. Una vez terminado el KSA se obtiene una clave modificada del mismo tamanio que el mensaje. Finalmente se procede a sumar los caracteres de la clave con el mensaje. Ahora el motivo para haber echo estos encriptadores, se debe a que queremos hacer una implementacion de un cliente-servidor utilizando sockets en c. El programa funcionara de la siguiente manera. Primero se pasara a inicializar un servidor, creando un socket y haciendole un bind con un respectivo puerto y direccion. Luego se hace un lisen, el cual estara abierto a la espera de una conexion para realizar accept y leer el mensaje recibido. Este mensaje va a ser el enviado por el cliente, el cual debio haber sido inicializado, luego se debio conectarlo a un servidor y asi este podra enviar y recibir informacion. Al moemnto de enviar la informacion el cliente debera leer de entrada estandar un mensaje y enviarlo de a 64 bytes, pero este mensaje debera estar encriptado por uno de los codificadores creados anteriormente, para asi ser recibidos por el servidor y desencriptados por el mismo.


#### Diagrama 1

![diagrama](https://user-images.githubusercontent.com/49823710/96625977-41761300-12e5-11eb-8f9e-30a58a999685.png)


#### En el siguiente diagrama podemos ver como funciona el programa. Vemos como el cliente esta asociado a un cifrador_t y tambien a un socket. Lo mismo para para el servidor. Finalmente vemos como el cliente es una agregacin del servidor. Esto es porque cuando el servidor deja de existir el cliente sigue existiendo. Y vemos como un cliente puede estar conectado a un servidor, y un servidor recibir multiples clientes.
