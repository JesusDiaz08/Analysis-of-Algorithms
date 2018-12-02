var numeros = []; // arreglo donde estan numeros de entrada
var colores = []; // arreglo para asociar un color a cada numero del arreglo de entrada
var colorleido = 'blue'; // color de numero en variable aux
var colorneutro = 'white'; // color sin leer
var colorres = 'red'; // color del resultados
var animar = false; // bandera para animar solo cuando se presione el boton

function showEntrada() {
    let elementos = document.getElementById("inputValues").value;
    let fieldNameElement = document.getElementById("res"); // prueba, se elimina despues
    
    let tokens = elementos.split (" ");
    let j;
	for (j = 0; j < tokens.length; j++){
		numeros.push(parseInt(tokens[j]));
		colores.push(colorneutro);
	}

	fieldNameElement.innerHTML = numeros [0]; // prueba, se elimina despues
	animar = true; // Animar 
	noLoop(); // Animar solo una vez
}


function setup() // Se ejecuta al cargar
{
  createCanvas(700, 400);  
}

function draw() // Se ejecuta infinitamente a menos que se use NoLoop ()
{ 
	if (animar){
		let j;
		drawArray (numeros, 10, 10, 50);
		animar = false;
	} 
}

function drawArray (arr, x, y, size){ // Funcion para dibujar el arreglo x y y posicines iniciales, size tamaño del cuadro
	let i;
	let posx;
	textSize (size/2);
	stroke ('black');
	for (i = 0; i < arr.length; i++){
		posx = x + size * i; 
		fill (colores[i]); // Llenar el cuadro de acuerdo a su color correspondiente
		rect (posx, y, size, size);
		fill ('black'); // Escribir numero en negro
		text (numeros[i], posx + (size/2), y + (size/2) + (size/10)); // Se escribe numero aprox. en el centro del cuadro
	}
}