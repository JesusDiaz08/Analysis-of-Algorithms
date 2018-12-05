var numeros = []; // arreglo donde estan numeros de entrada
var colores = []; // arreglo para asociar un color a cada numero del arreglo de entrada
var colorleido = 'blue'; // color de numero en variable aux
var colorneutro = 'white'; // color sin leer
var colorres = 'red'; // color del resultados
var animar = false; // bandera para animar solo cuando se presione el boton
var bandera = false;

var max_so_far = Number.MIN_SAFE_INTEGER; // Variables Kadane
	var max_ending_here = 0;

function showEntrada() { // Funcion que se llama al principio de animar
    let elementos = document.getElementById("inputValues").value;
    //let fieldNameElement = document.getElementById("res"); // prueba, se elimina despues
    let error = false;
    let tokens = elementos.split (" ");
    let j;
	for (j = 0; j < tokens.length; j++){
		if (!(isNaN(parseInt(tokens[j])))) {
			numeros.push(parseInt(tokens[j]));
			colores.push(colorneutro);	
		}
		else {
			elementos = [];
			numeros = [];
			colores = [];
			document.getElementById("inputValues").value = "";
			alert ("Pon números separados por un espacio en blanco, por favor");
			error = true;
			break;
		}
		
	}
	if (!error){
		//fieldNameElement.innerHTML = numeros [0]; // prueba, se elimina despues
		animar = true; // Animar 
		noLoop(); // Animar solo una vez
		animar = false;
		kadane ();
	}
}


function setup() // Se ejecuta al cargar
{
  createCanvas(900, 400);  
}

function draw() // Se ejecuta infinitamente a menos que se use NoLoop ()
{ 
	if (animar){
		console.log("en draw");
		drawArray (numeros, 10, 10, 75);
		drawResults (10, 10, 50);
		animar = false;
	} 
}

function drawArray (arr, x, y, size){ // Funcion para dibujar el arreglo x y y posicines iniciales, size tamaño del cuadro
	let i;
	let posx;
	textSize (size/3);
	stroke ('black');
	for (i = 0; i < arr.length; i++){
		posx = x + size * i; 
		fill (colores[i]); // Llenar el cuadro de acuerdo a su color correspondiente
		rect (posx, y, size, size);
		fill ('black'); // Escribir numero en negro
		text (numeros[i], posx + 3, y + (size/2) + (size/10)); // Se escribe numero aprox. en el centro del cuadro
	}
}

function drawResults (x, y, size){ // x y y son referencia del arreglo para no dibujar sobre el
	y = y + 50;
	
	textSize (size/2);
	fill (colorres);
	stroke (colorres);
	text ("Maximo general: " + max_so_far, x, y + 2 * size);
	fill (colorleido);
	stroke (colorleido);
	text ("Maximo hasta ahora: " + max_ending_here, x, y + 4 * size);
	fill ('black');	
}

async function kadane () {
	let i;
	let start = 0, end = 0, s = 0;
	for (i = 0; i < numeros.length; i++) 
    { 
        max_ending_here = max_ending_here + numeros[i];
        colores[i] = colorleido;
        if(i)
        {
        paso4.innerHTML='¿Es Máximo general < Máximo en la posición actual?';	
        }
        
        var paso5=document.getElementById("paso5");
        if (max_so_far < max_ending_here) 
        {
        	if(i)
        	{
        		paso5.innerHTML='Sí se actualiza el máximo general a: '+max_ending_here;
        	}
        	
           	max_so_far = max_ending_here;
            let j;
            for (j = start; j <= end; j++){
            	colores [j] = colorleido;
            } 

            start = s; 
            end = i;
            
            for (j = start; j <= end; j++){
            	colores [j] = colorres;
            }
        }else
        {
        	paso5.innerHTML='No';
        }
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        }

        console.log("en for");
        await sleep(2000);
        animar = true;

        paso1.innerHTML='Posición '+(i + 1);
        setup();
        redraw();
    } 
    //let fieldNameElement = document.getElementById("res");
    //fieldNameElement.innerHTML = max_so_far; // prueba funcionamiento
    numeros = [];
	colores = [];
	max_so_far = Number.MIN_SAFE_INTEGER;
	max_ending_here = 0;
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}